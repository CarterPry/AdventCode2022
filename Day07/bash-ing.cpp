#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
unordered_map<string, long long> lsblk;
vector<string> dirs;



void nano_size(string dir){
	long long size = 0;
	for (auto &entry : lsblk){
    	if (entry.first.find(dir + '/') == 0){
        	size += entry.second;}}
	lsblk[dir] = size;
	if (size <= 100000){
    	dirs.push_back(dir);}}
// yes this func is compressed and messy ^^


int main(){
	string path;
string cmd;
string filename;
	long long filesize;
	while (cin >> cmd){
    	if (cmd == "cd"){
        	cin >> path;
        	if (path == "/"){
            	path = "";
        	} 

else if (path == ".."){
            	int pos = path.rfind('/');
            	path = path.substr(0, pos);
        	} 

else{
            	path += '/' + filename;
        	}

    	} 

else if (cmd == "ls"){
        	cin >> filename >> filesize;
        	lsblk[path + '/' + filename] = filesize;
    	}
	}

	for (auto &entry : lsblk){
    	if (entry.first.find('/') == string::npos){
        	nano_size(entry.first);
    	}
	}

	long long sum = 0;
	for (auto &dir : dirs){
    	sum += lsblk[dir];
	}

	cout << sum << “\n”;
}
