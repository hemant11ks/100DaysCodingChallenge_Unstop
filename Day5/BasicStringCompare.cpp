#include <iostream>
#include <string>
using namespace std;

string processString(const string &s) {
    string result = "";
    for (char ch : s) {
        if (ch == '#') {
            if (!result.empty())
                result.pop_back();
        } else {
            result.push_back(ch);
        }
    }
    return result;
}

bool userLogic(string bob, string alice) {
    string finalBob = processString(bob);
    string finalAlice = processString(alice);
    return finalBob == finalAlice;
}

int main() {
    string bob, alice;
    getline(cin, bob);
    getline(cin, alice);
    bool result = userLogic(bob, alice);
    cout << (result ? "YES" : "NO") << endl;
    return 0;
} 