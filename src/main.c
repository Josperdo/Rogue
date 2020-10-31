#include "rogue.h"

int main ()
{
    int ch;
    Position * newPosition;

    Level * level;

    screenSetUp();

    level = createLevel(1);

    /* main game loop stuff */
    while ((ch = getch()) != 'q')
    {
        newPosition = handleInput(ch, level->user);
        checkPosition(newPosition, level);
        moveMonsters(level);
        move(level->user->position->y, level->user->position->x);
    }
    endwin();
    
    return 0;
}

// Screen
int screenSetUp()
{
    initscr();
    printw("Hello world!");
    noecho();
    refresh();

    srand(time(NULL));

    return 1;

}

