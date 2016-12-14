/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Moon.hpp
 *  Tribes
 *
 *  Created by ryan needham on 04/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Moon_hpp
#define Moon_hpp

#include "Model.hpp"

class Moon : public Model {
    public:
        Moon ();
       ~Moon ();
    
        virtual void draw (GameState state, SceneCamera* camera) override;
    
        void setSpeed (int s);
    
    private:
        int speed;
    
};

#endif /* Moon.hpp */
