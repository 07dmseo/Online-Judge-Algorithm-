#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int a, n, m, t, x, d, k, ans, s[51][51], dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
vector<vector<int>> r;
void r_rotate(int idx)
{
	int temp = s[idx][m];
	for (int i = m; i > 1; i--) s[idx][i] = s[idx][i - 1];
	s[idx][1] = temp;
}
void l_rotate(int idx)
{
	int temp = s[idx][1];
	for (int i = 1; i < m; i++) s[idx][i] = s[idx][i + 1];
	s[idx][m] = temp;
}
void rotate(int lx, int ld, int lk)
{
	bool erased = false; int cx, cy, cnt = 0, temp[51][51]; double avr = 0.0;
	for (int i = lx; i <= n; i++) if (!(i%lx)) 
		for (int j = 0; j < lk; j++) if (!ld) r_rotate(i); else l_rotate(i);
	memcpy(temp, s, sizeof(s));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				cx = j + dx[k], cy = i + dy[k];
				if (cy < 1 || cy > n) continue; else if (cx > m) cx = 1; else if (cx < 1) cx = m;
				if (temp[i][j] && temp[i][j] == temp[cy][cx]) { s[i][j] = 0, s[cy][cx] = 0, erased = true; }
			}
		}
	}
	if (!erased) {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			if (s[i][j]) { avr += s[i][j], cnt++; } avr /= (double)cnt;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			if (s[i][j] && s[i][j] > avr) s[i][j]--; else if (s[i][j] && s[i][j] < avr) s[i][j]++;
	}
}
int main()
{
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) { cin >> a; s[i][j] = a; }
	for (int i = 0; i < t; i++) { cin >> x >> d >> k; r.push_back({ x,d,k }); }
	for (int i = 0; i < t; i++) rotate(r[i][0], r[i][1], r[i][2]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ans += s[i][j];
	cout << ans << endl;
	return 0;

}