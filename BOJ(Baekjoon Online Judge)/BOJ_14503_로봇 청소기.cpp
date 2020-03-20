#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // N E S W

int N, M;
int graph[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> graph[i][j];

	int result = 0;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {r, c}, d });

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dir = q.front().second;
		if (graph[y][x] == 0)
		{
			//벽과 구분 위해
			graph[y][x] = 2;
			result++;
		}
		q.pop();

		bool flag = false;
		for (int i = 0; i < 4; i++)
		{
			//좌회전을 위해 모듈러 연산
			int nextDir = (dir + (3 - i)) % 4;
			int nextY = y + moveDir[nextDir].y;
			int nextX = x + moveDir[nextDir].x;

			if(0<=nextY && nextY < N && 0 <= nextX && nextX < M)
				if (!graph[nextY][nextX])
				{
					q.push({ {nextY, nextX}, nextDir});
					flag = true;
					break;
				}
		}

		//네 방향 다 청소되어 있는 경우
		if (!flag)
		{
			int beforeY = y - moveDir[dir].y;
			int beforeX = x - moveDir[dir].x;
			if ((0 <= beforeY && beforeY < N && 0 <= beforeX && beforeX < M) && graph[beforeY][beforeX] != 1)
				q.push({ {beforeY, beforeX}, dir });
			else
				break;
		}
	}

	cout << result << "\n";
	return 0;
}