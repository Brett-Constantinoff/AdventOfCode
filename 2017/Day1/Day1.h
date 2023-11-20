#pragma once
#include "../../Common.h"

template<class Output>
class Day1 : public DayBase<Output>
{
public:
    Day1<Output>(std::string file) : DayBase(file)
    {
        auto& utils = AoCUtilities::getInstance();
        setOutput();

        utils.display([this]() { this->part1(); }, false);
        utils.display([this]() { this->part2(); }, true);
    }
    ~Day1() {}

    void part1() override
    {
       std::cout << captchaSum(1);
    }

    void part2() override
    {
        std::cout << captchaSum(m_output.size() / 2);
    }

    void setOutput() override
    {
        auto& utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector(m_file);
    }

private:
    int32_t captchaSum(const int32_t& step)
    {
        auto& utils = AoCUtilities::getInstance();
        int32_t sum{};
        for (int32_t i = 0; i < m_output.size(); i++)
        {
            int32_t curr{ utils.strToInt(m_output[i]) };
            int32_t next{ utils.strToInt(m_output[(i + step) % m_output.size()]) };

            if (curr == next)
                sum += curr;
        }
        return sum;
    }
};
