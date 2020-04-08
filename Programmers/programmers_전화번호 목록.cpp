#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool solution(vector<string> phone) {
    bool answer = true;
    sort(phone.begin(), phone.end());
    for (int i = 0; i < phone.size() - 1; i++) {
        if(phone[i] == phone[i + 1].substr(0, phone[i].size())) return false;
    }
    return answer;
}