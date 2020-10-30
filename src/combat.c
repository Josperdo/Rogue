#include "rogue.h"

int combat(Player * player, Monster * monster, int order)
{
    // player attacks monster
    if (order == 1)
    {
        monster->health -= player->attack;
        if (monster->health > 0)
        {
            player->health -= monster->attack;
        }
        else
        {
            killMonster(monster);
        }
        
    }
    // monster attacks player
    else
    {
        player->attack -= monster->attack;
        if (player->health > 0)
        {
            monster->health -= player->attack;
        }
    }
    
    return 1;
}