#pragma once
#include "../../Common.h"

template<class Output>
class Day1 : public DayBase<Output>
{
public:
    Day1<Output>(std::string file) : DayBase(file)
    {
        auto& utils = AoCUtilities::getInstance();
        setOutput();

        utils.display([this]() { this->part1(); }, false);
        utils.display([this]() { this->part2(); }, true);
    }

    ~Day1() {}

    void part1() override
    {
        auto utils = AoCUtilities::getInstance();
        Vec2<int32_t> origin{};
        Vec2<int32_t> dest{};
        m_dir = Direction::North;

        for (const auto coord : m_output)
            processCoordinate(coord, utils, dest);
       std::cout << origin.manhatten(dest);
    }

    void part2() override
    {
        auto utils = AoCUtilities::getInstance();
        Vec2<int32_t> origin{};
        Vec2<int32_t> dest{};
        m_dir = Direction::North;
        std::vector<Vec2<int32_t>> seen{};

        for (const auto coord : m_output)
        {
            processDirection(coord);
            for (int32_t i = 0; i < utils.strToInt(coord.substr(1)); i++)
            {
                if (moveAndUpdateSeen(dest, origin, seen))
                    return;
            }
               
        }
    }

    void setOutput() override
    {
        auto utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file, ',');
    }

private:
    void processCoordinate(const std::string& coord, AoCUtilities& utils, Vec2<int32_t>& dest)
    {
        char direction = coord[0];
        std::string stepsStr = coord.substr(1);
        int32_t steps = utils.strToInt(stepsStr);

        updateDirection(direction);
        move(dest, steps);
    }

    void processDirection(const std::string& coord)
    {
        char direction = coord[0];
        updateDirection(direction);
    }

    void updateDirection(char turnDirection)
    {
        if (turnDirection == 'R')
            m_dir = static_cast<Direction>((static_cast<int32_t>(m_dir) + 1) % 4);
        else
            m_dir = static_cast<Direction>((static_cast<int32_t>(m_dir) + 3) % 4);
    }

    void move(Vec2<int32_t>& dest, int32_t steps)
    {
        switch (m_dir)
        {
        case Direction::North: dest.y += steps; break;
        case Direction::East: dest.x += steps; break;
        case Direction::South: dest.y -= steps; break;
        case Direction::West: dest.x -= steps; break;
        }
    }

    bool moveAndUpdateSeen(Vec2<int32_t>& dest, Vec2<int32_t>& origin, std::vector<Vec2<int32_t>>& seen)
    {
        move(dest, 1);
        for (const auto& point : seen)
        {
            if (dest.x == point.x && dest.y == point.y)
            {
                std::cout << origin.manhatten(dest);
                return true;
            }
        }
        seen.push_back(dest);
        return false;
    }

private:
    enum class Direction { North, East, South, West };
    Direction m_dir{};
};
