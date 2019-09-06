#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

//bad one
vector<int> sortArrayByParityII(vector<int>& A) {
    queue<int> evenNumbers;
    queue<int> oddNumbers;
    for(const auto& x : A) {
        if (x % 2 == 0) {
            evenNumbers.push(x);
        }
        if (x % 2 == 1) {
            oddNumbers.push(x);
        }
    }
    for(int i = 0; i < A.size(); i++) {
        if (i % 2 == 0) {
            A[i] = evenNumbers.front();
            evenNumbers.pop();
        }
        if (i % 2 == 1) {
            A[i] = oddNumbers.front();
            oddNumbers.pop();
        }
    }
    return A;
}

//Space O(N), Time O(N)
vector<int> sortArrayByParityII(vector<int>& A) {
    vector<int> answer(A.size(), 0);
    int k = 0;
    for(int i = 0; i < A.size(); i++) {
        if (A[i] % 2 == 0) {
            answer[k] = A[i];
            k += 2;
        }
    }
    k = 1;
    for(int i = 0; i < A.size(); i++) {
        if (A[i] % 2 == 1) {
            answer[k] = A[i];
            k += 2;
        }
    }
    return A;
}
