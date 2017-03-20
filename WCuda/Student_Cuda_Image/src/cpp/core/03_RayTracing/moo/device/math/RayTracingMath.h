#pragma once

#include <math.h>
#include "MathTools.h"
#include "Sphere.h"
#include <stdio.h>

#include "ColorTools_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class RaytracingMath
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__ RaytracingMath(float t,int nbSphere,Sphere* ptrDevTabSphere)
	    {
	    this->t = t;
	    this->nbSphere = nbSphere;
	    this->ptrDevTabSphere = ptrDevTabSphere;
	    }

	__device__
	   virtual ~RaytracingMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__device__
	void colorIJ(uchar4* ptrColor, float i, float j)
	    {
		ptrColor->x = 0;
		ptrColor->y = 0;
		ptrColor->z = 0;
		ptrColor->w = 255;
		float hCarre;
		for (uint index = 0; index < nbSphere; index++)
		{
		    hCarre = ptrDevTabSphere[index].hCarre(i, j);
		    if (ptrDevTabSphere[index].isEnDessous(hCarre))
		    {
			ColorTools::HSB_TO_RVB(ptrDevTabSphere[index].hue(t), 1.f, ptrDevTabSphere[index].brightness(ptrDevTabSphere[index].dz(hCarre)), ptrColor);
			break;
		    }
		}

	    }

    private:

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Tools
	float t;
	int nbSphere;
	Sphere* ptrDevTabSphere;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
