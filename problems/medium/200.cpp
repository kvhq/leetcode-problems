// Number: 200
// Name: Number of Islands
// Tags: DFS, BFS

// DFS
class Solution_0 {
public:
    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[y][x] = '0';
        // check bottom
        if (y - 1 >= 0 && grid[y - 1][x] == '1')
            dfs(x, y - 1, grid);
        // check top
        if (y + 1 < grid.size() && grid[y + 1][x] == '1')
            dfs(x, y + 1, grid);
        // check left
        if (x - 1 >= 0 && grid[y][x - 1] == '1')
            dfs(x - 1, y, grid);
        // check right
        if (x + 1 < grid[0].size() && grid[y][x + 1] == '1')
            dfs(x + 1, y, grid);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;
        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                if (grid[y][x] == '1') {
                    answer++;
                    dfs(x, y, grid);
                }
            }
        }
        return answer;
    }
};

