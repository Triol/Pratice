#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;
//url:  https://www.nowcoder.com/practice/93aacb4a887b46d897b00823f30bfea1?tpId=188&tags=&title=&diffculty=0&judgeStatus=0&rp=1
class LFU_Cache {
private:
	size_t capacity;
	size_t left_size;

	using pkv_t = pair<int, int>;
	using list_pkv_t = list<pkv_t>;
	list< pair<int, list_pkv_t> >cache_list;

	using row_iter_t = decltype(cache_list)::iterator;
	using col_iter_t = list_pkv_t::iterator;
	unordered_map<int, pair<row_iter_t, col_iter_t> >mp;
public:
	LFU_Cache(size_t capacity):capacity(capacity) {
		left_size = capacity;
	}
	int get(int key) {
		auto p = mp.find(key);
		if (p == mp.end()) {
			return -1;
		}
		else {
			p->second = to_next_times_list(p->second.first, p->second.second);
			return (p->second.second)->second;
		}
	}
	void set(int key, int val) {
		auto p = mp.find(key);
		if (p == mp.end()) { //not found
			if (!left_size) remove();
			auto row_iter = cache_list.begin();
			if (row_iter == cache_list.end() || row_iter->first != 1) {
				row_iter = cache_list.insert(row_iter, { 1, {} });
			}
			list_pkv_t& col_list = row_iter->second;
			auto col_iter = col_list.insert(col_list.end(), { key, val });
			mp[key] = { row_iter, col_iter };
			left_size--;
		}
		else {//found
			auto res = to_next_times_list(p->second.first, p->second.second);
			p->second = res;
			(p->second.second)->second = val;
		}
	}
private:
	pair<row_iter_t, col_iter_t> to_next_times_list(row_iter_t row_iter, col_iter_t col_iter) {

		list_pkv_t& col_list = row_iter->second;

		if (col_list.size() == 1) {//only one
			row_iter->first++;
			
		}
		else {//else remove it to a new list
			//remove
			pkv_t _pkv = *col_iter; //save key, value
			int rep_op = row_iter->first; // save the repeat time
			col_list.erase(col_iter);

			//insert to a new list
			row_iter++;

			//not a corresponding list, create and redirect to a new list
			if (row_iter == cache_list.end() || row_iter->first != rep_op + 1) {
				row_iter = cache_list.insert(row_iter, { rep_op + 1, {} });
			}
			list_pkv_t& col_list = row_iter->second;
			//push back
			col_iter = col_list.insert(col_list.end(), _pkv);
			
		}
		return { row_iter, col_iter };
	}
	void remove() {
		if (capacity == left_size) return;
		auto row_iter = cache_list.begin();
		list_pkv_t& col_list = row_iter->second;
		auto col_iter = col_list.begin();
		int key = col_iter->first;
		mp.erase(key);
		col_list.erase(col_iter);
		if (col_list.size() == 0) cache_list.erase(row_iter);

		left_size++;
	}

};
class Solution {
public:
	/**
	 * lfu design
	 * @param operators int整型vector<vector<>> ops
	 * @param k int整型 the k
	 * @return int整型vector
	 */
	vector<int> LFU(vector<vector<int> >& operators, int k) {
		// write code here
		LFU_Cache lfu(k);
		vector<int>res;
		for (auto v : operators) {
			int op = v[0];
			if (op == 1) lfu.set(v[1], v[2]);
			else if (op == 2) res.push_back(lfu.get(v[1]));
		}
		return res;
	}
};
int main() {
	vector< vector<int> >q = { { {1,1,1}, {1,2,2}, {1,3,2}, {1,2,4}, {1,3,5}, {2,2}, {1,4,4}, {2,1}} };
	int k = 3;
	Solution s;
	for (auto k : s.LFU(q, k)) {
		cout << k << ',';
	}
	return 0;
}