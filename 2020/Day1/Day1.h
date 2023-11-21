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

    // 2 sum pointer approach
    void part1() override
    {
        int32_t target{ 2020 };
        for (int32_t i = 0, j = m_output.size() - 1; i < j;)
        {
            if (m_output[i] + m_output[j] == target)
            {
                std::cout << m_output[i] * m_output[j];
                return;
            }
            if (m_output[i] + m_output[j] < target) i++;
            if (m_output[i] + m_output[j] > target) j--;
        }
    }

    // 3 sum pointer approach
    void part2() override
    {
        int32_t target{ 2020 };
        std::vector<Output> res{};
        int32_t sum{ 1 };
        for (int32_t i = 0, j = i + 1, k = m_output.size() - 1; i < m_output.size(); ++i)
        {
            while (j < k)
                movePointers(res, target, i, j, k);
        }
        for (const auto& num : res) sum *= num;
        std::cout << sum;
    }

    void setOutput() override
    {
        auto& utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, '\n', strToIntConverter);
        std::sort(m_output.begin(), m_output.end());
    }

private:
    void movePointers(std::vector<Output>& res, int32_t target, int32_t i, int32_t& j, int32_t& k)
    {
        if (m_output[i] + m_output[j] + m_output[k] == target)
        {
            res.push_back(m_output[i]);
            res.push_back(m_output[j]);
            res.push_back(m_output[k]);
            ++j;
        }
        else if (m_output[i] + m_output[j] + m_output[k] < target)
            ++j;
        else
            --k;
    }
};
