/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MainMenu.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef MainMenu_hpp
#define MainMenu_hpp

#include "KeyboardInputComponent.hpp"
#include "TextRenderingComponent.hpp"
#include "MenuItem.hpp"
#include "SubMenu.hpp"
#include <iostream>

class MainMenu {
    public:
        MainMenu (float width, float height);
       ~MainMenu ();
    
        void update();
    
        void hide();
        void show();
    
    private:
        float windowWidth;
        float windowHeight;
        float bassline;
    
        KeyboardInputComponent* keyboard;
        TextRenderingComponent* textPipeline;
        bool isHidden;
    
        MenuItem newgame;
        SubMenu  newgameSub;
    
        MenuItem loadgame;
        SubMenu  loadgameSub;
    
        MenuItem options;
        SubMenu  optionsSub;
    
        MenuItem quit;
        int selectedItem;
    
        std::vector<MenuItem> items;
        std::vector<SubMenu> children;
    
        void handleEvents ();
};

#endif /* MainMenu_hpp */
