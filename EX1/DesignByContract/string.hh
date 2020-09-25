#ifndef STRING_HH
#define STRING_HH

#include <vector>

class String
{
public:
  String();
  ~String();

  /*!
   * \brief length
   * \pre length >= 0
   * \return length of string
   */
  int length() const;

  /*!
   * \brief clear
   * \pre -
   * \post string cleared and length set to 0
   */
  void clear();

  /*!
   * \brief substr
   * \param location
   * \param amount
   * \pre location > 0 && amount > 0
   * \return substring
   */
  String substr(int location, int amount) const;

private:
  std::vector<char> chars_; // Would in reality be implemented e.g. with char* chars_;
  int length_;               // Pidetään kirjaa merkkien määrästä tehokkuussyistä
};

#endif // STRING_HH
