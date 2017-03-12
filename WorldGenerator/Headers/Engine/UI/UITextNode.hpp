//
//  UITextNode.hpp
//  WorldGenerator
//
//  Created by user on 12/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef UITextNode_hpp
#define UITextNode_hpp

#include "GraphicsEngine.hpp"
#include "GameObject.hpp"

class UITextNode: public GameObject {
    public:
        UITextNode (GraphicsEngine* graph);
       ~UITextNode ();
    
       virtual void update () override;
    
        void fadeIn  ();
        void fadeOut ();
    
    private:
        GraphicsObject* graphics;
    
        glm::vec3 litColour;
        glm::vec3 unlitColour;
    
};

#endif /* UITextNode_hpp */
