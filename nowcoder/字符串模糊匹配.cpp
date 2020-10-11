#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;
char str[1005];
char pat[200];
int ans = INT_MAX;
void solve(int p1, int p2, int len_str, int len_pat) {
	
	if (p2 == len_pat) {
		ans = min(ans, p1);
		return;
	}
	if (p1 >= len_str || p2 > len_str)return;
	if (str[p1] == pat[p2]) {
		solve(p1 + 1, p2 + 1, len_str, len_pat);
	}else if (pat[p2] == '?') {
		solve(p1 + 1, p2 + 1, len_str, len_pat);
		solve(p1 + 2, p2 + 1, len_str, len_pat);
		solve(p1 + 3, p2 + 1, len_str, len_pat);
	}
	

}
int main() {	
	scanf("%s%s", str, pat);
	int len_str = strlen(str);
	int len_pat = strlen(pat);
	solve(0, 0, len_str, len_pat);
	printf("%d", ans == INT_MAX ? -1 : ans);
	return 0;
}