#include "DxLib.h"

#ifndef SMARTPHONE2026_2_ENEMYS_H
#define SMARTPHONE2026_2_ENEMYS_H


class Enemys{
private:
    VECTOR myPos = VGet(0,0,0);
public:
    Enemys(VECTOR pos){
        myPos = pos;
    };
    ~Enemys();
    void EnemyMove();
};


#endif //SMARTPHONE2026_2_ENEMYS_H
