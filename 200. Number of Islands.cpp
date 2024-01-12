#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        char up = '\0', down = '\0', left = '\0', right = '\0';
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    advance(grid, i, j);
                    island++;
                }
            }
        }
        
        return island;
    }
    void advance(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        if (i != 0 && grid[i - 1][j] == '1')
            advance(grid, i - 1, j);
        if (i != grid.size() - 1 && grid[i + 1][j] == '1')
            advance(grid, i + 1, j);
        if (j != 0 && grid[i][j - 1] == '1')
            advance(grid, i, j - 1);
        if (j != grid[i].size() - 1 && grid[i][j + 1] == '1')
            advance(grid, i, j + 1);
    }
};