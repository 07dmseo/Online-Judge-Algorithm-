#include <iostream>
using namespace std;
unsigned long long n, fibo[1000001];
int main()
{
	cin >> n;
	if (n < 0 || n > 1000000)
		return 0;

	fibo[1] = 1, fibo[2] = 2;
	for (int i = 3; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2] % 15746;

	cout << fibo[n] % 15746 << endl;
	return 0;

}