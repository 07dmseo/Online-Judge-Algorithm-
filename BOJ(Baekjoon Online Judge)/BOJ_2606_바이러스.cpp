#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ret, N, P, P1, P2, com[101][101], infect[101];
void dfs(int virus)
{
	if (infect[virus])
		return;
	
	else if (!infect[virus]) {
		infect[virus] = 1;
		for (int i = 1; i <= N; i++) {
			if ((i == virus) || (!com[virus][i]))
				continue;
			else if (com[virus][i])
				dfs(i);
		}
	}
}
int main()
{
	cin >> N;
	if (N < 1 || N > 100)
		return 0;

	cin >> P;
	if (P < 1)
		return 0;

	for (int i = 1; i <= P; i++) {
		cin >> P1 >> P2;
		if (P1 < 1 || P1 > N || P2 < 1 || P2 > N)
			return 0;
		com[P1][P2] = 1;
		com[P2][P1] = 1;
	}

	dfs(1);
	for (int i = 1; i <= N; i++)
		if (infect[i])
			ret += 1;
	cout << ret - 1 << endl;

	return 0;
}