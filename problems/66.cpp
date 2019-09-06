vector<int> plusOne(vector<int>& digits) {
    vector<int> answer;
    answer.push_back(1);
    for (int i = digits.size() - 1; i >= 0; i--) {
        answer.back() += digits[i];
        if (answer.back() == 10) {
            answer.back() = 0;
            answer.push_back(1);
        }
        else if (i != 0) answer.push_back(0);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

//without extra memory
vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
        }
        else {
            digits[i]++;
            return digits;
        }
    }
    digits[0] = 1;
    digits.push_back(0);
    return digits;
}