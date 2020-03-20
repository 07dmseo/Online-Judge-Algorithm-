#include <iostream>
#include <algorithm>
using namespace std;
int n, m = 100000000, d[1001][3], rgb[1001][3];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (!j) d[i][j] = rgb[i][j] + min(d[i - 1][1], d[i - 1][2]);
			else if (j == 1) d[i][j] = rgb[i][j] + min(d[i - 1][0], d[i - 1][2]);
			else d[i][j] = rgb[i][j] + min(d[i - 1][0], d[i - 1][1]);
		}
	}
	for (int i = 0; i < 3; i++) m = min(m, d[n][i]);
	cout << m << endl;
	return 0;

}