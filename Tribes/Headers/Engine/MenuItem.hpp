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
