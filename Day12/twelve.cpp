#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <queue>

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};



int shortest(vector<vector<char>>& heightmap){
    int n = heightmap.size();
    int m = heightmap[0].size();
    vector<vector<int>> steps(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    int sx; 
    int sy; 
    int ex; 
    int ey;
    

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (heightmap[i][j] == 'S'){
                sx = i;
                sy = j;
            } 
  else if (heightmap[i][j] == 'E'){
                ex = i;
                ey = j;
            }
        }
    }

    
q.push(make_pair(sx, sy));
    steps[sx][sy] = 0;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == ex && y == ey){
            return steps[x][y];
        }


        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
            if (heightmap[nx][ny] - heightmap[x][y] > 1){
                continue;
            }
            if (steps[nx][ny] == -1){
                steps[nx][ny] = steps[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    // In case if an error we always turn to return -1
    return -1;
}



int main(){
    ifstream fin("input.txt");
    int n, m;
    fin >> n >> m;

    vector<vector<char>> heightmap(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fin >> heightmap[i][j];
        }
    }
    fin.close();

    int steps = shortest(heightmap);
    cout << "Steps to move from S to E is " << steps << “steps”;    
}
