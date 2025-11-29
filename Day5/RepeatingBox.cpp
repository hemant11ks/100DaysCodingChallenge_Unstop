#include <bits/stdc++.h>
using namespace std;

int main() {
    int total;
    cin >> total;
    
    vector<int> arr(total);
    for(int i = 0; i < total; i++) cin >> arr[i];
    
    unordered_map<int, int> freq;
    
    for(int x : arr) {
        freq[x]++;
    }
    
    int n = total / 2;
    
    for(auto &p : freq) {
        if(p.second == n) {
            cout << p.first;
            break;
        }
    }
    
    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/250490?moduleId=409