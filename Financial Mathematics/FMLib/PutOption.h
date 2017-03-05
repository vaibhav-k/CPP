#ifndef PUTOPTION_H_INCLUDED
#define PUTOPTION_H_INCLUDED

#pragma once

#include "stdafx.h"
#include "BlackScholesModel.h"

class PutOption
{
public:
    PutOption();
    double strike;
    double maturity;

    double payoff( double stockAtMaturity ) const;

    double price( const BlackScholesModel& bsm )
        const;
};

void testPutOption();

#endif // PUTOPTION_H_INCLUDED
