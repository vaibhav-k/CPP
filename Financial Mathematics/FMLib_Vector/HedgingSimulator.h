#ifndef HEDGINGSIMULATOR_H_INCLUDED
#define HEDGINGSIMULATOR_H_INCLUDED

#pragma once

#include "stdafx.h"
#include "BlackScholesModel.h"
#include "CallOption.h"

/**
 *   This class can be used to see the results of the delta
 *   hedging strategy
 */
class HedgingSimulator {
public:
    /*  Runs a number of simulations and returns
        a vector of the profit and loss */
    std::vector<double> runSimulations(
            int nSimulations ) const;
    void setToHedge(
            std::shared_ptr<CallOption> toHedge) {
        this->toHedge = toHedge;
    }
    void setSimulationModel(
        std::shared_ptr<BlackScholesModel> model) {
        this->simulationModel = model;
    }
    void setPricingModel(
        std::shared_ptr<BlackScholesModel> model) {
        this->pricingModel = model;
    }
    void setNSteps(int nSteps) {
        this->nSteps = nSteps;
    }
    /*  Default constructor */
    HedgingSimulator();
private:
    /*  The option that has been written */
    std::shared_ptr<CallOption> toHedge;
    /*  The model used to simulate stock prices */
    std::shared_ptr<BlackScholesModel>
        simulationModel;
    /* The model used to compute prices and deltas */
    std::shared_ptr<BlackScholesModel> pricingModel;
    /*  The number of steps to use */
    int nSteps;
    /*  Run a simulation and compute
        the profit and loss */
    double runSimulation() const;
    /*  How much should we charge the customer */
    double chooseCharge( double stockPrice ) const;
    /*  Hoe much stock should we hold */
    double selectStockQuantity(
        double date,
        double stockPrice ) const;
};

//     Tests

void testHedgingSimulator();

#endif // HEDGINGSIMULATOR_H_INCLUDED
