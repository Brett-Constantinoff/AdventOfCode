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
            handleInstructions(combo, coord, entry, m_buttons1);
    }

    void part2() override
    {
        std::string combo{};
        Vec2<int32_t> coord{-2, 0};
        for (const auto& entry : m_output)
            handleInstructions(combo, coord, entry, m_buttons2);
    }

    void setOutput() override
    {
        auto utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, '\n');
    }

private:
    void handleInstructions(std::string& combo, Vec2<int32_t>& coord, const std::string& instructions,
       const std::unordered_map<Vec2<int32_t>, std::string>& buttons)
    {
        std::size_t size{ instructions.size() };
        for (std::size_t i{ 0 }; i < size; i++)
        {
            const std::string& instruction{ instructions[i] };
            validButton(buttons, coord, instruction);
        }
        auto it{ buttons.find(coord) };
        if (it != buttons.end()) std::cout << it->second;
    }

    void validButton(const std::unordered_map<Vec2<int32_t>, std::string>& buttons, Vec2<int32_t>& coord, 
        const std::string& instruction)
    {
        if (instruction == "U" && buttons.find({ coord.x, coord.y + 1 }) != buttons.end()) coord.y++;
        else if (instruction == "D" && buttons.find({ coord.x, coord.y - 1 }) != buttons.end()) coord.y--;
        else if (instruction == "R" && buttons.find({ coord.x + 1, coord.y }) != buttons.end()) coord.x++;
        else if (instruction == "L" && buttons.find({ coord.x - 1, coord.y }) != buttons.end()) coord.x--;
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
