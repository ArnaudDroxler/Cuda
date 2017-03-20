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
		Sphere s = ptrDevTabSphere[0];
		for (uint index = 0; index < nbSphere; index++)
		{
		    s = ptrDevTabSphere[index];
		    hCarre = s.hCarre(i, j);
		    if (s.isEnDessous(hCarre))
		    {
			ColorTools::HSB_TO_RVB(s.hue(t), 1.f, s.brightness(s.dz(hCarre)), ptrColor);
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