#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void processQueries(int q, const vector<vector<string>>& queries) {
    unordered_map<string, long long> stock; // store stock of each chocolate

    for (int i = 0; i < q; i++) {
        int type = stoi(queries[i][0]);
        string name = queries[i][1];
        long long x = stoll(queries[i][2]);

        if (type == 1) {
            // Add chocolates
            stock[name] += x;
        } 
        else {
            // Sell chocolates
            long long available = stock[name];
            long long sold = min(available, x);

            cout << sold << "\n";

            stock[name] -= sold;
        }
    }
}

int main() {
    int q;
    cin >> q;
    vector<vector<string>> queries(q, vector<string>(3));

    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    processQueries(q, queries);
    return 0;
}


// Link to Problem : https://unstop.com/code/challenge-assessment/307596?moduleId=409