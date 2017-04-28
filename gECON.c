// FILE: 							  		gECON.c
// DESCRIPTION: Describes various theoretical economical mathematical functionalities in the galcor program
//-----------------------------------------------------------------------------------------------------------
#include <stdio.h>
//-----------------------------------------------------------------------------------------------------------
// Function Prototypes
float gECON_SellingPricePerUnit( float constant_a, float constant_b, float demand );
float gECON_Demand( float constant_a, float constant_b, float pricePerUnit );
float gECON_TotalRevenue0( float price, float demand );
float gECON_TotalRevenue1( float constant_a, float constant_b, float demand );
float gECON_TotalCost( float fixedCosts, float variableCostsPerUnit, float demand );
float gECON_Profit0( float totalRevenue, float totalCosts );
float gECON_Profit1( float constant_a, float constant_b, float demand, float fixedCosts, float variableCostsPerUnit );
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gECON_SellingPricePerUnit
// DESCRIPTION:
// -- Returns the selling price per unit given constants a and b and the demand D of each unit
// MATHEMATICAL EQUATION:
// -- p = a - bD
// -- -- p 		:= Price per unit
// -- -- D 		:= "Demand" - Total number of units sold
// -- -- a, b 	:= Constants
// ARGUMENTS:
// -- demand    	:= D
// -- constant_a    := a
// -- constant_b    := b
// INTERMEDIATE VARIABLES:
// -- pricePerUnit  := p
// RETURN:
// -- < float > pricePerUnit
// ERROR:
// -- 0 <= D <= ( a / b )
// -- a <= 0
// -- b <= 0
*/
float gECON_SellingPricePerUnit( float constant_a, float constant_b, float demand )
{
    float pricePerUnit;
    pricePerUnit = constant_a - constant_b * demand;
    return pricePerUnit;
} // END FUNCTION gECON_SellingPricePerUnit
//-----------------------------------------------------------------------------------------------------------
/*-----------------------------------------------------------------------------------------------------------
// FUNCTION: gECON_Demand
// DESCRIPTION:
// -- Returns the demand given constants a and b, and the price per unit p
// MATHEMATICAL EQUATION:
// -- D = ( a - p ) / b
// -- -- p      := Price per unit
// -- -- D      := "Demand" - Total number of units sold
// -- -- a, b   := Constants
// ARGUMENTS:
// -- pricePerUnit  := p
// -- constant_a    := a
// -- constant_b    := b
// INTERMEDIATE VARIABLES:
// -- demand        := D
// RETURN:
// -- < float > Demand
// ERROR:
// -- b != 0
*/
float gECON_Demand( float constant_a, float constant_b, float pricePerUnit )
{
    float demand;
    demand = ( constant_a - pricePerUnit ) / constant_b;
    return demand;
} // END FUNCTION gECON_Demand
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gECON_TotalRevenue0
// DESCRIPTION:
// -- Returns the total revenue given the price per unit and the demand
// MATHEMATICAL EQUATION:
// -- TR = pD
// -- -- TR := Total Revenue
// -- -- p  := Price per Unit
// -- -- D  := "Demand" - Total number of units sold
// ARGUMENTS:
// -- pricePerUnit  := p
// -- demand        := D
// INTERMEDIATE VARIABLES:
// -- totalRevenue  := TR
// RETURN:
// -- < float > totalRevenue
// ERROR:
// -- NONE
*/
float gECON_TotalRevenue0( float pricePerUnit, float demand )
{
    float totalRevenue;
    totalRevenue = pricePerUnit * demand;
    return totalRevenue;
} // END FUNCTION gECON_TotalRevenue0
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gECON_TotalRevenue1
// DESCRIPTION:
// -- Returns the total revenue given the constants a and b, and the demand
// MATHEMATICAL EQUATION:
// -- TR = ( a - bD )D = aD - bD^2
// -- -- TR     := Total revenue earned
// -- -- D      := "Demand" - Total number of units sold
// -- -- a, b   := Constants
// ARGUMENTS:
// -- demand        := D
// -- constant_a    := a
// -- constant_b    := b
// INTERMEDIATE VARIABLES:
// -- totalRevenue  := TR
// RETURN:
// -- < float > totalRevenue
// ERROR:
// -- 0 <= D <= ( a / b )
// -- a > 0
// -- b > 0
*/
float gECON_TotalRevenue1( float constant_a, float constant_b, float demand )
{
    float totalRevenue;
    totalRevenue = ( constant_a - constant_b * demand ) * demand;
    return totalRevenue;
} // END FUNCTION gECON_TotalRevenue1
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gECON_TotalCost
// DESCRIPTION:
// -- Returns the total costs of production given the fixed costs, the variable costs per unit, and the
// --   total number of units produced
// MATHEMATICAL EQUATION:
// -- C_T = C_F + ( c_v * D )
// -- -- C_T    := Total costs of production
// -- -- C_F    := Total fixed ( initial ) costs of production
// -- -- c_v    := Variable costs per unit produced
// -- -- D      := "Demand" - Total number of units sold
// ARGUMENTS:
// -- fixedCosts            := C_F
// -- variableCostsPerUnit  := c_v
// -- demand                := D
// INTERMEDIATE VARIABLES:
// -- totalCosts    := C_T
// RETURN:
// -- < float > totalCosts
// ERROR:
// -- C_F <= 0
// -- c_v <= 0
// -- D <= 0
*/
float gECON_TotalCost( float fixedCosts, float variableCostsPerUnit, float demand )
{
	float totalCosts;
	totalCosts = fixedCosts + variableCostsPerUnit * demand;
	return totalCosts;
} // END FUNCTION --
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gECON_Profit0
// DESCRIPTION:
// -- Returns the profit of a production given the total revenue and the total costs
// MATHEMATICAL EQUATION:
// -- P = TR - C_T
// -- -- P      := Profit
// -- -- TR     := Total Revenue
// -- -- C_T    := Total Costs
// ARGUMENTS:
// -- totalRevenue  := TR
// -- totalCosts    := C_T
// INTERMEDIATE VARIABLES:
// -- profit        := P
// RETURN:
// -- < float > profit
// ERROR:
// -- TR <= 0
*/
float gECON_Profit0( float totalRevenue, float totalCosts )
{
    float profit;
	profit = totalRevenue - totalCosts;
	return profit;
} // END FUNCTION gECON_Profit0
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gECON_Profit1
// DESCRIPTION:
// -- Returns the profit of a production given: the constants a and b, the number of units sold, the fixed
// --   ( initial ) costs of the production, and the variable costs per unit.
// MATHEMATICAL EQUATION:
// -- P = -bD^2 + ( a - c_v )D - C_F
// -- -- P      := Profit made from the production
// -- -- D      := "Demand" - Total number of units sold
// -- -- C_F    := Total fixed ( initial ) costs of the production
// -- -- c_v    := Variable costs per unit during production
// -- -- a, b   := Constants
// ARGUMENTS:
// -- constant_a            := a
// -- constant_b            := b
// -- demand                := D
// -- fixedCosts            := C_F
// -- variableCostsPerUnit  := c_v
// INTERMEDIATE VARIABLES:
// -- profit    := P
// -- profit = profit0 + profit1
// RETURN:
// -- < float > profit
// ERROR:
// -- 0 >= D >= ( a / b )
// -- D, C_F, c_v, a, b <= 0
*/
float gECON_Profit1( float constant_a, float constant_b, float demand, float fixedCosts, float variableCostsPerUnit )
{
	float profit;
	float profit0;  // Used to break total formula...
	float profit1;  // ...into smaller pieces

    profit0 = -constant_b * ( demand * demand );
    profit1 = ( constant_a - variableCostsPerUnit ) * demand;
    profit = profit0 + profit1 - fixedCosts;

    return profit;
} // END FUNCTION --
//-----------------------------------------------------------------------------------------------------------
