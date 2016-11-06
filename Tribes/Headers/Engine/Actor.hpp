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

#include "GameState.hpp"
#include "ActorComponent.hpp"
#include <iostream>
#include <map>

typedef int ComponentID;
typedef int ChildID;

/**
 *  Actor Class
 *
 */
class Actor {
public:
     Actor() {}
    ~Actor() {}

    // replace these for loops with something prettier maybe
    virtual void init   () {
        initComponents();
        initChildren();
    }
    
    virtual void update (GameState state) {
        updateComponents();
        updateChildren(state);
    }
    
    ActorComponent* addComponent (ActorComponent* comp) {
        components.insert(std::pair<ComponentID, ActorComponent*>(components.size(), comp));
        comp->setOwner(this);
        return comp;
    }
    
    Actor* addChild (Actor* child) {
        children.insert(std::pair<ChildID, Actor*>(children.size(), child));
        child->setParent(this);
        return child;
    }
    
    void setParent (Actor* parent) {
        this->parent = parent;
    }
    
protected:
    void initComponents   () { for (int i = 0; i < components.size(); i++) components.at(i)->init(); }
    void initChildren     () { for (int i = 0; i < children.size(); i++) children.at(i)->init(); }
    
    void updateComponents () { for (int i = 0; i < components.size(); i++) components.at(i)->update(); }
    void updateChildren   (GameState state) { for (int i = 0; i < children.size(); i++) children.at(i)->update(state); }
    
    std::map<ComponentID, ActorComponent*> components;
    std::map<ChildID, Actor*> children;
    
    Actor* parent;
    
};

#endif /* Actor_hpp */
