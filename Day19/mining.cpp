#include <bits/stdc++.h>
using namespace std;

struct AI {
    int ore = 0;
    int clay = 0;
    int obsidian = 0; 
    int geode = 0;
    int timeToBuild = 0; 
};

vector<AI> robots; 
unordered_map<string, int> robotIndices; 
unordered_map<string, int> resources; 

void readInput(){
    ifstream inputFile("input.txt");


    string line;
    while (getline(inputFile, line)){
        istringstream iss(line);
        string robotName, word;
        int oreCost = 0; 
        int clayCost = 0; 
        int obsidianCost = 0; 
        int geodeCost = 0;
        iss >> robotName;

        while (iss >> word){
            if (word == "ore"){
                iss >> oreCost;
            } 
            else if (word == "clay"){
                iss >> clayCost;
            } 
            else if (word == "obsidian"){
                iss >> obsidianCost;
            } 
            else if (word == "geode"){
                iss >> geodeCost;
            }
        }

        AI robot = {oreCost, clayCost, obsidianCost, geodeCost, 1};
        robots.push_back(robot);
        robotIndices[robotName] = robots.size() - 1;
    }
    getline(inputFile, line);
    istringstream iss(line);
    string word;
    while (iss >> word){
        int amount;
        iss >> amount;
        resources[word] = amount;
    }

    inputFile.close();
}

int main(){
   int num1;
   int num2;
   int sum;

   printf("Enter two integers: ");
   scanf("%d %d", &num1, &num2);
   sum = num1 + num2;
   printf("%d + %d = %d", num1, num2, sum);
}
