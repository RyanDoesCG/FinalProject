/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MainMenu.hpp
 *  Tribes
 *
 *  Created by ryan needham on 29/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef MainMenu_hpp
#define MainMenu_hpp

#include "Menu.hpp"

class MainMenu : public Menu {
    public:
        MainMenu(float width, float height, Game* game);
       ~MainMenu();
    
    private:
        virtual void handleEvents() override;
    
        MenuItem quit;
        MenuItem options;
        MenuItem biomes;
        MenuItem planets;
        //MenuItem loadGame;
        //MenuItem newGame;
};

#endif /* MainMenu_hpp */
