//
//  SeedMenu.hpp
//  Tribes
//
//  Created by user on 29/11/2016.
//  Copyright © 2016 Dissertation. All rights reserved.
//

#ifndef SeedMenu_hpp
#define SeedMenu_hpp

#include "Menu.hpp"

class SeedMenu : public Menu {
    public:
        SeedMenu(float width, float height, Game* game);
       ~SeedMenu();
    
    private:
        virtual void handleEvents() override;

        MenuItem randomSeed;
        MenuItem customSeed;
};

#endif /* SeedMenu_hpp */
