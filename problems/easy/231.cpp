// Number: 231
// Name: Power of Two
// Tags: bit manipulation

bool isPowerOfTwo(int n) {
    return n > 0 && !(n & (n - 1));
}

