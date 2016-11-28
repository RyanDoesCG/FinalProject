/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SubMenu.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef SubMenu_hpp
#define SubMenu_hpp

#include "KeyboardInputComponent.hpp"
#include "TextRenderingComponent.hpp"
#include "MenuItem.hpp"
#include <iostream>

class SubMenu {
    public:
        SubMenu (float width, float height);
        SubMenu () {}
       ~SubMenu ();
    
        void update();
    
        void hide();
        void show();
    
        void addItem(std::string item);
        void removeItem(std::string item);
    
    private:
        float windowWidth;
        float windowHeight;
        float bassline;
    
        KeyboardInputComponent* keyboard;
        TextRenderingComponent* textPipeline;
        int selectedItem;
    
        bool isHidden;
    
        std::vector<MenuItem> items;
        void handleEvents ();
};

#endif /* SubMenu_hpp */
