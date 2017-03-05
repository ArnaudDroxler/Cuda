#pragma once

#include "cudaType_CPU.h"
#include "Variateur_CPU.h"
#include "Animable_I_CPU.h"
#include "math/JuliaMathH.h"
#include "Fractale.h"

using namespace cpu;


class JuliaH: public Fractale
    {


    public:

	JuliaH(uint w, uint h, uint dt, float c1, float c2, const DomaineMath& domaineMath);

	virtual ~JuliaH(void);

	FractaleMath* getFractaleMath();

    };
