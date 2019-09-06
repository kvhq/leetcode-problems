bool ifSelfDividedNumber(int number) {
    int tempNumber = number;
    int digit = 0;
    while(tempNumber != 0) {
        digit = tempNumber % 10;
        if (digit == 0) {
            return false;
        }
        tempNumber = tempNumber / 10;
        if (number % digit != 0) {
            return false;
        }
    }
    return true;
}
    
vector<int> selfDividingNumbers(int left, int right) {
    vector<int> answer;
    for (int i = left; i <= right; ++i) {
        if (ifSelfDividedNumber(i)) {
            answer.push_back(i);
        }
    }
    return answer;
}
