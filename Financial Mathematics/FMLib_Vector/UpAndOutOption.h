#ifndef UPANDOUTOPTION_H_INCLUDED
#define UPANDOUTOPTION_H_INCLUDED

#pragma once

#include "BarrierOption.h"

class UpAndOutOption : public BarrierOption {
public:
    double payoff(
        const std::vector<double>& prices ) const;
};


void testUpAndOutOption();
#endif // UPANDOUTOPTION_H_INCLUDED
