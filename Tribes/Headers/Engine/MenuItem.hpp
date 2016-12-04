/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  MenuItem.hpp
 *  Tribes
 *
 *  Created by ryan needham on 29/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef MenuItem_hpp
#define MenuItem_hpp

#include <string>

class Menu;

class MenuItem {
public:
    std::string label;
    int         index;
    Menu*       menu;
};

#endif /* MenuItem.hpp */
