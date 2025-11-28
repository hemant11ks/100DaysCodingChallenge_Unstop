#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long val = 1;

    // First element of the row is always 1
    cout << 1;

    for (int k = 1; k <= n; k++) {
        val = val * (n - k + 1) / k;   // Compute next binomial coefficient
        cout << " " << val;
    }

    return 0;
}


// Link to Problem : https://unstop.com/code/challenge-assessment/250178?moduleId=408