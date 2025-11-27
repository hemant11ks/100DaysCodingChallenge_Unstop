#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countConsistentCars(const string& components, int n, const vector<string>& models) {
    
    // Create a boolean array of allowed characters
    bool allowed[26] = {false};
    for (char c : components) {
        allowed[c - 'a'] = true;
    }

    int count = 0;

    // Check each model
    for (const string &model : models) {
        bool consistent = true;

        for (char c : model) {
            if (!allowed[c - 'a']) {
                consistent = false;
                break;
            }
        }

        if (consistent) count++;
    }

    return count;
}

int main() {
    string components;
    int n;
    vector<string> models;

    getline(cin, components); 
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string model;
        cin >> model;
        models.push_back(model);
    }

    int result = countConsistentCars(components, n, models);
    cout << result << endl;

    return 0;
}


// Link to Problem : https://unstop.com/code/challenge-assessment/250500?moduleId=407