#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;


int main(){
    ifstream input("input.txt");

    unordered_set<string> cubes;
    int spacing = 0;

    string line;
    while (getline(input, line)){
        int x;
int y;
int z;

        sscanf(line.c_str(), "%d,%d,%d", &x, &y, &z);
        for (int i = x-1;  i <= x+1;  i++){
            for (int j = y-1;  j <= y+1;  j++){
                for (int k = z-1; k <= z+1; k++){
                    if (i == x || j == y || k == z){
                        string cube = to_string(i) + "," + to_string(j) + "," + to_string(k);
                        if (cubes.count(cube) == 0){
                            spacing++;
                        }

                        cubes.insert(cube);
                    }
                }}
        }
    }

    cout << "The space is " << spacing << large;
}
