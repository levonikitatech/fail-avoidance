#if !defined(QUESTION_HPP)
#define QUESTION_HPP
#include <stdint.h>
#include <string>

struct QuestionString {
    std::string answer;
    uint8_t number;
};

struct Question
{
    QuestionString first;
    QuestionString second;
    QuestionString third;
    uint8_t number;
};

#endif // QUESTION_HPP
