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
    }

    void part2() override
    {
    }

    void setOutput() override
    {
        auto utils = AoCUtilities::getInstance();
        m_output = utils.fileToVector<Output>(m_file);
    }
};
