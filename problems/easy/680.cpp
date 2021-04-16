// Number: 680
// Name: Valid Palindrome II
// Tags: string

bool helper(const string& s, int left, int right, int del_cntr) {
    while (left <= right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            if (del_cntr == 0) return false;
            else return helper(s, left + 1, right, del_cntr - 1) || helper(s, left, right - 1, del_cntr - 1);
        }
    }
    return true;
}

bool validPalindrome(string s) {
    if (s.size() == 0 || s.size() == 1) return true;
    int left = 0;
    int right = (int)s.size() - 1;
    int del_counter = 1;
    bool wasDeleted = false;
    while (left <= right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            return helper(s, left + 1, right, del_counter - 1) || helper(s, left, right - 1, del_counter - 1);
        }
    }
    return true;
}

