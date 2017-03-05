#include "JuliaH.h"

#include <iostream>
#include <omp.h>
#include "OmpTools.h"

#include "IndiceTools_CPU.h"

#include "math/JuliaMathH.h"
using cpu::IndiceTools;

using std::cout;
using std::endl;



JuliaH::JuliaH(uint w, uint h, uint dt, float c1, float c2,  const DomaineMath& domaineMath) :
	Fractale(w, h, dt, domaineMath)
    {

    // Tools
    this->t = 30;					// protected dans super classe Animable
    this->parallelPatern = ParallelPatern::OMP_MIXTE;   // protected dans super classe Animable

    this->ptrFractalMath = new JuliaMathH(this->t, c1 ,c2);
    // OMP
    cout << "\n[Julia] : OMP : nbThread = " << this->nbThread << endl; // protected dans super classe Animable
    }

JuliaH::~JuliaH(void)
    {
    delete this->ptrFractalMath;
    }

FractaleMath* JuliaH::getFractaleMath()
    {
    return this->ptrFractalMath;
    }
