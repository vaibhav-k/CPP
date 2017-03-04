#include "matlib.h"

const double root2Pi = sqrt( 2.0 * 3.141592653589793 );

double normcdf( double x )
{
    if (x<=0)
    {
        return 1-normcdf(-x);
    }
    double k = 1/(1 + 0.2316419*x);
    double poly = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937
                  + k*(-1.821255978 + 1.330274429*k))));
    double approx = 1.0 - 1.0/root2Pi * exp(-0.5*x*x) * poly;

    return approx;
}

double hornerFunction( double x, double a0, double a1)
{
    return a0 + x*a1;
}

double hornerFunction( double x, double a0, double a1, double a2)
{
    return a0 + x*hornerFunction( x, a1, a2);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3)
{
    return a0 + x*hornerFunction( x, a1, a2, a3);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4)
{
    return a0 + x*hornerFunction( x, a1, a2, a3, a4);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                       double a5)
{
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                       double a5, double a6)
{
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                       double a5, double a6, double a7)
{
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6, a7);
}

double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                       double a5, double a6, double a7, double a8)
{
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6, a7, a8);
}

const double a0 = 2.50662823884;
const double a1 = -18.61500062529;
const double a2 = 41.39119773534;
const double a3 = -25.44106049637;
const double b1 = -8.47351093090;
const double b2 = 23.08336743743;
const double b3 = -21.06224101826;
const double b4 = 3.13082909833;
const double c0 = 0.3374754822726147;
const double c1 = 0.9761690190917186;
const double c2 = 0.1607979714918209;
const double c3 = 0.0276438810333863;
const double c4 = 0.0038405729373609;
const double c5 = 0.0003951896511919;
const double c6 = 0.0000321767881768;
const double c7 = 0.0000002888167364;
const double c8 = 0.0000003960315187;

double norminv( double x ) {
    // We use Moro's algorithm
    double y = x - 0.5;

    if (y<0.42 && y>-0.42)
    {
        double r = y*y;

        return y*hornerFunction(r,a0,a1,a2,a3)/hornerFunction(r,1.0,b1,b2,b3,b4);
    }
    else
    {
        double r;
        if (y<0.0)
        {
            r = x;
        }
        else
        {
            r = 1.0 - x;
        }

    double s = log( -log( r ));
    double t = hornerFunction(s,c0,c1,c2,c3,c4,c5,c6,c7,c8);
    if (x>0.5)
        {
            return t;
        } else
        {
            return -t;
        }
    }
}

// Tests

static void testNormCdf()
{
  // test bounds
  ASSERT(normcdf(0.3)>0);
  ASSERT(normcdf(0.3)<1);
  // test extreme values
  ASSERT_APPROX_EQUAL(normcdf(-1e10), 0, 0.001);
  ASSERT_APPROX_EQUAL(normcdf(1e10), 1.0, 0.001);
  // test increasing
  ASSERT(normcdf(0.3)<normcdf(0.5));
  // test symmetry
  ASSERT_APPROX_EQUAL(normcdf(0.3),
    1 - normcdf(-0.3), 0.0001);
  ASSERT_APPROX_EQUAL(normcdf(0.0), 0.5, 0.0001);
  // test inverse
  ASSERT_APPROX_EQUAL(normcdf(norminv(0.3)),
    0.3, 0.0001);
  // test well known value
  ASSERT_APPROX_EQUAL(normcdf(1.96), 0.975, 0.001);
}

static void testNormInv()
{
    ASSERT_APPROX_EQUAL(norminv(0.975), 1.96, 0.01 );
}

void testMatlib()
{
    TEST( testNormInv );
    TEST( testNormCdf );
}
