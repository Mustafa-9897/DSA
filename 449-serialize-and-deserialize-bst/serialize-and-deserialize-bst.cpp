/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root, string &s) {
        if (root == NULL) return;

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        return s;
    }

    TreeNode* helper(string &s, int &i, long long low, long long high) {
        if (i >= s.size()) return NULL;

        int j = i;
        while (j < s.size() && s[j] != ',') {
            j++;
        }

        int val = stoi(s.substr(i, j - i));

        if (val <= low || val >= high) return NULL;

        i = j + 1;

        TreeNode* root = new TreeNode(val);
        root->left = helper(s, i, low, val);
        root->right = helper(s, i, val, high);

        return root;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        int i = 0;
        return helper(data, i, LLONG_MIN, LLONG_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;