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
#include "Water.hpp"

class Planet : public Model {
    public:
        Planet ();
       ~Planet ();
    
        virtual void draw (SceneCamera* camera) override;
        virtual void update (GameState state) override;
    
        void setLight (Actor* );

        void randomise();
    
        std::string getName ();
    
        void toggleWater () {waterActive=!waterActive;}
        void toggleAtmos () {atmosActive=!atmosActive;}
    
    private:
        void generateName();
        std::string name;
    
        Water water;
        Model atmosphere;

        bool waterActive = true;
        bool atmosActive = true;
};

#endif /* Planet_hpp */
