#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> nscv_q;
int solution(vector<int> scv, int K) {
    int answer = 0, first, second, third;
    for(int i = 0; i < scv.size(); i++)
        nscv_q.push(scv.at(i));
    while(nscv_q.top() < K && nscv_q.size() > 1){
        first = nscv_q.top(); nscv_q.pop(); second = nscv_q.top(); nscv_q.pop();
        third = first + (second * 2); nscv_q.push(third);
        answer += 1;
    }
    if(nscv_q.top() < K) return -1;
    else return answer;
}