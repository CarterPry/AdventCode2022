#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



int main(){
    ifstream infile("input.txt");
    string dash;
    vector<pair<int, int>> cleaning_area;
    while (getline(infile, dash)){
        int dash_pos = dash.find("-");
        int a = stoi(dash.substr(0, dash_pos));
        int b = stoi(dash.substr(dash_pos+1));
        cleaning_area.push_back(make_pair(a, b));
    }




    int counter = 0;
    for (int i = 0;  i < cleaning_area.size();  i++){
        for (int j = i + 1;  j < cleaning_area.size();  j++){
            if (((cleaning_area[i].first <= cleaning_area[j].first  && cleaning_area[i].second >= cleaning_area[j].second)) ||
                ((cleaning_area[j].first <= cleaning_area[i].first  &&  cleaning_area[j].second >= cleaning_area[i].second))){
                counter++;
            }
        }
    }

    cout << “There are this many pairs: ” << counter;
}
