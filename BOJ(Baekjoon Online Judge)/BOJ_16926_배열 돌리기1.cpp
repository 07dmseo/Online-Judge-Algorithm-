#include <iostream>
#include <cstring>
using namespace std;
int n, m, r, board[301][301];
void printout()
{
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++)
			cout << board[y][x] << " ";
		cout << "\n";
	}
}
void rotation()
{
	int t = (n > m ? m : n) / 2;
	while (r--) {
		for (int k = 1; k <= t; k++) {
			int temp = board[k][k];
			for (int x = k; x < m + 1 - k; x++) board[k][x] = board[k][x + 1];
			for (int y = k; y < n + 1 - k; y++) board[y][m + 1 - k] = board[y + 1][m + 1 - k];
			for (int x = m + 1 - k; x > k; x--) board[n + 1 - k][x] = board[n + 1 - k][x - 1];
			for (int y = n + 1 - k; y > k; y--) board[y][k] = board[y - 1][k];
			board[k + 1][k] = temp;
		}
	}
}
int main()
{
	cin >> n >> m >> r;
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= m; x++)
			cin >> board[y][x];
	rotation();
	printout();
	return 0;
}