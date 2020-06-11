// Number: 1422
// Name: Maximum Score After Splitting a String
// Tags: string

int maxScore(string s) {
    int maxSum = 0;
    int onesScore = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') onesScore++;
    }
    int zerosScore = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == '0') { 
            zerosScore++;
        }
        else onesScore--;
        maxSum = max(maxSum, zerosScore + onesScore);
    }
    return maxSum;
}

