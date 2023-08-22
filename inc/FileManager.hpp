#pragma once
#include <fstream>

class FileManager
{
private:
public:
    FileManager();
    ~FileManager();
    void storeScore(std::string playerName, int score);
    void getTopTen();
    long int topTen[10];
    std::string topTenNames[10];
    int topTenSize = 0;

};