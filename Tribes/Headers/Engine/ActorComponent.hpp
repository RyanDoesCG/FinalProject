/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ActorComponent.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef ActorComponent_hpp
#define ActorComponent_hpp

class Actor;
class ActorComponent {
    public:
        ActorComponent () { }
       ~ActorComponent () { }
    
        virtual void init   () { }
        virtual void update () { }
    
        void setOwner (Actor* a) { this->owner = a; }
        void releaseOwner () { this->owner = nullptr; }
    
        int componentID;
    
    protected:
        Actor* owner;
};

#endif /* ActorComponent_hpp */
