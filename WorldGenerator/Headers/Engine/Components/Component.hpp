/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Component.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Component_hpp
#define Component_hpp

class Actor;
class Component {
    public:
        Component () { }
       ~Component () { }
    
        virtual void init   () { }
        virtual void update () { }
    
        void setOwner (Actor* a) { this->owner = a; }
        void releaseOwner () { this->owner = nullptr; }
    
        int componentID;
    
    protected:
        Actor* owner;
};

#endif /* Component_hpp */
