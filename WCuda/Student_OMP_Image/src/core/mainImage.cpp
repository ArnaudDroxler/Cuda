#include <iostream>

#include "Viewer_CPU.h"
#include "Settings_CPU.h"

#include "03_Julia/b_provider/JuliaHProvider.h"
#include "03_Julia/b_provider/MandelbrotHProvider.h"
#include "01_Rippling/b_provider/RipplingProvider.h"
using namespace cpu;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainImage(Settings& settings);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int mainImage(Settings& settings)
    {
    cout << "\n[Image] mode" << endl;

    GLUTImageViewers::init(settings.getArgc(), settings.getArgv()); // only once

    // ImageOption : (boolean,boolean) : (isSelection,isAnimation)
    ImageOption zoomable(true,true,true,true);
    ImageOption nozoomable(false,false,false,false);


    Viewer<JuliaHProvider> julia(zoomable, 25, 25); //  imageOption px py
    //Viewer<MandelbrotHProvider> mandelbrot(zoomable, 25, 25); //  imageOption px py
    //Viewer<MandelbrotProvider> mandelbrot(zoomable, 25, 25);


    GLUTImageViewers::runALL();  // Bloquant, Tant qu'une fenetre est ouverte

    cout << "\n[Image] end" << endl;

    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

