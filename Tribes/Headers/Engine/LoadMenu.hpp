/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Actor.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 29/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef LoadMenu_hpp
#define LoadMenu_hpp

#include "Menu.hpp"

class LoadMenu : public Menu {
    public:
        LoadMenu(float width, float height, Game* game);
       ~LoadMenu();
    
    private:
        virtual void handleEvents() override;
    
        MenuItem example1;
        MenuItem example2;
        MenuItem example3;
};

#endif /* LoadMenu_hpp */
