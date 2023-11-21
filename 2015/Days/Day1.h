#pragma once
#include "../../Common.h"

template <class Output>
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

	~Day1()
	{

	}

	void part1() override
	{
		auto utils = AoCUtilities::getInstance();
		const int32_t& count = utils.count('(', m_output[0]) - utils.count(')', m_output[0]);
		std::cout << count;
	}

	void part2() override
	{
		int32_t count = 0;
		for (int32_t i = 0; i < m_output[0].size(); i++)
		{
			count += (m_output[0][i] == '(') ? 1 : -1;

			if (count == -1) {
				std::cout << i + 1;
				return;
			}
		}
	}

	void setOutput() override
	{
		auto utils = AoCUtilities::getInstance();
		m_output.emplace_back(utils.fileToString(m_file));
	}
};