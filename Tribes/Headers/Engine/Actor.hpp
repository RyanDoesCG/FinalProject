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

#include "ActorComponent.hpp"
#include <iostream>
#include <map>

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
        for (int i = 0; i < components.size(); i++)
            components.at(i)->init();
    }
    
    virtual void update () {
        for (int i = 0; i < components.size(); i++)
            components.at(i)->update();
    }
    
    void addComponent (ActorComponent* comp) {
        components.insert(std::pair<int, ActorComponent*>(components.size(), comp));
        comp->setOwner(this);
    }
    
protected:
    std::map<int, ActorComponent*> components;
    
};

#endif /* Actor_hpp */
