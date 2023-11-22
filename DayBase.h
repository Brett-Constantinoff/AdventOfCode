#pragma once
#include <string>
#include <iostream>
#include <functional>

template<class Output>
class DayBase
{
public:
	DayBase<Output>(const std::string& file) : m_file{ file } 
	{
		m_name = m_file.substr(0, input.find("."));
		m_name[0].std::toupper();
	}
	virtual ~DayBase() {};

	virtual void part1() = 0;
	virtual void part2() = 0;
	virtual void setOutput() = 0;

	[inline]
    const std::string& getName() const { return m_name; }

protected:
	std::string m_file{};
	std::vector<Output> m_output{};
	std::string m_name{};
};