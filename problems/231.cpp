bool isPowerOfTwo(int n) {
    if (n == 1) {
        return true;
    }
    long long temp = 1;
    while (temp < n) {
        temp *= 2;
    }
    if (temp == n) {
        return true;
    }
    return false;
}

//should add bit manipulation solution