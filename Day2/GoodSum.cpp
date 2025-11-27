#include <iostream>
#include <vector>
using namespace std;

int good_sum(int N, vector<int> &A) {
    vector<int> st;  // stack

    for (int i = 0; i < N; i++) {
        int x = A[i];

        if (x >= 0) {
            st.push_back(x);
        } else {
            int need = -x;
            int removed_sum = 0;

            // Remove minimum elements from back
            while (!st.empty() && removed_sum < need) {
                removed_sum += st.back();
                st.pop_back();
            }

            // Regardless of removed sum, push abs(x)
            st.push_back(-x);
        }
    }

    // Sum remaining elements
    long long ans = 0;
    for (int v : st) ans += v;

    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    cout << good_sum(N, A) << endl;
    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/302515?moduleId=406