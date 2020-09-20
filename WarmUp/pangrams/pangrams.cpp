#include <iostream>
#include <vector>

using namespace std;

string is_pangram(string s) {
	int ascii_start = 97;
	int alphabet_length = 26;

	transform(s.begin(), s.end(), s.begin(), ::tolower);
	vector<int> v(alphabet_length);


	for(auto& i: s){
		v[int(i) - ascii_start]++;
  	}

  	for(auto& i: v) {
  		if (i == 0) return "not pangram";
  	}
  	return "pangram";
}

int main() {
	string s; getline(cin, s);
	cout << is_pangram(s);

  	return 0;
}