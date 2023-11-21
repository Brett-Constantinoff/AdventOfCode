#pragma once
#include "../../Common.h"

template <class Output>
class Day2 : public DayBase<Output>
{
public:
	Day2<Output>(std::string file) : DayBase(file)
	{
		auto& utils = AoCUtilities::getInstance();
		setOutput();

		utils.display([this]() { this->part1(); }, false);
		utils.display([this]() { this->part2(); }, true);
	}

	~Day2()
	{

	}

	void part1() override
	{
		int32_t area{};
		std::vector<int32_t> nums{};
		nums.reserve(3);

		auto& utils = AoCUtilities::getInstance();
		for (const auto& entry : m_output)
		{
			nums = utils.dataFromStr<int32_t>(entry, strToIntConverter, "x");
		    area += 2 * nums[0] * nums[1] + 2 * nums[1] * nums[2] + 2 * nums[2] * nums[0];
			area += std::min({ nums[0] * nums[1], nums[1] * nums[2], nums[2] * nums[0] });
		}
		std::cout << area;
	}

	void part2() override
	{
		int32_t ribbon{};
		std::vector<int32_t> nums{};
		nums.reserve(3);

		auto& utils = AoCUtilities::getInstance();
		for (const auto& entry : m_output)
		{
			nums = utils.dataFromStr<int32_t>(entry, strToIntConverter, "x");
			ribbon += 2 * std::min({ nums[0] + nums[1], nums[1] + nums[2], nums[2] + nums[0] });
			ribbon += (nums[0] * nums[1] * nums[2]);
		}
		std::cout << ribbon;
	}

	void setOutput() override
	{
		auto utils = AoCUtilities::getInstance();
		m_output = utils.fileToVector<Output>(m_file, '\n');
	}
};