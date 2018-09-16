#include <iostream>
#include <vector>

using namespace std;

// Note: In order to pass the test case (wrong test) [1,3,5,2,4,6,8] 
// is necessary not evaluate the position 7 because not exist.
int main(){
  int n; cin >> n;
  vector<int> arr(n);
  for(auto& it: arr)
    cin >> it;
  
  int temp, swaps = 0;
  for(int i = 0; i < arr.size(); i++){
    if(arr[i] != arr[arr[i]-1]){
      temp = arr[arr[i]-1];
      arr[arr[i]-1] = arr[i];
      arr[i] = temp;
      swaps++;
      i--;
    }
  }
  cout << swaps << endl;
  return 0;
}