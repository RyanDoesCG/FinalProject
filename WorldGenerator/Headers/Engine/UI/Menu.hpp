/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Menu.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Menu_hpp
#define Menu_hpp

#include "../Components/GamepadComponent.hpp"
#include "../Components/KeyboardComponent.hpp"
#include "../Components/TextRenderingComponent.hpp"

#include "MenuItem.hpp"
#include <iostream>

class Game;
class Menu {
    public:
        Menu (float width, float height, Game* game);
       ~Menu ();
    
        void update();
    
        void hide();
        void show();

    protected:
        float windowWidth;
        float windowHeight;
        float bassline;
    
        Game* game;
    
        GamepadComponent*       gamepad;
        KeyboardCopmonent* keyboard;
        TextRenderingComponent* textPipeline;

        std::vector<MenuItem> items;
        std::vector<Menu*> children;
        virtual void handleEvents ();
        int selectedItem;
        bool isHidden;
};

#endif /* MainMenu_hpp */
