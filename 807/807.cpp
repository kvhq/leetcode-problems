#include <vector>
#include <algorithm>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int answer = 0;
    vector<int> maxColumns;
    vector<int> maxRaws;

    for (int i = 0; i < grid.size(); ++i) {
        int tempMaxRaw = *max_element(grid[i].begin(), grid[i].end());
        maxRaws.push_back(tempMaxRaw);
    }
    
    for (int i = 0; i < grid[0].size(); ++i) {
        vector<int> tempVec;
        for (int j = 0; j < grid.size(); ++j) {
            tempVec.push_back(grid[j][i]);
        }
        int tempMaxColumn = *max_element(tempVec.begin(), tempVec.end());
        maxColumns.push_back(tempMaxColumn);
    }

    cout << endl;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[0].size(); ++j) {
            if (min(maxColumns[j], maxRaws[i]) > grid[i][j]) {
                answer += (min(maxColumns[j], maxRaws[i]) - grid[i][j]);
            }
        }
    }

    return answer;
}
