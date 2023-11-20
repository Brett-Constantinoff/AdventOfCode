#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <functional>

#include "Timer.h"

class AoCUtilities
{
public:
    static AoCUtilities& getInstance()
    {
        static AoCUtilities instance;
        return instance;
    }

    static void display(std::function<void(void)> func, bool part2 = false) {
        auto& timer = Timer::getInstance();
        std::cout << (part2 ? "Part2" : "Part1") << " Answer: ";
        timer.start();
        func();
        std::cout << "\n";
        timer.stop();
    }

    static std::string fileToString(const std::string& file)
    {
        std::ifstream input{ file };
        try
        {
            return readIntoString(input);
        }
        catch (const std::ifstream::failure& e) {
            std::cerr << "File error: " << e.what() << std::endl;
        }
    }

    static std::vector<std::string> fileToVector(const std::string& file, const char delim = NULL)
    {
        std::ifstream input{ file };
        try
        {
            return readIntoVector(input, delim);
        }
        catch (const std::ifstream::failure& e)
        {
            std::cerr << "File error: " << e.what() << std::endl;
        }
    }

    static int32_t count(const char c, const std::string input)
    {
        return std::count(input.begin(), input.end(), c );
    }

    static int32_t strToInt(const std::string& s)
    {
        return std::atoi(s.c_str());
    }

private:
    AoCUtilities() { }

    static std::string readIntoString(std::ifstream& input)
    {
        if (!input.is_open())
            throw std::ifstream::failure("Could not open the file");
        std::string fileContent((std::istreambuf_iterator<char>(input)),
            std::istreambuf_iterator<char>());
        input.close();
        return fileContent;
    }

    static std::vector<std::string> readIntoVector(std::ifstream& input, const char delim)
    {
        if (!input.is_open())
            throw std::ifstream::failure("Could not open the file");
        std::vector<std::string> fileData{};
        std::string line{};
        while (std::getline(input, line))
        {
            if (delim == NULL)
                parseByChar(fileData, line);
            else
                parseByDelim(fileData, line, delim);
        }
        input.close();
        return fileData;
    }

    static void parseByChar(std::vector<std::string>& fileData, const std::string& line)
    {
        for (const auto& ch : line)
            fileData.push_back(std::string{ch});
    }

    static void parseByDelim(std::vector<std::string>& fileData, std::string& line, const char delim)
    {
        std::istringstream ss{ line };
        std::string value{};
        while (std::getline(ss, line, delim))
        {
            if (std::istringstream(line) >> value)
                fileData.push_back(value);
        }
    }
};



