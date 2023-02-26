#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
    ifstream infile("input.txt");
    string line;


    while (getline(infile, line)){
        if (line.empty()) continue;
        int count = 0;

        // loop through every character
        for (char c : line){
            if (isdigit(c)){
                count += c - '0';
            }
        }
        cout << count;
    }
    infile.close();
}
