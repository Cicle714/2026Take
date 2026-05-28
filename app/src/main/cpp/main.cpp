
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

VECTOR PlayerPos = VGet(ScreenW/2,1200,0);

int PlayerColor = GetColor(0,0,255);;
int ColorRed = GetColor(255,0,0);
int ColorGreen = GetColor(0,255,0);
int ColorBlue = GetColor(0,0,255);

bool ScreenTouch = false;
bool PlayerTouch = false;

void PlayerObject(VECTOR PosP){

    int touchPX = 0;
    int touchPY = 0;

    VECTOR MoveForce;
    float MaxForce = 50;

    GetTouchInput(0, &touchPX, &touchPY);
    if(touchPY != 0 || touchPX != 0){
        if(PosP.x - ObjectSize / 2 < touchPX && PosP.x + ObjectSize/2 > touchPX &&
              PosP.y - ObjectSize / 2 < touchPY && PosP.y + ObjectSize / 2 > touchPY && !ScreenTouch){
        PlayerColor = ColorGreen;
        PlayerTouch = true;
        }
        if(PlayerTouch){
            MoveForce =VGet( PosP.x-touchPX, PosP.y - touchPY,0);
        }

        ScreenTouch = true;
    }else{
        ScreenTouch = false;
        PlayerTouch = false;

        if(MoveForce.x >= MaxForce){
            MoveForce.x = MaxForce;
        }
        if(MoveForce.y >= MaxForce){
            MoveForce.y = MaxForce;
        }

        MoveForce.x *= 0.95f;
        MoveForce.y *= 0.95f;
        PlayerColor = ColorRed;

    }
    if(!PlayerTouch)
    PlayerPos = VGet(MoveForce.x + PlayerPos.x,MoveForce.y + PlayerPos.y,0);
    if(PlayerPos.x <= 0 || PlayerPos.x >= ScreenW){
        if(PlayerPos.x <= 0)
            PlayerPos.x = 0;
        else
            PlayerPos.x = ScreenW;
        MoveForce.x = -MoveForce.x;
    }if(PlayerPos.y <= 0 || PlayerPos.y >= ScreenH){
        if(PlayerPos.y <= 0)
            PlayerPos.y = 0;
        else
            PlayerPos.y = ScreenH;
        MoveForce.y = -MoveForce.y;
    }

    DrawBox(PosP.x - ObjectSize / 2,PosP.y - ObjectSize / 2,PosP.x + ObjectSize/2,PosP.y +ObjectSize/2, PlayerColor,true);
}



int SpawnTime = 120;
int SpawnCount = 0;



int android_main()
{


    SetGraphMode(720,1280,32);

    if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
    {
        return -1 ;			// エラーが起きたら直ちに終了
    }

    SetDrawScreen(DX_SCREEN_BACK);

    int PPosY = 1200;






    while(ProcessMessage() == 0) {
        ClearDrawScreen();


        PlayerObject(PlayerPos);


        ScreenFlip();

    }


    DxLib_End() ;				// ＤＸライブラリ使用の終了処理

    return 0 ;					// ソフトの終了
}

