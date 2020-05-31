#include <memory>

#include <cxxtest/TestSuite.h>
#include <Questions.hpp>
#include <CSVAdapter.hpp>
#include <Person.hpp>

class MyTestSuite1 : public CxxTest::TestSuite {
    public:
        void testQuestions(void){
            TS_ASSERT_EQUALS(questions[0].first.answer, "смелый");
        }
        void testCSVStorage(void){
            int count;
            {
                CSVStorage<Person> csv("test_data.csv");
                std::unique_ptr<Person> person(new Person("1", "2", "3", 0, 1000));
                person->testResult = 4;
                count = csv.Count();
                csv.Append(std::move(person));
                csv.Save();
            } 
            {
                CSVStorage<Person> csv("test_data.csv");
                TS_ASSERT_EQUALS(csv.Count(), count + 1);
                std::unique_ptr<Person> person(new Person("1", "2", "3", 0, 1000));
                person->testResult = 6;
                csv.Append(std::move(person));
                csv.Save();
            }
            {
                CSVStorage<Person> csv("test_data.csv");
                TS_ASSERT_EQUALS(csv.Count(), count + 2);
            }
        }
    
};