#pragma once

#include <math.h>
#include "MathTools.h"

#include "Calibreur_CPU.h"
#include "ColorTools_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MandelbrotMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	MandelbrotMath(uint n) :
		calibreur(Interval<float>(0, n), Interval<float>(0, 1))
	    {
	    this->n = n;
	    }

	// constructeur copie automatique car pas pointeur dans
	//	DamierMath
	// 	calibreur
	// 	IntervalF

	virtual ~MandelbrotMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void colorXY(uchar4* ptrColor, float x, float y)
	    {
	    float z = f(x, y);

	    if(z != n){
		calibreur.calibrer(z);
		float hue01 = z;
		ColorTools::HSB_TO_RVB(hue01, ptrColor); // update color
	    }else{
		ptrColor->x = 0;
		ptrColor->y = 0;
		ptrColor->z = 0;
	    }

	    ptrColor->w = 255; // opaque
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


/*		for (i = 0; i < n; ++i)
		{
		    copyA = a;
		    a = (a*a-b*b)+x;
		    b = 2.0f*copyA*b+y;
		    if( a*a+b*b > 4.0f){
			return i;
		    }
		}
*/

		return i;
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Input
	uint n;

	// Tools
	Calibreur<float> calibreur;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
