#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int r, c, k, t, lx = 3, ly = 3, arr[101][101];
typedef struct { int n, cnt; }num; 
bool comp(num a, num b) { if (a.cnt != b.cnt) return a.cnt < b.cnt; else return a.n < b.n; }
void r_calculation()
{
	int cx = 0;
	for (int y = 1; y <= ly; y++) {
		bool visited[101]; memset(visited, 0, sizeof(visited)); 
		map<int, int> m; vector<num> v;
		for (int x = 1; x <= lx; x++) {
			if (!arr[y][x]) continue;
			else if (visited[arr[y][x]]) m[arr[y][x]]++;
			else { m.insert({ arr[y][x], 1 }); visited[arr[y][x]] = true; }
		}
		for (auto it = m.begin(); it != m.end(); it++) v.push_back({it->first, it->second});
		sort(v.begin(), v.end(), comp); 
		memset(arr + y, 0, sizeof(int) * 101);
		for (int x = 1; x <= (int)v.size() * 2; x++) {
			if (x % 2) { arr[y][x] = v[x / 2].n; }
			else { arr[y][x] = v[x / 2 - 1].cnt; }
		}
		cx = max(cx, (int)m.size() * 2);
	}
	lx = cx, t++;
}
void c_calculation()
{
	int cy = 0;
	for (int x = 1; x <= lx; x++) {
		bool visited[101]; memset(visited, 0, sizeof(visited));
		map<int, int> m; vector<num> v;
		for (int y = 1; y <= ly; y++) {
			if (!arr[y][x]) continue;
			else if (visited[arr[y][x]]) m[arr[y][x]]++;
			else { m.insert({ arr[y][x], 1 }); visited[arr[y][x]] = true; }
		}
		for (auto it = m.begin(); it != m.end(); it++) v.push_back({it->first, it->second});
		sort(v.begin(), v.end(), comp);
		for (int y = 1; y <= ly; y++) arr[y][x] = 0;
		for (int y = 1; y <= (int)v.size() * 2; y++) {
			if (y % 2) { arr[y][x] = v[y / 2].n; }
			else { arr[y][x] = v[y / 2 - 1].cnt; }
		}
		cy = max(cy, (int)m.size() * 2);
	}
	ly = cy, t++;
}

int main()
{
	cin >> r >> c >> k;
	for (int y = 1; y <= 3; y++) for (int x = 1; x <= 3; x++) cin >> arr[y][x];
	while (arr[r][c] != k) { 
		if (t > 100) { cout << -1 << "\n"; return 0; }
		else if (ly >= lx) r_calculation(); 
		else c_calculation(); 
	}
	cout << t << "\n";
	return 0;

}
