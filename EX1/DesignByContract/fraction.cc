#include "fraction.hh"


int Fraction::giveNumerator() const
{
    return numerator_;
}

int Fraction::givedenominator() const
{
    if (denominator_ == 0) {
        return -1;
    }
    return denominator_;
}

double Fraction::giveAsFloating() const
{
    return double(numerator_/denominator_);
}
