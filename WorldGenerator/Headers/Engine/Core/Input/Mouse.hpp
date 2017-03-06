//
//  Mouse.hpp
//  WorldGenerator
//
//  Created by user on 06/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef Mouse_hpp
#define Mouse_hpp

class Mouse {
    public:
        Mouse ();
       ~Mouse ();
    
        void attach (GLFWwindow* window);
        void update ();
    
        void hideMouse ();
        void showMouse ();
    
        void placeMouse(int x, int y);
        void centerMouse();
    
        float getMouseX ();
        float getMouseY ();
    
        float getXoffset ();
        float getYoffset ();
    
    private:
        GLFWwindow* window;
};

#endif /* Mouse_hpp */
