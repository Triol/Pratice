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
void quick_sort(vector<int>& vec, int l, int r) {
	if (l >= r) return;
	int id = get_index(vec, l, r);
	quick_sort(vec, l, id - 1);
	quick_sort(vec, id + 1, r);
}

int main() {
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	quick_sort(vec, 0, n - 1);
	for (auto k : vec) {
		printf("%d ", k);
	}
	return 0;
}