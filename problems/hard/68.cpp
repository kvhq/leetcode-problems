// Number: 68
// Name: Text Justification
// Tags: string

// ugly version

string make_line(const vector<string>& lineWords, size_t maxWidth, size_t wordsLen, bool isLast) {
  string line = "";
  size_t wordsNumber = lineWords.size();
  size_t spacesLength = maxWidth - wordsLen;
  size_t spacesNum = 0;
  if (wordsNumber == 1) {
    spacesNum = 1;
  }
  else if (isLast) {
    spacesNum = wordsNumber;
  }
  else {
    spacesNum = wordsNumber - 1;
  }
  size_t minSpace = spacesLength / spacesNum;
  size_t extraSpaces = spacesLength % spacesNum;
  for (size_t i = 0; i < lineWords.size(); ++i) {
    line += lineWords[i];
    if (!isLast) {
      if (extraSpaces > 0) {
        line += string(minSpace + 1, ' ');
        extraSpaces--;
      }
      else if (i < lineWords.size() - 1) {
        line += string(minSpace, ' ');
      }
    }
    else {
      line += string(1, ' ');
    }
  }
  if (line.size() < maxWidth) {
    line += string(maxWidth - line.size(), ' ');
  }
  return line;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
  vector<string> answerVector;
  vector<string> tempVector;
  size_t curLength = 0;
  size_t curWordsSumLength = 0;
  for (size_t i = 0; i < words.size();) {
    string word = words[i];
    if (curLength + word.size() < maxWidth) {
      curLength += (word.size() + 1);
      curWordsSumLength += word.size();
      tempVector.push_back(word);
      i++;
    }
    else {
      if (curLength + word.size() == maxWidth) {
        tempVector.push_back(word);
        curLength += word.size();
        curWordsSumLength += word.size();
        i++;
      }
      string new_line = make_line(tempVector, maxWidth, curWordsSumLength, false);
      answerVector.push_back(new_line);
      curLength = 0;
      curWordsSumLength = 0;
      tempVector.clear();
      continue;
    }
    if (i == words.size()) {
      string new_line = make_line(tempVector, maxWidth, curWordsSumLength, true);
      answerVector.push_back(new_line);
      curLength = 0;
      curWordsSumLength = 0;
      tempVector.clear();
    }
  }
  return answerVector;
}
