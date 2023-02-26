#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include <vector>


const int ROWS = 12; 
const int COLS = 12; 


int wrap(int i){
    if (i < 0){
        return i + ROWS;
    } 
    else if (i >= ROWS){
        return i - ROWS;
    } 
    else {
        return i;
    }
}


void move(int& row, int& col, int& facing, int steps){
    int drow, dcol;
    switch (facing){
        case 0: drow = 0; dcol = 1; break;   // right
        case 1: drow = 1; dcol = 0; break;   // down
        case 2: drow = 0; dcol = -1; break;  // left
        case 3: drow = -1; dcol = 0; break;  // up
    }
    while (steps > 0){
        int new_row = wrap(row + drow);
        int new_col = wrap(col + dcol);
        if (board[new_row][new_col] == '#'){
            break;
        }
        row = new_row;
        col = new_col;
        steps--;
    }
}

int main(){
    ifstream infile("input.txt");
    vector<string> lines;
    string line;
    while (getline(infile, line)){
        lines.push_back(line);
    }
    infile.close();

    vector<string> board_strs(lines.begin(), lines.begin() + ROWS);
    string path_str = lines.back();
    vector<vector<char>> board(ROWS, vector<char>(COLS));
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            board[i][j] = board_strs[i][j];
        }
    }
    int row = 0;
    int col = 0;
    int facing = 0; 
    int path_pos = 0;
    while (path_pos < path_str.size()){
        char c = path_str[path_pos];
        if (isdigit(c)){
            int steps = c - '0';
            path_pos++;
            while (isdigit(path_str[path_pos])){
                steps = steps * 10 + (path_str[path_pos] - '0');
                path_pos++;
            }
            move(row, col, facing, steps);
        } 
        else {
            switch (c){
                case 'R': facing = (facing + 1) % 4; break;
                case 'L': facing = (facing + 3) % 4; break;
            }
            path_pos++;
        }
    }

    int password = 1000 * (row + 1) + 4 * (col + 1) + facing;
    cout << "Password is" << password;
}
