//
//  TerrainWireframe.cpp
//  WorldGenerator
//
//  Created by user on 25/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include  "../../Headers/Engine/Actors/TerrainWireframe.hpp"
#include  "../../Headers/soil/SOIL.h"
#include  "../../Headers/GLM/gtc/type_ptr.hpp"

// Mesh
GLuint VAO;
GLuint vertVBO;
GLuint indVBO;
glm::vec3 verts[VERT_COUNT];
GLuint    ind  [IND_COUNT];

// Height Map
std::string filepath = "map.jpg";
GLuint heightMapID;

TerrainWireframe::TerrainWireframe (): shader("Assets/shaders/WireTest") {
    makeShader();
    makeMesh();
    makeMap();
}

TerrainWireframe::~TerrainWireframe () {

}

void TerrainWireframe::update (GameState state) {

}

void TerrainWireframe::draw   (SceneCamera* camera) {
    shader.bind();
    
        // M V P
    
        glm::mat4 view = camera->getViewTransform();
        glm::mat4 proj = camera->getProjectionTransform();
        shader.passMatrix4("view", 1, GL_FALSE, glm::value_ptr(view));
        shader.passMatrix4("proj", 1, GL_FALSE, glm::value_ptr(proj));
    
        glm::mat4 model;
        model = glm::translate(glm::mat4(), position);
        model = glm::rotate(model, rotation.x, glm::vec3(1.0, 0.0, 0.0));
        model = glm::rotate(model, rotation.y, glm::vec3(0.0, 1.0, 0.0));
        model = glm::rotate(model, rotation.z, glm::vec3(0.0, 0.0, 1.0));
        //model = glm::scale(model,  scale);
        shader.passMatrix4("model", 1, GL_FALSE, glm::value_ptr(model));
    
        //draw terrain mesh
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_TRIANGLES, IND_COUNT, GL_UNSIGNED_INT, 0);
    
    shader.unbind();
}

void TerrainWireframe::makeShader() {
    
    shader.bind();
    // vertices
    //shader->AddAttribute("vVertex");
    
    // uniforms
    shader.AddUniform("heightMapTexture");
    shader.AddUniform("scale");
    shader.AddUniform("half_scale");
    shader.AddUniform("HALF_TERRAIN_SIZE");
    shader.AddUniform("MVP");
    
    // set values of constant uniforms as initialization
    shader.passUniform1i("heightMapTexture", 0);
    shader.passUniform2i("HALF_TERRAIN_SIZE", TERRAIN_WIDTH>>1, TERRAIN_DEPTH>>1);
    shader.passUniform1f("scale", SCALE);
    shader.passUniform1f("half_scale", HALF_SCALE);
    shader.unbind();
}

void TerrainWireframe::makeMesh()   {
    //fill indices array
    GLuint* id = &ind[0];
    
    //setup vertices
    int count = 0;
    //fill terrain vertices
    for(int z = 0; z < TERRAIN_DEPTH; z++) {
        
        for(int x = 0; x < TERRAIN_WIDTH; x++, count++) {
            
            verts[count] = glm::vec3(
                                     (float(x)/(TERRAIN_WIDTH-1)),
                                     0,
                                     (float(z)/(TERRAIN_DEPTH-1))
                                     );
        }
    }
    
    //fill terrain indices
    for (int z = 0; z < TERRAIN_DEPTH - 1; z++) {
        for (int x = 0; x < TERRAIN_WIDTH-1; x++) {
            int i0 = x + z*TERRAIN_WIDTH;
            int i1 = i0+1;
            int i2 = i0+TERRAIN_WIDTH;
            int i3 = i2+1;
            *id++ = i0;
            *id++ = i2;
            *id++ = i1;
            *id++ = i1;
            *id++ = i2;
            *id++ = i3;
        }
    }
    
    // Give to GPU
    glGenVertexArrays (1, &VAO);
    glGenBuffers      (1, &vertVBO);
    glGenBuffers      (1, &indVBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer (GL_ARRAY_BUFFER, vertVBO);
    //pass terrain vertices to buffer object
    glBufferData (GL_ARRAY_BUFFER, sizeof(verts), &verts[0], GL_STATIC_DRAW);
    
    //printError();
    //GL_CHECK_ERRORS
    
    //enable vertex attribute array for position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    //printError();
    //GL_CHECK_ERRORS
    
    //pass the terrain indices array to element array buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indVBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ind), &ind[0], GL_STATIC_DRAW);
}

void TerrainWireframe::makeMap()    {
    //load the heightmap texture using SOIL
    int texture_width   = 0;
    int texture_height  = 0;
    int channels        = 0;
    
    GLubyte* pData = SOIL_load_image(filepath.c_str(), &texture_width, &texture_height, &channels, SOIL_LOAD_L);
    
    //vertically flip the heightmap image on Y axis since it is inverted
    for(int y = 0; y * 2 < texture_height; ++y ) {
        int index1 = y * texture_width ;
        int index2 = (texture_height - 1 - y) * texture_width ;
        
        for(int x = texture_width; x > 0; --x) {
            GLubyte temp = pData[index1];
            pData[index1] = pData[index2];
            pData[index2] = temp;
            ++index1;
            ++index2;
        }
    }
    
    //setup OpenGL texture
    glGenTextures(1, &heightMapID);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, heightMapID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, texture_width, texture_height, 0, GL_RED, GL_UNSIGNED_BYTE, pData);
    
    //free SOIL image data
    SOIL_free_image_data(pData);
}
