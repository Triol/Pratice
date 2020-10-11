#include<iostream>
#include<cstdio>
using namespace std;
int x, y, z;
int res = 0;
void dfs(int n) {
	if (n < 0) return;
	if (n == 0) {
		res++;
		return;
	}
	dfs(n - x);
	dfs(n - y);
	dfs(n - z);
}
int main() {
	int n;
	scanf("%d%d%d%d", &n, &x, &y, &z);
	dfs(n);
	printf("%d", res);
	return 0;
}