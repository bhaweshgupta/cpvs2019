#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int maxcuts(int n, int a, int b, int c)
{
	if (n == 0)
		return 0;
	if (n < 0)
		return -1;

	int res=max(maxcuts(n - a, a, b, c), max(maxcuts(n - b, a, b, c), maxcuts(n - c, a, b, c)));
	if (res == -1)
		return -1;
	return res+1;
}
int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		cout << maxcuts(n, a, b, c);
	}
	system("pause");

}