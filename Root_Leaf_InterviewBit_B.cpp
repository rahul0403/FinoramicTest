/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    int sum=B-A->val;
    vector< vector<int> > x;
     vector<vector <int> > ans={};
    if((A->left==NULL)&&(A->right==NULL)&&(sum==0))
    {
        vector<int> y;
        y.push_back(A->val);
        ans.push_back(y);
        return ans;
    }
 
    if(A->left!=NULL)
    {
        x=Solution::pathSum(A->left,sum);
 
        for (int i=0;i<x.size();i++)
        {
            vector <int> xx;
            xx=x[i];
            if(x[i].size()!=0)
            {
                //xx.push_back(A->val);
                xx.insert(xx.begin(), A->val);
            }
            ans.push_back(xx);
 
        }
    }
    if(A->right!=NULL)
    {
        x=Solution::pathSum(A->right,sum);
 
        for (int i=0;i<x.size();i++)
        {
            vector <int> xx;
            xx=x[i];
            if(x[i].size()!=0)
            {
                xx.insert(xx.begin(), A->val);
            }
            ans.push_back(xx);
        }
 
    }
    return ans;
}
