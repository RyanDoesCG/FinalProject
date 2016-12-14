/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Quad.cpp
 *  Tribes
 *
 *  Created by Ryan Needham on 08/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Headers/Engine/Actors/Quad.hpp"
#include "../../Headers/Engine/Utility/ShaderCache.hpp"
#include "../../Headers/glm/gtc/type_ptr.hpp"

Quad::Quad () {
    std::vector<GLfloat> vertices = {
        -1.0, 1.0,        -1.0, 1.0,
        1.0, 1.0,           1.0, 1.0,
        -1.0, -1.0,        -1.0,-1.0,
        
        -1.0, -1.0,        -1.0, -1.0,
        1.0, -1.0,          1.0, -1.0,
        1.0, 1.0,           1.0, 1.0,
    };
    
    shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent("HUDPane", BASIC));
    mesh = (MeshComponent*)addComponent(new MeshComponent(vertices, 0));
}

Quad::~Quad () {
    
}

void Quad::setTexture(GLuint tex) {
    texture = tex;
}

void Quad::setShader(std::string name) {
    shader = (ShaderComponent*)addComponent(ShaderCache::loadShaderComponent(name, BASIC));
}

void Quad::draw (GameState state, SceneCamera* camera) {
    mesh->position = position;
    mesh->rotation = rotation;
    mesh->scale    = scale;
    mesh->colour   = colour;
    
    shader->update();

    mesh->texturedDraw(shader, camera, texture);
}
