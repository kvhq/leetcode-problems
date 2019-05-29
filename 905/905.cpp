vector<int> sortArrayByParity(vector<int>& A) {
    int s = A.size();
    if (s == 1) {
        return A;
    }
    int flag = 0;
    for(int i = 0; i < (s - flag);) {
        if(A[i] % 2 == 0) {
            i++;
            continue;
        }
        if(A[i] % 2 == 1) {
            swap(A[i], A[s - 1 - flag]);
            flag++;
            continue;
        }
    }
    return A;
}