// Number: 1134
// Name: Armstrong Number
// Tags: Math

class Solution {
public:
    bool isArmstrong(int n) {
        int numberSize = 1;
        vector<int> digits;
        while (true) {
            int temp = n % (int)pow(10, numberSize);
            if (numberSize == 1) digits.push_back(temp);
            else {
                int curDigit = temp / (int)pow(10, numberSize - 1);
                digits.push_back(curDigit);
            }
            if (temp == n) break;
            numberSize++;
        }
        for (const auto& x : digits)
            n -= pow(x, numberSize);
        if (n == 0) return true;
        return false;
    }
};

