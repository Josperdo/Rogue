#include "rogue.h"

int main ()
{
    int ch;
    Position * newPosition;

    Level * level;

    screenSetUp();

    level = createLevel(1);
    printGameHub();

    /* main game loop stuff */
    while ((ch = getch()) != 'q')
    {
        printGameHub();
        newPosition = handleInput(ch, level->user);
        checkPosition(newPosition, level);
        moveMonsters(level);
        move(level->user->position->y, level->user->position->x);
    }
    endwin();
    
    return 0;
}

