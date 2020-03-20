#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int n, m, map[9][9], temp[9][9], mvalue = 0;
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
queue<pair<int, int>> bfs_q;

void bfs()
{
	int nx, ny, px, py;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if (temp[i][j] == 2)
				bfs_q.push(make_pair(j, i));

	while (!bfs_q.empty()) {
		px = bfs_q.front().first, py = bfs_q.front().second;
		bfs_q.pop();
		for (int i = 0; i < 4; i++) {
			nx = px + dx[i], ny = py + dy[i];
			if (temp[ny][nx] || nx < 1 || nx > m || ny < 1 || ny > n)
				continue;
			temp[ny][nx] = 2;
			bfs_q.push(make_pair(nx, ny));
		}
	}
}

void bp(int x, int y, int cnt)
{
	int curr_value = 0;

	if(cnt == 3){
		memcpy(&temp, &map, sizeof(map));
		bfs();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (!temp[i][j])
					curr_value += 1;
		mvalue = max(mvalue, curr_value);
		return;
	}
	
	else if (cnt < 3) {
		for (int i = y; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (!map[i][j]) {
					map[i][j] = 1;
					bp(j, i, cnt + 1);
					map[i][j] = 0;
				}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	if (n < 3 || n > 8 || m < 3 || m > 8)
		return 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);

	bp(1,1,0);
	printf("%d\n", mvalue);
	return 0;
}