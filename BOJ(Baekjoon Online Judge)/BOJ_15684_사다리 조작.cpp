#include <iostream>
#include <algorithm>
using namespace std;
int a, b, n, m, h, s = 4; bool ladder[100][100] = { false, };
bool game()
{
	int curr_x, curr_y;
	for (int i = 1; i <= n; i++) {
		curr_x = i, curr_y = 1;
		while (curr_y <= h) {
			if (curr_x < n && ladder[curr_y][curr_x]) curr_x += 1, curr_y += 1;
			else if (curr_x > 1 && ladder[curr_y][curr_x - 1]) curr_x -= 1, curr_y += 1;
			else curr_y += 1;
		}
		if (curr_x != i) return false;
	}
	return true;
}
void bp(int x, int y, int cnt)
{
	if (cnt > 3) return;
	else if (game()) {
		s = min(s, cnt);
		return;
	}
	int cx, cy;
	for (cy = y; cy <= h; cy++) {
		for (cx = x; cx < n; cx++) {
			if (ladder[cy][cx] || ladder[cy][cx - 1] || ladder[cy][cx + 1]) continue;
			else {
				ladder[cy][cx] = true;
				bp(cx, cy, cnt + 1);
				ladder[cy][cx] = false;
			}
		} x = 1;
	}
}
int main()
{
	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		ladder[a][b] = true;
	}
	bp(1, 1, 0);
	if (s < 4) cout << s << endl;
	else cout << -1 << endl;
	return 0;

}