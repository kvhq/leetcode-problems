string addStrings(string num1, string num2) {
    string answer = "";
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int temp = 0;
    while (i >= 0 || j >= 0) {
        if (i >= 0) {
            temp += (num1[i] - '0');
            i--;
        }
        if (j >= 0) {
            temp += (num2[j] - '0');
            j--;
        }
        answer += to_string(temp % 10);
        temp /= 10;
    }
    while (temp != 0) {
        answer += to_string(temp % 10);
        temp /= 10;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}