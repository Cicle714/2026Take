#include "DxLib.h"

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

int android_main()
{

    SetGraphMode(720,1280,32);

    if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
    {
        return -1 ;			// エラーが起きたら直ちに終了
    }

    SetDrawScreen(DX_SCREEN_BACK);

    while(ProcessMessage() == 0) {
        ClearDrawScreen();
        int ScreenW = 720;
        int ScreenH = 1280;


        UILayout layout = CreateLayout(ScreenW,ScreenH);
        DrawUILayout(layout);

        DrawString(20, 1240, "Android UI Layout Sample", GetColor(0, 255, 255), TRUE);

        ScreenFlip();
    }


    DxLib_End() ;				// ＤＸライブラリ使用の終了処理

    return 0 ;					// ソフトの終了
}