// Number: 1423
// Name: Maximum Points You Can Obtain from Cards
// Tags: array, sliding window

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int startSum = 0;
        for (int i = 0; i < k; ++i) {
            startSum += cardPoints[i];
        }
        if (k >= cardPoints.size()) return startSum;
        int answer = startSum;
        for (int i = k - 1, j = cardPoints.size() - 1; i >= 0;) {
            startSum -= (cardPoints[i] - cardPoints[j]); 
            answer = max(answer, startSum);
            i--;
            j--;
        }
        return answer;
    }
};

