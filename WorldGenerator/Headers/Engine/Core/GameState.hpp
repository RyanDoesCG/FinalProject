/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameState.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef GameState_hpp
#define GameState_hpp

enum GameState {
    MAIN_MENU,          // 0
    SET_SEED,           // 1
    RUNNING_FREEMODE,   // 2
    RUNNING_EDITMODE,   // 3
    PAUSED,             // 4
    LOAD_GAME,          // 5
    OPTIONS,            // 6
    OVER                // 7
};

#endif
