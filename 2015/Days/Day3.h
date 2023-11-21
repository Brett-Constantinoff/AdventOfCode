#pragma once
#include "../../Common.h"

template <class Output>
class Day3 : public DayBase<Output>
{
public:
    Day3<Output>(std::string file) : DayBase(file)
    {
        auto& utils = AoCUtilities::getInstance();
        setOutput();

        utils.display([this]() { this->part1(); }, false);
        utils.display([this]() { this->part2(); }, true);
    }

    ~Day3()
    {
    }

    void part1() override
    {
        Vec2<int32_t> santa{};
        int32_t presents{ 1 };
        std::unordered_map<Vec2<int32_t>, int32_t> houses{};
        houses[santa] = presents;

        for (const auto& entry : m_output)
            deliverPresent(houses, santa, presents, entry);
        std::cout << presents;
    }

    void part2() override
    {
        Vec2<int32_t> santa{};
        Vec2<int32_t> robot{};
        int32_t presents{ 1 };
        std::unordered_map<Vec2<int32_t>, int32_t> houses{};
        houses[santa] = presents;
        std::size_t size{ m_output.size() };

        for (std::size_t i{ 0 }; i < size; i++)
        {
            if (i % 2 == 0)
                deliverPresent(houses, santa, presents, m_output[i]);
            else
                deliverPresent(houses, robot, presents, m_output[i]);
        }
        std::cout << presents;
    }

    void setOutput() override
    {
        auto utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file);
    }

private:
    void deliverPresent(std::unordered_map<Vec2<int32_t>, int32_t>& houses, Vec2<int32_t>& location,
        int32_t& presents, const std::string& dir)
    {
        move(location, dir);
        checkHouse(houses, location, presents);
    }

    void move(Vec2<int32_t>& location, const::std::string& dir)
    {
        if (dir == "^") location.y++;
        else if (dir == "v") location.y--;
        else if (dir == ">") location.x++;
        else if (dir == "<") location.x--;
    }

    void checkHouse(std::unordered_map<Vec2<int32_t>, int32_t>& houses, Vec2<int32_t>& location, int32_t& presents)
    {
        if (houses.find(location) == houses.end())
        {
            presents++;
            houses[location] = 1;
        }
    }
};
