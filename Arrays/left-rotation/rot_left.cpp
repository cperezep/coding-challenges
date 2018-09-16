#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, d; cin >> n >> d;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
        cin >> v[(i-d < 0) ? n+(i-d) : i-d];
    
    for(auto i: v)
        cout << i << " ";
    return 0;
}