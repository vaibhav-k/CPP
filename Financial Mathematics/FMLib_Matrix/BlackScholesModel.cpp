#include "BlackScholesModel.h"
#include "MultiStockModel.h"

using namespace std;

#include "matlib.h"

BlackScholesModel::BlackScholesModel() :
    drift(0.0),
    stockPrice(0.0),
    volatility(0.0),
    riskFreeRate(0.0),
    date(0.0) {
}

/**
 *  Creates a price path according to the model parameters
 */
Matrix BlackScholesModel::
            generateRiskNeutralPricePaths(
        mt19937& rng,
        double toDate,
        int nPaths,
        int nSteps ) const {
    MultiStockModel msm(*this);
    MarketSimulation sim
        = msm.generateRiskNeutralPricePaths(
            rng, toDate, nPaths, nSteps);
    return *sim.getStockPrices(MultiStockModel::DEFAULT_STOCK);
}

/**
*  Creates a price path according to the model parameters
*/
Matrix BlackScholesModel:: generatePricePaths(
        mt19937& rng,
        double toDate,
        int nPaths,
        int nSteps) const {
    MultiStockModel msm(*this);
    MarketSimulation sim
        = msm.generatePricePaths(
        rng, toDate, nPaths, nSteps);
    return *sim.getStockPrices( MultiStockModel::DEFAULT_STOCK);
}





////////////////////////////////
//
//   TESTS
//
////////////////////////////////

void testRiskNeutralPricePath() {
    mt19937 rng;

    BlackScholesModel bsm;
    bsm.riskFreeRate = 0.05;
    bsm.volatility = 0.1;
    bsm.stockPrice = 100.0;
    bsm.date = 2.0;

    int nPaths = 10000;
    int nsteps = 5;
    double maturity = 4.0;
    Matrix paths =
        bsm.generateRiskNeutralPricePaths( rng,
                                           maturity,
                                            nPaths,
                                            nsteps );
    Matrix finalPrices = paths.col( nsteps-1 );
    ASSERT_APPROX_EQUAL( meanCols( finalPrices ).asScalar(),
        exp( bsm.riskFreeRate*2.0)*bsm.stockPrice, 0.5);
}

void testVisually() {

    mt19937 rng;

    BlackScholesModel bsm;
    bsm.riskFreeRate = 0.05;
    bsm.volatility = 0.1;
    bsm.stockPrice = 100.0;
    bsm.date = 2.0;

    int nSteps = 1000;
    double maturity = 4.0;

    Matrix path = bsm.generatePricePaths( rng,
                                          maturity,
                                         1,
                                         nSteps );
    double dt = (maturity-bsm.date)/nSteps;
    Matrix times = linspace(dt, maturity, nSteps, 1 );
    plot("examplePricePath.html",
         times,
         path );
}


void testBlackScholesModel() {
    TEST( testRiskNeutralPricePath );
    TEST( testVisually );
}
