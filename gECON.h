#ifndef GECON_H
#define GECON_H

struct breakEvenPoints {
    double low;
    double high;
};

typedef struct breakEvenPoints BEP;

double gECON_SellingPricePerUnit( double constant_a, double constant_b, double demand );
double gECON_Demand( double constant_a, double constant_b, double pricePerUnit );
double gECON_TotalRevenue0( double price, double demand );
double gECON_TotalRevenue1( double constant_a, double constant_b, double demand );
double gECON_TotalCost0( double fixedCosts, double variableCosts );
double gECON_TotalCost1( double fixedCosts, double variableCostsPerUnit, double demand );
double gECON_Profit( double totalRevenue, double totalCosts );
double gECON_RevenueMaximizedDemand( double constant_a, double constant_b );
BEP gECON_BreakEvenPoints( double constant_a, double constant_b, double variableCostsPerUnit, double fixedCosts );

#endif // GECON_H

