#include <iostream>
#include <algorithm>
using namespace std;
int n, dp[10000000];
int main()
{
	cin >> n;
	for (int i = n - 1; i >= 1; i--) {
		if (i * 2 > n && i * 3 > n) dp[i] = 1 + dp[i + 1];
		else if (i * 2 <= n && i * 3 > n) dp[i] = 1 + min(dp[i + 1], dp[i * 2]);
		else dp[i] = 1 + min(dp[i*3], min(dp[i + 1], dp[i * 2]));
	}
	cout << dp[1] << endl;
	return 0;

}