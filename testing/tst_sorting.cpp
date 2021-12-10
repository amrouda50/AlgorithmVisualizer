#include <QtTest>

// add necessary includes here

class Sorting : public QObject
{
    Q_OBJECT

public:
    Sorting();
    ~Sorting();

private slots:
    void test_case1();

};

Sorting::Sorting()
{

}

Sorting::~Sorting()
{

}

void Sorting::test_case1()
{
QCOMPARE(1 , 2);
}

QTEST_APPLESS_MAIN(Sorting)

#include "tst_sorting.moc"
