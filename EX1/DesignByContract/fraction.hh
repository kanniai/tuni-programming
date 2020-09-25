#ifndef FRACTION_HH
#define FRACTION_HH

class Fraction
{
public:
  Fraction(int numerator, int denominator);
  ~Fraction();

  /*!
   * \brief giveNumerator
   * \pre -
   * \return numerator
   */
  int giveNumerator() const;

  /*!
   * \brief givedenominator
   * \pre denominator != 0
   * \return denominator
   */
  int givedenominator() const;

  /*!
   * \brief giveAsFloating
   * \return fraction in float type
   * \pre -
   */
  double giveAsFloating() const;

  Fraction& operator+=(Fraction f);
  Fraction& operator/=(Fraction f);
// ...

private:
  int numerator_;
  int denominator_;
};

#endif // Fraction_HH
