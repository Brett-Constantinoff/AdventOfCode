#pragma once
#include "../../Common.h"

template<class Output>
class Day4 : public DayBase<Output>
{
public:
    Day4<Output>(std::string file) : DayBase(file)
    {
        auto& utils = AoCUtilities::getInstance();
        utils.display([this]() { this->part1(); }, false);
        utils.display([this]() { this->part2(); }, true);
    }

    ~Day4() {}

    void part1() override
    {
        setOutput();
        auto& utils = AoCUtilities::getInstance();
        int32_t sum{ 0 };
        for (const auto& line : m_output)
            sum += processRoom(utils.dataFromStr<Output>(line, "-"));
        std::cout << sum;
    }

    void part2() override
    {
    
    }

    void setOutput() override
    {
        auto utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, '\n');
    }

private:
    int32_t processRoom(const std::vector<std::string>& roomData)
    {
        const std::vector<std::string>& idAndCheckSum{ processIdAndCheckSum(roomData.back())};

        return 0;
    }

    const std::vector<std::string> processIdAndCheckSum(const std::string& idAndCheckSum)
	{
		const auto& parsed{ AoCUtilities::getInstance().dataFromStr<std::string>(idAndCheckSum, "[") };
		const std::string& checkSum{ std::move(parsed[0]) };
		std::string commonLetters{ parsed[1] };
		commonLetters.pop_back();
        return { checkSum, std::move(commonLetters) };
	}
};
