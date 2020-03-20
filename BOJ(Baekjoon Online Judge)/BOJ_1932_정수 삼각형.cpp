#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n, triangle[1000000], temp[1000000], mvalue, curr_sidx, prev_sidx = 1, prev_cols = 0;

int main()
{
	cin >> n;
	if (n < 1 || n > 500) return 0;
	
	for (int i = 1; i <= n; i++) {
		curr_sidx = prev_sidx + prev_cols;
		prev_sidx = curr_sidx, prev_cols = i;
		for (int j = 0; j < i; j++) {
			cin >> triangle[curr_sidx + j];
			if (triangle[curr_sidx + j] < 0 || triangle[curr_sidx + j] > 9999) return 0;
		}
	}
	memcpy(temp, triangle, sizeof(triangle));

	prev_sidx = 1, prev_cols = 0;
	for (int i = 1; i < n; i++) {
		curr_sidx = prev_sidx + prev_cols;
		prev_sidx = curr_sidx, prev_cols = i;
		for (int j = 0; j < i; j++) {
			mvalue = max(mvalue, temp[curr_sidx + j + i] = 
				max(temp[curr_sidx + j] + triangle[curr_sidx + j + i], temp[curr_sidx + j + i]));
			mvalue = max(mvalue, temp[curr_sidx + j + i + 1] =
				max(temp[curr_sidx + j] + triangle[curr_sidx + j + i + 1], temp[curr_sidx + j + i + 1]));
		}
	}
	cout << mvalue << endl;
	return 0;

}