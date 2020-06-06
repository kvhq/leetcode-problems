// Number: 406
// Name: Queue Reconstruction by Height
// Tags: sorting, array

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2) {
        return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    });
    vector<vector<int>> ans;
    for (const auto& p : people) {
        ans.insert(ans.begin() + p[1], p);
    }
    return ans;
}

