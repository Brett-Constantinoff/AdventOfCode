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

    template<typename T>
    static std::vector<T> fileToVector(const std::string& file, const char delim = NULL,
        std::function<T(const std::string&)> converter = [](const std::string& s) -> T {return T(s); })
    {
        std::ifstream input{ file };
        try
        {
            return readIntoVector<T>(input, delim, converter);
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
        return std::stoi(s.c_str());
    }

private:
    AoCUtilities() { }

    static std::string readIntoString(std::ifstream& input)
    {
        checkFileStatus(input);
        std::string fileContent((std::istreambuf_iterator<char>(input)),
            std::istreambuf_iterator<char>());
        input.close();
        return fileContent;
    }

    template<typename T>
    static std::vector<T> readIntoVector(std::ifstream& input, const char delim,
        std::function<T(const std::string&)> converter)
    {
        checkFileStatus(input);
        std::vector<T> fileData{};
        std::string line{};
        while (std::getline(input, line))
            parseLine(fileData, line, delim, converter);
        input.close();
        return fileData;
    }

    static void checkFileStatus(std::ifstream& input)
    {
        if (!input.is_open())
            throw std::ifstream::failure("Could not open the file");
    }

    template<typename T>
    static void parseLine(std::vector<T>& fileData, std::string& line, const char delim,
        std::function<T(const std::string&)> converter)
    {
        if (delim == NULL)
            parseByChar<T>(fileData, line, converter);
        else
            parseByDelim<T>(fileData, line, delim, converter);
    }

    template<typename T>
    static void parseByChar(std::vector<T>& fileData, const std::string& line,
        std::function<T(const std::string&)> converter)
    {
        for (const auto& ch : line)
        {
            std::string strValue(1, ch);
            fileData.push_back(converter(strValue));
        }
    }

    template<typename T>
    static void parseByDelim(std::vector<T>& fileData, std::string& line, const char delim, 
        std::function<T(const std::string&)> converter)
    {
        std::istringstream ss{ line };
        std::string value{};
        while (std::getline(ss, line, delim))
        {
            if (std::istringstream(line) >> value)
               fileData.push_back(converter(value));
        }
    }
};



