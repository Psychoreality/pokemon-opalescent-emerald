#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mycelium Might ignores opposing abilities")
{
    GIVEN {
        PLAYER(SPECIES_TOEDSCOOL) { Speed(100); Ability(ABILITY_MYCELIUM_MIGHT); }
        OPPONENT(SPECIES_BELDUM) { Speed(1); Ability(ABILITY_CLEAR_BODY);}
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SCREECH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, player);
        NOT ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
    }
}

