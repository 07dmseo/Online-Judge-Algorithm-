#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct { int x, y, t; }pos; queue<pos> bfs_q;
int m, n, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, box[1001][1001]; 
bool visited[1001][1001];
int bfs()
{
	int curr_x, curr_y, time = 0;
	while (!bfs_q.empty()) {
		pos curr_pos = bfs_q.front(); bfs_q.pop();
		time = max(time, curr_pos.t); box[curr_pos.y][curr_pos.x] = 1;
		for (int i = 0; i < 4; i++) {
			curr_x = curr_pos.x + dx[i], curr_y = curr_pos.y + dy[i];
			if (curr_x < 1 || curr_x > m || curr_y < 1 || curr_y > n) continue;
			else if (visited[curr_y][curr_x] || box[curr_y][curr_x] == -1) continue;
			bfs_q.push({ curr_x, curr_y, curr_pos.t + 1 }); visited[curr_y][curr_x] = true;
		}
	}
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= m; x++)
			if (!box[y][x]) return -1;

	return time;
}
int main()
{
	cin >> m >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			cin >> box[y][x];
			if (box[y][x] == 1) { bfs_q.push({ x, y, 0}); visited[y][x] = true; }
		}
	}
	cout << bfs() << endl;
	return 0;

}