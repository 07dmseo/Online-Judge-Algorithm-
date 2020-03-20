#include <iostream>
#include <algorithm>
using namespace std;
int n, l, l_cnt, path, map[101][101];

void simulation(int rc)
{
	for (int i = 1; i <= n; i++) {
		l_cnt = 1;
		for (int j = 1; j <= n - 1; j++) {
			int d = (rc > 0 ? map[j + 1][i] - map[j][i] : map[i][j + 1] - map[i][j]);
			if (d == 0) l_cnt += 1;
			else if (d == 1 && l_cnt >= l) l_cnt = 1;
			else if (d == -1 && l_cnt >= 0) l_cnt = -l + 1;
			else {
				l_cnt = -1;
				break;
			}
		}
		if (l_cnt >= 0) path += 1;
	}
}

int main()
{
	cin >> n >> l;
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			cin >> map[y][x];
	for (int rc = 0; rc < 2; rc++)
		simulation(rc);

	cout << path << endl;
	return 0;

}
