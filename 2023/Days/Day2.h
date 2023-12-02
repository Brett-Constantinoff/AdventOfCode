#pragma once
#include "../../Common.h"

template <class Output = std::string>
class Day2 : public DayBase<Output>
{
public:
	Day2(const std::string& file) : DayBase<Output>(file)
	{
		AoCUtilities::getInstance().display(*this);
	}
	~Day2() {}

	void part1() override
	{
		int32_t sum{};
		for (const auto& line : this->m_output)
			sum += isValid(line);
	}

	void part2() override
	{
		int32_t sum{};
		for (const auto& line : this->m_output)
			sum += getSum(line);
	}

	void setOutput() override
	{
		this->m_output = AoCUtilities::getInstance().fileToVector<Output>(this->m_file, '\n');
	}

private:
	int32_t isValid(const std::string& line)
	{
		bool possible{ true };
		std::istringstream iss{ line };
		int32_t id;
		iss.ignore(5) >> id;
		iss.ignore(2);
		for (std::string token{}; std::getline(iss, token, ';'); )
		{
			std::replace(token.begin(), token.end(), ',', ' ');
			std::istringstream cubes{ token };
			int32_t count{};
			std::string color{};

			while (cubes >> count >> color)
			{
				if (color == "red" && count > 12 ||
					color == "blue" && count > 14 ||
					color == "green" && count > 13)
				{
					possible = false;
					break;
				}
			}
			if (!possible) return 0;
		}
		return id;
	}

	int32_t getSum(const std::string& line)
	{
		std::istringstream iss{ line };
		std::string toIgnore{};
		iss >> toIgnore;
		iss >> toIgnore;
		int32_t maxB{ 1 };
		int32_t maxR{ 1 };
		int32_t maxG{ 1 };

		for (std::string token{}; std::getline(iss, token, ';');)
		{
			std::replace(token.begin(), token.end(), ',', ' ');
			std::istringstream cubes{ token };
			int32_t count{};
			std::string color{};

			while (cubes >> count >> color)
			{
				if (color == "red") maxR = std::max(maxR, count);
				if (color == "blue") maxB = std::max(maxB, count);
				if (color == "green") maxG = std::max(maxG, count);
			}
		}
		return (maxB * maxR * maxG);
	}
};