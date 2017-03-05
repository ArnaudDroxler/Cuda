#include "MathTools.h"

#include "ImageAnimable_CPU.h"
#include "DomaineMath_CPU.h"

#include "JuliaHProvider.h"

#include "../a_animable/JuliaH.h"
using namespace cpu;


Animable_I<uchar4>* JuliaHProvider::createAnimable(void)
    {
    DomaineMath domaineMath = DomaineMath(-1.3,-1.4 , 1.3, 1.4);

    // Animation;
    int dt = 1;

    // Dimension
    int dw = 16 * 60;
    int dh = 16 * 60;

    float c1 = -0.12;
    float c2 = +0.85;

    return new JuliaH(dw, dh, dt, c1, c2, domaineMath);
    }


Image_I* JuliaHProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 0, 0); // black
    return new ImageAnimable_RGBA_uchar4(createAnimable(),colorTexte);
    }
