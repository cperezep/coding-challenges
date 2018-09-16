// Best Solution use multimap
#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  cout.tie(0);

	int q; cin >> q;
	int a, b;
	unordered_map<int, int> freq, ocur;
	for(int i = 0; i < q; i++){
		cin >> a >> b;
		switch(a){
			case 1:
				if(ocur[freq[b]])
					ocur[freq[b]]--;
				freq[b]++;
				ocur[freq[b]]++;
				break;
			case 2:
				if(freq[b]){
					ocur[freq[b]]--;
					freq[b]--;
					ocur[freq[b]]++;
				}		
				break;
			case 3:
				cout << ((ocur[b]) ? "1" : "0") << endl;
				break;
		}
	}
	return 0;
}