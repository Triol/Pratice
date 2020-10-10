#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
// url: https://www.nowcoder.com/practice/9cf027bf54714ad889d4f30ff0ae5481?tpId=188&tags=&title=&diffculty=0&judgeStatus=0&rp=1
class Solution {
public:
	/**
	 * retrun the longest increasing subsequence
	 * @param arr int整型vector the array
	 * @return int整型vector
	 */
	vector<int> LIS(vector<int>& arr) {
		// write code here
		vector<int>v;
		vector<int>dp(arr.size());
		vector<int>ans;
		for (int i = 0; i < arr.size(); i++) {
			int x = arr[i];
			auto p = lower_bound(v.begin(), v.end(), x);
			if (p == v.end()) {
				v.push_back(x);
				dp[i] = v.size();
			}
			else {
				*p = x;
				dp[i] = p - v.begin() + 1;
			}
			if (dp[i] > ans.size()) {
				ans = vector<int>(v.begin(), v.begin() + dp[i]);
			}
			else if (dp[i] == ans.size()) {
				vector<int> tmp(v.begin(), v.begin() + dp[i]);
				if (tmp < ans) {
					ans = tmp;
				}
			}
		}
		for (int i = arr.size() - 1, j = ans.size(); i >= 0; i--) {
			if (dp[i] == j) {
				ans[--j] = arr[i];
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	for (auto k : s.LIS(vector<int>({1, 5, 10, 4, 11}))) {
		cout << k << ',';
	}

	return 0;
}