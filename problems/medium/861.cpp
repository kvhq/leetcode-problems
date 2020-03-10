// Number: 861
// Name: Score After Flipping Matrix
// Tags: math, greedy, matrix

int binToDec(const vector<int>& binNumber) {
  int result = 0;
  int base = 1;
  for (int i = binNumber.size() - 1; i >= 0; i--) {
    result += binNumber[i] * base;
    base *= 2;
  }
  return result;
}

void toggleRow(vector<int>& v) {
  for (size_t i = 0; i < v.size(); ++i) {
    if (v[i] == 0) v[i] = 1;
    else if (v[i] == 1) v[i] = 0;
  }
  return;
}

void toggleColumn(vector<vector<int>>& A, size_t col) {
  for (auto& row : A) {
    if (row[col] == 0) row[col] = 1;
    else if (row[col] == 1) row[col] = 0;
  }
}

int calculateAnswer(const vector<vector<int>>& A) {
  int sum = 0;
  for (const auto& row : A) {
    sum += binToDec(row);
  }
  return sum;
}

int matrixScore(vector<vector<int>>& A) {
  for (auto& x : A) {
    if (x[0] != 1) toggleRow(x);
  }
  if (A[0].size() == 1) return calculateAnswer(A);
  for (size_t i = 1; i < A[0].size(); ++i) {
    int ones = 0;
    int zeros = 0;
    for (size_t j = 0; j < A.size(); ++j) {
      A[j][i] == 0 ? zeros++ : ones++;
    }
    if (zeros > ones) toggleColumn(A, i);
  }
  return calculateAnswer(A);
}
