#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
int n, l, r, ans, sum[2501], cnt[2501], board[51][51], checked[51][51];
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
typedef struct { int x, y; } pos; queue<pos> q;
int bfs()
{
	while (1) {
		int region = 0;
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= n; x++) {
				if (checked[y][x]) continue;
				region += 1, checked[y][x] = region; q.push({ x,y });
				while (!q.empty()) {
					pos current = q.front(); q.pop();
					int cx = current.x, cy = current.y;
					sum[region] += board[cy][cx], cnt[region]++;
					for (int i = 0; i < 4; i++) {
						int nx = cx + dx[i], ny = cy + dy[i];
						if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
						else if (checked[ny][nx]) continue;
						else if (abs(board[ny][nx] - board[cy][cx]) <= r && abs(board[ny][nx] - board[cy][cx]) >= l) {
							checked[ny][nx] = region; q.push({ nx, ny });
						}
					}
				}
				if (cnt[region] == 1 && sum[region] == board[y][x])
					cnt[region] = 0, sum[region] = 0, checked[y][x] = 0, region -= 1;
			}
		}

		if (!region) break;
		for (int y = 1; y <= n; y++)
			for (int x = 1; x <= n; x++)
				if (checked[y][x])
					board[y][x] = (sum[checked[y][x]] / cnt[checked[y][x]]);

		ans++;
		memset(sum, 0, sizeof(sum));
		memset(cnt, 0, sizeof(cnt));
		memset(checked, 0, sizeof(checked));
	}
	return ans;

}
int main()
{
	cin >> n >> l >> r;
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			cin >> board[y][x];
	cout << bfs() << "\n";
	return 0;

}