#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
	TreeNode* preinCon(const vector<int>& pre, const vector<int>& in) {
		int preLen = pre.size();
		int inLen = in.size();
		if (preLen == 0 || inLen == 0 || preLen != inLen) {
			return NULL;
		}
		TreeNode* root =new TreeNode(pre[0]);
		int root_in = 0;
		for (int i = 0; i < inLen; i++) {
			if (pre[0] == in[i]) {
				root_in = i;
				break;
			}
		}
		vector<int> pre_left;
		vector<int> pre_right;
		vector<int> in_left;
		vector<int> in_right;
		for (int i = 0; i < root_in; i++) {
			in_left.push_back(in[i]);
			pre_left.push_back(pre[i + 1]);
		}
		for (int i = root_in + 1; i < preLen; i++) {
			in_right.push_back(in[i]);
			pre_right.push_back(pre[i]);
		}
		root->left = preinCon(pre_left, in_left);
		root->right = preinCon(pre_right, in_right);
		return root;
	}
	TreeNode* postinCon(const vector<int>& post, const vector<int>& in) {
		int postLen = post.size();
		int inLen = in.size();
		if (postLen == 0 || inLen == 0 || postLen != inLen) {
			return NULL;
		}
		TreeNode* root = new TreeNode(post[postLen - 1]);
		int root_in = 0;
		for (int i = 0; i < inLen; i++) {
			if (post[postLen - 1] == in[i]) {
				root_in = i;
				break;
			}
		}
		vector<int> post_left;
		vector<int> post_right;
		vector<int> in_left;
		vector<int> in_right;
		for (int i = 0; i < root_in; i++) {
			post_left.push_back(post[i]);
			in_left.push_back(in[i]);
		}
		for (int i = root_in; i < postLen - 1; i++) {
			post_right.push_back(post[i]);
			in_right.push_back(in[i + 1]);
		}
		root->left = postinCon(post_left, in_left);
		root->right = postinCon(post_right, in_right);
		return root;
	}
	void InOrder(TreeNode *root)
	{
		if (root == NULL)
			return;
		InOrder(root->left);
		std::cout << root->val << " ";
		InOrder(root->right);
	}
};
int main() {
	int a[5] = { 3,9,20,15,7 };
	int b[5] = { 9,3,15,20,7 };
	int c[5] = { 9,15,7,20,3 };
	vector<int> pre(a, a + 5);
	vector<int> in(b, b + 5);
	vector<int> post(c, c + 5);
	Solution s;
	TreeNode* p=s.preinCon(pre, in);
	s.InOrder(p);
	cout << endl;
	TreeNode* p2 = s.postinCon(post, in);
	s.InOrder(p2);
	while (1);
	return 0;
}