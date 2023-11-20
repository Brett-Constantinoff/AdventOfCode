#pragma once
#include "../../Common.h"

template<class T, class O>
class Day1 : public Day<T, O>
{
public:
    Day1<T, O>(std::string file) : Day<T, O>(file)
    {
        SetOutput();
        Part1();
        Part2();
    }

    ~Day1() {}

    void Part1() override
    {
        auto utils = AoCUtilities::GetInstance();
        Vec2<int32_t> origin{};
        Vec2<int32_t> dest{};
        m_dir = Direction::North;

        for (const auto coord : m_output)
            ProcessCoordinate(coord, utils, dest);
        DisplayPart1Answer(origin.Manhatten(dest));
    }

    void Part2() override
    {
        auto utils = AoCUtilities::GetInstance();
        Vec2<int32_t> origin{};
        Vec2<int32_t> dest{};
        m_dir = Direction::North;
        std::vector<Vec2<int32_t>> seen{};

        for (const auto coord : m_output)
        {
            ProcessDirection(coord);
            for (int32_t i = 0; i < utils.StrToInt(coord.substr(1)); i++)
                MoveAndUpdateSeen(dest, origin, seen);
        }
    }

    void SetOutput() override
    {
        auto utils = AoCUtilities::GetInstance();
        m_output = utils.FileToVector<std::string>(m_file, ',');
    }

private:
    enum class Direction { North, East, South, West };
    Direction m_dir{};

    void ProcessCoordinate(const std::string& coord, AoCUtilities& utils, Vec2<int32_t>& dest)
    {
        char direction = coord[0];
        std::string stepsStr = coord.substr(1);
        int32_t steps = utils.StrToInt(stepsStr);

        UpdateDirection(direction);
        Move(dest, steps);
    }

    void ProcessDirection(const std::string& coord)
    {
        char direction = coord[0];
        UpdateDirection(direction);
    }

    void UpdateDirection(char turnDirection)
    {
        if (turnDirection == 'R')
            m_dir = static_cast<Direction>((static_cast<int32_t>(m_dir) + 1) % 4);
        else
            m_dir = static_cast<Direction>((static_cast<int32_t>(m_dir) + 3) % 4);
    }

    void Move(Vec2<int32_t>& dest, int32_t steps)
    {
        switch (m_dir)
        {
        case Direction::North: dest.y += steps; break;
        case Direction::East: dest.x += steps; break;
        case Direction::South: dest.y -= steps; break;
        case Direction::West: dest.x -= steps; break;
        }
    }

    void MoveAndUpdateSeen(Vec2<int32_t>& dest, Vec2<int32_t>& origin, std::vector<Vec2<int32_t>>& seen)
    {
        Move(dest, 1);
        for (const auto& point : seen)
        {
            if (dest.x == point.x && dest.y == point.y)
            {
                DisplayPart2Answer(origin.Manhatten(dest));
                std::exit(0);
            }
        }
        seen.push_back(dest);
    }
};
