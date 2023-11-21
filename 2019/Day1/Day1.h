#pragma once
#include "../../Common.h"

template<class Output>
class Day1 : public DayBase<Output>
{
public:
    Day1(std::string file) : DayBase(file)
    {
        auto& utils = AoCUtilities::getInstance();
        setOutput();

        utils.display([this]() { this->part1(); }, false);
        utils.display([this]() { this->part2(); }, true);
    }
    ~Day1() {}

    void part1() override
    {
        auto& utils = AoCUtilities::getInstance();
        int32_t sum{};
        for (const auto& entry : m_output)
        {
            int32_t mass{ (entry / 3) - 2};
            sum += mass;
        }
        std::cout << sum;
    }

    void part2() override
    {
        auto& utils = AoCUtilities::getInstance();
        int32_t sum{};
        for (const auto& entry : m_output)
            sum += recurse(entry);
        std::cout << sum;
    }

    void setOutput() override
    {
        auto& utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, '\n', [&utils](const std::string& str) -> Output
            {
                return utils.strToInt(str);
            }
        );
    }

private:
    int32_t recurse(int32_t entry)
    {
        const int32_t fuel{ (entry / 3) - 2 };

        if (fuel <= 0) return 0;

        int32_t additionalFuel{ std::max(0, recurse(fuel)) };
        return fuel + additionalFuel;
    }
};
