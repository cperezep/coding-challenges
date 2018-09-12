// Grading Students
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> grades(n);
    int item;

    for (auto it = grades.begin(); it != grades.end(); it++) {
        cin >> item;
        *it = item >= 38 && (item+(5-item%5))-item < 3 ? (item+(5-item%5)) : item;
    }

    for (auto &it : grades)
        cout << it << endl;

    return 0;
}