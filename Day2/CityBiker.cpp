#include <iostream>
#include <vector>
using namespace std;

// User logic function
int highestAltitude(int n, const vector<int>& arr) {
    int currentAltitude = 0;
    int maxAltitude = 0;

    for (int i = 0; i < n; ++i) {
        currentAltitude += arr[i];
        maxAltitude = max(maxAltitude, currentAltitude);
    }

    return maxAltitude;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int result = highestAltitude(n, arr);
    cout << result << endl;

    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/250431?moduleId=406