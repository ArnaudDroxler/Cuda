#include <iostream>
#include <stdio.h>
#include "Grid.h"
#include "Device.h"
#include "Chrono.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

#include "host/MontecarloMultiGPU.h"

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useMontecarloMultiGPU(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useMontecarloMultiGPU()
    {

    bool isOk = true;

    int nbDarts = INT_MAX;
    float m = 20;

    dim3 dg = dim3(512, 1, 1);
    dim3 db = dim3(1024, 1, 1);

    Grid grid(dg, db);

    MontecarloMultiGPU mc(grid, nbDarts, m);
    Chrono c;
    mc.run();
    double time = c.stop();
    float reslut = mc.getResult();
    cout << "Result : " << reslut << "  Time : " << time;
    return isOk;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

