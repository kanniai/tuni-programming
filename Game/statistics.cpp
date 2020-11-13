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
    std::cout << "Nysse created";
}

void Statistics::nysseLeft()
{

}

void Statistics::nysseRemoved()
{

}

void Statistics::morePassengers(int num)
{

}

}
