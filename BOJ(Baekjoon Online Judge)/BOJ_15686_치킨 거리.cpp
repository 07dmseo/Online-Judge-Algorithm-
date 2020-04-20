/* STL을 활용한 조합 구하기 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct { int x, y; }pos; vector<pos> house, chicken;
int n, m, a, ans = 1e9;
int main()
{
	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> a;
			switch (a) {
			case 1: house.push_back({ x,y }); break;
			case 2: chicken.push_back({ x,y }); break;
			default: break;
			}
		}
	}
	vector<bool> comb;
	for (int i = 0; i < m; i++) comb.push_back(1);
	for (int i = m; i < chicken.size(); i++) comb.push_back(0);
	sort(comb.begin(), comb.end());
	do {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int curr_d = 1e9;
			for (int j = 0; j < comb.size(); j++) {
				if (comb[j]) curr_d = min(curr_d, abs(house[i].x - chicken[j].x) + abs(house[i].y - chicken[j].y));
			}
			sum += curr_d;
		}
		ans = min(ans, sum);
	} while (next_permutation(comb.begin(), comb.end()));
	cout << ans << endl;
	return 0;

}

/* 재귀를 활용한 조합 구하기 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct { int x, y; } pos; vector<pos> house, chicken;
bool visited[250]; int n, m, a, ans = 1e9;
void comb(int n, int r, int idx, vector<int>& t)
{
	if (!r) {
		int res = 0;
		for (int i = 0; i < house.size(); i++) {
			int curr_d = 1e9;
			for (int j = 0; j < t.size(); j++) {
				curr_d = min(curr_d, abs(house[i].x - chicken[t[j]].x) + abs(house[i].y - chicken[t[j]].y));
			}
			res += curr_d;
		}
		ans = min(ans, res);
		return;
	}
	for (int i = idx; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true; t.push_back(i);
		comb(n, r - 1, i + 1, t);
		visited[i] = false; t.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> a;
			switch (a) {
			case 1: house.push_back({ x,y }); break;
			case 2: chicken.push_back({ x,y }); break;
			default: break;
			}
		}
	}
	vector<int> subcase;
	comb(chicken.size(), m, 0, subcase);
	cout << ans << endl;
	return 0;

}