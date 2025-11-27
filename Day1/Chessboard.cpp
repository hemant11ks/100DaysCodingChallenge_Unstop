#include <iostream>
#include <string>

std::string determineColor(const std::string& s) {
    // Write your logic here to determine the color based on the string s.
    // Return "Black" or "White" based on the problem statement.\

    // Example b2 -> file = b, rank = 2

    char file = s[0]; // column letter
    char rank = s[1]; // row letter

    int fileConv = file - 'a' + 1;
    int rankConv = rank - '0';

    if((fileConv + rankConv)%2==0){
        return "Black";
    }
    else {
        return "White";
    }
}

int main() {
    std::string s;
    std::cin >> s;
    std::string result = determineColor(s);
    std::cout << result << std::endl;
    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/250904?moduleId=372