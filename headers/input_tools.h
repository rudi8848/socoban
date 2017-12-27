#ifndef INPUT_TOOLS_H
#define INPUT_TOOLS_H

typedef enum
{
    KEY_UNKNOWN = 0
    ,KEY_ENTER
    ,KEY_SPACE
    ,KEY_ESC
    ,KEY_UP
    ,KEY_RIGHT
    ,KEY_DOWN
    ,KEY_LEFT
}eKeyCode;

eKeyCode    it_get_key();

#endif