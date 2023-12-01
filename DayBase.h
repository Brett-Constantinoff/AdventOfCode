#pragma once
#include <string>
#include <iostream>
#include <functional>

template<class Output = std::string>
class DayBase
{
public:
	DayBase<Output>(const std::string& file) : m_file{ file }
	{
		const std::size_t slash{ m_file.find_last_of("/") };
		std::string day{ m_file.substr(slash + 1) };
		const std::size_t dot{ day.find(".") };
		m_name = day.substr(0, dot);
		m_name[0] -= ('a' - 'A');
	}
	virtual ~DayBase() {};

	virtual void part1() = 0;
	virtual void part2() = 0;
	virtual void setOutput() = 0;

    const std::string& getName() const { return m_name; }

protected:
	std::string m_file{};
	std::vector<Output> m_output{};
	std::string m_name{};
};