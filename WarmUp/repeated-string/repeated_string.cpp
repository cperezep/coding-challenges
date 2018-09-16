#include <iostream>

using namespace std;

int main(){
	string s; getline(cin, s);
	long n; cin >> n;

	cout << n/s.size() * count(s.begin(), s.end(), 'a') 
					+ count(s.begin(), s.begin()+(n%s.size()), 'a') << endl;
	return 0;
}