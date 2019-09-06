#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void sortColors(vector<int>& nums) {
    if (nums.size() <= 1) {
        return;
    }
    int zeroEnd = 0;
    int twoStart = nums.size() - 1;
    for(int i = 0; i < nums.size();) {
        if (nums[i] == 1) {
            i++;
        }
        else if (nums[i] == 0) {
            if (i == zeroEnd) {
                i++;
                zeroEnd++;
            }
            else {
                swap(nums[i], nums[zeroEnd]);
                zeroEnd++;
            }
        }
        else if (nums[i] == 2) {
            if (i >= twoStart) {
                return;
            }
            else {
                swap(nums[i], nums[twoStart]);
                twoStart--;
                
            }
        }
    }
}

int main() {
    vector<int> tempV = {2,2,2,2,2,2,1,0};
    sortColors(tempV);
    for (const auto& x : tempV) {
        cout << x << endl;
    }
    return 0;
}