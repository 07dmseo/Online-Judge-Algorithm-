#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
using namespace std;
int cnt, map[16], n;

bool promising(int cols)
{
	for (int i = 1; i < cols; i++) {
		if (map[i] == map[cols])
			return false;
		else if (abs(map[i] - map[cols]) == abs(i - cols))
			return false;
	}
	return true;
}

void btracking(int cols)
{
	if (!promising(cols))
		return;
	else if (cols == n) {
		cnt += 1;
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			map[cols + 1] = i;
			btracking(cols + 1);
		}
	}
	return;
}

int main()
{
	scanf("%d",&n);
	if (n < 1 || n > 15)
		return 0;
	btracking(0);
	printf("%d\n", cnt);
	return 0;

}