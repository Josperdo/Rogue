#include "rogue.h"
int main ()
{
    Player * user;
    int ch;
    Position * newPosition;
    char ** level;

    screenSetUp();

    mapSetUp();

    level = saveLevelPositions();

    user = playerSetUp();

    mvprintw(0,0, "The char at 13, 13 is: %c", level[13]);
    
    /* main game loop stuff */
    while ((ch = getch()) != 'q')
    {
        newPosition = handleInput(ch, user);
        checkPosition(newPosition, user, level);
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

