#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef struct { int x, y, t; }pos; queue<pos> bfs_q; vector<pos> v;
int n, m, tcnt = 10000, lab[51][51], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visited[51][51] = { false, };
void bfs()
{
	pos curr_pos; int curr_x, curr_y; bool temp[51][51];
	memcpy(temp, visited, sizeof(visited));
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			if (temp[y][x]) bfs_q.push({ x,y,0 });
	while (!bfs_q.empty()) {
		curr_pos = bfs_q.front(); bfs_q.pop();
		for (int i = 0; i < 4; i++) {
			curr_x = curr_pos.x + dx[i], curr_y = curr_pos.y + dy[i];
			if (curr_x < 1 || curr_x > n || curr_y < 1 || curr_y > n) continue;
			else if (temp[curr_y][curr_x] || lab[curr_y][curr_x] == 1) continue;
			bfs_q.push({ curr_x, curr_y, curr_pos.t + 1 }); temp[curr_y][curr_x] = true;
		}
	}
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			if (!temp[y][x] && !lab[y][x]) return;
	tcnt = min(tcnt, curr_pos.t);
	return;

}
void bp(int idx, int cnt)
{
	if (cnt == m) { bfs(); return; }
	else if (idx >= v.size()) return;
	for (int i = idx; i < v.size(); i++) {
		pos curr_pos = v.at(i);
		visited[curr_pos.y][curr_pos.x] = true;
		bp(i + 1, cnt + 1);
		visited[curr_pos.y][curr_pos.x] = false;
	}
}
int main()
{
	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> lab[y][x];
			if (lab[y][x] == 2) v.push_back({ x,y,0 });
		}
	}
	bp(0, 0);
	if (tcnt != 10000) cout << tcnt << endl;
	else cout << -1 << endl;
	return 0;

}