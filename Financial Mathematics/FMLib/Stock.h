#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#pragma once

#include "Priceable.h"

class Stock : public Priceable {
public:
    /*  Compute the price of the security in the
    Black Scholes world */
    virtual double price(
        const BlackScholesModel& model) const {
        return model.stockPrice;
    }
};

#endif // STOCK_H_INCLUDED
