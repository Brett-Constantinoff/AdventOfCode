#pragma once
#include "../../Common.h"

template<class T, class O>
class Day1 : public Day<T, O>
{
public:
	Day1<T,O>(std::string file) : Day<T, O>(file)
	{
		SetOutput();
		Part1();
		Part2();
	}

	~Day1()
	{

	}

	void Part1() override
	{
		auto utils = AoCUtilities::GetInstance();
		const int32_t& count = utils.Count('(', m_output) - utils.Count(')', m_output);
		DisplayPart1Answer(count);
	}

	void Part2() override
	{
		int32_t count = 0;
		for (int32_t i = 0; i < m_output.size(); i++)
		{
			count += (m_output[i] == '(') ? 1 : -1;

			if (count == -1) {
				DisplayPart2Answer(i + 1);
				return;
			}
		}
	}

	void SetOutput() override
	{
		auto utils = AoCUtilities::GetInstance();
		m_output = utils.FileToString(m_file);
	}
};