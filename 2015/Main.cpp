#include "Days.h"
#include <memory>

int main()
{
    std::unique_ptr<Day1<int32_t, std::string>> day1 = std::make_unique<Day1<int32_t, std::string>>(std::string{ "2015/inputs/day1Input.txt" });
    return 0;
}
