#include "Days.h"

int main()
{
    auto& timer = Timer::getInstance();
    timer.start();

    Day1<std::string> day1("inputs/day1.txt");
    //Day2<std::string> day2("inputs/day2.txt");
    //Day3<int32_t> day3("inputs/day3.txt");
    //Day4<std::string> day4("inputs/day4.txt");

    timer.stop("\nAll days");
    return 0;
}
