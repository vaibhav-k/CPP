#ifndef MONTECARLOPRICER_H_INCLUDED
#define MONTECARLOPRICER_H_INCLUDED

#pragma once

#include "stdafx.h"
#include "CallOption.h"
#include "BlackScholesModel.h"

class MonteCarloPricer {
public:
    /*  Constructor */
    MonteCarloPricer();
    /*  Number of scenarios */
    int nScenarios;
    /*  Price a call option */
    double price( const CallOption& option,
                  const BlackScholesModel& model );
};

void testMonteCarloPricer();

#endif // MONTECARLOPRICER_H_INCLUDED
