#include "statistics.hh"
#include "iostream"

namespace StudentSide
{

Statistics::Statistics()
{}

StudentSide::Statistics::~Statistics()
{}

void Statistics::newNysse()
{
    nysses_++;
}

void Statistics::nysseLeft()
{
    nysses_--;
}

void Statistics::nysseRemoved()
{
    nysses_--;
}
int Statistics::returnNysses()
{
    return nysses_;
}

void Statistics::morePassengers(int num)
{
    //QVERIFY2(num > 1, "num <= 0");
    std::cout << "++ passenger" << passengers_ << std::endl;
    passengers_+= num;
}

}
