

#include "Engine.h"
#include "Color_Buffer.cpp"


//ѕеременные игры

const int Global_Scale = 3;                     // маштаб игры по сравнению с оригиналом



const int Reck_Width = 15 * Global_Scale;       // ширина игрового "кирпича"
const int Rect_Height = 7 * Global_Scale;       // висота игрового "кирпича"
const int Rect_Distance = 1 * Global_Scale;     // дистанци€ между игровими "кирпичами"

const int Level_Offset_X = 8;                   // отступ пол€ игры от начала координаты по X
const int Level_Offset_Y = 6;                   // отступ пол€ игры от начала координаты по Y

const int Ellipse_Distance = 21 * 3;

HPEN Rect_Pen_Blue, Rect_Pen_Violet, Rect_Pen_Pink, Rect_Pen_Violet_Midl, Rect_Pen_Violet_Dark;                                              // карандаш который используетс€ дл€ отрисовки "кирпичей"
HBRUSH Rect_Bbrush_Blue, Rect_Bbrush_Violet, Rect_Bbrush_Pink, Rect_Bbrush_Violet_Midl, Rect_Bbrush_Violet_Dark;                             // кисть котора€ используетс€ дл€ отрисовки "кирпичей"

char Level_01[14][12] =
{
    1, 0, 0, 1, 0, 0 ,0, 0, 1 ,0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4 ,4, 4, 4 ,4, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    0, 0, 0, 0, 0, 0 ,0, 0, 0 ,0, 0, 0,
    0, 0, 0, 0, 0, 0 ,0, 0, 0 ,0, 0, 0,
    0, 0, 0, 0, 0, 0 ,0, 0, 0 ,0, 0, 0,
    0, 0, 0, 0, 0, 0 ,0, 0, 0 ,0, 0, 0,
    0, 0, 0, 0, 0, 0 ,0, 0, 0 ,0, 0, 0,
    0, 0, 0, 0, 0, 0 ,0, 0, 0 ,0, 0, 0
};


//----------------------------------------------------------------------------------------------------
// 
//  ‘”Ќ ÷»я: Init()
// 
//  ÷≈Ћ№: »нициализаци€ объектов дл€ рисовани€
// 
// 
//----------------------------------------------------------------------------------------------------
void Init()
{
    Rect_Pen_Blue = CreatePen(PS_SOLID, 1, RGB(180, 218, 252));
    Rect_Pen_Violet = CreatePen(PS_SOLID, 1, RGB(187, 187, 249));
    Rect_Pen_Pink = CreatePen(PS_SOLID, 1, RGB(204, 164, 253));
    Rect_Pen_Violet_Midl = CreatePen(PS_SOLID, 1, RGB(173, 140, 252));
    Rect_Pen_Violet_Dark = CreatePen(PS_SOLID, 1, RGB(127, 81, 253));

    Rect_Bbrush_Blue = CreateSolidBrush(RGB(180, 218, 252));
    Rect_Bbrush_Violet = CreateSolidBrush(RGB(187, 187, 249));
    Rect_Bbrush_Pink = CreateSolidBrush(RGB(204, 164, 253));
    Rect_Bbrush_Violet_Midl = CreateSolidBrush(RGB(173, 140, 252));
    Rect_Bbrush_Violet_Dark = CreateSolidBrush(RGB(127, 81, 253));
}
//----------------------------------------------------------------------------------------------------
// 
//  ‘”Ќ ÷»я: Draw_Rectangle(HDC hdc, int Side_Style, int Side_Width, int Rect_Color, int x_position, int y_position, int Reck_Width, int Rect_Height)
// 
//  ÷≈Ћ№: ќтрисовка игровой платформы.
// 
//  »—ѕќЋ№«”ё“—я ѕ≈–≈ћ≈ЌЌџ… »« Color_Buffer.cpp
// 
//----------------------------------------------------------------------------------------------------
void Draw_Platform(HDC hdc, int Platform_X, int Platform_Y)
{

    SelectObject(hdc, Rect_Pen_Pink);
    SelectObject(hdc, Rect_Bbrush_Pink);

    Ellipse(hdc, Platform_X, Platform_Y, Platform_X + 7 * Global_Scale, Platform_Y + 7 * Global_Scale);
    Ellipse(hdc, Platform_X + Ellipse_Distance,  Platform_Y, Platform_X + Ellipse_Distance + 7 * Global_Scale, Platform_Y + 7 * Global_Scale);

    SelectObject(hdc, Rect_Pen_Blue);
    SelectObject(hdc, Rect_Bbrush_Blue);

    RoundRect(hdc, Platform_X + 10, Platform_Y + 3, Platform_X + Ellipse_Distance + 11, Platform_Y + 18, 15, 15);

}
//----------------------------------------------------------------------------------------------------
// 
//  ‘”Ќ ÷»я: Draw_Rectangle(HDC hdc, int Side_Style, int Side_Width, int Rect_Color, int x_position, int y_position, int Reck_Width, int Rect_Height)
// 
//  ÷≈Ћ№: ќтрисовка пр€моугольников.
// 
//  »—ѕќЋ№«”ё“—я ѕ≈–≈ћ≈ЌЌџ… »« Color_Buffer.cpp
// 
//----------------------------------------------------------------------------------------------------
void Draw_Rectangle(HDC hdc, int Rect_Color, int x_position, int y_position, int Reck_Width, int Rect_Height)
{

    switch (Rect_Color)
    {
    case CLR_BLUE:
        SelectObject(hdc, Rect_Pen_Blue);
        SelectObject(hdc, Rect_Bbrush_Blue);
        break;
    case CLR_VIOLET:
        SelectObject(hdc, Rect_Pen_Violet);
        SelectObject(hdc, Rect_Bbrush_Violet);
        break;
    case CLR_PINK:
        SelectObject(hdc, Rect_Pen_Pink);
        SelectObject(hdc, Rect_Bbrush_Pink);
        break;
    case CLR_VIOLET_MIDL:
        SelectObject(hdc, Rect_Pen_Violet_Midl);
        SelectObject(hdc, Rect_Bbrush_Violet_Midl);
        break;
    case CLR_vIOLET_DARK:
        SelectObject(hdc, Rect_Pen_Violet_Dark);
        SelectObject(hdc, Rect_Bbrush_Violet_Dark);
        break;
    }


    RoundRect(hdc, x_position, y_position, x_position + Reck_Width, y_position + Rect_Height, 7, 7);
}
//----------------------------------------------------------------------------------------------------
// 
//  ‘”Ќ ÷»я: Draw_Rectangle_Field(HDC hdc, int Many_Rect, int Many_Rect_Line, int Initial_X, int Initial_Y) 
// 
//  ÷≈Ћ№: ќтрисовка пол€ "кирпичей"
// 
//----------------------------------------------------------------------------------------------------
void Draw_Rectangle_Field(HDC hdc, int Many_Rect, int Many_Rect_Line, int Initial_X, int Initial_Y)
{

    char Which_Cell;

    for (int i = 0; i < Many_Rect_Line; i++)
    {
        for (int j = 0; j < Many_Rect; j++)
        {

            Which_Cell = Level_01[i][j];

            if (Which_Cell == 0)
            {
                Initial_X = Initial_X + Reck_Width + Rect_Distance;
            }
            else
            {
                Draw_Rectangle(hdc, Which_Cell, Initial_X, Initial_Y, Reck_Width, Rect_Height);

                Initial_X = Initial_X + Reck_Width + Rect_Distance;
            }
        }
        Initial_X = Level_Offset_X;
        Initial_Y = Initial_Y + Rect_Height + Rect_Distance;
    }
}
//----------------------------------------------------------------------------------------------------
// 
//  ‘”Ќ ÷»я: Draw_Frame(HDC hdc) 
// 
//  ÷≈Ћ№: ѕрорисовка елементов клиенской области с используванием HDC.
// 
//----------------------------------------------------------------------------------------------------
void Draw_Frame(HDC hdc)
{
    //573 / 2 - 42 - 42
    //35 + 21 
    Draw_Platform(hdc, 573 / 2 - 42 - 42, Wind_Height - 35 - 21);
    Draw_Rectangle_Field(hdc, 12, 15, Level_Offset_X, Level_Offset_Y);
}
//----------------------------------------------------------------------------------------------------