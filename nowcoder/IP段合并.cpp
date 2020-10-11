#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	vector<pair<int, int>>vec;
	int n;
	scanf("%d", &n);
	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec.emplace_back(x, y);
	}
	sort(vec.begin(), vec.end());
	vector<pair<int, int>>ans;
	int cur_l = vec[0].first;
	int cur_r = vec[0].second;
	for (auto p : vec) {
		if (p.first <= cur_r) {
			cur_r = max(cur_r, p.second);
		}
		else {
			ans.emplace_back(cur_l, cur_r);
			cur_l = p.first;
			cur_r = p.second;
		}
	}
	ans.emplace_back(cur_l, cur_r);
	for (auto p : ans) {
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}