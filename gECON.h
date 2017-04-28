#ifndef GECON_H
#define GECON_H

float gECON_SellingPricePerUnit( float constant_a, float constant_b, float demand );
float gECON_Demand( float constant_a, float constant_b, float pricePerUnit );
float gECON_TotalRevenue0( float price, float demand );
float gECON_TotalRevenue1( float constant_a, float constant_b, float demand );
float gECON_TotalCost( float fixedCosts, float variableCostsPerUnit, float demand );
float gECON_Profit0( float totalRevenue, float totalCosts );
float gECON_Profit1( float constant_a, float constant_b, float demand, float fixedCosts, float variableCostsPerUnit );

#endif // GECON_H
