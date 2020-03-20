#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
typedef struct { int x, y; } pos; queue<pos> bfs_q; bool visited[101][101];
int n, r, h, map[101][101], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
void bfs(int rain)
{
	int curr_x, curr_y, curr_r = 0;
	memset(visited, false, sizeof(visited));
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			if (map[y][x] <= rain) visited[y][x] = true;
	
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (visited[y][x]) continue;
			bfs_q.push({ x,y }); visited[y][x] = true;
			while (!bfs_q.empty()) {
				pos curr_pos = bfs_q.front(); bfs_q.pop();
				for (int i = 0; i < 4; i++) {
					curr_x = curr_pos.x + dx[i], curr_y = curr_pos.y + dy[i];
					if (curr_x < 1 || curr_x > n || curr_y < 1 || curr_y > n) continue;
					else if (visited[curr_y][curr_x]) continue;
					bfs_q.push({ curr_x, curr_y }); visited[curr_y][curr_x] = true;
				}
			}
			curr_r += 1;
		}
	}
	r = max(r, curr_r);
}

int main()
{
	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> map[y][x];
			h = max(h, map[y][x]);
		}
	}

	for (int i = 0; i <= h; i++)
		bfs(i);
	cout << r << endl;
	return 0;

}