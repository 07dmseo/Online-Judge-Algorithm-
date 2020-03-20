#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string cache[102][102];
string string_add(const string num1, const string num2) {
    long long sum = 0;
    string copy1(num1), copy2(num2);
    string ret;
 
    while (!copy1.empty() || !copy2.empty() || sum) {
        if (!copy1.empty()) {
            sum += copy1.back() - '0';
            copy1.pop_back();
        }
        if (!copy2.empty()) {
            sum += copy2.back() - '0';
            copy2.pop_back();
        }
        ret.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string bino(const int r, const int n) {
    string & ret = cache[r][n];
    if (ret != "") return ret;
    else if(r== n||n ==0) return ret = '1';
    else return ret = string_add(bino(r - 1, n), bino(r - 1, n - 1));
}

int main() {
    int n, r;
    cin >> n >> r;
    cout << bino(n, r);
    return 0;
}