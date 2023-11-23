#pragma once
#include "../../Common.h"

template<class Output>
class Day4 : public DayBase<Output>
{
public:
    Day4<Output>(std::string file) : DayBase(file)
    {
        AoCUtilities::getInstance().display(*this);
    }

    ~Day4() {}

    void part1() override
    {
        auto& utils = AoCUtilities::getInstance();
        std::map<char, int32_t> letters{};
        int32_t sum{ 0 };
        for (const auto& line : m_output)
            sum += processRoom(utils.dataFromStr<Output>(line, "-"), letters);
        //std::cout << "Part1 - " << sum << '\n';
    }

    void part2() override
    {
        auto& utils = AoCUtilities::getInstance();
        for (const auto& line : m_output)
        {
            int32_t res{ decryptRoom(utils.dataFromStr<Output>(line, "-")) };
            if (res != -1) 
            {
                //std::cout << "Part2 - " << res << "\n";
                return;
            }
        }
    }

    void setOutput() override
    {
        auto utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, '\n');
    }

private:
    int32_t decryptRoom(std::vector<std::string>& roomData)
    {
        const int32_t id{ strToIntConverter(processIdAndCheckSum(roomData.back())[0]) };
        std::string room{};
        std::size_t size{ roomData.size() };
        for (std::size_t i{0}; i < size - 1; i++)
        {
            for (auto& c : roomData[i])
                room += (c - 'a' + id) % 26 + 'a';
            room += ' ';
        }
        if (room.find("north") != std::string::npos) return id;
        return -1;
    }

    int32_t processRoom(std::vector<std::string>& roomData, std::map<char, int32_t>& letters)
    {
        std::size_t size{ roomData.size() };
        for (std::size_t i{ 0 }; i < size - 1; i++)
        {
            for (auto& c : roomData[i])
                letters[c]++;
        }
        return validRoom(letters, processIdAndCheckSum(roomData.back()));
    }

    std::vector<std::string> processIdAndCheckSum(const std::string& idAndCheckSum) 
	{
		const auto& parsed{ AoCUtilities::getInstance().dataFromStr<std::string>(idAndCheckSum, "[") };
		const std::string& checkSum{ std::move(parsed[0]) };
		std::string commonLetters{ parsed[1] };
		commonLetters.pop_back();
        return { checkSum, std::move(commonLetters) };
	}

    int32_t validRoom(std::map<char, int32_t>& letters, std::vector<std::string>& idAndCheckSum)
    {
        std::vector<std::pair<char, int32_t>> sorted(letters.begin(), letters.end());
        std::sort(sorted.begin(), sorted.end(),
            [](const auto& a, const auto& b) {
                return (a.second > b.second) || (a.second == b.second && a.first < b.first);
            });
        std::string str{};
        for (const auto& pair : sorted) 
        {
            str += pair.first;
            if (str.size() == 5) 
                break;
        }
        letters.clear();
        if (str == idAndCheckSum[1]) return strToIntConverter(idAndCheckSum[0]);
        return 0;
    }
};
