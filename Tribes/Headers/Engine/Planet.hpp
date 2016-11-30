//
//  Planet.hpp
//  Tribes
//
//  Created by user on 30/11/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#ifndef Planet_hpp
#define Planet_hpp

#include "Actor.hpp"
#include "Model.hpp"

class Planet : public Actor {
    public:
        Planet ();
       ~Planet ();
    
       virtual void update (GameState state, SceneCamera* camera) override;
    
        void setLightSource (Actor* light) {frame.setLightSource(light);}
    
    private:
        Model frame;
};

#endif /* Planet_hpp */
