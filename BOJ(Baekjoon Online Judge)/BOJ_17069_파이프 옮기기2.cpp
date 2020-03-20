#include <iostream>
using namespace std;
long long int n, dp[33][33][3]; bool v[33][33];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> v[i][j];
	dp[1][2][0] = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		int left = v[i][j - 1], up = v[i - 1][j], dia = left + up + v[i - 1][j - 1];
		if (v[i][j]) continue;
		if (!left) dp[i][j][0] += (dp[i][j - 1][0] + dp[i][j - 1][2]);
		if (!up) dp[i][j][1] += (dp[i - 1][j][1] + dp[i - 1][j][2]);
		if (!dia) dp[i][j][2] += (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]);
	}
	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << '\n';
	return 0;
	
}