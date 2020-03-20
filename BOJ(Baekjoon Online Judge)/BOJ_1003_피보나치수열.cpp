#include <iostream>
using namespace std;
int n, tc, fibo[41][2];
int main()
{
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> n;
		if (n < 0 || n > 40)
			return 0;
		fibo[0][0] = 1, fibo[1][1] = 1;
		for (int j = 2; j <= n; j++) {
			fibo[j][0] = fibo[j - 1][0] + fibo[j - 2][0];
			fibo[j][1] = fibo[j - 1][1] + fibo[j - 2][1];
		}
		cout << fibo[n][0]<< " " << fibo[n][1] << endl;
	}
	return 0;
}