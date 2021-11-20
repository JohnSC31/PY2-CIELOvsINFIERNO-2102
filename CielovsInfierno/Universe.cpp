#include "structs.h"



Universe::Universe(){
    world = new TheWorld(goodActions, sinsActions);
    hell = new Hell(world->humanList, demonsName, sinsActions, goodActions);
}
