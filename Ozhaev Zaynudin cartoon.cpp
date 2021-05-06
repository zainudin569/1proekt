//{===========================================================================
//! @mainpage
//!
//!   "Мультик не о чём!"
//!
//! @par Ссылка на github.com
//!      https://github.com/zainudin569/1proekt.git
//!
//! @author     Ожаев Зайнудин
//! @date       Аксай 2021 год.
//!
//!  @par     Функции:
//!                         - @ref DrawMir()
//!                           @image html im1.jpg
//!                           @image html im2.jpg
//!                         - @ref DrawZoomHouse1()
//!                           @image html im3.jpg
//! @note Любите! И цените Счастье! Оно рождается в Семье! Что может быть Семьи дороже на этой сказочной земле.
//}===========================================================================
#include "TXLib.h"
#include "SunLib.h"

void DrawMir        ();
void DrawZoomHouse1 ();
void DraTrainFare   (   int t);
void DrawTrain      (   int x,     int y);
void DrawHouse2     (   int x,     int y);
void DrawHouse3     (   int x,     int y);
void DrawTrain      (   int x,     int y, double sizeX, double sizeY);
void DrawTree1      (   int x,     int y, double sizeX, double sizeY, COLORREF TreeColor);
void DrawTree2      (   int x,     int y, double sizeX, double sizeY, COLORREF TreeColor);
void DrawGirl       (   int x,     int y, double sizeX, double sizeY, COLORREF GirlColor,
                                       double eyes , double smayl);
void DrawMan        (   int x,     int y, double sizeX, double sizeY, COLORREF ManColor,
                                       double eyes , double smayl);
void DrawHouse1     (double x,  double y, double sizeX, double sizeY, COLORREF HoleColor);
void DrawBackground (COLORREF SkyColor);
int main()

    {
    txCreateWindow (480, 400);
    txBegin();

    DrawMir();
    DrawZoomHouse1();

    txEnd();

    return 0;
    }
//{===========================================================================
//! @par Рисуется проезд поезда
//!
//!
//}===========================================================================
void DraTrainFare(int t)
    {
    if (t<=10)
        {
        DrawTrain  (480 - t*30, 370, .45, .45);
        }
    if (t>10 and t<=20)
        {
        DrawTrain  (180, 370, .45, .45);
        DrawGirl   (220 + (t-10)*5, 220 + (t-10)*5 + ((t%2)*5), 0.7, 0.7, RGB (  255, 130, 1), 1,  3);
        DrawMan    (250 + (t-10)*5, 220 + (t-10)*5 + ((t%2)*2), 0.7, 0.7, RGB (135, 219, 255), 1,  3);
         }
    if (t>20 and t<=70)
        {
        DrawTrain  (480 - (t-10)*30, 370, .45, .45);
        }
    if (t>70 and t<=80)
        {
        DrawTrain  ((t-70)*40, 370, -.45, .45);
        }
    if (t>80 and t<=90)
        {
        DrawTrain  (400, 370, -.45, .45);
        DrawGirl   (270 - (t-80)*5, 270 - (t-80)*5 + ((t%2)*5), 0.8, 0.8, RGB (  255, 130, 1), 0.8,  -1);
        DrawMan    (300 - (t-80)*5, 270 - (t-80)*5 + ((t%2)*2), 0.8, 0.8, RGB (135, 219, 255), 0.8,  -1);
        }
    if (t>90 and t<=100)
        {
        DrawTrain  ((t-80)*40, 370, -.45, .45);
        }
    }

void DrawMir()
    {
    int t = 0;
    while ( t <=100 )
        {
        txClear ();

        DrawBackground (RGB (0, 180 - pow(t-50,2)/25,
                                180 - pow(t-50,2)/25));
        DrawSun    (  7 + 5*t              ,
                     75 + pow(t-50,2)/100*3,
                    1.2 - pow(t-50,2)/2000 ,
                    1.2 - pow(t-50,2)/2000 ,
                    RGB (255 - pow(t-50,2)/50, 255 - pow(t-50,2)/50, 0));
        DrawHouse2 (290,  60);
        DrawHouse1 (320, 260, 1, 1, RGB (0, 180 - pow(t-50,2)/25, 180 - pow(t-50,2)/25));
        DrawHouse3 (355, 120);
        DrawTree2  (100, 285, 1, 1, RGB ( 50, 150,   0));
        DrawTree1  (  3, 163, 1, 1, RGB ( 50, 200,   0));
        DraTrainFare(t);
        t ++;
        txSleep (120);
        }

    }

void DrawGirl  (int x, int y, double sizeX, double sizeY, COLORREF GirlColor,
                              double eyes,  double smayl)

    {
    txSetFillColor (RGB (240, 234, 182));
    txEllipse     (x, y, ROUND( x + 30*sizeX ), ROUND( y + 30*sizeY ));
    txSetFillColor (GirlColor);
    POINT Body [3] =  {{ ROUND( x + 15*sizeX ), ROUND( y + 30*sizeY )},
                       { ROUND( x +  5*sizeX ), ROUND( y + 75*sizeY )},
                       { ROUND( x + 25*sizeX ), ROUND( y + 75*sizeY )}};
    txPolygon (Body, 3);
    txSetColor     (RGB (255, 128, 0), 1);
    txSetFillColor (RGB (255,   0, 0));
    POINT Mouth [3] = {{ ROUND( x +  7*sizeX ), ROUND( y + 20*sizeY         )},
                       { ROUND( x + 15*sizeX ), ROUND( y + 20*sizeY + smayl )},
                       { ROUND( x + 23*sizeX ), ROUND( y + 20*sizeY         )}};
    txPolygon  (Mouth, 3);
    txSetColor     (RGB (200, 200, 0), 1);
    txSetFillColor (RGB (200, 200, 0));
    txEllipse ( ROUND( x +  7*sizeX      ), ROUND( y + 7*sizeY       ),
                ROUND( x + 13*sizeX*eyes ), ROUND( y + 13*sizeY*eyes ));
    txEllipse ( ROUND( x + 17*sizeX      ), ROUND( y + 7*sizeY       ),
                ROUND( x + 23*sizeX*eyes ), ROUND( y + 13*sizeY*eyes ));
    }

void DrawMan  (int x, int y, double sizeX, double sizeY, COLORREF ManColor,
                             double eyes,  double smayl)

    {
    txSetFillColor (RGB (240, 234, 182));
    txRectangle (x, y, ROUND( x + 30*sizeX ), ROUND( y + 30*sizeY ));
    txSetFillColor (ManColor);
    POINT Body [3] =  {{ ROUND( x +  1*sizeX ), ROUND( y + 30*sizeY )},
                      { ROUND( x + 29*sizeX ), ROUND( y + 30*sizeY )},
                      { ROUND( x + 15*sizeX ), ROUND( y + 75*sizeY )}};
    txPolygon (Body, 3);
    txSetColor     (RGB (255, 128, 0), 1);
    txSetFillColor (RGB (255,   0, 0));
    POINT Mouth [3] = {{ ROUND( x +  7*sizeX ), ROUND( y + 20*sizeY         )},
                      { ROUND( x + 15*sizeX ), ROUND( y + 20*sizeY + smayl )},
                      { ROUND( x + 23*sizeX ), ROUND( y + 20*sizeY         )}};
    txPolygon  (Mouth, 3);
    txSetColor     (RGB (200, 200, 0), 1);
    txSetFillColor (RGB (200, 200, 0));
    txEllipse ( ROUND( x +  7*sizeX      ), ROUND( y + 7*sizeY       ),
                ROUND( x + 13*sizeX*eyes ), ROUND( y + 13*sizeY*eyes ));
    txEllipse ( ROUND( x + 17*sizeX      ), ROUND( y + 7*sizeY       ),
                ROUND( x + 23*sizeX*eyes ), ROUND( y + 13*sizeY*eyes ));
    }

void DrawTree1 (int x, int y, double sizeX, double sizeY, COLORREF TreeColor)

    {
    txSetFillColor (TreeColor);
    POINT Tree [4] = {{ ROUND( x + 35*sizeX ), ROUND( y +  92*sizeY )},
                      { ROUND( x + 35*sizeX ), ROUND( y + 117*sizeY )},
                      { ROUND( x + 57*sizeX ), ROUND( y + 117*sizeY )},
                      { ROUND( x + 57*sizeX ), ROUND( y +  92*sizeY )}};
    txPolygon (Tree, 4);
    txEllipse ( x, y, ROUND( x + 94*sizeX ),
                      ROUND( y + 94*sizeY ));
    }

void DrawTree2 (int x, int y, double sizeX, double sizeY, COLORREF TreeColor)

    {
    txSetFillColor (TreeColor);
    POINT Tree2 [7] = {{        x              ,        y             },
                       { ROUND( x +  37*sizeX ),        y             },
                       { ROUND( x +  37*sizeX ), ROUND( y + 30*sizeY )},
                       { ROUND( x +  63*sizeX ), ROUND( y + 30*sizeY )},
                       { ROUND( x +  63*sizeX ),        y             },
                       { ROUND( x + 100*sizeX ),        y             },
                       { ROUND( x +  50*sizeX ), ROUND( y - 88*sizeY )}};
    txPolygon (Tree2, 7);
    }

//{===========================================================================
//! @par Рисуется небо и земля
//!
//! @param SkyColor   - цвет неба которая зависит от положения солнца
//}===========================================================================
void DrawBackground (COLORREF SkyColor)

    {
    txSetColor     (RGB (255, 255, 255), 1);
    txSetFillColor (RGB (180, 180, 180));
    txRectangle (0, 150, 480, 400);
    txSetFillColor (SkyColor);
    txRectangle (0, 0, 480, 150);
    }

void DrawHouse1 (double x, double y, double sizeX, double sizeY, COLORREF HoleColor)

    {
    txSetFillColor (RGB (255, 255, 255));
    POINT stena [4] =  {{ ROUND( x               ), ROUND( y               )},
                        { ROUND( x - 120 * sizeX ), ROUND( y               )},
                        { ROUND( x - 120 * sizeX ), ROUND( y - 140 * sizeY )},
                        { ROUND( x               ), ROUND( y - 140 * sizeY )}};
    txPolygon (stena, 4);
    for (int corX = ( ROUND( x - 110 * sizeX )); corX <= ( ROUND( x - 30 * sizeX )); corX += ROUND( 40 * sizeX ))
        {
        txSetFillColor (RGB (0, 0, 0));
        POINT Window [4] = {{        corX               , ROUND( y - 120 * sizeY )},
                            {        corX               , ROUND( y - 100 * sizeY )},
                            { ROUND( corX + 20 * sizeX ), ROUND( y - 100 * sizeY )},
                            { ROUND( corX + 20 * sizeX ), ROUND( y - 120 * sizeY )}};
        txPolygon (Window, 4);
        }

    txSetFillColor (RGB (0, 0, 0));
    POINT Door [4] =       {{ ROUND( x - 95 * sizeX ), ROUND( y              )},
                            { ROUND( x - 95 * sizeX ), ROUND( y - 50 * sizeY )},
                            { ROUND( x - 50 * sizeX ), ROUND( y - 50 * sizeY )},
                            { ROUND( x - 50 * sizeX ), ROUND( y              )}};
    txPolygon (Door, 4);

    txSetFillColor (RGB (230, 230, 230));
    POINT Attic [4] =      {{ ROUND( x - 65 * sizeX ), ROUND( y - 140 * sizeY )},
                            { ROUND( x - 65 * sizeX ), ROUND( y - 180 * sizeY )},
                            { ROUND( x - 30 * sizeX ), ROUND( y - 180 * sizeY )},
                            { ROUND( x - 30 * sizeX ), ROUND( y - 140 * sizeY )}};
    txPolygon (Attic, 4);

    txSetFillColor (HoleColor);
    txEllipse ( ROUND( x - 37 * sizeX ), ROUND( y - 150 * sizeY ),
                ROUND( x - 57 * sizeX ), ROUND( y - 170 * sizeY ));
    }

void DrawHouse2 (int x, int y)

    {

    txSetFillColor (RGB (255, 0, 0));
    POINT Roof [3] =    {{ x      , y      },
                         { x +  60, y - 30 },
                         { x + 130, y      }};
    txPolygon (Roof, 3);

    txSetFillColor (RGB (150, 0, 0));
    POINT stena [4] =   {{ x +  20, y       },
                         { x +  20, y + 117 },
                         { x + 110, y + 117 },
                         { x + 110, y       }};
    txPolygon (stena, 4);

    txSetFillColor (RGB (0, 0, 0));
    POINT Window1 [4] = {{ x + 30, y + 40 },
                         { x + 30, y + 20 },
                         { x + 55, y + 20 },
                         { x + 55, y + 40 }};
    txPolygon (Window1, 4);

    POINT Window2 [4] = {{ x +  90, y + 25 },
                         { x +  90, y + 10 },
                         { x + 105, y + 10 },
                         { x + 105, y + 25 }};
    txPolygon (Window2, 4);

    POINT Window3 [4] = {{ x +  90, y + 55 },
                         { x +  90, y + 40 },
                         { x + 105, y + 40 },
                         { x + 105, y + 55 }};
    txPolygon (Window3, 4);

    }

void DrawHouse3(int x, int y)

    {

    txSetFillColor (RGB (0, 100, 0));
    POINT Roof [3] =  {{ x     , y      },
                       { x - 60, y + 70 },
                       { x + 60, y + 70 }};
    txPolygon (Roof, 3);

    txSetFillColor (RGB (50, 100, 0));
    POINT stena [4] = {{ x + 40, y +  70 },
                       { x + 40, y + 170 },
                       { x - 45, y + 170 },
                       { x - 45, y +  70 }};
    txPolygon (stena, 4);

    txSetFillColor (RGB (0, 0, 0));
    POINT Door [4] =  {{ x - 35, y + 170 },
                       { x - 35, y + 135 },
                       { x     , y + 135 },
                       { x     , y + 170 }};
    txPolygon (Door, 4);

    txCircle ( x + 15, y + 100, 15 );

    }

void DrawTrain (int x, int y, double sizeX, double sizeY)
    {
    txSetColor  (RGB (100, 255, 255), 1);
    txSetFillColor (RGB (50, 50, 200));
    txRectangle (       x              ,        y              ,
                 ROUND( x +  70*sizeX ), ROUND( y -  80*sizeY ));
    txRectangle (ROUND( x +  70*sizeX ),        y              ,
                 ROUND( x + 160*sizeX ), ROUND( y - 100*sizeY ));
    txRectangle (ROUND( x +  80*sizeX ), ROUND( y - 100*sizeY ),
                 ROUND( x + 150*sizeX ), ROUND( y - 160*sizeY ));
    txRectangle (ROUND( x + 160*sizeX ), ROUND( y -  30*sizeY ),
                 ROUND( x + 180*sizeX ), ROUND( y -  50*sizeY ));

    POINT Spout [3] =      {{        x             ,        y              },
                            { ROUND( x - 50*sizeX ),        y              },
                            {        x             , ROUND( y - 50*sizeY ) }};
    txPolygon (Spout, 3);
    txSetFillColor (RGB (150, 200, 150));
    txRectangle (ROUND( x +  90*sizeX ), ROUND( y - 110*sizeY ),
                 ROUND( x + 140*sizeX ), ROUND( y - 150*sizeY ));
    txSetFillColor (RGB (255, 255, 0));
    txEllipse   (ROUND( x +   3*sizeX ), ROUND( y -  33*sizeY ),
                 ROUND( x +  66*sizeX ), ROUND( y +  33*sizeY ));
    txEllipse   (ROUND( x +  82*sizeX ), ROUND( y -  33*sizeY ),
                 ROUND( x + 148*sizeX ), ROUND( y +  33*sizeY ));
    int corX = 0;
    for (int temp = 1; temp <= 2; temp += 1 )
        {
        txSetFillColor (RGB (255, 0, 0));
        txRectangle (ROUND(( x + 180*sizeX) + corX ),        y              ,
                     ROUND(( x + 270*sizeX) + corX ), ROUND( y - 100*sizeY ));
        txRectangle (ROUND(( x + 270*sizeX) + corX ),        y              ,
                     ROUND(( x + 360*sizeX) + corX ), ROUND( y - 100*sizeY ));
        txRectangle (ROUND(( x + 360*sizeX) + corX ), ROUND( y -  30*sizeY ),
                     ROUND(( x + 380*sizeX) + corX ), ROUND( y -  50*sizeY ));
        txSetFillColor (RGB (255, 255, 0));
        txEllipse   (ROUND(( x + 192*sizeX) + corX ), ROUND( y -  33*sizeY ),
                     ROUND(( x + 258*sizeX) + corX ), ROUND( y +  33*sizeY ));
        txEllipse   (ROUND(( x + 282*sizeX) + corX ), ROUND( y -  33*sizeY ),
                     ROUND(( x + 348*sizeX) + corX ), ROUND( y +  33*sizeY ));
        corX = ROUND( corX + 200*sizeX );
        }
    }

void DrawZoomHouse1()
    {
    int n = 0;
    int t = 0;
    while ( n <= 5 )
        {
        while ( t <=120 )
            {
            if (t <=100 )
                {
                txClear ();
                DrawBackground (RGB (0, 80, 80));
                DrawHouse1 (320 + t*14.2, 260 + t*22.5 , 1 + t*0.24, 1 + t*0.2, RGB (0, 80, 80));
                double x = ROUND( 260 - t*2.6 );
                double y = 163 - t*1.7;
                double sizeX = 0.006*t;
                double sizeY = 0.0037*t;

                txSetColor     (RGB (255, 255, 255), 1);
                txSetFillColor (RGB (240, 234, 182));
                txEllipse   (ROUND( x + 110*sizeX ), ROUND( y +  80*sizeY ),
                             ROUND( x + 320*sizeX ), ROUND( y + 290*sizeY ));

                txSetFillColor (RGB (0, 0, 0));
                txRectangle (ROUND( x + 170*sizeX ), ROUND( y + 180*sizeY ),
                             ROUND( x + 230*sizeX ), ROUND( y + 200*sizeY ));
                POINT EyeGirl [4] =   {{ ROUND( x + 260*sizeX ), ROUND( y + 205*sizeY )},
                                       { ROUND( x + 270*sizeX ), ROUND( y + 190*sizeY )},
                                       { ROUND( x + 300*sizeX ), ROUND( y + 215*sizeY )},
                                       { ROUND( x + 290*sizeX ), ROUND( y + 230*sizeY )}};
                txPolygon (EyeGirl, 4);

                txSetFillColor (RGB (239, 23, 2));
                POINT MouthGirl [3] = {{ ROUND( x + 190*sizeX ), ROUND( y + 240*sizeY )},
                                       { ROUND( x + 255*sizeX ), ROUND( y + 255*sizeY )},
                                       { ROUND( x + 220*sizeX ), ROUND( y + 270*sizeY )}};
                txPolygon (MouthGirl, 3);

                txSetFillColor (RGB (255, 130, 1));
                POINT TorsoGirl [3] = {{ ROUND( x + 170*sizeX ), ROUND( y + 280*sizeY )},
                                       { ROUND( x +  22*sizeX ), ROUND( y + 700*sizeY )},
                                       { ROUND( x + 320*sizeX ), ROUND( y + 700*sizeY )}};
                txPolygon (TorsoGirl, 3);

                txSetFillColor (RGB (255,254, 233));
                POINT ArmGirl1 [3] = {{ ROUND( x + 150*sizeX ), ROUND( y + 407*sizeY )},
                                      { ROUND( x + 202*sizeX ), ROUND( y + 375*sizeY )},
                                      { ROUND( x + 330*sizeX ), ROUND( y + 630*sizeY )}};
                txPolygon (ArmGirl1, 3);

                POINT ArmGirl2 [3] = {{ ROUND( x + 185*sizeX ), ROUND( y + 320*sizeY )},
                                      { ROUND( x + 206*sizeX ), ROUND( y + 380*sizeY )},
                                      { ROUND( x + 415*sizeX ), ROUND( y + 420*sizeY )}};
                txPolygon (ArmGirl2, 3);

                txSetFillColor (RGB (236, 237, 242));
                POINT LegGirl1 [3] = {{ ROUND( x + 115*sizeX ), ROUND( y + 710*sizeY )},
                                      { ROUND( x + 170*sizeX ), ROUND( y + 710*sizeY )},
                                      { ROUND( x + 140*sizeX ), ROUND( y + 970*sizeY )}};
                txPolygon (LegGirl1, 3);

                POINT LegGirl2 [3] = {{ ROUND( x + 195*sizeX ), ROUND( y + 710*sizeY )},
                                      { ROUND( x + 255*sizeX ), ROUND( y + 710*sizeY )},
                                      { ROUND( x + 225*sizeX ), ROUND( y + 970*sizeY )}};
                txPolygon (LegGirl2, 3);

                txSetFillColor (RGB (176, 34, 20));
                txRectangle (ROUND( x + 110*sizeX ), ROUND( y +  970*sizeY ),
                             ROUND( x + 180*sizeX ), ROUND( y + 1020*sizeY ));

                txRectangle (ROUND( x + 190*sizeX ), ROUND( y +  970*sizeY ),
                             ROUND( x + 260*sizeX ), ROUND( y + 1020*sizeY ));

            //_________________________________________

                txSetFillColor (RGB (240, 234, 182));
                txRectangle (ROUND( x + 575*sizeX ), ROUND( y +  50*sizeY ),
                             ROUND( x + 720*sizeX ), ROUND( y + 228*sizeY ));

                POINT NoseMen [3] = {{ ROUND( x + 575*sizeX ), ROUND( y + 130*sizeY )},
                                     { ROUND( x + 556*sizeX ), ROUND( y + 155*sizeY )},
                                     { ROUND( x + 575*sizeX ), ROUND( y + 158*sizeY )}};
                txPolygon (NoseMen, 3);

                txSetFillColor (RGB (0, 0, 0));
                POINT EyeMen [4] =  {{ ROUND( x + 586*sizeX ), ROUND( y + 129*sizeY )},
                                     { ROUND( x + 596*sizeX ), ROUND( y + 116*sizeY )},
                                     { ROUND( x + 646*sizeX ), ROUND( y + 148*sizeY )},
                                     { ROUND( x + 634*sizeX ), ROUND( y + 161*sizeY )}};
                txPolygon (EyeMen, 4);

                txSetFillColor (RGB (0, 138, 253));
                txRectangle (ROUND( x + 650*sizeX ), ROUND( y + 557*sizeY ),
                             ROUND( x + 696*sizeX ), ROUND( y + 723*sizeY ));
                POINT HipMen [4] =    {{ ROUND( x + 643*sizeX ), ROUND( y + 553*sizeY )},
                                       { ROUND( x + 599*sizeX ), ROUND( y + 541*sizeY )},
                                       { ROUND( x + 552*sizeX ), ROUND( y + 699*sizeY )},
                                       { ROUND( x + 598*sizeX ), ROUND( y + 712*sizeY )}};
                txPolygon (HipMen, 4);

                txSetFillColor (RGB (135, 219, 255));
                POINT TorsoMen [3] =  {{ ROUND( x + 512*sizeX ), ROUND( y + 245*sizeY )},
                                       { ROUND( x + 780*sizeX ), ROUND( y + 245*sizeY )},
                                       { ROUND( x + 640*sizeX ), ROUND( y + 590*sizeY )}};
                txPolygon (TorsoMen, 3);

                txSetFillColor (RGB (236, 237, 242));
                POINT ArmMen1 [3] =  {{ ROUND( x + 414*sizeX ), ROUND( y + 425*sizeY )},
                                      { ROUND( x + 549*sizeX ), ROUND( y + 342*sizeY )},
                                      { ROUND( x + 560*sizeX ), ROUND( y + 381*sizeY )}};
                txPolygon (ArmMen1, 3);

                POINT ArmMen2 [3] =  {{ ROUND( x + 480*sizeX ), ROUND( y + 600*sizeY )},
                                      { ROUND( x + 616*sizeX ), ROUND( y + 343*sizeY )},
                                      { ROUND( x + 667*sizeX ), ROUND( y + 377*sizeY )}};
                txPolygon (ArmMen2, 3);

                txSetFillColor (RGB (0, 138, 253));
                POINT LegMen1 [3] =  {{ ROUND( x + 542*sizeX ), ROUND( y + 715*sizeY )},
                                      { ROUND( x + 598*sizeX ), ROUND( y + 715*sizeY )},
                                      { ROUND( x + 567*sizeX ), ROUND( y + 970*sizeY )}};
                txPolygon (LegMen1, 3);

                POINT LegMen2 [3] =  {{ ROUND( x + 642*sizeX ), ROUND( y + 736*sizeY )},
                                      { ROUND( x + 698*sizeX ), ROUND( y + 729*sizeY )},
                                      { ROUND( x + 695*sizeX ), ROUND( y + 970*sizeY )}};
                txPolygon (LegMen2, 3);

                txRectangle (ROUND( x + 532*sizeX ), ROUND( y +  970*sizeY ),
                             ROUND( x + 601*sizeX ), ROUND( y + 1026*sizeY ));

                txRectangle (ROUND( x + 641*sizeX ), ROUND( y +  970*sizeY ),
                             ROUND( x + 709*sizeX ), ROUND( y + 1026*sizeY ));

            //_________________________________________

                txSetFillColor (RGB (3, 196, 152));
                POINT SleeveBoy1 [4] = {{ ROUND( x + 288*sizeX ), ROUND( y + 678*sizeY )},
                                        { ROUND( x + 334*sizeX ), ROUND( y + 650*sizeY )},
                                        { ROUND( x + 358*sizeX ), ROUND( y + 683*sizeY )},
                                        { ROUND( x + 322*sizeX ), ROUND( y + 730*sizeY )}};
                txPolygon (SleeveBoy1, 4);

                POINT SleeveBoy2 [4] = {{ ROUND( x + 465*sizeX ), ROUND( y + 646*sizeY )},
                                        { ROUND( x + 514*sizeX ), ROUND( y + 668*sizeY )},
                                        { ROUND( x + 494*sizeX ), ROUND( y + 719*sizeY )},
                                        { ROUND( x + 454*sizeX ), ROUND( y + 672*sizeY )}};
                txPolygon (SleeveBoy2, 4);

                txEllipse   (ROUND( x + 319*sizeX ), ROUND( y + 661*sizeY ),
                             ROUND( x + 502*sizeX ), ROUND( y + 841*sizeY ));

                txRectangle (ROUND( x + 333*sizeX ), ROUND( y +  962*sizeY ),
                             ROUND( x + 402*sizeX ), ROUND( y + 1015*sizeY ));

                txRectangle (ROUND( x + 415*sizeX ), ROUND( y +  967*sizeY ),
                             ROUND( x + 484*sizeX ), ROUND( y + 1022*sizeY ));

                txSetFillColor (RGB (236, 237, 242));
                POINT NoseBoy [3] = {{ ROUND( x + 413*sizeX ), ROUND( y + 510*sizeY )},
                                     { ROUND( x + 405*sizeX ), ROUND( y + 532*sizeY )},
                                     { ROUND( x + 418*sizeX ), ROUND( y + 532*sizeY )}};
                txPolygon (NoseBoy, 3);

                txEllipse   (ROUND( x + 340*sizeX ), ROUND( y + 531*sizeY ),
                             ROUND( x + 480*sizeX ), ROUND( y + 671*sizeY ));

                POINT ArmBoy1 [3] =  {{ ROUND( x + 278*sizeX ), ROUND( y + 580*sizeY )},
                                      { ROUND( x + 329*sizeX ), ROUND( y + 653*sizeY )},
                                      { ROUND( x + 312*sizeX ), ROUND( y + 664*sizeY )}};
                txPolygon (ArmBoy1, 3);

                POINT ArmBoy2 [3] =  {{ ROUND( x + 523*sizeX ), ROUND( y + 583*sizeY )},
                                      { ROUND( x + 474*sizeX ), ROUND( y + 648*sizeY )},
                                      { ROUND( x + 490*sizeX ), ROUND( y + 656*sizeY )}};
                txPolygon (ArmBoy2, 3);

                txSetFillColor (RGB (236, 237, 242));
                txRectangle (ROUND( x + 345*sizeX ), ROUND( y + 824*sizeY ),
                             ROUND( x + 390*sizeX ), ROUND( y + 960*sizeY ));

                txRectangle (ROUND( x + 427*sizeX ), ROUND( y + 822*sizeY ),
                             ROUND( x + 473*sizeX ), ROUND( y + 966*sizeY ));

                txSetFillColor (RGB (0, 0, 0));
                POINT EyeBoy1 [4] = {{ ROUND( x + 372*sizeX ), ROUND( y + 560*sizeY )},
                                     { ROUND( x + 405*sizeX ), ROUND( y + 550*sizeY )},
                                     { ROUND( x + 410*sizeX ), ROUND( y + 560*sizeY )},
                                     { ROUND( x + 375*sizeX ), ROUND( y + 570*sizeY )}};
                txPolygon (EyeBoy1, 4);

                POINT EyeBoy2 [4] = {{ ROUND( x + 418*sizeX ), ROUND( y + 560*sizeY )},
                                     { ROUND( x + 424*sizeX ), ROUND( y + 550*sizeY )},
                                     { ROUND( x + 454*sizeX ), ROUND( y + 567*sizeY )},
                                     { ROUND( x + 448*sizeX ), ROUND( y + 575*sizeY )}};
                txPolygon (EyeBoy2, 4);

                //_________________________________________

                txSetColor     (RGB (255, 0, 0), 3);
                txSetFillColor (RGB (255, 0, 0));
                POINT ArmBoy [3] =  {{ ROUND( x + 413*sizeX ), ROUND( y + 464*sizeY )},
                                     { ROUND( x + 371*sizeX ), ROUND( y + 396*sizeY )},
                                     { ROUND( x + 455*sizeX ), ROUND( y + 396*sizeY )}};
                txPolygon (ArmBoy, 3);

                txEllipse   (ROUND( x + 365*sizeX ), ROUND( y + 355*sizeY ),
                             ROUND( x + 415*sizeX ), ROUND( y + 405*sizeY ));

                txEllipse   (ROUND( x + 415*sizeX ), ROUND( y + 355*sizeY ),
                             ROUND( x + 465*sizeX ), ROUND( y + 405*sizeY ));
                t ++;
                txSleep (60);
                }
            else
                {
                double x = ROUND( 260 - t*2.6 );
                double y = 163 - t*1.7;
                double sizeX = 0.006*t;
                double sizeY = 0.0037*t;
                txSetColor     (RGB (255, 0, 0), 5);
                txSetFillColor (RGB (255, 0, 0));
                POINT ArmBoy [3] =  {{ ROUND( x + 413*sizeX ), ROUND( y + 464*sizeY )},
                                     { ROUND( x + 371*sizeX ), ROUND( y + 396*sizeY )},
                                     { ROUND( x + 455*sizeX ), ROUND( y + 396*sizeY )}};
                txPolygon (ArmBoy, 3);

                txEllipse   (ROUND( x + 364*sizeX ), ROUND( y + 354*sizeY ),
                             ROUND( x + 413*sizeX ), ROUND( y + 404*sizeY ));

                txEllipse   (ROUND( x + 413*sizeX ), ROUND( y + 354*sizeY ),
                             ROUND( x + 463*sizeX ), ROUND( y + 404*sizeY ));
                t ++;
                txSleep (20);
                }
            }
        t = 100;
        n ++;
        }
    }


