#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n, region[21][21], ward[21][21], sum[6], most_min = 10000;

void calculate(int x, int y, int d1, int d2)
{
	int curr_min = 10000, curr_max = 0;
	memset(sum, 0, sizeof(int) * 6);
	for (int i = 1; i <= n; i++)
		memset(ward[i]+1, 0, sizeof(int)*n);

	for (int i = 0; i < d1; i++)
		ward[y - i][x + i] = 5;

	for (int i = 0; i <= d2; i++)
		ward[y - d1 + i][x + d1 + i] = 5;

	for (int i = 0; i < d2; i++)
		ward[y + i][x + i] = 5;

	for (int i = 0; i < d1; i++)
		ward[y + d2 - i][x + d2 + i] = 5;

	for (int i = 1; i < y; i++) {
		for (int j = 1; j <= x + d1; j++) {
			if (ward[i][j] == 5)
				break;
			ward[i][j] = 1;
		}
	}

	for (int i =  y - d1 + d2; i >= 1; i--) {
		for (int j = n; j > x + d1; j--) {
			if (ward[i][j] == 5)
				break;
			ward[i][j] = 2;
		}
	}

	for (int i = y; i <= n; i++) {
		for (int j = 1; j < x + d2; j++) {
			if (ward[i][j] == 5)
				break;
			ward[i][j] = 3;
		}
	}

	for (int i = n; i > y - d1 + d2; i--) {
		for (int j = n; j >= x + d2; j--) {
			if (ward[i][j] == 5)
				break;
			ward[i][j] = 4;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ward[i][j] == 0 || ward[i][j] == 5)
				sum[5] += region[i][j];
			else if (ward[i][j] == 1)
				sum[1] += region[i][j];
			else if (ward[i][j] == 2)
				sum[2] += region[i][j];
			else if (ward[i][j] == 3)
				sum[3] += region[i][j];
			else if (ward[i][j] == 4)
				sum[4] += region[i][j];
		}
	}

	for (int i = 1; i <= 5; i++) {
		curr_max = max(sum[i], curr_max);
		curr_min = min(sum[i], curr_min);
	}

	most_min = min(most_min, curr_max - curr_min);
	return;
}

void setDistance(int x, int y)
{
	for (int d1 = 1; d1 <= n; d1++) {
		for (int d2 = 1; d2 <= n; d2++) {
			if ((x + d1 > n) || (y - d1 < 1) || (x + d2 > n) || (y + d2 > n))
				break;
			else if ((x + d1 + d2) > n)
				break;
			else
				calculate(x, y, d1, d2);
		}
	}
}

int main()
{
	cin >> n;
	if (n < 5 || n > 20)
		return 0;
	
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> region[y][x];
			if (region[y][x] > 100 || region[y][x] < 1)
				return 0;
		}
	}

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			setDistance(x, y);

	cout << most_min << endl;
	return 0;

}