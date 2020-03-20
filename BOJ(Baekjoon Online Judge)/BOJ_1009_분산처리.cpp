#include <iostream>
using namespace std;
int t, a, b, tc[10000];
void pow(int idx, int a, int b)
{
	int res = 1;
	for (int i = 1; i <= b; i++)
		res = res * a % 10;
	if (!res) tc[idx] = 10;
	else tc[idx] = res;
}
int main()
{
	cin >> t;
	for (int i = 1; i <= t; i++) {cin >> a >> b; pow(i, a, b);}
	for (int i = 1; i <= t; i++) cout << tc[i] << endl;
	return 0;

}