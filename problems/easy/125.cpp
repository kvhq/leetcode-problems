// Number: 125
// Name: Valid Palindrome
// Tags: string, two pointer

// form new string and check, O(n) time and O(n) space
class Solution_1 {
public:
    bool isPalindrome(string s) {
        string d_s;
        for (const auto& x : s) {
            if (isalnum(x)) d_s += tolower(x);
        }
        for (int i = 0; i < d_s.size() / 2; ++i) {
            if (d_s[i] != d_s[d_s.size() - 1 - i]) return false;
        }
        return true;
    }
};

// two pointer
class Solution_2 {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (isalnum(s[left])) {
                while (!isalnum(s[right]) && right >= left) right--;
                if (tolower(s[left]) != tolower(s[right])) return false;
                left++;
                right--;
            } else while (!isalnum(s[left]) && left <= right) left++;
        }
        return true;
    }
};

