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
    void test_case1();

};

StatisticsUnitTest::StatisticsUnitTest()
{

}

StatisticsUnitTest::~StatisticsUnitTest()
{

}

void StatisticsUnitTest::test_case1()
{

}

QTEST_APPLESS_MAIN(StatisticsUnitTest)

#include "tst_statisticsunittest.moc"
