#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct { int x, y; }pos; typedef struct { int x; char d; }turn;
vector<pos> v; queue<turn> q; char d;
int t, n, k, l, r, c, x, map[101][101], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int r_rotate(int idx) { if (idx == 3) return 0; else return idx + 1; }
int l_rotate(int idx) { if (!idx) return 3; else return idx - 1; }
int main()
{
	cin >> n >> k; for (int i = 0; i < k; i++) { cin >> r >> c; map[r][c] = 1; }
	cin >> l; for (int i = 0; i < l; i++) { cin >> x >> d; q.push({x, d}); }
	turn curr_turn = q.front(); int cx = 1, cy = 1, curr_d = 0; v.push_back({ cx, cy });
	while (true) {
		int nx = cx + dx[curr_d], ny = cy + dy[curr_d];
		for (int i = 0; i < v.size(); i++) if (nx == v[i].x && ny == v[i].y) { cout << t + 1 << "\n"; return 0; }
		if (nx < 1 || nx > n || ny < 1 || ny > n) { cout << t + 1 << "\n"; return 0; }
		else { if (map[ny][nx]) map[ny][nx] = 0; else v.erase(v.begin(), v.begin() + 1); t++; v.push_back({ nx, ny }); }
		if (!q.empty() && curr_turn.x == t) { 
			if (curr_turn.d == 'D') curr_d = r_rotate(curr_d); else curr_d = l_rotate(curr_d); 
			q.pop(); if(!q.empty()) curr_turn = q.front();
		}
		cx = nx, cy = ny;
	}
	return 0;
	
}