#include "Fraction.h"


Fraction::Fraction(double _numerator,double _denominator)
{
    

}


Fraction::Fraction(double num)
{


}



bool Fraction::isDecimal(double x)
{
    double int_part;
    return std::modf(x, &int_part) != 0.0; 
}