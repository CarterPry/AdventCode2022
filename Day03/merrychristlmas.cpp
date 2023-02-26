#include <bits/stdc++.h>
using namespace std;



int main(){
	vector<string> sacks;
	string line;
	while (getline(cin, line)){
    	sacks.push_back(line);
	}

	int sum = 0;
	for (auto sack : sacks){
    	int length = sack.length() / 2;
    	vector<bool> pocket_one(26 + 26, false), pocket_two(26 + 26, false);
    	for (int i = 0; i < length; i++){
        	char o = sack[i];
        	if (o >= 'a' && o <= 'z'){
            	pocket_one[o - 'a'] = true;
        	}
        	else{
            	pocket_one[o - 'A' + 26] = true;
        	}
    	}
    	for (int i = length; i < sack.length(); i++){
        	char o = sack[i];
        	if (o >= 'a' && o <= 'z'){
            	if (pocket_one[o - 'a']){
                	sum += o - 'a' + 1;
                	break;
            	}
            	pocket_two[o - 'a'] = true;
        	}
        	else{
            	if (pocket_one[o - 'A' + 26]){
                	sum += o - 'A' + 27;
                	break;
            	}
            	pocket_two[o - 'A' + 26] = true;
        	}
    	}
	}
	cout << sum;
	
}
