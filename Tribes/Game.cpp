/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Game.cpp
 *  Tribes
 *
 *  Created by ryan needham on 02/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Game.hpp"

#include "Mesh.hpp"

Game::Game() {
    input  = new InputHandler(this);
    window = new Window(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "tribes"
    );
    
    camera = new Camera(
        glm::vec3(0, 0, -12),
        100.0f,
        (float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,
        0.01f,
        1000.0f
    );
    
    state = RUNNING;
}

Game::~Game() {

}

void Game::begin() {
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;
    
    // test vertices
    Vertex one = Vertex();
    Vertex two = Vertex();
    Vertex three = Vertex();
    one.Position = glm::vec3(-0.3, -0.5, 0);
    one.Normal   = glm::vec3();
    one.TexCoords= glm::vec2(0.0, 0.0);
    two.Position = glm::vec3(0, 0.3, 0);
    two.Normal   = glm::vec3();
    two.TexCoords= glm::vec2(0.5, 1.0);
    three.Position = glm::vec3(0.3, -0.5, 0);
    three.Normal   = glm::vec3();
    three.TexCoords= glm::vec2(1.0, 0.0);
    vertices.push_back(one);
    vertices.push_back(two);
    vertices.push_back(three);
    
    // test indices
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);

    Shader* testShade = new Shader("land");
    Mesh* test = new Mesh(
        vertices,
        indices,
        textures
    );

    while (state != ENDED) {
        input->checkInput();
        
        if (state == RUNNING) {
            // update
            window->clear();
            test->draw(*testShade);
            window->update();
        }
    }
}

void Game::end() {
    state = ENDED;
}

void Game::pause() {
    // toggle pause on and off
    if (state == PAUSED) state = RUNNING;
    else if (state == RUNNING) state = PAUSED;
    std::cout << "pause msg received\n";
}
