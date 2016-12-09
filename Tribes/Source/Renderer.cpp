#include "../Headers/Engine/Renderer.hpp"

Renderer::Renderer (SceneCamera* cam) {
    camera = cam;
}

Renderer::~Renderer () {
    
}

void Renderer::addToScene(Actor* actor) {
    scene.push_back(actor);
}

void Renderer::drawScene(GameState state) {
    for (int i = 0; i < scene.size(); i++) {
        scene.at(i)->update(state, camera);
    }
}
