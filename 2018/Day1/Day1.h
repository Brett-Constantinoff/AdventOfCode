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
        int32_t res{};

        for (const auto& entry : m_output)
            calculateResult(entry, res, utils);
        std::cout << res;
    }

    void part2() override
    {
        auto& utils = AoCUtilities::getInstance();
        std::set<int32_t> seen{};
        int32_t res{};
        const size_t size{ m_output.size() };

        for (int32_t i = 0; ; ++i)
        {
            const auto& curr{ m_output[i % size] };
            calculateResult(curr, res, utils);

            if (seen.find(res) != seen.end())
            {
                std::cout << res;
                return;
            }
            seen.emplace(res);
        }
    }

    void setOutput() override
    {
        auto& utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, '\n');
    }

private:
    void calculateResult(const std::string& str, int32_t& res, AoCUtilities& utils)
    {
        const char sign{ str[0] };
        const int32_t change = utils.strToInt(str.substr(1));
        res = (sign == '+') ? res + change : res - change;
    }
};
