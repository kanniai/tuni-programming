#include "string.hh"
#include <QString>


int String::length() const
{
    return length_;
}

void String::clear()
{
    length_ = 0;
}

String String::substr(int location, int amount) const
{
    std::string str;
    for (int i = 0; i < amount; ++i) {
        str += chars_.at(location + i);
    }
}



