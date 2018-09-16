#include <iostream>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
  for(auto& i: s1){
    // if find(i) dont find i return -1
    // string::npos = -1
    if (s2.find(i) != string::npos)
      return "YES";
  }
  return "NO";
}

int main() {
  int q; cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for (int q_itr = 0; q_itr < q; q_itr++) {
    string s1; getline(cin, s1);
    string s2; getline(cin, s2);
    cout << twoStrings(s1, s2) << endl;
  }
  return 0;
}