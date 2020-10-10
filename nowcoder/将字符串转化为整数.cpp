#include<iostream>
#include<climits>
using namespace std;
//url: https://www.nowcoder.com/practice/44d8c152c38f43a1b10e168018dcc13f?tpId=188&tags=&title=&diffculty=0&judgeStatus=0&rp=1
class Solution {
public:
	int atoi(const char* str) {
		if (str == nullptr) return 0;
		int res = 0;
		int m = 1;
		const char* p = str;
		while (isspace(*p) && *p)p++;
		if (*p == '+') {
			m = 1;
			p++;
		}
		else if (*p == '-') {
			m = -1;
			p++;
		}
		while (p) {
			if (*p >= '0' && *p <= '9') {
				if (res > INT_MAX / 10 || res == INT_MAX / 10 && (*p - '0') > INT_MAX % 10) {
					return m == 1 ? INT_MAX : INT_MIN;
				}
				res = res * 10 + (*p - '0');
			}
			else {
				break;
			}
			p++;
		}
		return res * m;
	}
};

int main() {
	Solution s;
	cout << s.atoi("    010");
}