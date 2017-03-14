#ifndef UPANDINOPTION_H_INCLUDED
#define UPANDINOPTION_H_INCLUDED

#pragma once

#include "BarrierOption.h"

class UpAndInOption : public BarrierOption {
public:
    double payoff(
        const std::vector<double>& prices) const;
};


void testUpAndInOption();

#endif // UPANDINOPTION_H_INCLUDED
