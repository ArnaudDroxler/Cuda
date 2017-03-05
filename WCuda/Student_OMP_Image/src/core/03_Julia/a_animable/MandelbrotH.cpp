#include <iostream>
#include <omp.h>
#include "OmpTools.h"

#include "IndiceTools_CPU.h"

#include "MandelbrotH.h"

using cpu::IndiceTools;

using std::cout;
using std::endl;


MandelbrotH::MandelbrotH(uint w, uint h, uint dt,  const DomaineMath& domaineMath) :
	Fractale(w, h, dt, domaineMath)
    {

    // Tools
    this->t = 30;					// protected dans super classe Animable
    this->parallelPatern = ParallelPatern::OMP_MIXTE;   // protected dans super classe Animable

    this->ptrFractalMath = new MandelbrotMathH(this->t);

    // OMP
    cout << "\n[Mandelbrot] : OMP : nbThread = " << this->nbThread << endl; // protected dans super classe Animable
    }

MandelbrotH::~MandelbrotH(void)
    {
    delete this->ptrFractalMath;
    }

FractaleMath* MandelbrotH::getFractaleMath()
    {
    return this->ptrFractalMath;
    }


