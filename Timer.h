#pragma once
#include <chrono>
#include <iostream>

class Timer
{
public:
    static Timer& getInstance()
    {
        static Timer instance;
        return instance;
    }

    void start(void)
    {
        m_start = std::chrono::high_resolution_clock::now();
    }
    
    void stop(const std::string& process = "Process")
    {
        m_stop = std::chrono::high_resolution_clock::now();
        m_time = std::chrono::duration_cast<std::chrono::duration<double>>(m_stop - m_start);
        std::cout<< process << " took " << m_green <<  m_time.count() << " seconds." << m_reset << "\n";
    }
private:
    Timer() {};

    std::chrono::high_resolution_clock::time_point m_start{};
    std::chrono::high_resolution_clock::time_point m_stop{};
    std::chrono::duration<double> m_time{};
    const std::string& m_reset = "\x1b[0m";
    const std::string& m_green = "\x1b[32m";

};