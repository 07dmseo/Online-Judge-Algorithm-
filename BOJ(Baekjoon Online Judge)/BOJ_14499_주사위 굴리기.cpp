#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int dice[6] = { 0,0,0,0,0,0 };
int temp[6];
int N, M, x, y, K, nx, ny;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int command[1000];
int map[20][20];

void dicepositionchange(int command);

int main()
{

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < K; i++)
		cin >> command[i];

	for (int i = 0; i < K; i++) {
		nx = x + dx[command[i] - 1];
		ny = y + dy[command[i] - 1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
			dicepositionchange(command[i]);
	}

	return 0;
}


void dicepositionchange(int command)
{
	for (int i = 0; i < 6; i++)
		temp[i] = dice[i];
	// 0: 拉 1:悼 2:辑 3:合 4:巢 5:酒贰
	switch (command) {
	case 1: // 悼率
		y += 1;
		dice[5] = temp[1];
		dice[1] = temp[0];
		dice[0] = temp[2];
		dice[2] = temp[5];
		break;
	case 2: // 辑率
		y -= 1;
		dice[5] = temp[2];
		dice[2] = temp[0];
		dice[0] = temp[1];
		dice[1] = temp[5];
		break;
	case 3: // 合率
		x -= 1;
		dice[5] = temp[3];
		dice[3] = temp[0];
		dice[0] = temp[4];
		dice[4] = temp[5];
		break;
	case 4: // 巢率
		x += 1;
		dice[5] = temp[4];
		dice[4] = temp[0];
		dice[0] = temp[3];
		dice[3] = temp[5];
		break;
	}

	if (map[x][y]) {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}
	else
		map[x][y] = dice[5];

	cout << dice[0] << endl;

}