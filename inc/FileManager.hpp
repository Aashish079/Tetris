#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <map>

class FileManager
{
private:
// Map to store name and score of player
std::map<std::string, int> playerScore;


public:
    FileManager();
    ~FileManager();
    void storeScore(std::string playerName, int score); // Stores score in file
    void getScoreFromFile(); // Gets top ten scores from file into map
    std::map <std::string, int> getPlayerScore(); // Returns map
    void sortScore(); // Sorts scores in map
    int topTenSize = 0;

};