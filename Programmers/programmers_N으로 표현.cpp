using namespace std;
int answer = 9;
void dfs(int n, int number, int depth, int result) {
    if(depth > 8) return;
    else if(result == number) {
        answer = answer > depth ? depth : answer;
        return ;
    }
    
    int temp = 0;
    for (int i = 1; i < 9 - depth; i++) {
        temp = temp * 10 + n;
        if(result + temp) dfs(n, number, depth + i, result + temp);
        if(result - temp) dfs(n, number, depth + i, result - temp);
        if(result * temp) dfs(n, number, depth + i, result * temp);
        if(result / temp) dfs(n, number, depth + i, result / temp);
    }
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if(answer == 9) return -1;
    return answer;
}