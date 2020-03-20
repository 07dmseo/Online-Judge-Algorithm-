#include <iostream>
using namespace std;
int main()
{
	unsigned long long n, fibo[91] = { 0, 1, 1, 0, };
	cin >> n;
	if (n < 0 || n > 90)
		return 0;

	for (int i = 2; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	cout << fibo[n] << endl;
	return 0;

}