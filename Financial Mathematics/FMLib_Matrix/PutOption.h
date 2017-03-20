#pragma once

#include "stdafx.h"
#include "BlackScholesModel.h"
#include "PathIndependentOption.h"

class PutOption : public PathIndependentOption {
public:

    /*  Returns the payoff at maturity given a column vector
        of scenarios */
    Matrix payoffAtMaturity( const Matrix& finalStockPrice) const;


    double price( const BlackScholesModel& bsm )
        const;

};

void testPutOption();
