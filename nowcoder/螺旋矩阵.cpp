#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> >& matrix) {
		if (matrix.size() == 0) return vector<int>();
		int r = 0, c = -1;
		//state: 
//        const int RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3, END = 4;
		int width = matrix[0].size(), height = matrix.size();
		vector<int>res;
		while (width > 0 && height > 0) {
			//go right
			for (int i = 0; i < width; i++) {
				res.emplace_back(matrix[r][++c]);
			}
			//go down
			for (int i = 0; i < height - 1; i++) {
				res.emplace_back(matrix[++r][c]);
			}
			//go left
			if(height > 1)
			for (int i = 0; i < width - 1; i++) {
				res.emplace_back(matrix[r][--c]);
			}
			//go up
			if(width > 1)
			for (int i = 0; i < height - 2; i++) {
				res.emplace_back(matrix[--r][c]);
			}
			width -= 2;
			height -= 2;
		}
		return res;
	}
};

int main() {
	vector<vector<int>>m = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9}
	},
		m1 = { {1, 2}, {3, 4} },
		m2 = { {1, 2, 3, 4} },
		m3 = { {1}, {2}, {3}, {4} };
	Solution s;
	for (auto k : s.spiralOrder(m3)) {
		cout << k << ',';
	}
	return 0;
}