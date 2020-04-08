#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int solution(vector<int> money) {
    int answer = 0, n = money.size();
    int dp[2][n]; memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) { // 0 번집 선택 안함
        if(i == 1) { dp[0][i] += money[1]; continue; }
        dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + money[i]);
    }
    for (int i = 0; i < n - 1; i++) { // 0 번집 선택할 경우
        if(!i || i == 1) { dp[1][i] += money[0]; continue; }
        dp[1][i] = max(dp[1][i - 1], dp[1][i - 2] + money[i]);
    }
    answer = max(dp[0][n - 1], dp[1][n - 2]);
    return answer;
}