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

    const std::string FileToString(const std::string& file)
    {
        std::ifstream input{ file };
        try
        {
            if (!input.is_open()) 
                throw std::ifstream::failure("Could not open the file");

            std::string fileContent((std::istreambuf_iterator<char>(input)),
                std::istreambuf_iterator<char>());
            input.close();

            return fileContent;
        }
        catch (const std::ifstream::failure& e) {
            std::cerr << "File error: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }

    template <typename T>
    const std::vector<T> FileToVector(const std::string& file)
    {
        std::ifstream input{ file };
        try
        {
            if (!input.is_open())
                throw std::ifstream::failure("Could not open the file");

            std::vector<T> fileData{};
            std::string line{};
            while (std::getline(input, line, ','))
            {
                std::istringstream ss{ line };
                T value{};
                if (ss >> value)
                    fileData.push_back(value);
            }
            input.close();
            return fileData;
        }
        catch (const std::ifstream::failure& e)
        {
            std::cerr << "File error: " << e.what() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }

    const int32_t Count(const char c, const std::string input)
    {
        return std::count(input.begin(), input.end(), c );
    }

    int32_t StrToInt(const std::string& s) {
        return std::atoi(s.c_str());
    }

private:
    AoCUtilities() { }
};



