// Number: 905
// Name: Sort Array By Parity
// Tags: array, two pointers


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

vector<int> sortArrayByParity_second(vector<int>& A) {
    size_t l = A.size();
    if (l == 1) return A;
    int f = 0;
    int s = 1;
    while (f < l && A[f] % 2 == 0) {
        f++;
    }
    if (f < l) s = f + 1;
    else return A;
    while (s < l) {
        if (A[s] % 2 == 0) {
            swap(A[s], A[f]);
            f++;
        }
        s++;
    }
    return A;
}
