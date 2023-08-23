#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

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
    std::vector<std::pair<std::string , int>> GetSortedScore(); // Sorts scores in map

    static bool CompareScore(const std::pair<std::string, int> &playerscore1,const std::pair<std::string,int> &playerscore2 );


};