#include "Enemys.h"




void Enemys::EnemyMove(){
    myPos.y += 5;
    DrawBox(myPos.x - 64,myPos.y - 64,myPos.x + 64,myPos.y + 64,GetColor(255,255,255),TRUE);

}