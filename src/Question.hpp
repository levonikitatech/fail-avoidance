#if !defined(QUESTION_HPP)
#define QUESTION_HPP
#include <stdint.h>
#include <string>

struct Question
{
    std::string first;
    std::string second;
    std::string third;
    uint8_t number;
};

#endif // QUESTION_HPP
