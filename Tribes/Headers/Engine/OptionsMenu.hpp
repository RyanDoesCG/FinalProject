//
//  OptionsMenu.hpp
//  Tribes
//
//  Created by user on 29/11/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#ifndef OptionsMenu_hpp
#define OptionsMenu_hpp

#include "Menu.hpp"

class OptionsMenu : public Menu {
public:
    OptionsMenu(float width, float height, Game* game);
    ~OptionsMenu();
    
private:
    virtual void handleEvents() override;
    
    MenuItem resolution;
    MenuItem quality;
    MenuItem controller;
    MenuItem about;
};

#endif /* OptionsMenu_hpp */
