#include <string>
#include <vector>
using namespace std;
int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int i = 123; i < 988; i++){
        string num = to_string(i); bool matched = true;
        if(num[0] == '0' || num[1] == '0'|| num[2] == '0') continue;
        else if(num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) continue;
        for(int j = 0; j < baseball.size(); j++) {
            string cmp = to_string(baseball[j][0]); int strike = 0, ball = 0;
            for(int a = 0; a < 3; a++)
                for(int b = 0; b < 3; b++)
                    if(num[a] == cmp[b]) {
                        if(a == b) strike++;
                        else ball++;
                    }
            if(strike != baseball[j][1] || ball != baseball[j][2]) {
                matched = false;
                break;
            }
        }
        if(matched) answer++;
    }
    return answer;
}