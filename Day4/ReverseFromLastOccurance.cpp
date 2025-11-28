#include <iostream>
#include <string>
#include <algorithm>

std::string transform_string(const std::string& s, char ch) {
    int last_pos = -1;

    // Find last occurrence of ch
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ch) {
            last_pos = i;
            break;
        }
    }

    // If ch not found, return original string
    if (last_pos == -1) return s;

    // Reverse substring from last_pos to end
    std::string result = s;
    std::reverse(result.begin() + last_pos, result.end());

    return result;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    size_t space_pos = input.find(' ');
    std::string s = input.substr(0, space_pos);
    char ch = input[space_pos + 1];
    
    std::string result = transform_string(s, ch);
    std::cout << result << std::endl;
    return 0;
}


// Link to Problem : https://unstop.com/code/challenge-assessment/250903?moduleId=408