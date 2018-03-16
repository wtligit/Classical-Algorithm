#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	void LCS(const string& a, const string& b, vector<vector<int>>& dp, vector<vector<int>>& flag) {
		int aLen = a.length();
		int bLen = b.length();
		for (int i = 1; i <= aLen; i++) {
			for (int j = 1; j <= bLen; j++) {
				if (a[i-1] == b[j-1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					//向右下标记
					flag[i][j] = 1;
				}
				else if (dp[i][j - 1] > dp[i - 1][j]) {
						dp[i][j] = dp[i][j - 1];
						//向右标记
						flag[i][j] = 2;
					}
				else {
						dp[i][j] = dp[i - 1][j];
						//向下标记
						flag[i][j] = 3;
					}
			}
		}
	}
	void getLCS(const string& a, const string& b, vector<vector<int>>& flag, vector<char>& path) {
		int i = a.length();
		int j = b.length();
		while (i > 0 && j > 0) {
			if (flag[i][j] == 1) {
				path.push_back(a[i - 1]);
				i--;
				j--;
			}
			else if (flag[i][j] == 2) {
				j--;
			}
			else {
				i--;
			}
		}
	}
};
int main() {
	string a= "ABCBDAB";
	string b="BDCABA";
	int aLen = a.length();
	int bLen = b.length();
	vector<vector<int>> dp(aLen+1,vector<int>(bLen+1,0));
	vector<vector<int>> flag(aLen+1, vector<int>(bLen+1, 0));
	vector<char> path;
	Solution s;
	s.LCS(a,b,dp,flag);
	s.getLCS(a,b,flag,path);
	cout << "length" << dp[a.length()][b.length()] << endl;
	int pSize = path.size();
	for (int i = pSize-1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << endl;
	return 0;
}