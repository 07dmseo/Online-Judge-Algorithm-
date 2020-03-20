#include <iostream>
#include <algorithm>
using namespace std;
int in, out, tot, mvalue;
int main()
{
	for (int i = 1; i <= 4; i++) {
		cin >> out >> in;
		tot += in - out;
		mvalue = max(mvalue, tot);
	}
	cout << mvalue << endl;
	return 0;

}