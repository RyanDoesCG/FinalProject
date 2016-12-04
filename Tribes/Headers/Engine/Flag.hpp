/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Actor.hpp
 *  Tribes
 *
 *  Created by ryan needham on 04/12/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Flag_hpp
#define Flag_hpp

#include "Actor.hpp"

class Flag : public Actor {
    public:
         Flag();
        ~Flag();
    
    private:
        virtual void update (GameState state, SceneCamera* camera) override;
};

#endif /* Flag_hpp */
