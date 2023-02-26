#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;



int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");
        int n;
    input >> n; // Read in the number of elements
    vector<int> v(n);

    for (int i = 0; i < n; i++){
        input >> v[i]; 
    }
    
    sort(v.begin(), v.end()); //sorting
    
    int you_shall_not_pass = 1; 
int count = 1;
    int mode = v[0];
int current = v[0];
    for (int i = 1; i < n; i++){
        if (v[i] == current){
        count++;
        } 

else{ 
            if (count > you_shall_not_pass){ 
                you_shall_not_pass = count;
                mode = current;
            }
            count = 1; 
            current = v[i];
        }
    }
    
    if (count > you_shall_not_pass){
        mode = current;
    }
        output << mode << “\n”;
    
    input.close();
    output.close();
    }
