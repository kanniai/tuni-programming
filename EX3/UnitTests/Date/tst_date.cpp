#include <QtTest>
#include "date.hh"

// add necessary includes here

class DateTest : public QObject
{
    Q_OBJECT

public:

    DateTest();

private Q_SLOTS:
    void weekday();
    void weekday_data();
    void test_month();
};

DateTest::DateTest()
{
}

Q_DECLARE_METATYPE(Date::Weekday);

void DateTest::test_month()
{
    QFETCH(unsigned int, day);
    QFETCH(unsigned int, month);
    QFETCH(unsigned int, year);

    Date d(day, month, year);
    QCOMPARE(d.giveDay(), std::string("Monday"));
}

void DateTest::weekday()
{
   // This method tests a row of the test matrix generated by the method weekday_data.
   // It is called automatically for each row of the matrix

   // Fetching data from the matrix, variables are created automatically
   QFETCH(unsigned int, day);
   QFETCH(unsigned int, month);
   QFETCH(unsigned int, year);
   QFETCH(Date::Weekday, weekday);

   // Performing the test
   Date d(day, month, year);
   QVERIFY2(d.giveWeekday() == weekday, "Wrong weekday");
}

void DateTest::weekday_data()
{
    // This method defines the test matrix for the weekday test and generates the desired test cases there

    // Defining columns for the test matrix (types and names)
    QTest::addColumn<unsigned int>("day");
    QTest::addColumn<unsigned int>("month");
    QTest::addColumn<unsigned int>("year");
    QTest::addColumn<Date::Weekday>("weekday");

    // Generating test cases for the test matrix, 3u etc. are needed since the type is unsigned
    QTest::newRow("today")      << 3u  << 2u  << 2014u << Date::MONDAY;
    QTest::newRow("last Christmas") << 24u << 12u << 2013u << Date::TUESDAY;
    QTest::newRow("next May Day")  << 1u  << 5u  << 2014u << Date::THURSDAY;
    QTest::newRow("end of the year")<< 31u << 12u << 2013u << Date::TUESDAY;
    QTest::newRow("new year")  << 1u  << 1u  << 2014u << Date::WEDNESDAY;
}

QTEST_APPLESS_MAIN(DateTest)

#include "tst_date.moc"
