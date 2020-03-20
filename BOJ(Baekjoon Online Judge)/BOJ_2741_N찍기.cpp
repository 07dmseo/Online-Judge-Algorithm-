#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    if(a <= 100000){
        for(int i=1;i<=a;i++)
            cout << i << '\n';
    }
    return 0;
}