#pragma once
#include "../../Common.h"

template <class Output = std::string>
class Day1 : public DayBase<Output>
{
public:
	Day1(const std::string& file) : DayBase<Output>(file)
	{
		AoCUtilities::getInstance().display(*this);
	}
	~Day1() {}

	void part1() override
	{
		int32_t sum{ 0 };
		for (const auto& line : this->m_output) 
		{
			auto isDigit = [](char ch) { return std::isdigit(ch); };

			auto firstDigitIt { std::find_if(line.begin(), line.end(), isDigit) };
			auto lastDigitIt { std::find_if(line.rbegin(), line.rend(), isDigit) };

			char firstDigit = (firstDigitIt != line.end()) ? *firstDigitIt : '0';
			char lastDigit = (lastDigitIt != line.rend()) ? *lastDigitIt : '0';
			sum += (firstDigit - '0') * 10 + (lastDigit - '0');
		}
		//std::cout << "Part 1 - " << sum << '\n';
	}

	void part2() override
	{
		int32_t sum{ 0 };
		for (const auto& line : this->m_output)
		{
			int32_t left{ 0 };
			int32_t right { static_cast<int32_t>(line.size() - 1) };
			std::string first{};
			std::string last{};
			bool firstFound{ false };
			bool lastFound{ false };
			for (; (left <= line.size() && right >= 0); left++, right--)
			{
				if (!firstFound)
				{
					first += line[left];
					firstFound = checkAndUpdate(first);
				}
				if (!lastFound)
				{
					last.insert(last.begin(), line[right]);
					lastFound = checkAndUpdate(last);
				}
				if (firstFound && lastFound)
				{
					sum += std::stoi(first) * 10 + std::stoi(last);
					break;
				}
			}
		}
		//std::cout << "Part 2 - " << sum << '\n';
	}

	void setOutput() override
	{
		this->m_output = AoCUtilities::getInstance().fileToVector<Output>(this->m_file, '\n');
	}

private:
	bool checkAndUpdate(std::string& num)
	{
		for (const auto& pair : m_nums)
		{
			if (num.find(pair.first) != std::string::npos)
			{
				num = pair.second;
				return true;
			}
		}
		return false;
	}

private:
	const std::unordered_map<std::string, std::string> m_nums
	{
		{"one", "1"},
		{"two", "2"},
		{"three", "3"},
		{"four", "4"},
		{"five", "5"},
		{"six", "6"},
		{"seven", "7"},
		{"eight", "8"},
		{"nine", "9"},

		// wtf
		{"1", "1"},
		{"2", "2"},
		{"3", "3"},
		{"4", "4"},
		{"5", "5"},
		{"6", "6"},
		{"7", "7"},
		{"8", "8"},
		{"9", "9"},
	};
};