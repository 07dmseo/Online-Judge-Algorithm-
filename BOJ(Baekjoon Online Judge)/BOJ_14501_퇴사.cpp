#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c[16][2];
void bp(int day, int pay)
{
	if (day > n || day + c[day][0] > n + 1) return;
	else m = max(m, pay);
	for (int i = day + c[day][0]; i <= n; i++) {
		bp(i, pay + c[i][1]);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i][0] >> c[i][1];
	for (int i = 1; i <= n; i++)
		bp(i, c[i][1]);
	cout << m << endl;
	return 0;

}