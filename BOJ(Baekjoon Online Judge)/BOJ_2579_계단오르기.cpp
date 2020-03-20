#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, l[301], d[301][3];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i];
	for (int i = 1; i <= n; i++) {
		d[i][1] = l[i] + d[i - 1][2];
		d[i][2] = l[i] + max(d[i - 2][1], d[i - 2][2]);
	}
	cout << max(d[n][1], d[n][2]) << endl;
	return 0;
}