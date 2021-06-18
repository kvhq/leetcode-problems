// Number: 695
// Name: Max Area of Island
// Tags: DFS

class Solution {
public:
    void dfs(int y, int x, vector<vector<int>>& grid, int& counter) {
        // set current cell to -1
        grid[y][x] = -1;
        // check top
        if (y - 1 >= 0 && grid[y - 1][x] == 1)
            dfs(y - 1, x, grid, ++counter);
        // check bottom
        if (y + 1 <= grid.size() - 1 && grid[y + 1][x] == 1)
            dfs(y + 1, x, grid, ++counter);
        // check left
        if (x - 1 >= 0 && grid[y][x - 1] == 1)
            dfs(y, x - 1, grid, ++counter);
        // check right
        if (x + 1 <= grid[0].size() - 1 && grid[y][x + 1] == 1)
            dfs(y, x + 1, grid, ++counter);
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int answer = 0;
        int counter = 1;
        int max_y = grid.size() - 1;
        int max_x = grid[0].size() - 1;
        for (int y = 0; y <= max_y; ++y) {
            for (int x = 0; x <= max_x; ++x) {
                if (grid[y][x] == 1) {
                    dfs(y, x, grid, counter);
                    answer = max(answer, counter);
                    counter = 1;
                }
            }
        }
        return answer;
    }
};

