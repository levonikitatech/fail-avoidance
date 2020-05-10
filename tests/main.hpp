#include <cxxtest/TestSuite.h>
#include <Questions.hpp>

class MyTestSuite1 : public CxxTest::TestSuite {
    public:void testAddition(void){
        TS_ASSERT_EQUALS(questions[0].first, "смелый");
    }

};