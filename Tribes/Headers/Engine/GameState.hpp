#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

enum GameState {
    MENU, RUNNING, PAUSED, ENDED
};

enum NextGenGameState {
    MAIN_MENU,
    NEW_GAME,
    LOAD_GAME,
    OPTIONS_SCREEN,
    IN_GAME,
    IN_GAME_PAUSED,
    GAME_OVER
};


#endif
