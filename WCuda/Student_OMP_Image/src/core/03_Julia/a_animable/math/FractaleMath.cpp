
#include <iostream>
#include <omp.h>
#include "OmpTools.h"

#include "IndiceTools_CPU.h"

#include "FractaleMath.h"

using cpu::IndiceTools;

using std::cout;
using std::endl;


FractaleMath::FractaleMath(uint n) :
	calibreur(Interval<float>(0, n), Interval<float>(0, 1))
    {
    this->n = n;
    }

FractaleMath::~FractaleMath(){

}

void FractaleMath::colorXY(uchar4* ptrColor, float x, float y){

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

bool FractaleMath::isStop(float a, float n){

}

void FractaleMath::setN(int n){

    this->n = n;
    calibreur = Calibreur<float>(Interval<float>(0, n), Interval<float>(0, 1));

}
