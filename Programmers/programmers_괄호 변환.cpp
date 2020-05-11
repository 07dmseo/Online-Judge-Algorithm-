#include <string>
using namespace std;
string recursive(string& s)
{
    int open = 0, close = 0;
    string u = "", v = "";
    for (int i = 0; i < s.size(); i++) {
        if(s[i] =='(') open++; else close++;
        if(open == close) {
            u += s.substr(0, i + 1);
            v += s.substr(i + 1, s.size() - i - 1);
            break;
        }
    }
    if(u[0] == '(') return u + recursive(v);
    else if(u[0] == ')') {
        string new_u;
        for (int i = 0; i < u.size(); i++) {
            if(!i || i == u.size() - 1) continue;
            else if(u[i] == '(') new_u += ")";
            else new_u += "(";
        }
        return "(" + recursive(v) + ")" + new_u;
    }
    else return "";
}

string solution(string p) {
    if(!p.size()) return "";
    string ans = recursive(p);
    return ans;
}