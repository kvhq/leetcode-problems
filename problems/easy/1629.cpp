// Number: 1629
// Name: Slowest Key
// Tags: string

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char answer = keysPressed[0];
        int curMax = releaseTimes[0];
        for (int i = 1; i < keysPressed.size(); ++i) {
            if (releaseTimes[i] - releaseTimes[i - 1] > curMax) {
                curMax = releaseTimes[i] - releaseTimes[i - 1];
                answer = keysPressed[i];
            } else if (releaseTimes[i] - releaseTimes[i - 1] == curMax)
                answer = keysPressed[i] > answer ? keysPressed[i] : answer;
        }
        return answer;
    }
};

