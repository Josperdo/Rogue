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

    return  newMonster;
}


int setStartingPosition(Monster * monster, Room * room)
{
    char buffer[8];

    monster->position.x = (rand() % room->width - 2) + room->position.x + 1;
    monster->position.y = (rand() % room->height - 2) + room->position.y + 1;

    sprintf(buffer, "%c", monster->symbol);

    mvprintw(monster->position.y, monster->position.x, buffer);
}