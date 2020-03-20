#include <iostream>
#include <cstring>
using namespace std;
long long t, n, dp[101], ans[1000001];
int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		if (n <= 3) ans[i] = 1;
		else {
			for (int j = 1; j <= 3; j++) dp[j] = 1;
			for (int k = 4; k <= n; k++) dp[k] = dp[k - 2] + dp[k - 3];
			ans[i] = dp[n];
		}
	}
	for (int i = 1; i <= t; i++) cout << ans[i] << endl;
	return 0;

}