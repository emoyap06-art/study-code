#ifndef STDUDENT_HPP
#define STUDENT_HPP

#include <cstdint>
#include <iostream>

void readStudentData(std::string &name, std::uint_fast16_t &homework, std::uint8_t &midterm, uint8_t &finalExam);

void readScore(const std::string &text, std::uint8_t &value);


#endif