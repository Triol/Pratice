#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
vector<int>vec;
int get_index(vector<int>& vec, int l, int r) {
	int tp = vec[l];
	while (l < r) {
		while (l < r && vec[r] >= tp) r--;
		vec[l] = vec[r];
		while (l < r && vec[l] <= tp) l++;
		vec[r] = vec[l];
	}
	vec[r] = tp;
	return r;

}
int quick_select(vector<int>& vec, int l, int r, int k) {
	if (l >= r) return vec[l];
	int id = get_index(vec, l, r);
	int len = id - l + 1;
	if (k == len) return vec[id];
	else if (k < len) return quick_select(vec, l, id - 1, k);
	else if (k > len) return quick_select(vec, id + 1, r, k - len);
}

int main() {

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	int res = quick_select(vec, 0, n - 1, k + 1);
	printf("%d", res);
	return 0;
}