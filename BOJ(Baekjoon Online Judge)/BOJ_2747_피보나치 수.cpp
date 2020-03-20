#include <iostream>
using namespace std;
int a, dp[46];
int main()
{
    cin >> a;
    for(int i = 0; i <= a; i++){
        if(!i || i == 1) dp[i] = i;
        else {dp[i] = dp[i - 1] + dp[i - 2];}
    }
    cout << dp[a] << endl;
    return 0;
    
}