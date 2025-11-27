#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
      int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int index = 0;  // position to place next non-zero element

    // Move all non-zero elements to the front
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            arr[index++] = arr[i];
        }
    }

    // Fill the remaining positions with zeroes
    while(index < n) {
        arr[index++] = 0;
    }

    // Output the result
    for(int x : arr) {
        cout << x << " ";
    }

    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/250721?moduleId=407