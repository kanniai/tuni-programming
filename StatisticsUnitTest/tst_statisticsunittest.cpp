#include <QtTest>
#include "statistics.hh"

// add necessary includes here

class StatisticsUnitTest : public QObject
{
    Q_OBJECT

public:
    StatisticsUnitTest();
    ~StatisticsUnitTest();

private slots:
    void testAddAndRemoveNysses();
    void testMorePassengers();

};

StatisticsUnitTest::StatisticsUnitTest()
{

}

StatisticsUnitTest::~StatisticsUnitTest()
{

}

void StatisticsUnitTest::testAddAndRemoveNysses()
{
    StudentSide::Statistics statistics;
    statistics.newNysse();
    statistics.newNysse();
    QCOMPARE(statistics.returnNysses(), 2);
    statistics.newNysse();
    statistics.newNysse();
    QCOMPARE(statistics.returnNysses(), 4);
    statistics.nysseLeft();
    statistics.nysseLeft();
    QCOMPARE(statistics.returnNysses(), 2);
    statistics.nysseRemoved();
    QCOMPARE(statistics.returnNysses(), 1);
}


void StatisticsUnitTest::testMorePassengers()
{
    StudentSide::Statistics statistics;
    statistics.morePassengers(3);
    QCOMPARE(statistics.returnPassengers(), 3);
    statistics.morePassengers(2);
    QCOMPARE(statistics.returnPassengers(), 5);
    QVERIFY(3 > 0);
}

QTEST_APPLESS_MAIN(StatisticsUnitTest)

#include "tst_statisticsunittest.moc"
