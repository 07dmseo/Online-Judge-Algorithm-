#include <string>
#include <vector>
using namespace std;
long long p[81];
long long solution(int N) {
    long long ans = 0; p[1] = p[2] = 1;
    for(int i = 3; i <= N; i++) p[i] = p[i-1] + p[i-2];
    ans = 2*(2*p[N] + p[N - 1]);
    return ans;
    
}