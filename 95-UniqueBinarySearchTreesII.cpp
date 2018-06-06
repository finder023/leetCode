//一个非常差劲的方法

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//把这个问题简单化，输入顺序不同，造成数的结构不同。
//要做的有两项，一是建树，二是排列组合

//这个思路有问题，不同的输入序列，数的结构可能是相同的，避免重复，是不是只和上一个重复？
//
class Solution {
public:
    bool is_same(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL && node2 == NULL)
            return true;
        if(node1 == NULL ^ node2 == NULL)
            return false;
        if(node1->val != node2->val)
            return false;
        return is_same(node1->left, node2->left) && is_same(node1->right, node2->right);
    }
    
    TreeNode* build_tree(vector<int>& data){
        if (data.size() == 0) return NULL;
        TreeNode* head = NULL, *new_node = NULL, *node = NULL;
        for(int i=0; i<data.size(); ++i){
            new_node = new TreeNode(data[i]);
            node = head;
            if(head == NULL){
                head = new_node;
                continue;
            }
            while(1){
                if(new_node->val > node->val){
                    if(node->right == NULL){
                        node->right = new_node;
                        break;
                    }
                    else
                        node = node->right;
                }
                else{
                    if(node->left == NULL){
                        node->left = new_node;
                        break;
                    }
                    else
                        node = node->left;
                }
            }            
        } 
        return head;
    }

    
    void generate_data(vector<int>& data, vector<bool>& isused, vector<TreeNode*>& tree, int index){
        if(index == data.size()){
            TreeNode* r = build_tree(data);
            if(tree.empty()){
                tree.push_back(r);
                return;
            }
            bool isexist = false;
            for(int i=0; i<tree.size(); ++i){
                if(is_same(r, tree[i])){
                    isexist = true;
                    break;
                }
            }
            if(!isexist)
                tree.push_back(build_tree(data));
            return;
        }
        for(int i=0; i<data.size(); ++i){
            if(isused[i])   continue;
            data[index] = i+1;
            isused[i] = true;
            generate_data(data, isused, tree, index+1);
            isused[i] = false;
        }
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0)  return vector<TreeNode*>();
        vector<int> order(n, 0);
        vector<bool> isused(n, false);
        vector<TreeNode*> trees;
        generate_data(order, isused, trees, 0 );
        return trees;
    }
};
