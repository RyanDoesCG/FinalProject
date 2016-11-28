/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  GameState.hpp
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef GameState_hpp
#define GameState_hpp

enum GameState {
    MAIN_MENU, // 0
    SET_SEED,  // 1
    RUNNING,   // 2
    PAUSED,    // 3
    LOAD_GAME, // 4
    OPTIONS,   // 5
    OVER       // 6
};

#endif
