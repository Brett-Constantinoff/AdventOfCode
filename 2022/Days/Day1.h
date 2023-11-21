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
        std::cout << greatestN(1);
    }

    void part2() override
    {
        std::cout << greatestN(3);
    }

    void setOutput() override
    {
        auto& utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, '\n', "-1", strToIntConverter);
    }

private:
    int32_t greatestN(int32_t n)
    {
        std::vector<int32_t> sums{};
        int32_t curr{};
        for (const auto& entry : m_output)
            handleEntry(sums, curr, entry);

        const std::size_t size{ sums.size() };
        std::sort(sums.begin(), sums.end());
        
		return calcSum(sums, n);
    }

    static void handleEntry(std::vector<int32_t>& sums, int32_t& curr, const int32_t entry)
    {
        if (entry == -1)
        {
			sums.push_back(curr);
			curr = 0;
		}
		else curr += entry;
	}

    static int32_t calcSum(std::vector<int32_t>& sums, int32_t n)
    {
        int32_t res{};
        while (n > 0)
        {
            res += sums[sums.size() - n];
            --n;
        }
        return res;
    }
};
