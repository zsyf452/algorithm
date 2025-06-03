#pragma _FRACTION_H_

#include <cmath>

class Fraction
{
private:
    int numerator;    // 分子
    int denominator;  // 分母

private:
    bool isDecimal(double x);

public:
    Fraction(double _numerator,double _denominator);
    Fraction(double num);


};