/*
#include "DxLib.h"
#include "main.h"
#include "Enemys.h"

#include <vector>
#include <list>


int ObjectSize = 128;

int ScreenW = 720;
int ScreenH = 1280;

std::list<Enemys*> Enes;


struct Rect{
    int x;
    int y;
    int w;
    int h;
};

struct UILayout{
    Rect topLeft;
    Rect topRight;
    Rect BottomLeft;
    Rect BottomRight;
    Rect center;
};


UILayout CreateLayout(int ScreenW,int ScreenH){
    const int panelW = 180;
    const int panelH = 90;

    const int centerW = 360;
    const int centerH = 160;

    const int margin = 20;

    UILayout layout;

    layout.topLeft = {
            margin,
            margin,
            panelW,
            panelH,
    };
    layout.topRight = {
            ScreenW - panelW - margin,
            margin,
            panelW,
            panelH,
    };
    layout.BottomLeft = {
            ScreenW - panelW - margin,
            margin,
            panelW,
            panelH,
    };
    layout.BottomRight = {
            ScreenW - panelW - margin,
            ScreenH - panelH - margin,
            panelW,
            panelH,
    };
    layout.center= {
            ScreenW / 2 - centerW / 2,
            ScreenH / 2 - centerH / 2,
            centerW,
            centerH,
    };

    return layout;
}

void DrawUIRect(const Rect& rect,const char* label,int color){
    DrawBox(rect.x,
            rect.y,
            rect.x + rect.w,
            rect.y + rect.h,
            color,
            TRUE
            );

    DrawBox(rect.x,
            rect.y,
            rect.x + rect.w,
            rect.y + rect.h,
            GetColor(255,255,255),
            FALSE
            );
    DrawString(rect.x + 10,
               rect.y + 10,
               label,
               GetColor(255,255,255)
               );

}

void DrawUILayout(const UILayout& layout){
    DrawUIRect(layout.topLeft,"TopLeft",GetColor(80,120,200));
    DrawUIRect(layout.topRight,"TopRight",GetColor(80,160,120));
    DrawUIRect(layout.BottomLeft,"BottomLeft",GetColor(180,120,80));
    DrawUIRect(layout.BottomRight,"BottomRight",GetColor(180,80,120));
    DrawUIRect(layout.center,"Center",GetColor(180,80,120));
}


void PlayerObject(VECTOR PosP){

    DrawBox(PosP.x - ObjectSize / 2,PosP.y + - ObjectSize / 2,PosP.x + ObjectSize/2,PosP.y +ObjectSize/2, GetColor(0,255,0),true);
}

VECTOR EPos;


VECTOR EPos1 = VGet(ScreenW/4,-ObjectSize,0);
VECTOR EPos2 = VGet(ScreenW/2,-ObjectSize,0);
VECTOR EPos3 = VGet((ScreenW * 3)/4,-ObjectSize,0);

int SpawnTime = 120;
int SpawnCount = 0;

void EnemySpawn(){

    SpawnCount++;
    if(SpawnCount >= SpawnTime) {

        Enemys* ene;
        ene = new Enemys();
        SpawnCount = 0;

        int tmp = GetRand(2);
        int EposX = SRand(tmp);

        switch (EposX) {
            case 0:
                ene->Pos = EPos1;
                break;
            case 1:
                ene->Pos = EPos2;
                break;
            case 2:
                ene->Pos = EPos3;

        }

        Enes.push_back(ene);

        for(int i = 0;i < Enes.size();i++){
          //  Enes[i]->pos.y+= 60;
          //  DrawBox(Enes[i]->Pos.x - ObjectSize / 2, Enes[i]->Pos.y + -ObjectSize / 2, Enes[i]->Pos.x + ObjectSize / 2,
             //   Enes[i]->Pos.y + ObjectSize / 2, GetColor(255, 0, 0), true);
    }}
}

int android_main()
{


    SetGraphMode(720,1280,32);

    if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
    {
        return -1 ;			// エラーが起きたら直ちに終了
    }

    SetDrawScreen(DX_SCREEN_BACK);

    int PPosY = 1200;


    VECTOR PPos1 = VGet(ScreenW/4,PPosY,0);
    VECTOR PPos2 = VGet(ScreenW/2,PPosY,0);
    VECTOR PPos3 = VGet((ScreenW * 3)/4,PPosY,0);

    int touchPX = 0;
    int touchPY = 0;



    while(ProcessMessage() == 0) {
        ClearDrawScreen();

        GetTouchInput(0, &touchPX, &touchPY) ;

        if(touchPX <= ScreenW/3)
        PlayerObject(PPos1);
        else if(touchPX <= (ScreenW * 2) / 3)
            PlayerObject(PPos2);
        else PlayerObject(PPos3);


        EnemySpawn();


        ScreenFlip();

    }


    DxLib_End() ;				// ＤＸライブラリ使用の終了処理

    return 0 ;					// ソフトの終了
}


*/