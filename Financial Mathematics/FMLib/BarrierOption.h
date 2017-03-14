#ifndef BARRIEROPTION_H_INCLUDED
#define BARRIEROPTION_H_INCLUDED

#pragma once

#include "ContinuousTimeOptionBase.h"

/**
 *   An option with a barrier
 */
class BarrierOption : public ContinuousTimeOptionBase {
public:
    virtual ~BarrierOption() {}

    double getBarrier() const {
        return barrier;
    }

    void setBarrier(double barrier) {
        this->barrier=barrier;
    }

    bool isPathDependent() const {
        return true;
    }
private:
    double barrier;
};

#endif // BARRIEROPTION_H_INCLUDED
