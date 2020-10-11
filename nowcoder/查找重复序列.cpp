#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	map<vector<int>, vector<int>>mp;
	for (int i = 0; i < n; i++) {
		vector<int>vec;
		int k;
		scanf("%d", &k);
		while (k--) {
			int x;
			scanf("%d", &x);
			vec.push_back(x);
		}
		mp[vec].push_back(i);
	}
	bool flag = false;
	vector<vector<int>>ans;
	for (auto v : mp) {
		if (v.second.size() > 1) {
			flag = true;
			ans.push_back(v.second);
		}
	}
	sort(ans.begin(), ans.end(), [](vector<int>& lhs, vector<int>& rhs)->bool {
		if (lhs.size() != 0 && rhs.size() != 0) return lhs[0] < rhs[0];
		else return lhs.size() < rhs.size();
		});
	for (auto v : ans) {
		for (int i = 0; i < v.size(); i++) {
			printf("%s%d", i ? " " : "", v[i]);
		}
		printf("\n");
	}
	if (!flag) printf("no");
	return 0;
}