#include<cstdio>
#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>>pad(8, vector<int>(8));
bool bound(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}
int ans = 0;
void dfs(vector<vector<int>>cur_pad, int left, int x) {

	if (left == 0) {
		int cnt = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (cur_pad[i][j] == 2)
					cnt++;
			}
		}
		ans = max(ans, cnt);
		return;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (cur_pad[i][j] != 0)
				continue;
			bool flag = false;
			decltype(cur_pad) new_pad = cur_pad;
			new_pad[i][j] = x;
			for (int dx = -1; dx <= 1; dx++) {
				for (int dy = -1; dy <= 1; dy++) {
					if (dx == 0 && dy == 0) continue;
					int nx = i + dx, ny = j + dy;
					bool _flag = false;
					int cnt = 0;
					while (bound(nx, ny)) {
						if (new_pad[nx][ny] == 0) {
							_flag = false;
							break;
						}
						else if (new_pad[nx][ny] == x) {
							if (cnt) _flag = true;
							break;
						}
						else if (new_pad[nx][ny] == 3 - x) {
							cnt++;
						}
						nx += dx;
						ny += dy;
					}
					if (_flag) {
						flag = true;
						int nx = i + dx, ny = j + dy;
						while (bound(nx, ny)) {
							if (new_pad[nx][ny] == x)break;
							new_pad[nx][ny] = x;
							nx += dx;
							ny += dy;
						}
					}
				}
			}
			if (flag) {
				dfs(new_pad, left - 1, 3 - x);
			}
		}
	}
}
int main() {
	int s = 0;
	scanf("%d", &s);
	int b = 0, w = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%d", &pad[i][j]);
			if (pad[i][j] == 1) b++;
			else if (pad[i][j] == 2) w++;
		}
	}

	dfs(pad, (s - 1) * 2 + 1, 2);

	printf("%d", ans);
	return 0;
}