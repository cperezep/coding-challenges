#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> v){
	for(auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}

// the special and wrong input [1,3,5,2,4,6,8] -> int order to pass that case is necessary not look for the position 7 coz dont exist
int minimumSwaps(vector<int> arr){
	int temp, swaps=0;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] != arr[arr[i]-1]){
			temp = arr[arr[i]-1];
			arr[arr[i]-1] = arr[i];
			arr[i] = temp;
			i--;
			swaps++;
		}
	}
	return swaps;
}

int main(){
	vector<int> v = {1,3,5,2,4,7,6};
	cout << minimumSwaps(v) << endl;
	return 0;
}