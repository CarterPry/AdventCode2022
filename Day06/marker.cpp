#include <iostream>
#include <fstream>
#include <string>
#include <map>


int main(){
	std::ifstream input_file("input.txt");
	std::string buffer;
	std::getline(input_file, buffer);

	std::map<char, int> char_count;
	int start = -1;

	for (int i = 0; i < buffer.length(); i++){
    	char current_char = buffer[i];
    	char_count[current_char]++;

    	if (char_count[current_char] > 1){
        	char_count.clear();
        	
start = -1;
    	} 

else if (char_count.size() == 4){
        	start = i - 3;
        	break;
    	}
	}

	std::cout << start + 1 << std::endl;

	
}
