// Number: 1564
// Name: Put Boxes Into the Warehouse I
// Tags: two pointer

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end(), greater<int>());
        int answer = 0;
        for (int i = 0, j = 0; i < boxes.size() && j < warehouse.size();) {
            int cur_box = boxes[i];
            if (cur_box <= warehouse[j]) {
                    answer++;
                    i++;
                    j++;
            } else i++;
        }
        return answer;
    }
};

