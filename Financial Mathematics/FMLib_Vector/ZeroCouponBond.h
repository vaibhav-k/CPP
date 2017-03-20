#ifndef ZEROCOUPONBOND_H_INCLUDED
#define ZEROCOUPONBOND_H_INCLUDED

#pragma once

#include "Priceable.h"

class ZeroCouponBond : public Priceable {
public:

    double maturity;

    /*  Compute the price of the security in the
        Black Scholes world */
    virtual double price(
        const BlackScholesModel& model) const {
        return exp(-model.riskFreeRate*maturity);
    }
};

#endif // ZEROCOUPONBOND_H_INCLUDED
