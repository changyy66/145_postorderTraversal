// 145_postorderTraversal.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
1
\
2
/
3

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <stack>
#include <vector>

using namespace std;

/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void postorderTraversal(TreeNode* root, vector<int> &res)
	{
		if (!root)return;
		postorderTraversal(root->left, res);
		postorderTraversal(root->right, res);
		res.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode* root) {
		if (!root)return{};
		TreeNode* tmp = root;
		vector<int> res;
		stack<TreeNode*> s;
		while (tmp || s.size()>0)
		{
			if (!tmp)
			{
				tmp = s.top();
				s.pop();
			}
			res.push_back(tmp->val);
			if (tmp->left)s.push(tmp->left);
			tmp = tmp->right;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
    return 0;
}

