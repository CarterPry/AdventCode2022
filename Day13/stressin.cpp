#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



bool comparing(const vector<int>& left, const vector<int>& right){
	int n = min(left.size(), right.size());
	for (int i = 0; i < n; i++){
    	if (left[i] < right[i]){
        	return true;}
    	if (left[i] > right[i]){return false;}}return (left.size() < right.size());}vector<int> to_list(int n){return vector<int>{n};}
// I have a bad habit of compressing functions when I’m done writing them



int reorder_packets(const string& filename){
	ifstream input_file(filename);
	if (!input_file.is_open()){
    	cerr << "Failed to open input file";
    	return -1;
	}
	int count = 0;
	vector<int> left, right;
	string line;
	while (getline(input_file, line)){
    	if (line.empty()){
        	if (comparing(left, right)){
            	count++;
        	}
        	left.clear();
        	right.clear();
    	} 
else{
        	vector<int> packet;
        	int i = 0;
        	while (i < line.length()){
            	if (isdigit(line[i])){
                	int n = 0;
                	while (i < line.length() && isdigit(line[i])){
                    	n = n * 10 + (line[i] - '0');
                    	i++;
                	}
                	packet.push_back(n);
            	} 
else if (line[i] == '['){
                	vector<int> sublist;
                	i++;
                	while (i < line.length() && line[i] != ']'){
                    	if (isdigit(line[i])){
                        	int n = 0;
                        	while (i < line.length() && isdigit(line[i])){
                            	n = n * 10 + (line[i] - '0');
                            	i++;
                        	}
                        	sublist.push_back(n);
                    	} 
else if (line[i] == '['){
                        	vector<int> sub_list;
                        	i++;
                        	while (i < line.length() && line[i] != ']'){


                            	vector<int> sub_packet;
                            	int j = i;
                            	while (j < line.length() && line[j] != ',' && line[j] != ']'){
                                	j++;
                            	}
                            	sub_packet = to_list(stoi(line.substr(i, j - i)));
                            	sub_list.insert(sub_list.end(), sub_packet.begin(), sub_packet.end());
                            	i = j + 1;
                        	}
                        	sublist.push_back(sub_list);
                    	} 
else{
                        	i++;
                    	}
                	}
                	packet.push_back(sublist);
                	i++;
            	} 
else{
                	i++;
            	}
        	}
        	if (left.empty()){
            	left = packet;
        	} 
else{
            	right = packet;
        	}
    	}
	}
	input_file.close();
	return count;
}

int main(){
	int count = reorder_packets("input.txt");
	cout << "Number of pairs in the right order: " << count;
}
