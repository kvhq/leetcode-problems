// Number: 1268
// Name: Search Suggestions System
// tags: string, trie

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
  vector<vector<string>> answer;
  sort(products.begin(), products.end());
  string curPrefix = "";
  for (const auto& c : searchWord) {
    curPrefix += c;
    vector<string> suggested;
    auto it = lower_bound(products.begin(), products.end(), curPrefix);
    for (int i = 0; i < 3 && it + i != products.end(); i++) {
      string s = *(it + i);
      if (s.find(curPrefix) != 0) break;
      suggested.push_back(s);
    }
    answer.push_back(suggested);
  }
  return answer;
}
