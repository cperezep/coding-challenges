#include <iostream>
#include <vector>

using namespace std;

bool sort_pairs(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second != b.second)
      return a.first < b.first;
  return a.second < b.second;
}

int main(){
    vector< pair<int,int> > pairs;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        pairs.push_back(make_pair(a+b, i+1));
    }
    stable_sort(pairs.begin(), pairs.end(), sort_pairs);
    for(int i = 0; i < pairs.size(); i++)
        cout << pairs[i].second << " ";
    return 0;
}

// Best Solution use multimap
/*
int main(){
    multimap<int,int> m;
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int a, b; cin >> a >> b;
        m.insert(make_pair(a+b, i));
    }
    for(multimap<int,int >::iterator me = m.begin(); me != m.end(); me++)
        cout<<me->second<<" ";      
    return 0;
}
*/
