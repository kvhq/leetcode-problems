// Number: 1710
// Name: Maximum Units on a Truck
// Tags: sort

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int answer = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[1] > rhs[1];
        });
        for (const auto& x : boxTypes) {
            if (x[0] <= truckSize) {
                answer += x[0] * x[1];
                truckSize -= x[0];
            } else {
                answer += truckSize * x[1];
                break;
            }
        }
        return answer;
    }
};

