/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Sun.hpp
 *  Tribes
 *
 *  Created by ryan needham on 01/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Sun_hpp
#define Sun_hpp

#include "Model.hpp"
#include "Quad.hpp"
#include "../Utility/ShaderCache.hpp"

class Sun: public Model {
    public:
         Sun();
        ~Sun();
    
        virtual void draw (SceneCamera* camera) override;
        virtual void update (GameState state) override;
    
    private:
        Quad flare1;
        Quad flare2;
        Quad flare3;
        Quad flare4;
    
};

#endif
