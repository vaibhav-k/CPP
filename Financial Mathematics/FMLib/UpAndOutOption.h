#ifndef UPANDOUTOPTION_H_INCLUDED
#define UPANDOUTOPTION_H_INCLUDED

#pragma once

#include "KnockoutOption.h"

class UpAndOutOption : public KnockoutOption
{
public:
    double payoff(const std::vector<double>& prices ) const;

    double price(const BlackScholesModel& model) const
    {
        if (model.stockPrice >= getBarrier())
            return 0;
        return KnockoutOption::price(model);
    }
};


void testUpAndOutOption();

#endif // UPANDOUTOPTION_H_INCLUDED
