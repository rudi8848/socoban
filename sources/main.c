//#include <stdio.h>
#include "../headers/socoban_menu.h"

typedef enum {
    GAME_INIT = 0
    ,GAME_MENU
    ,GAME_MAIN
    ,GAME_ABOUT
    ,GAME_SELECT_LEVEL
    ,GAME_EXIT
}eGameState;

void    game_init();
void    game_main();
void    game_draw();
void    game_processing();
void    game_menu();
void    game_about();
void    game_select_level();
void    game_exit();

eGameState g_game_state = GAME_INIT;

int main() {
    char isRun = 1;
    while (isRun)
    {
        switch (g_game_state)
        {
            case GAME_INIT:
            {
                game_init();
                g_game_state = GAME_MENU;
                break;
            }
            case GAME_MENU:
            {
                game_menu();
                break;
            }
            case GAME_MAIN:
            {
                game_menu();
                break;
            }
            case GAME_ABOUT:
            {
                game_about();
                break;
            }
            case GAME_SELECT_LEVEL:
            {
                game_select_level();
                break;
            }
            case GAME_EXIT:
            {
                game_exit();
                isRun = 0;
                break;
            }
        }
    }
    return 0;
}

void    game_init()
{
    g_game_state = GAME_MENU;
}
void    game_main()
{

}
void    game_draw()
{

}
void    game_processing()
{

}
void    game_menu()
{
    socoban_menu_processing();
}
void    game_about()
{

}
void    game_select_level()
{

}
void    game_exit()
{

}