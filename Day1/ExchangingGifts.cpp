#include <iostream>
#include <vector>

void find_youngest_member(int n, int m, std::vector<std::pair<int, int>> &gifts) {
    // Write your logic here.
    std::vector<int> indegree(n + 1, 0);
    std::vector<int> outdegree(n + 1, 0);

    // Count indegree and outdegree
    for (auto &p : gifts) {
        int a = p.first;   // giver
        int b = p.second;  // receiver
        outdegree[a]++;
        indegree[b]++;
    }

    // Youngest member condition
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0) {
            std::cout << i;
            return;
        }
    }

    std::cout << -1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> gifts(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> gifts[i].first >> gifts[i].second;
    }
    find_youngest_member(n, m, gifts);
    return 0;
}


// Link to Problem : https://unstop.com/code/challenge-assessment/250196?moduleId=372