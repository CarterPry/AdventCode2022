#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


const int TheMostRows = 2000;
const int TopCandyCane = 2000;
char grid[TheMostRows][TopCandyCane];
bool resting[TheMostRows][TopCandyCane];



int main(){
    ifstream infile("input.txt");
    string line;
    vector<pair<int,int>> rocks;

    while (getline(infile, line)){
        int x1;
        int y1;
        int x2; 
        int y2;
        sscanf(line.c_str(), "%d,%d -> %d,%d", &x1, &y1, &x2, &y2);
        rocks.push_back({x1, y1});
        if (x1 != x2){
            for (int x = min(x1, x2); x <= max(x1, x2); x++){
                rocks.push_back({x, y1});
            }
        } 
        else {
            for (int y = min(y1, y2); y <= max(y1, y2); y++){
                rocks.push_back({x1, y});
            }
        }
    }
    for (auto p : rocks){
        grid[p.second][p.first] = '#';
    }
    grid[0][500] = '+';
    int num_sand = 0;

    while (true){
        bool moved_sand = false;
        for (int y = 0; y < TheMostRows; y++){
            for (int x = 0; x < TopCandyCane; x++){
                if (grid[y][x] == '+'){
                    if (grid[y+1][x] == '.'){
                        grid[y+1][x] = '+';
                        moved_sand = true;
                    } 
         else if (grid[y+1][x] == '#' || resting[y+1][x]){
                        if (grid[y][x-1] == '.'){
                            grid[y][x-1] = '+';
                            moved_sand = true;
                        } 
                    else if (grid[y][x-1] == '#' && grid[y+1][x-1] == '.'){
                            grid[y+1][x-1] = '+';
                            moved_sand = true;
                        }
                        if (grid[y][x+1] == '.'){
                            grid[y][x+1] = '+';
                            moved_sand = true;
                        } 
                    else if (grid[y][x+1] == '#' && grid[y+1][x+1] == '.'){
                            grid[y+1][x+1] = '+';
                            moved_sand = true;
                        }
                     if (grid[y][x-1] == '#' && grid[y][x+1] == '#' && (grid[y+1][x-1] == '#' || resting[y+1][x-1]) && (grid[y+1][x+1] == '#' || resting[y+1][x+1])){
                            resting[y][x] = true;
                        }
                    }
                }
            }
        }
        if (!moved_sand){
            break;
        }
    }
    int resting = 0;
    for (int y = 0; y < TheMostRows; y++){
        for (int x = 0; x < TopCandyCane; x++){
            if (grid[y][x] == '+' || grid[y][x] == '|'){
                num_sand++;
            }
            if (resting[y][x]){
                resting++;
            }
        }
    }
    cout << "# of sand: " << num_sandl;
    cout << "Resting sand: " << resting;
}
