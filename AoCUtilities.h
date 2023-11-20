#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

class AoCUtilities
{
public:
    static AoCUtilities& GetInstance()
    {
        static AoCUtilities instance;
        return instance;
    }

    std::string FileToString(const std::string& file) const
    {
        std::ifstream input{ file };
        try
        {
            return ReadIntoString(input);
        }
        catch (const std::ifstream::failure& e) {
            std::cerr << "File error: " << e.what() << std::endl;
        }
    }

    std::vector<std::string> FileToVector(const std::string& file, const char delim = NULL) const
    {
        std::ifstream input{ file };
        try
        {
            return ReadIntoVector(input, delim);
        }
        catch (const std::ifstream::failure& e)
        {
            std::cerr << "File error: " << e.what() << std::endl;
        }
    }

    int32_t Count(const char c, const std::string input) const
    {
        return std::count(input.begin(), input.end(), c );
    }

    int32_t StrToInt(const std::string& s) const
    {
        return std::atoi(s.c_str());
    }

private:
    AoCUtilities() { }

    std::string ReadIntoString(std::ifstream& input) const
    {
        if (!input.is_open())
            throw std::ifstream::failure("Could not open the file");
        std::string fileContent((std::istreambuf_iterator<char>(input)),
            std::istreambuf_iterator<char>());
        input.close();
        return fileContent;
    }

    std::vector<std::string> ReadIntoVector(std::ifstream& input, const char delim) const
    {
        if (!input.is_open())
            throw std::ifstream::failure("Could not open the file");
        std::vector<std::string> fileData{};
        std::string line{};
        while (std::getline(input, line))
        {
            if (delim == NULL)
                ParseByChar(fileData, line);
            else
                ParseByDelim(fileData, line, delim);
        }
        input.close();
        return fileData;
    }

    void ParseByChar(std::vector<std::string>& fileData, const std::string& line) const
    {
        for (const auto& ch : line)
            fileData.push_back(std::string{ch});
    }

    void ParseByDelim(std::vector<std::string>& fileData, std::string& line, const char delim) const
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



