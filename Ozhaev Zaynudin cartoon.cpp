#include "TXLib.h"

void DrawMir(int t);
void DraTrainFare(int t);
void DrawTrain   (int x,     int y);
void DrawHouse2  (int x,     int y);
void DrawHouse3  (int x,     int y);
void DrawTrain   (int x,     int y, double sizeX, double sizeY);
void DrawTree1   (int x,     int y, double sizeX, double sizeY, COLORREF TreeColor);
void DrawTree2   (int x,     int y, double sizeX, double sizeY, COLORREF TreeColor);
void DrawSun     (int x,  double y, double sizeX, double sizeY, COLORREF SunColor);
void DrawGirl    (int x,     int y, double sizeX, double sizeY, COLORREF GirlColor,
                                    double eyes,  double smayl);
void DrawMan     (int x,     int y, double sizeX, double sizeY, COLORREF ManColor,
                                    double eyes,  double smayl);
void DrawHouse1 (int x,     int y, COLORREF HoleColor);
void DrawBackground (COLORREF SkyColor);

int main()

    {
    txCreateWindow (480, 400);
    txBegin();

    int t = 0;
    while ( t <=100 )
        {
        txClear ();

        DrawMir(t);
        DraTrainFare(t);
        t ++;
        txSleep (100);
        }

    txEnd();

    return 0;
    }

void DraTrainFare(int t)
    {
    if (t<=10)
        {
        DrawTrain  (480 - t*30, 370, .45, .45);
        }
    if (t>10 and t<=20)
        {
        DrawTrain  (180, 370, .45, .45);

        DrawGirl   (220 + (t-10)*5, 220 + (t-10)*5 + ((t%2)*5), 0.7, 0.7, RGB (  0, 255,   0), 1,  3);
        DrawMan    (250 + (t-10)*5, 220 + (t-10)*5 + ((t%2)*2), 0.7, 0.7, RGB (228, 100, 100), 1,  3);

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
        DrawGirl   (270 - (t-80)*5, 270 - (t-80)*5 + ((t%2)*5), 0.7, 0.7, RGB (  0, 255,   0), 1,  3);
        DrawMan    (300 - (t-80)*5, 270 - (t-80)*5 + ((t%2)*2), 0.7, 0.7, RGB (228, 100, 100), 1,  3);
        }
    if (t>90 and t<=100)
        {
        DrawTrain  ((t-80)*40, 370, -.45, .45);
        }
    }

void DrawMir(int t)
    {
    DrawBackground (RGB (0, 180 - pow(t-50,2)/25,
                            180 - pow(t-50,2)/25));
    DrawSun    (  7 + 5*t              ,
                 75 + pow(t-50,2)/100*3,
                1.2 - pow(t-50,2)/2000 ,
                1.2 - pow(t-50,2)/2000 ,
                RGB (255 - pow(t-50,2)/50, 255 - pow(t-50,2)/50, 0));
    DrawHouse2 (290,  60);
    DrawHouse1 (320, 260, RGB (0, 180 - pow(t-50,2)/25, 180 - pow(t-50,2)/25));
    DrawHouse3 (355, 120);
    DrawTree2  (100, 285,   1,   1, RGB ( 50, 150,   0));
    DrawTree1  (  3, 163,   1,   1, RGB ( 50, 200,   0));
   // DrawGirl   (220, 220, 0.7, 0.7, RGB (  0, 255,   0), 1,  3);
    //DrawMan    (250, 220, 0.7, 0.7, RGB (228, 100, 100), 1,  3);

    }

void DrawGirl  (int x, int y, double sizeX, double sizeY, COLORREF GirlColor,
                              double eyes,  double smayl)

    {
    txSetFillColor (GirlColor);
    txEllipse     (x, y, ROUND( x + 30*sizeX ), ROUND( y + 30*sizeY ));
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
    txSetFillColor (ManColor);
    txEllipse    (x, y, ROUND( x + 30*sizeX ), ROUND( y + 30*sizeY ));
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

void DrawSun   (int x, double y, double sizeX, double sizeY, COLORREF SunColor)

    {
    txSetFillColor (SunColor);
    POINT Sun [8] = {{ ROUND( x -  2*sizeX ), ROUND( y - 50*sizeY )},
                     { ROUND( x - 37*sizeX ), ROUND( y + 35*sizeY )},
                     { ROUND( x + 50*sizeX ), ROUND( y            )},
                     { ROUND( x - 37*sizeX ), ROUND( y - 35*sizeY )},
                     { ROUND( x -  2*sizeX ), ROUND( y + 50*sizeY )},
                     { ROUND( x + 33*sizeX ), ROUND( y - 35*sizeY )},
                     { ROUND( x - 50*sizeX ), ROUND( y            )},
                     { ROUND( x + 33*sizeX ), ROUND( y + 35*sizeY )}};
    txPolygon (Sun, 8);
    txSetFillColor (RGB (0, 180, 180));
    txEllipse ( ROUND( x - 32*sizeX ), ROUND( y - 32*sizeY ),
                ROUND( x + 32*sizeX ), ROUND( y + 32*sizeY ));
    txSetFillColor (SunColor);
    txEllipse ( ROUND( x - 27*sizeX ), ROUND( y - 27*sizeY ),
                ROUND( x + 27*sizeX ), ROUND( y + 27*sizeY ));
    }

void DrawBackground (COLORREF SkyColor)

    {
    txSetColor     (RGB (255, 255, 255), 1);
    txSetFillColor (RGB (180, 180, 180));
    txRectangle (0, 150, 480, 400);
    txSetFillColor (SkyColor);
    txRectangle (0, 0, 480, 150);
    }

void DrawHouse1 (int x, int y, COLORREF HoleColor)

    {
    txSetFillColor (RGB (255, 255, 255));
    POINT stena [4] =  {{ x      , y       },
                        { x - 120, y       },
                        { x - 120, y - 140 },
                        { x      , y - 140 }};
    txPolygon (stena, 4);
    for (int corX = ( x - 110 ); corX <= (x - 30); corX += 40 )
        {
        txSetFillColor (RGB (0, 0, 0));
        POINT Window [4] = {{ corX     , y - 120 },
                            { corX     , y - 100 },
                            { corX + 20, y - 100 },
                            { corX + 20, y - 120 }};
        txPolygon (Window, 4);
        }

    txSetFillColor (RGB (0, 0, 0));
    POINT Door [4] =       {{ x - 95, y      },
                            { x - 95, y - 50 },
                            { x - 50, y - 50 },
                            { x - 50, y      }};
    txPolygon (Door, 4);

    txSetFillColor (RGB (230, 230, 230));
    POINT Attic [4] =      {{ x - 65, y - 140 },
                            { x - 65, y - 180 },
                            { x - 30, y - 180 },
                            { x - 30, y - 140 }};
    txPolygon (Attic, 4);

    txSetFillColor (HoleColor);
    txCircle ( x - 47, y - 160, 10 );
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
