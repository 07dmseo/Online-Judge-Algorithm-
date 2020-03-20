#include <vector>
#include <cstring>
using namespace std;
int solution(int m, int n, vector<vector<int>> p) {
    int dp[101][101]; bool visited[101][101];
    memset(dp, 0, sizeof(dp)); memset(visited, 0, sizeof(visited));
    for (int i = 0; i < p.size(); i++) visited[p[i][1]][p[i][0]] = 1; dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++){
            if (!visited[i][j]) dp[i][j] = dp[i][j - 1] + dp[i - 1][j]  % 1000000007;
        }
    }
    return dp[n][m];
}