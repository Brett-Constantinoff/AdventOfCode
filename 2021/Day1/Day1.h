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
        int32_t res{ 0 };
        const std::size_t size{ m_output.size() };

        for (std::size_t i{ 0 }; i < size - 1; ++i)
        {
            if (m_output[i] < m_output[i + 1]) ++res;
        }
        std::cout << res;
    }

    void part2() override
    {
        int32_t res{ 0 };
        auto& utils{ AoCUtilities::getInstance() };
        const std::size_t size{ m_output.size() - 3 };

        for (std::size_t i{ 0 }; i < size; ++i)
        {
            int32_t curr{ m_output[i] + m_output[i + 1] + m_output[i + 2] };
            int32_t next{ m_output[i + 1] + m_output[i + 2] + m_output[i + 3] };

            if (curr < next) ++res;
        }
        std::cout << res;
    }

    void setOutput() override
    {
        auto& utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, '\n', strToIntConverter);
    }
};
