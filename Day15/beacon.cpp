#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;



struct Point {int x, y;};
int manhattanDistance(Point a, Point b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}



int main(){
    ifstream inputFile("input.txt");
    string line;
    vector<Point> sensors, beacons;
    while (getline(inputFile, line)){
        stringstream ss(line);
        char c;
        int x;
        int y;
        ss >> c >> x >> c >> y >> c;
        if (c == 'S'){
            sensors.push_back({x, y});
        } 
        else {
            beacons.push_back({x, y});
        }
    }
    inputFile.close();
    int rowCount = 23; 
    int colCount = 50;  
    int noBeaconCount = 0;
    for (int row = 0; row < rowCount; row++){
        vector<int> closestBeacon(sensors.size(), -1);
        for (int i = 0; i < sensors.size(); i++){
            int minDist = manhattanDistance(sensors[i], beacons[0]);
            for (int j = 1; j < beacons.size(); j++){
                int dist = manhattanDistance(sensors[i], beacons[j]);
                if (dist < minDist){
                    minDist = dist;
                    closestBeacon[i] = j;
                }
            }
        }
        for (int col = 0; col < colCount; col++){
            bool possibleBeacon = false;
            for (int j = 0; j < beacons.size(); j++){
                bool valid = true;
                for (int i = 0; i < sensors.size(); i++){
                    int dist = manhattanDistance({col, row}, beacons[j]);
                    if (closestBeacon[i] != j && dist <= manhattanDistance({col, row}, sensors[i])){
                        valid = false;
                        break;
                    }
                }
                if (valid){
                    possibleBeacon = true;
                    break;
                }
            }
            if (!possibleBeacon){
                noBeaconCount++;
            }
        }
    }
    cout << noBeaconCount;
}
