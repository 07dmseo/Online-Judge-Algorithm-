#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct pos { int x, y, cnt; } pos; queue<pos> bfs_q;
int n, m, min_cnt = 10000, dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 }; 
char map[101][101];

int bfs()
{
	int curr_x, curr_y, curr_cnt;
	bfs_q.push({ 1,1,1 });

	while (!bfs_q.empty()) {
		pos curr_pos = bfs_q.front();
		curr_x = curr_pos.x, curr_y = curr_pos.y, curr_cnt = curr_pos.cnt;
		bfs_q.pop();
		if (curr_x == m && curr_y == n) min_cnt = min(min_cnt, curr_cnt);
		else if (curr_x < 1 || curr_x > m || curr_y < 1 || curr_y > n || map[curr_y][curr_x] == '0') continue;
		else {
			map[curr_y][curr_x] = '0';
			for (int i = 0; i < 4; i++) {
				curr_x += dx[i], curr_y += dy[i];
				if (map[curr_y][curr_x] != '0') bfs_q.push({curr_x, curr_y, curr_cnt + 1});
				curr_x -= dx[i], curr_y -= dy[i];
			}
		}
	}

	return min_cnt;

}

int main()
{
	cin >> n >> m;
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= m; x++)
			cin >> map[y][x];

	cout << bfs() << endl;
	return 0;

}