#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Placeholder for user logic function
int user_logic(vector<string>& ops) {
     vector<int> record;

    for (string &op : ops) {
        if (op == "C") {
            // Invalidate last score
            record.pop_back();
        } 
        else if (op == "D") {
            // Double the previous score
            int last = record.back();
            record.push_back(last * 2);
        } 
        else if (op == "+") {
            // Sum of last two scores
            int last1 = record.back();
            int last2 = record[record.size() - 2];
            record.push_back(last1 + last2);
        } 
        else {
            // Integer value
            record.push_back(stoi(op));
        }
    }

    // Calculate total sum
    int sum = 0;
    for (int val : record) sum += val;

    return sum;
}

int main() {
    int n;
    cin >> n; // Input for number of operations
    vector<string> ops(n);
    
    // Input vector of operations
    for (int i = 0; i < n; ++i) {
        cin >> ops[i];
    }
    
    // Call user logic function and print the output
    int result = user_logic(ops);
    cout << result << endl;
    
    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/250404?moduleId=407