#pragma once
#include <string>
#include <iostream>
#include <functional>

#include "AoCUtilities.h"

template<class Output>
class DayBase
{
public:
	DayBase<Output>(const std::string& file) : m_file{ file } {}
	virtual ~DayBase() {};

	virtual void part1() = 0;
	virtual void part2() = 0;
	virtual void setOutput() = 0;

protected:
	std::string m_file{};
	Output m_output{};
};