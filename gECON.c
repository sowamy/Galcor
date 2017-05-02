#include <stdio.h>
#include <math.h>

struct breakEvenPoints {
    double low;
    double high;
};

typedef struct breakEvenPoints BEP;

// Function Prototypes
double gECON_SellingPricePerUnit( double constant_a, double constant_b, double demand );
double gECON_Demand( double constant_a, double constant_b, double pricePerUnit );
double gECON_TotalRevenue0( double price, double demand );
double gECON_TotalRevenue1( double constant_a, double constant_b, double demand );
double gECON_TotalCost0( double fixedCosts, double variableCosts );
double gECON_TotalCost1( double fixedCosts, double variableCostsPerUnit, double demand );
double gECON_Profit( double totalRevenue, double totalCosts );
double gECON_RevenueMaximizedDemand( double constant_a, double constant_b );
BEP gECON_BreakEvenPoints( double constant_a, double constant_b, double variableCostsPerUnit, double fixedCosts );

// Functions
double gECON_SellingPricePerUnit( double constant_a, double constant_b, double demand ){ return constant_a - constant_b * demand; }
double gECON_Demand( double constant_a, double constant_b, double pricePerUnit ){ return ( constant_a - pricePerUnit ) / constant_b; }
double gECON_TotalRevenue0( double pricePerUnit, double demand ){ return pricePerUnit * demand; }
double gECON_TotalRevenue1( double constant_a, double constant_b, double demand ){ return ( constant_a - constant_b * demand ) * demand; }
double gECON_TotalCost0( double fixedCosts, double variableCosts ){ return fixedCosts + variableCosts; }
double gECON_TotalCost1( double fixedCosts, double variableCostsPerUnit, double demand ){ return fixedCosts + variableCostsPerUnit * demand; }
double gECON_Profit( double totalRevenue, double totalCosts ){ return totalRevenue - totalCosts; }
double gECON_RevenueMaximizedDemand( double constant_a, double constant_b ) { return constant_a / ( 2 * constant_b ); }

BEP gECON_BreakEvenPoints( double constant_a, double constant_b, double variableCostsPerUnit, double fixedCosts )
{
    double i0 = - ( constant_a - variableCostsPerUnit );
    double i1 = sqrt( ( ( constant_a - variableCostsPerUnit ) * ( constant_a - variableCostsPerUnit ) - ( 4 * constant_b * fixedCosts ) ) );
    double i2 = 2 * -constant_b;
    BEP out;
    out.high = ( i0 - i1 ) / i2;
    out.low = ( i0 + i1 ) / i2;
    return out;
} // END FUNCTION gECON_BreakEvenPoint
