#include "rogue.h"

int addMonsters(Level * level)
{
    int x;
    level->monsters = malloc(sizeof(Monster *)* 6);
    level->numberOfMonsters = 0;

    for (x = 0; x < level->numberOfRooms; x++)
    {
        if ((rand() % 2) == 0)
        {
            level->monsters[level->numberOfMonsters] = selectMonsters(level->level);
            setStartingPosition(level->monsters[level->numberOfMonsters], level->rooms[x]);
            level->numberOfMonsters++;
        }
    }
}

Monster * selectMonsters(int level)
{
    int monster;
    switch (level)
    {
        case 1:
        case 2: 
        case 3:
            monster = (rand() % 2) + 1;
            break;
        case 4: 
        case 5:
            monster = (rand() % 2) + 2;
            break;
        case 6:
            monster = 3;
            break;
    }

    switch (monster)
    {
        case 1: // spider
            return createMonster('X', 2, 1, 1, 1, 1);

        case 2: // goblin
            return createMonster('G', 5, 3, 1, 1, 2);

        case 3: // troll
            return createMonster('T', 15, 5, 1, 1, 1);

/* MONSTER STATS REFERENCE

1 Spider
    symbol: X
    levels: 1-3
    health: 2
    attack: 1
    speed: 1
    defense: 1
    pathfinding: 1 (random)

2 Goblin
    symbol: G
    levels: 1-5
    health: 5
    attack: 3
    speed: 1
    defense: 1
    pathfinding: 2 (seeking)

3 Troll
    symbol: T
    levels: 4-6
    health: 15
    attack: 5
    speed: 1
    defense: 1
    pathfinding: 1 (random)

*/
    }

}

Monster * createMonster(char symbol, int health, int attack, int speed, int defense, int pathfinding)
{
    Monster * newMonster;
    newMonster = malloc(sizeof(Monster));

    newMonster->symbol = symbol;
    newMonster->health = health;
    newMonster->attack = attack;
    newMonster->speed = speed;
    newMonster->defense = defense;
    newMonster->pathfinding = pathfinding;

    sprintf(newMonster-string, "%c", monster->symbol);


    return  newMonster;
}


int setStartingPosition(Monster * monster, Room * room)
{

    monster->position.x = (rand() % (room->width - 2)) + room->position.x + 1;
    monster->position.y = (rand() % (room->height - 2)) + room->position.y + 1;

    mvprintw(monster->position.y, monster->position.x, monster->string);
}

int moveMonsters(Level * level)
{
    int x;
    for (x = 0; x < level->numberOfMonsters; x++)
    {
        mvprintw(level->monsters[x]->position->y, level->monsters[x]->position->x, ".");

        if (level->monsters[x]->pathfinding == 1)
        {
            pathfindinRandom(level->monsters[x]->position);
        } else
        {
            pathfindingSeek(level->monsters[x]->position, level->user->position);
            mvprintw(level->monsters[x]->position->y, level->monsters[x]->position->x, level->monsters[x]->string);
        }

         mvprintw(level->monsters[x]->position->y, level->monsters[x]->position->x, level->monsters[x]->string);

    } 
    
}

int pathfindingRandom(Position * Position)
{
    int random;
    random = rand() % 5;

    switch (random)
    {
        // stepping up
        case 0:
            if (mvinch(position->y - 1, position->x) == '.')
            {
                position->y = position->y - 1;
            }
            break;
        
        // stepping down
        case 1: 
        if (mvinch(position->y + 1, position->x) == '.')
            {
                position->y = position->y + 1;
            }
            break;
        
        // stepping left
        case 2:
        if (mvinch(position->y, position0>x - 1) == '.')
            {
                position->x = position->x - 1;
            }
            break;

        // stepping right
        case 3: 
        if (mvinch(position->y, position0>x + 1) == '.')
            {
                position->x = position->x + 1;
            }
            break;

        // do nothing
        case 4: 
            break;

    }
}

pathfindingSeek(Position * start, Position * destination)
{
    // Establishing leftward movement
    if ((abs((start->x - 1) - destination->x) < abs(start->x - destination->x)) && (mvinch(start->y, start->x - 1) == '.'))
    {
       
        start->x = start->x - 1;

    // Establishing rightward movement
    } else if ((abs((start->x + 1) - destination->x) < abs(start->x - destination->x)) && (mvinch(start->y, start->x + 1) == '.'))
    {

        start->x = start->x + 1;
    
    // Establishing downward movement
    } else if ((abs((start->y + 1) - destination->y) < abs(start->y - destination->y)) && (mvinch(start->y + 1, start->x == '.')))
    {
    
        start->y = start->y + 1;
    
    // Establishing upward movement
    } else if ((abs((start->y - 1) - destination->y) < abs(start->y - destination->y)) && (mvinch(start->y - 1, start->x == '.')))
    {
        start->y = start->y - 1;
    } else 
    {
        // do nothing
    }
    return 1;
}