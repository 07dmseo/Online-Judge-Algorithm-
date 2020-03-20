#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef struct { int x, y, s; }rt; vector<rt> v, t; bool visited[6];
int n, m, k, r, c, s, a, ans = 10000, src[51][51];
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0,1,0,-1 };
void rotate()
{
	int temp[51][51], temp2[51][51];
	memcpy(temp, src, sizeof(src));

	for (int i = 0; i < t.size(); i++) {
		for (int j = 1; j <= t[i].s; j++) {
			memcpy(temp2, temp, sizeof(temp));
			int nx, ny, cx = t[i].x - j, cy = t[i].y - j;
			for (int l = 0; l < 4; l++) {
				while (true) {
					nx = cx + dx[l], ny = cy + dy[l];
					if (nx < (t[i].x - j) || nx > (t[i].x + j) || ny < (t[i].y - j) || ny > (t[i].y + j)) break;
					else if (nx == t[i].x - j && ny == t[i].y - j) { temp[ny][nx] = temp2[cy][cx]; break; }
					else temp[ny][nx] = temp2[cy][cx], cx = nx, cy = ny;
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) a += temp[i][j];
		ans = min(a, ans), a = 0;
	}
}
void perm(int n, int r)
{
	if (!r) { rotate(); return; }
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true; t.push_back(v[i]);
		perm(n, r - 1);
		t.pop_back(); visited[i] = false;
	}
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> src[i][j];
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s; v.push_back({ c, r, s });
	}
	perm(v.size(), v.size());
	cout << ans << endl;
	return 0;

}