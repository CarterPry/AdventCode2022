#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;




int interpret(const string& monkeh, const map<string, int>& values){
	stringstream ss(monkeh);
	string current; 
string op;
	vector<int> nums;
	while (ss >> current){
    	if (isdigit(current[0])){
        	nums.push_back(stoi(current));
    	} 
else{
        	op = current;
    	}
	}
	int bannana = nums[0];
	if (op == "+"){
    	bannana += nums[1];
	} 
else if (op == "-"){
    	bannana -= nums[1];
	} 
else if (op == "*"){
    	bannana *= nums[1];
	} 
else if (op == "/"){
    	bannana /= nums[1];
	}
	return bannana;
}

int main(){
	ifstream infile("input.txt");
	map<string, int> values;
	string line;
	while (getline(infile, line)){
    	istringstream iss(line);
    	string name; 
string monkeh;
    	getline(iss, name, ':');
    	getline(iss, monkeh);
    	if (isdigit(monkeh[0])){
        	values[name] = stoi(monkeh);
    	}
	}
	infile.close();
	while (values.find("root") == values.end()){
    	for (auto& p : values){
        	if (isdigit(p.second)){
            	continue;
        	}
        	stringstream ss(p.second);
        	string current;
        	bool ready = true;
        	while (ss >> current){
            	if (!isdigit(current[0])){
                	if (values.find(current) == values.end()){
                    	ready = false;
                    	break;
                	}
            	}
        	}
        	if (ready){
            	values[p.first] = interpret(p.second, values);
        	}
    	}
	}
	cout << values["root"];
}
