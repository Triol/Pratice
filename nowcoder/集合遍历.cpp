#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int ct[20];
int ct_1[20];
int k, n;
vector<int>tmp;
void dfs(int cur_k, int left_n) {
	if (!left_n) {
		for (int i = 0; i < k; i++) printf("%d", ct_1[i]);
		printf("\n");
		return;
	}
	if (cur_k >= k) return;
	for (int i = 0; i <= min(left_n, ct[cur_k]); i++) {
		ct_1[cur_k] = i;
		dfs(cur_k + 1, left_n - i);
	}
	ct_1[cur_k] = 0;
}
int main() {
	
	scanf("%d%d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", &ct[i]);
	}
	dfs(0, n);
	return 0;
}