#include "TXLib.h"

void DrawMir();
void DrawHouse2 (int x,     int y);
void DrawHouse3 (int x,     int y);
void DrawTree1  (int x,     int y, double sizeX, double sizeY, COLORREF TreeColor);
void DrawTree2  (int x,     int y, double sizeX, double sizeY, COLORREF TreeColor);
void DrawSun    (int x,  double y, double sizeX, double sizeY, COLORREF SunColor);
void DrawGirl   (int x,     int y, double sizeX, double sizeY, COLORREF GirlColor,
                                   double Glaz,  double smayl);
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
        DrawBackground (RGB (0, 180 - pow(t-50,2)/25,
                                180 - pow(t-50,2)/25));

        DrawSun    (  7 + 5*t              ,
                     75 + pow(t-50,2)/100*3,
                    1.2 - pow(t-50,2)/2000 ,
                    1.2 - pow(t-50,2)/2000 ,
               RGB (255 - pow(t-50,2)/50   , 255 - pow(t-50,2)/50, 0));

        DrawHouse2 (290,  60);
        DrawHouse1 (320, 260, RGB (0, 180 - pow(t-50,2)/25,
                                      180 - pow(t-50,2)/25));
        DrawMir();
        t ++;
        txSleep (100);
        }

    txEnd();

    return 0;
    }

void DrawMir()
    {
    DrawHouse3 (355, 120);
    DrawTree2  (100, 285,   1,   1, RGB ( 50, 150,   0));
    DrawTree1  (  3, 163,   1,   1, RGB ( 50, 200,   0));
    DrawGirl   ( 50, 320,   1,   1, RGB (  0, 255,   0), 1,  3);
    DrawGirl   (100, 320,   1,   1, RGB (228, 100, 100), 1,  3);
    DrawGirl   (300, 300,   1, 0.8, RGB (234, 255, 255), 1, -2);
    DrawGirl   (415, 215, 0.5, 0.4, RGB (234, 255, 255), 1,  1);
    DrawGirl   (215, 300, 0.5, 0.9, RGB (228,  50,   0), 1,  1);
    }

void DrawGirl  (int x, int y, double sizeX, double sizeY, COLORREF GirlColor,
                double Glaz, double smayl)

    {
    txSetFillColor (GirlColor);
    txEllipse (x, y, ROUND( x + 30*sizeX ), ROUND( y + 30*sizeY ));
    POINT Girl [3] =  {{ ROUND( x + 15*sizeX ), ROUND( y + 30*sizeY )},
                       { ROUND( x +  5*sizeX ), ROUND( y + 75*sizeY )},
                       { ROUND( x + 25*sizeX ), ROUND( y + 75*sizeY )}};
    txPolygon (Girl, 3);
    txSetColor     (RGB (255, 128, 0), 1);
    txSetFillColor (RGB (255,   0, 0));
    POINT Girl2 [3] = {{ ROUND( x +  7*sizeX ), ROUND( y + 20*sizeY         )},
                       { ROUND( x + 15*sizeX ), ROUND( y + 20*sizeY + smayl )},
                       { ROUND( x + 23*sizeX ), ROUND( y + 20*sizeY         )}};
    txPolygon  (Girl2, 3);
    txSetColor     (RGB (200, 200, 0), 1);
    txSetFillColor (RGB (200, 200, 0));
    txEllipse ( ROUND( x +  7*sizeX      ), ROUND( y + 7*sizeY       ),
                ROUND( x + 13*sizeX*Glaz ), ROUND( y + 13*sizeY*Glaz ));
    txEllipse ( ROUND( x + 17*sizeX      ), ROUND( y + 7*sizeY       ),
                ROUND( x + 23*sizeX*Glaz ), ROUND( y + 13*sizeY*Glaz ));
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

    txSetFillColor (RGB (0, 0, 0));
    POINT Window1 [4] = {{ x - 110, y - 120 },
                         { x - 110, y - 100 },
                         { x -  90, y - 100 },
                         { x -  90, y - 120 }};
    txPolygon (Window1, 4);

    POINT Window2 [4] = {{ x - 70, y - 120 },
                         { x - 70, y - 100 },
                         { x - 50, y - 100 },
                         { x - 50, y - 120 }};
    txPolygon (Window2, 4);

    POINT Window3 [4] = {{ x - 30, y - 120 },
                         { x - 30, y - 100 },
                         { x - 10, y - 100 },
                         { x - 10, y - 120 }};
    txPolygon (Window3, 4);

    txSetFillColor (RGB (0, 0, 0));
    POINT Door [4] =    {{ x - 95, y      },
                         { x - 95, y - 50 },
                         { x - 50, y - 50 },
                         { x - 50, y      }};
    txPolygon (Door, 4);

    txSetFillColor (RGB (230, 230, 230));
    POINT Attic [4] =  {{ x - 65, y - 140 },
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
