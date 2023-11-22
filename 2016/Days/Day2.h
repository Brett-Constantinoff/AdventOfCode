#pragma once
#include "../../Common.h"

template<class Output>
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

    ~Day2() {}

    void part1() override
    {
        std::string combo{};
        Vec2<int32_t> coord{};
        for (const auto& entry : m_output)
            handleInstructions(combo, coord, entry, false);
    }

    void part2() override
    {
        std::string combo{};
        Vec2<int32_t> coord{-2, 0};
        for (const auto& entry : m_output)
            handleInstructions(combo, coord, entry, true);
    }

    void setOutput() override
    {
        auto utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, '\n');
    }

private:
    void handleInstructions(std::string& combo, Vec2<int32_t>& coord, const std::string& instructions,
        const bool& part2)
    {
        std::size_t size{ instructions.size() };
        for (std::size_t i{ 0 }; i < size; i++)
        {
            const std::string& instruction{ instructions[i] };
            validButton(part2, coord, instruction);
        }
        if (part2)
        {
            auto it{ m_buttons2.find(coord) };
            if (it != m_buttons2.end()) std::cout << it->second;
        }
        else
        {
            auto it{ m_buttons1.find(coord) };
            if (it != m_buttons1.end()) std::cout << it->second;
        }
    }

    void validButton(const bool& part2, Vec2<int32_t>& coord, const std::string& instruction) 
    {
        if (!part2)
        {
            if (instruction == "U" && m_buttons1.find({ coord.x, coord.y + 1 }) != m_buttons1.end()) coord.y++;
            else if (instruction == "D" && m_buttons1.find({ coord.x, coord.y - 1 }) != m_buttons1.end()) coord.y--;
            else if (instruction == "R" && m_buttons1.find({ coord.x + 1, coord.y }) != m_buttons1.end()) coord.x++;
            else if (instruction == "L" && m_buttons1.find({ coord.x - 1, coord.y }) != m_buttons1.end()) coord.x--;
        }
        else
        {
            if (instruction == "U" && m_buttons2.find({ coord.x, coord.y + 1 }) != m_buttons2.end()) coord.y++;
            else if (instruction == "D" && m_buttons2.find({ coord.x, coord.y - 1 }) != m_buttons2.end()) coord.y--;
            else if (instruction == "R" && m_buttons2.find({ coord.x + 1, coord.y }) != m_buttons2.end()) coord.x++;
            else if (instruction == "L" && m_buttons2.find({ coord.x - 1, coord.y }) != m_buttons2.end()) coord.x--;
        }
    }

private:
    std::unordered_map<Vec2<int32_t>, std::string> m_buttons1
    {
        {{-1, 1}, "1"},
        {{0, 1}, "2"},
        {{1, 1}, "3"},

        {{-1, 0}, "4"},
        {{0, 0}, "5"},
        {{1, 0}, "6"},

        {{-1, -1}, "7"},
        {{0, -1}, "8"},
        {{1, -1}, "9"}
    };

    std::unordered_map<Vec2<int32_t>, std::string> m_buttons2
    {
        {{-1, 1}, "2"},
        {{0, 1}, "3"},
        {{1, 1}, "4"},

        {{-1, 0}, "6"},
        {{0, 0}, "7"},
        {{1, 0}, "8"},

        {{-1, -1}, "A"},
        {{0, -1}, "B"},
        {{1, -1}, "C"},

        {{-2, 0}, "5"},
        {{0, -2}, "D"},
        {{2, 0}, "9"},
        {{0, 2}, "1"},
    };
};
