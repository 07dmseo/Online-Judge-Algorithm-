#include <string>
using namespace std;
string solution(int n) {
    string answer = "";
    while(n) {
        int remainder = n % 3;
        n /= 3;
        if(!remainder) { answer = "4" + answer, n--; }
        else if(remainder == 1) answer = "1" + answer;
        else answer = "2" + answer;
    }
    return answer;
    
}