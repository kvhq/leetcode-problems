// Number: 1465
// Name: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
// Tags: array, sort

// time O(N * log(N) + M * log(M)) ; space O(1)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxH = horizontalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); ++i)
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
        maxH = max(maxH, h - horizontalCuts[horizontalCuts.size() - 1]);
        int maxW = verticalCuts[0];
        for (int i = 1; i < verticalCuts.size(); ++i)
            maxW = max(maxW, verticalCuts[i] - verticalCuts[i - 1]);
        maxW = max(maxW, w - verticalCuts[verticalCuts.size() - 1]);
        return (long)maxW * maxH % 1000000007;
    }
};

