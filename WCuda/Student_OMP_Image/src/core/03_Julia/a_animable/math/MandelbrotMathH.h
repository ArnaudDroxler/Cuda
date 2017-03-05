#pragma once

#include <math.h>
#include "MathTools.h"
#include "FractaleMath.h"

#include "Calibreur_CPU.h"
#include "ColorTools_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MandelbrotMathH : public FractaleMath
    {


    public:

	MandelbrotMathH(uint n) : FractaleMath(n)
	    {

	    }

	virtual ~MandelbrotMathH()
	    {
	    // rien
	    }

    private:

	int f(float x, float y)
	    {
		float a = 0;
		float b = 0;
		float copyA = 0;
		int i = 0;

		do{
		    i++;
		    copyA = a;
		    a = (a*a-b*b)+x;
		    b = 2.0f*copyA*b+y;
		}
		while( a*a+b*b < 4.0f && i < this->n );

		return i;
	    }


    };
