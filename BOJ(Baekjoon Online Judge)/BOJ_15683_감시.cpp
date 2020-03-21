#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool visited[9][9];
int n, m, s = 100, l[] = { 0, 4, 2, 4, 4, 1 }, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, map[9][9];
typedef struct { int x, y, t; } cam; vector<cam> pos; queue<vector<int>> q;
int bf()
{
	bool backup[9][9]; int cnt = 0;
	while (!q.empty()) {
		memcpy(backup, visited, sizeof(visited));
		vector<int> v = q.front(); q.pop();
		for (int i = 0; i < v.size(); i++) {
			int cx = pos[i].x, cy = pos[i].y;
			switch (pos[i].t) {
			case 1:
				while (1) {
					cx += dx[v[i]], cy += dy[v[i]];
					if (cx < 1 || cx > m || cy < 1 || cy > n || map[cy][cx] == 6) break;
					else visited[cy][cx] = true;
				}
				break;
			case 2:
				for (int j = 0; j < 4; j++) {
					if (!v[i] && (j % 2)) continue; else if (v[i] && !(j % 2)) continue;
					else {
						while (1) {
							cx += dx[j], cy += dy[j];
							if (cx < 1 || cx > m || cy < 1 || cy > n || map[cy][cx] == 6) break;
							else visited[cy][cx] = true;
						}
						cx = pos[i].x, cy = pos[i].y;
					}
				}
				break;
			case 3:
				for (int j = 0; j < 2; j++) {
					while (1) {
						cx += dx[v[i] % 4], cy += dy[v[i] % 4];
						if (cx < 1 || cx > m || cy < 1 || cy > n || map[cy][cx] == 6) break;
						else visited[cy][cx] = true;
					}
					cx = pos[i].x, cy = pos[i].y, v[i]++;
				}
				break;
			case 4:
				for (int j = 0; j < 4; j++) {
					if (j == v[i]) continue;
					while (1) {
						cx += dx[j], cy += dy[j];
						if (cx < 1 || cx > m || cy < 1 || cy > n || map[cy][cx] == 6) break;
						else visited[cy][cx] = true;
					}
					cx = pos[i].x, cy = pos[i].y;
				}
				break;
			case 5:
				for (int j = 0; j < 4; j++) {
					while (1) {
						cx += dx[j], cy += dy[j];
						if (cx < 1 || cx > m || cy < 1 || cy > n || map[cy][cx] == 6) break;
						else visited[cy][cx] = true;
					}
					cx = pos[i].x, cy = pos[i].y;
				}
				break;
			default:
				break;
			}
		}
		for (int y = 1; y <= n; y++)
			for (int x = 1; x <= m; x++)
				if (!visited[y][x]) cnt++;
		s = min(s, cnt); cnt = 0;
		memcpy(visited, backup, sizeof(backup));
	}
	return s;
}
void comb(int n, int r, vector<int>& v)
{
	if (r >= n) { q.push(v); return; }
	for (int i = 0; i < l[pos[r].t]; i++) { v.push_back(i); comb(n, r + 1, v); v.pop_back(); }
}
int main()
{
	vector<int> v;  cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			cin >> map[y][x];
			if (map[y][x] && map[y][x] != 6) { visited[y][x] = true; pos.push_back({ x,y,map[y][x] }); }
			else if (map[y][x] == 6) visited[y][x] = true;
		}
	}
	comb(pos.size(), 0, v);
	cout << bf() << endl;
	return 0;

}