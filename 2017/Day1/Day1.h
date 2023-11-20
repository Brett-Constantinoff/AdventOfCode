#pragma once
#include "../../Common.h"

template<class T, class O>
class Day1 : public Day<T, O>
{
public:
    Day1<T, O>(std::string file) : Day<T, O>(file)
    {
        SetOutput();
        Part1();
        Part2();
    }

    ~Day1() {}

    void Part1() override
    {
        DisplayPart1Answer(CaptchaSum(1));
    }

    void Part2() override
    {
        DisplayPart2Answer(CaptchaSum(m_output.size() / 2));
    }

    void SetOutput() override
    {
        auto utils = AoCUtilities::GetInstance();
        m_output = utils.FileToVector(m_file);
    }

private:
    int32_t CaptchaSum(const int32_t& step)
    {
        int32_t sum{};
        auto utils = AoCUtilities::GetInstance();
        for (int32_t i = 0; i < m_output.size(); i++)
        {
            int32_t curr{ utils.StrToInt(m_output[i]) };
            int32_t next{ utils.StrToInt(m_output[(i + step) % m_output.size()]) };

            if (curr == next)
                sum += curr;
        }
        return sum;
    }
};
