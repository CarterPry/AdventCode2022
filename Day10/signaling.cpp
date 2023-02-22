#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main(){
	ifstream inputFile("input.txt");
	if (!inputFile.is_open()){
    	cerr << "Failed to open input file";
    	return 1;
	}

	vector<pair<string, int>> program;
	string op;
	int elf;
	while (inputFile >> op >> elf){
    	program.emplace_back(op, elf);
	}

	inputFile.close();

	int cycle = 0;
	int x = 1;
	int strength = 0;
	for ( size_t i = 0; i < program.size(); i++){
    	const auto& [op, elf] = program[i];
    	if (op == "addx"){
        	x += elf;
        	cycle += 2;
    	} 
else{
        	cycle += 1;
    	}

    	if ((cycle == 20) || ((cycle - 20) % 40 == 0)){
        	strength += x * cycle;
    	}
	}
	cout << "The signal’ strength is " << strength;
}
