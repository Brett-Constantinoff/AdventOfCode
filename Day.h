#pragma once
#include <string>
#include <iostream>

template <class T, class O>
class Day
{
public:
	Day<T, O>(const std::string& file) : m_file{ file } {};
	virtual ~Day() {};

	virtual void Part1() = 0;
	virtual void Part2() = 0;
	virtual void SetOutput() = 0;

	void DisplayPart1Answer(T answer)
	{
		std::cout << "Answer for part 1: " << answer << "\n";
	}

	void DisplayPart2Answer(T answer)
	{
		std::cout << "Answer for part 2: " << answer << "\n";
	}

protected:
	std::string m_file{};
	O m_output{};
};