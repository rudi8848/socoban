#include <stdio.h>
#include <stdlib.h>
#include "../headers/socoban_menu.h"
#include "../headers/input_tools.h"
#include "../headers/socoban_levels.h"
//#include "level_data.c"

unsigned    g_cur_lev = 1;

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

eGameState      g_game_state = GAME_INIT;
eMenuState      g_menu_state = MENU_MAIN;

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
                game_main();
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
    g_cur_lev = 1;
    socoban_levels_load(g_cur_lev);
    it_get_key();
}

void    game_main()
{
    game_draw();
    game_processing();
}
void    game_draw()
{
    system("cls");
    socoban_levels_draw();

    if (socoban_levels_is_victory())
    {
        printf("Victory!\n");
        ++g_cur_lev;
        socoban_levels_load(g_cur_lev);
    }

}
void    game_processing()
{
    switch (it_get_key())
    {
    case KEY_UP:
    {
        socoban_levels_player_move(DIR_UP);
        break;
    }
    case KEY_RIGHT:
    {
        socoban_levels_player_move(DIR_RIGHT);
        break;
    }
    case KEY_DOWN:
    {
        socoban_levels_player_move(DIR_DOWN);
        break;
    }
    case KEY_LEFT:
    {
        socoban_levels_player_move(DIR_LEFT);
        break;
    }
    case KEY_ESC:
    {
        g_game_state = GAME_MENU;
        socoban_menu_init();
        break;
    }

    case KEY_UNKNOWN:
    case KEY_ENTER:
    case  KEY_SPACE:
        break;
    }

}
void    game_menu()
{
    socoban_menu_processing();
    g_menu_state = socoban_menu_current_state();
    switch(g_menu_state)
    {
    case MENU_START:
    {
        g_game_state = GAME_MAIN;
        break;
    }
    case MENU_SELECT_LEVEL:
    {
        g_game_state = GAME_SELECT_LEVEL;
        break;
    }
    case MENU_ABOUT:
    {
        g_game_state = GAME_ABOUT;
        break;
    }
    case MENU_EXIT:
    {
        g_game_state = GAME_EXIT;
        break;
    }
    case MENU_MAIN_END:
    case MENU_MAIN:
        break;
    }
}
void    game_about()
{
    system("cls");
    printf("about\n");
    if (it_get_key() == KEY_ESC)
    {
        g_game_state = GAME_MENU;
        socoban_menu_init();
    }
}
void    game_select_level()
{
    system("cls");
    printf("select level\n");
    if (it_get_key() == KEY_ESC)
    {
        g_game_state = GAME_MENU;
        socoban_menu_init();
    }
}
void    game_exit()
{
    system("cls");
    printf("looser!\n");
    it_get_key();
}