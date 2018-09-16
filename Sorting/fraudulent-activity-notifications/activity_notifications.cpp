#include <iostream>
#include <vector>

using namespace std;

float get_median(vector<int>& freq, int& d, int& index_median){
  int count, i, j;
  count = i = j = 0;
  while(true){
    count += freq[i];
    if(count >= index_median) break;
    i++;
  }
  if(d%2 != 0 || count > index_median){
    return i;
  } else{
    j = i+1;
    while(freq[j] == 0){
        j++;
    }
    return (float)(i+j)/2;
  }
}

int activityNotifications(vector<int>& expenditure, int& d){
  int index_median, remove_elem = 0, notifications = 0;
  float median;
  index_median = (d%2==0 ? d/2 : d/2+1);
  vector<int> freq(201, 0);

  for (int i = 0; i < d; i++)
    freq[expenditure[i]] += 1;

  for(int i = d; i < expenditure.size(); i++){
    median = get_median(freq, d, index_median);
    if(expenditure[i] >= median*2) notifications++;

    // Remove first element
    freq[expenditure[remove_elem]] -= 1;
    remove_elem++;
    // Add next element
    freq[expenditure[i]] += 1;
  }
  return notifications;
}

int main(){
  int n, d; cin >> n >> d;
  vector<int> expenditure(n);

  for(auto& it: expenditure)
    cin >> it;

  cout << activityNotifications(expenditure, d) << endl;
}