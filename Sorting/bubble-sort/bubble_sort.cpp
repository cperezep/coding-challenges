#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);

	for(auto& i: v)
		cin >> i;

	int swaps = 0;
	for (int i = 0; i < n; i++) {  
	  for (int j = 0; j < n - 1; j++) {
      // Swap adjacent elements if they are in decreasing order
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
        swaps++;
      }
	  }
	}

	cout << "Array is sorted in " << swaps << " swaps." << endl;
	cout << "First Element: " << v[0] << endl;
	cout << "Last Element: " << v[v.size()-1] << endl;
	return 0;
}