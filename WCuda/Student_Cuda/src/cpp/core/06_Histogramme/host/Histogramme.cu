#include <iostream>
#include "Device.h"
#include "cudaTools.h"
#include "DataCreator.h"

#include "Histogramme.h"


using std::cout;
using std::endl;

extern __global__ void histogramme(int* ptrTabIn, uint lenght, int* ptrHistogrammeGM);

Histogramme::Histogramme(const Grid& grid, int* ptrResult, int dataMax)
    {

    this->dg = grid.dg;
    this->db = grid.db;

    this->ptrResult = ptrResult;

    DataCreator dataCreator(dataMax);
    this->data = dataCreator.getTabData();
    this->lenght= dataCreator.getLength();


    this->sizeOctetResult = sizeof(int) * dataMax; // octet
    this->sizeOctetData = sizeof(int) * this->lenght;

    Device::malloc(&ptrTabIn, sizeOctetData);
    Device::memclear(ptrTabIn, sizeOctetData);
    Device::memcpyHToD(ptrTabIn, data, sizeOctetData);

    Device::malloc(&ptrTabOut, sizeOctetResult);
    Device::memclear(ptrTabOut, sizeOctetResult);

    }

Histogramme::~Histogramme(void)
    {
    Device::free(ptrTabIn);
    Device::free(ptrTabOut);
    }


void Histogramme::run()
    {
    Device::lastCudaError("histogramme (before)");
    histogramme<<<dg,db, sizeOctetResult>>>(ptrTabIn, lenght, ptrTabOut);
    Device::lastCudaError("histogramme (after)");

    Device::synchronize();

    Device::memcpyDToH(ptrResult, ptrTabOut, sizeOctetResult);
    }

