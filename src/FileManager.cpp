#include "FileManager.hpp"
#include <iostream>

FileManager::FileManager()
{
    std::ifstream file("scores.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            std::string name = line.substr(0, line.find(" "));
            std::string score = line.substr(line.find(" ") + 1, line.length());
            topTenNames[topTenSize] = name;
            topTen[topTenSize] = std::stoi(score);
            topTenSize++;
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
}

FileManager::~FileManager()
{
}

void FileManager::storeScore(std::string playerName, int score)
{
    std::ofstream file;
    file.open("../rec/scores.txt", std::ios::app);
    if(file.fail())
    {
        std::cout << "Error opening file" << std::endl;
    }
    file << playerName << " " << score << std::endl;
    file.close();
}

