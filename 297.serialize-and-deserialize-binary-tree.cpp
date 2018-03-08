/*
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (34.72%)
 * Total Accepted:    95.9K
 * Total Submissions: 276.2K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * For example, you may serialize the following tree
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * 
 * as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * 
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 * Credits:
 * Special thanks to @Louis1992 for adding this problem and creating all test
 * cases.
 * 
 */
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    void SerializeHelper(TreeNode *root,stringstream &ss){
        if(root==NULL){
            ss<<"# ";
            return ;
        }
        ss<<root->val<<" ";
        SerializeHelper(root->left,ss);
        SerializeHelper(root->right,ss);
    }
    TreeNode * DeserializeHelper(stringstream &ss){
        string s;
        ss>>s;
        if(s=="#")
            return NULL;
        int t=stoi(s);
        TreeNode *temp=new TreeNode(t);
        temp->left=DeserializeHelper(ss);
        temp->right=DeserializeHelper(ss);
        return temp;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        SerializeHelper(root,ss);
        //std::cout<<ss.str();
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return DeserializeHelper(ss);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
