// Number: 973
// Name: K Closest Points to Origin
// Tags: heap, sort

class Comp {
    public:
        int operator()(const pair<int, vector<int>>& p1, const pair<int, vector<int>>& p2) {
            int p1_dist_sq = p1.second[0]*p1.second[0] + p1.second[1]*p1.second[1];
            int p2_dist_sq = p2.second[0]*p2.second[0] + p2.second[1]*p2.second[1];
            return p1_dist_sq > p2_dist_sq;
        }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<vector<int>> answer;
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, Comp> minHeap;
    for (int i = 0; i < points.size(); ++i) {
        minHeap.push(make_pair(i, points[i]));
        if (minHeap.size() > points.size() - K) {
            answer.push_back(points[minHeap.top().first]);
            minHeap.pop();
        }
    }
    return answer;
}
