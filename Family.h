
void DrawFamily ();
void DrawHouse  ( double x, double y, double sizeX, double sizeY, COLORREF HoleColor );

void DrawFamily ()
    {
    int n = 0;
    int t = 0;
    while ( n <= 5 )
        {
        while ( t <=120 )
            {
            if (t <=100 )
                {
                txSetFillColor (TX_BLACK);
                txClear ();
                txSetColor     (RGB (255, 255, 255), 1);
                txSetFillColor (RGB (180, 180, 180));
                txRectangle (0, 150, 480, 400);
                txSetFillColor (SkyColor);
                txRectangle (0, 0, 480, 150);
                txSetColor  (RGB (255, 255, 255), 1);
                DrawHouse ( ROUND( 320 + t*14.2 ), ROUND( 260 + t*22.5 ),
                    1 + t*0.24, 1 + t*0.2, RGB (0, 80, 80));
                int x = ROUND( 240 - t*2.4 );
                int y = 200 - t*2;
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
                int x = ROUND( 240 - t*2.4 );
                int y = 200 - t*2;
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

void DrawHouse (double x, double y, double sizeX, double sizeY, COLORREF HoleColor)

    {
    txSetFillColor (RGB (255, 255, 255));
    POINT stena [4] =  {{        x                ,        y                },
                        { ROUND( x - 120 * sizeX ),        y                },
                        { ROUND( x - 120 * sizeX ), ROUND( y - 140 * sizeY )},
                        {        x                , ROUND( y - 140 * sizeY )}};
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
    POINT Door [4] =       {{ ROUND( x - 95 * sizeX ),        y                },
                            { ROUND( x - 95 * sizeX ), ROUND( y - 50 * sizeY ) },
                            { ROUND( x - 50 * sizeX ), ROUND( y - 50 * sizeY ) },
                            { ROUND( x - 50 * sizeX ),        y                }};
    txPolygon (Door, 4);

    txSetFillColor (RGB (230, 230, 230));
    POINT Attic [4] =      {{ ROUND( x - 65 * sizeX ), ROUND( y - 140 * sizeY )},
                            { ROUND( x - 65 * sizeX ), ROUND( y - 180 * sizeY )},
                            { ROUND( x - 30 * sizeX ), ROUND( y - 180 * sizeY )},
                            { ROUND( x - 30 * sizeX ), ROUND( y - 140 * sizeY )}};
    txPolygon (Attic, 4);

    txSetFillColor (HoleColor);
    txCircle ( ROUND( x - 47 * sizeX ), ROUND( y - 160 * sizeY ), 10 );
    }
