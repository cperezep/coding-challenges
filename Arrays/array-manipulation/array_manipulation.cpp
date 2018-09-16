#include <iostream>
#include <vector>

using namespace std;

int main(){
  long int n, m, x = 0, max = 0; 
  cin >> n >> m;
  vector<int> arr(n+1);
  int a, b, k;
  
  for(int i = 0; i < m; i++){
    cin >> a >> b >> k;
    arr[a] += k;
    if(b+1 <= n)
      arr[b+1] -= k;
  }
  
  for(auto& i: arr){
		x = x + i;
		if(max < x) max = x;
  }
  
  cout << max << endl;
  return 0;
}