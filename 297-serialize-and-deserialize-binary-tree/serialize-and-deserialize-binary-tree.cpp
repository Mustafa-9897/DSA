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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        string s="";
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node==NULL) s += "null,";
            else{
                s += (to_string(node->val)+',');
            }
            // here we are not checking of validity of node's left and right , we are checking only for node since even if its left and right are null still we have to store it in string
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        stringstream s(data); // allows us to traverse strign=data as a collection of string objects
        string str;

        getline(s,str,','); // gives us the first string object of s seperated by , and assigns it to str . similarly next getline will give the next object after , 

        queue<TreeNode*>q;
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="null"){
                node->left=NULL;
            }
            else{
                TreeNode* l=new TreeNode(stoi(str));
                q.push(l);
                node->left=l;
            }

            getline(s,str,',');
            if(str=="null"){
                node->right=NULL;
            }
            else{
                TreeNode* r=new TreeNode(stoi(str));
                q.push(r);
                node->right=r;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));