
void DrawSun   (int x, double y, double sizeX, double sizeY, COLORREF SunColor);


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
