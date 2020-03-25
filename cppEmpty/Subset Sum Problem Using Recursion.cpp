#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int ssrec(int arr[],int n,int sum)
{
	if (n == 0)
	{
		return (sum == 0) ? 1 : 0;
	}
	return ssrec(arr, n - 1, sum) + ssrec(arr, n - 1, sum - arr[n - 1]);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int n = 3;
		int arr[] = { 10,15,20 };
		int sum = 25;
		cout<<ssrec(arr, 3, 25);

		//int n;
		//cin >> n;
		//vector<int> v;
		//int x;
		//for (int i = 0;i < n;i++)
		//	v.push_back(1);
	}
}