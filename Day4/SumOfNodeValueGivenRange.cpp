#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int rangeSumBST(TreeNode* root, int start, int end) {
    if (!root) return 0;

    if (root->val < start)
        return rangeSumBST(root->right, start, end);

    if (root->val > end)
        return rangeSumBST(root->left, start, end);

    return root->val +
           rangeSumBST(root->left, start, end) +
           rangeSumBST(root->right, start, end);
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertBST(root, val);
    }

    int start, end;
    cin >> start >> end;

    cout << rangeSumBST(root, start, end) << endl;

    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/250874?moduleId=408