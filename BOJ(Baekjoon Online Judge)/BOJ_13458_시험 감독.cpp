#include <iostream>
using namespace std;
#define MAXSIZE 1000000
long N, B, C, arr[MAXSIZE];
long long part[MAXSIZE];
long long total = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		if (arr[i] - B <= 0) // 부감독관 필요 없을 경우
            part[i] = 0;
        else if ((arr[i] - B) % C == 0)
			part[i] = (arr[i] - B) / C;
		else
			part[i] = (arr[i] - B) / C + 1;
        total += (1 + part[i]);
	}
    
	cout << total << endl;
	return 0;
}