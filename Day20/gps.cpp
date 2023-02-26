#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



int main(){
	ifstream infile("input.txt");
	vector<int> numbers;
	int x;
	while (infile >> x){
    	numbers.push_back(x);
	}




	int YouAreHere = 0;
	int n = numbers.size();
	for (int i = 0; i < n; i++){
    	int moves = numbers[i];
    	int NewSpot = (YouAreHere + moves) % n;
    	if (NewSpot < 0){
        	NewSpot += n;
    	}
    	swap(numbers[YouAreHere], numbers[NewSpot]);
    	YouAreHere = NewSpot;
	}




	int spot_1 = 0;
int spot_2 = 0;
int spot_3 = 0;
	int count = 0;
	for (int i = 0; i < n; i++){
    	if (numbers[i] == 0){
        	spot_1 = numbers[(i + 1000) % n];
        	spot_2 = numbers[(i + 2000) % n];
        	spot_3 = numbers[(i + 3000) % n];
        	break;
    	}
	}
	cout << "All coordinates together are " << spot_1 + spot_2 + spot_3;
}
