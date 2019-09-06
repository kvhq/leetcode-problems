vector<int> sortedSquares(vector<int>& A) {
    int Asize = A.size();
    int posI = 0;
    while (posI < Asize && A[posI] < 0) {
        posI++;
    }
    vector<int> answer;
    int negI = posI - 1;
    if (negI < 0) {
        for (auto& x : A) {
            x = x * x;
            answer.push_back(x);
        }
        return answer;
    }
    for (;negI >= 0 && posI < Asize;) {
        if (A[posI] > A[negI] * (-1)) {
            answer.push_back(A[negI]*A[negI]);
            negI--;
        }
        else if (A[posI] < A[negI] * (-1)) {
            answer.push_back(A[posI]*A[posI]);
            posI++;
        }
        else {
            answer.push_back(A[posI]*A[posI]);
            answer.push_back(A[negI]*A[negI]);
            posI++;
            negI--;
        }
    }
    if (posI < Asize) {
        while (posI < Asize) {
            answer.push_back(A[posI]*A[posI]);
            posI++;
        }
        return answer;
    }
    if (negI >= 0) {
        while (negI >= 0) {
            answer.push_back(A[negI]*A[negI]);
            negI--;
        }
        return answer;
    }
    return answer;
}