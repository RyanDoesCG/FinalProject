/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Actor.hpp
 *  Tribes
 *
 *  Created by ryan needham on 01/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Actor_hpp
#define Actor_hpp

#include "../../glm/glm.hpp"
#include "../Core/GameState.hpp"
#include "../Components/Component.hpp"
#include <iostream>
#include <map>

typedef int ComponentID;
typedef int ChildID;
class SceneCamera; // dont like this

/**
 *  Actor Class
 *
 */
class Actor {
    public:
        Actor() {}
       ~Actor() {}

        virtual void init () {
            initComponents();
            initChildren();
        }
    
        virtual void draw (GameState state, SceneCamera* camera) {
            updateComponents();
            drawChildren(state, camera);
        }
    
        virtual void moveLeft     () { position.x -= 0.1; }
        virtual void moveRight    () { position.x += 0.1; }
        virtual void moveForward  () { position.z += 0.1; }
        virtual void moveBackward () { position.z -= 0.1; }
    
        void setScale    (float s)          { scale = glm::vec3(s, s, s);}
        void setScale    (glm::vec3 s)      { scale = s; }
        void setParent   (Actor* parent)    { this->parent = parent; }
        void setColour   (glm::vec3 col)    { colour = col;}
        void setPosition (glm::vec3 newPos) { this->position = newPos; }
        void setRotation (glm::vec3 rot)    { this->rotation = rot;}
    
        glm::vec3 getPosition () { return this->position; }
        glm::vec3 getRotation () { return this->rotation; }
        glm::vec3 getColour   () { return colour; }
    
    protected:
        Component* addComponent (Component* comp) {
            comp->componentID = components.size();
            components.insert(std::pair<ComponentID, Component*>(comp->componentID, comp));
            comp->setOwner(this);
            return comp;
        }
    
        void dropComponent (ComponentID id) {
            components.at(id)->releaseOwner();
            components.erase(id);
        }
    
        Actor* addChild (Actor* child) {
            children.insert(std::pair<ChildID, Actor*>(children.size(), child));
            child->setParent(this);
            return child;
        }
    
        void initComponents () {
            for (int i = 0; i < components.size(); i++)
                components.at(i)->init();
        }
    
        void initChildren () {
            for (int i = 0; i < children.size(); i++)
                children.at(i)->init();
        }
    
        void updateComponents () {
            for (int i = 0; i < components.size(); i++)
                components.at(i)->update();
        }
    
        void drawChildren (GameState state, SceneCamera* camera) {
            for (int i = 0; i < children.size(); i++)
                children.at(i)->draw(state, camera);
        }
    
        std::map<ComponentID, Component*> components;
        std::map<ChildID, Actor*> children;
    
        Actor* parent;
    
        glm::vec3 position = glm::vec3(0.0, 0.0, 0.0);
        glm::vec3 rotation = glm::vec3(0.0, 0.0, 0.0);
        glm::vec3 colour   = glm::vec3(1.0, 0.5, 0.5);
        glm::vec3 scale    = glm::vec3(1.0, 1.0, 1.0);
    
};

#endif /* Actor_hpp */
