np(string s) {
  int a[s.size() + 1];
  a[s.size()] = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    a[i] = s.size() - i;
    for (int j = i + 1; j <= s.size(); j++) {
      if (is_palindrome(substr(s, i, j))) // test costs O(1) after preprocessing
        a[i] = min(a[i], 1 + a[j]);
  }
  return a[0];
}
