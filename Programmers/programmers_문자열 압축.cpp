#include <iostream>
#include <string>
using namespace std;
int solution(string s) {
    int ans = s.size();
    for (int i = 1; i <= s.size() / 2; i++) {
        string res = "", comp = s.substr(0, i); int cnt = 1;
        for (int j = i; j < s.size(); j += i) {
            string curr = s.substr(j, i);
            if(j + i - 1 >= s.size() - 1) {
                if(comp == curr) res += to_string(++cnt) + comp;
                else {
                    if(cnt == 1) res += comp + curr;
                    else res += to_string(cnt) + comp + curr;
                }
            }
            else if (comp != curr) {
                if(cnt == 1) res += comp;
                else res += to_string(cnt) + comp;
                comp = curr; cnt = 1;
            }
            else cnt++;
        }
        ans = ans > res.size() ? res.size() : ans;
    }
    return ans;
}