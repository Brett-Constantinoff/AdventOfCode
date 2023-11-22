#pragma once
#include "../../Common.h"

template<class Output>
class Day3 : public DayBase<Output>
{
public:
    Day3<Output>(std::string file) : DayBase(file)
    {
        auto& utils = AoCUtilities::getInstance();
        utils.display([this]() { this->part1(); }, false);
        utils.display([this]() { this->part2(); }, true);
    }

    ~Day3() {}

    void part1() override
    {
        setOutput();
        const std::size_t size{ m_output.size() };
        int32_t valid{};
        for (std::size_t i{ 0 }; i < size - 3; i += 3)
        {
            if (isValidTriangle(m_output[i], m_output[i + 1], m_output[i + 2]))
				valid++;
        }
        std::cout << valid;
    }

    void part2() override
    {
        const std::size_t size{ m_output.size() };
        int32_t valid{};
        for (std::size_t i{ 0 }; i < size - 8; i += 9)
        {
            if (isValidTriangle(m_output[i], m_output[i + 3], m_output[i + 6])) valid++;
            if (isValidTriangle(m_output[i + 1], m_output[i + 4], m_output[i + 7])) valid++;
            if (isValidTriangle(m_output[i + 2], m_output[i + 5], m_output[i + 8])) valid++;
        }
        std::cout << valid;
    }

    void setOutput() override
    {
        auto utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, ' ', "", strToIntConverter);
    }

private:
    bool isValidTriangle(int32_t a, int32_t b, int32_t c)
	{
		return (a + b > c) && (a + c > b) && (b + c > a);
	}
};
