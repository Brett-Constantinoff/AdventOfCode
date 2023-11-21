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
        deliverPresents(false);
    }

    void part2() override
    {
        deliverPresents(true);
    }

    void setOutput() override
    {
        auto utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file);
    }

private:
    void move(const std::string& dir, Vec2<int32_t>& location)
    {
        if (dir == "^")
            location.y++;
        else if (dir == "v")
            location.y--;
        else if (dir == ">")
            location.x++;
        else if (dir == "<")
            location.x--;
    }

    void deliverPresent(Vec2<int32_t>& location, std::unordered_set<Vec2<int32_t>>& houses, int32_t& presentsDelivered)
    {
        if (houses.find(location) == houses.end())
        {
            houses.insert(location);
            presentsDelivered++;
        }
    }

    void deliverPresents(bool useRoboSanta)
    {
        Vec2<int32_t> origin{};
        Vec2<int32_t> santaLocation{};
        Vec2<int32_t> roboSantaLocation{};
        std::unordered_set<Vec2<int32_t>> houses{ origin };

        int32_t presentsDelivered{ 1 };

        for (int32_t i = 0; i < m_output.size(); i++)
        {
            Vec2<int32_t>& currentLocation = (useRoboSanta && i % 2 == 1) ? roboSantaLocation : santaLocation;

            move(m_output[i], currentLocation);
            deliverPresent(currentLocation, houses, presentsDelivered);
        }

        std::cout << presentsDelivered;
    }
};
