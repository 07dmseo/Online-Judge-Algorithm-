#include <iostream>
#include <algorithm>
using namespace std;
int x, sum, l = 64, cnt;
int main()
{
	cin >> x;
	while (x > sum) {
		if (l + sum <= x) cnt += 1, sum += l;
		l /= 2;
	}
	cout << cnt << endl;
	return 0;

}