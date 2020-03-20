#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef struct { int x, y, a; }dust; queue<dust> q; vector<dust> v;
int r, c, t, a, src[51][51], res[51][51], dx[] = { 1,0,-1,0 }, dy[] = { 0,-1,0,1 };
int c_cw[][4] = { { 0,1,2,3 },{ 0,3,2,1 } };
void cleaning()
{
	for (int i = 0; i < 2; i++) {
		int cx = v[i].x + 1, cy = v[i].y, nx, ny;
		for (int j = 0; j < 4; j++) {
			while (true) {
				nx = cx + dx[j], ny = cy + dy[c_cw[i][j]];
				if (nx < 1 || nx > c || ny < 1 || ny > r) break;
				else if (nx == v[i].x && ny == v[i].y) break;
				res[ny][nx] = src[cy][cx], cx = nx, cy = ny;
			}
		}
		res[v[i].y][v[i].x + 1] = 0;
	}
	memcpy(src, res, sizeof(res)); return;
}
void dusting()
{
	for (int y = 1; y <= r; y++)
		for (int x = 1; x <= c; x++)
			if (src[y][x] && src[y][x] != -1) q.push({ x, y, src[y][x] });

	while (!q.empty()) {
		dust c_dust = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = c_dust.x + dx[i], cy = c_dust.y + dy[i];
			if (cx < 1 || cx > c || cy < 1 || cy > r) continue;
			else if (src[cy][cx] == -1) continue;
			res[cy][cx] += src[c_dust.y][c_dust.x] / 5;
			res[c_dust.y][c_dust.x] -= src[c_dust.y][c_dust.x] / 5;
		}
	}
	memcpy(src, res, sizeof(res)); return;
}
int main()
{
	cin >> r >> c >> t;
	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			cin >> src[y][x]; 
			if (src[y][x] == -1) v.push_back({ x,y,-1 });
		}
	}
	memcpy(res, src, sizeof(src));
	for (int i = 1; i <= t; i++) { dusting(); cleaning(); }
	for (int y = 1; y <= r; y++)
		for (int x = 1; x <= c; x++)
			if (res[y][x] && res[y][x] != -1) a += res[y][x];
	cout << a << endl;
	return 0;

}