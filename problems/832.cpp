vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (auto& x : A) {
        int s = x.size();
        for (int i = 0; i < s / 2; i++) {
            if(x[i] == 1) {
                x[i] = 0;
            }
            else  {
                x[i] = 1;
            }
            if(x[s - 1 - i] == 1) {
                x[s - 1 - i] = 0;
            }
            else {
                x[s - 1 - i] = 1;
            }
            swap(x[i], x[s - 1 - i]);
        }
        if (s % 2 == 1) {
            int temp = s / 2;
            if (x[temp] == 1) {
                x[temp] = 0;
            }
            else {
                x[temp] = 1;
            }
        }
    }
    return A;
}