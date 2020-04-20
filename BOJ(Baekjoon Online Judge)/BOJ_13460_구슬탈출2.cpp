#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct { int rx, ry, bx, by, d; }pos; queue<pos> q;
int n, m, hx, hy, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
char board[11][11]; bool checked[11][11][11][11];
void move(int& x, int& y, int& c, int d)
{
	while (board[y + dy[d]][x + dx[d]]!='#') {
		x += dx[d], y += dy[d], c++;
		if (hx == x && hy == y) return;
	}
}
int bfs()
{
	while (!q.empty()) {
		int rx = q.front().rx, ry = q.front().ry, bx = q.front().bx, by = q.front().by;
		int nd = q.front().d + 1; q.pop();
		if (nd > 10) return -1;
		for (int i = 0; i < 4; i++) {
			int rc = 0, bc = 0, nrx = rx, nry = ry, nbx = bx, nby = by;
			move(nrx, nry, rc, i); move(nbx, nby, bc, i);
			if (nbx == hx && nby == hy) continue; else if (nrx == hx && nry == hy) return nd;
			if (nrx == nbx && nry == nby) {
				if (rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}
			if (checked[nrx][nry][nbx][nby]) continue;
			else q.push({ nrx,nry,nbx,nby,nd }); checked[nrx][nry][nbx][nby] = true;
		}
	}
	return -1;

}
int main()
{
	int rx, ry, bx, by;
	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			cin >> board[y][x];
			switch (board[y][x]) {
			case 'R': rx = x, ry = y; break;
			case 'B': bx = x, by = y; break;
			case 'O': hx = x, hy = y; break;
			default: break;
			}
		}
	}
	q.push({ rx,ry,bx,by,0 }); checked[rx][ry][bx][by] = true;
	cout << bfs() << endl;
	return 0;

}