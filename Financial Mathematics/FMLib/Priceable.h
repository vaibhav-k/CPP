#ifndef PRICEABLE_H_INCLUDED
#define PRICEABLE_H_INCLUDED

#pragma once

#include "BlackScholesModel.h"

/**
 *   Represents a general security
 */
class Priceable {
public:
    /*  Compute the price of the security in the
        Black Scholes world */
    virtual double price(
        const BlackScholesModel& model ) const = 0;
};

#endif // PRICEABLE_H_INCLUDED
