/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Planet.hpp
 *  Tribes
 *
 *  Created by ryan needham on 30/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Planet_hpp
#define Planet_hpp

#include "Actor.hpp"
#include "Model.hpp"

class Planet : public Model {
    public:
        Planet ();
       ~Planet ();
    
        virtual void update (GameState state, SceneCamera* camera) override;
        void setLight (Actor* );

        void randomise();
    
        std::string getName ();
    private:
        void generateName();
        std::string name;
    
        Model water;

};

#endif /* Planet_hpp */