#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
	int n; cin >> n;
  int k; cin >> k;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
  	int arr_item; cin >> arr_item;
    arr[i] = arr_item;
  }
  
  k--;
  sort(arr.begin(), arr.end());
  int min = pow(10, 9);
  for(int i = 0; i < arr.size()-k; i++){
  	if(arr[i+k]-arr[i] < min)
    	min = arr[i+k]-arr[i];
  }

  cout << min;
  return 0;
}