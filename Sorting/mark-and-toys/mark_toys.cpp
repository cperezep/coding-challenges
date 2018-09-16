#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> prices(n);

    for(auto& i: prices)
        cin >> i;

    sort(prices.begin(), prices.end());
    int toys = 0;
    for(auto& i: prices){
        if(k-i >= 0){
            k -= i;
            toys++;
        } else{
            cout << toys << endl;
            return 0;
        }
    }
    cout << toys << endl;
    return 0;
}