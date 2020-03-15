#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		int q;
		cin >> q;
		int arr[100001];
		for (int i = 1;i <= n;i++)
			cin >> arr[i];


		while (q--)
		{

			int count = 0;
			int x1, x2, y;
			cin >> x1 >> x2 >> y;

			for (int j = x1;j < x2;j++)
			{
				int minn = min(arr[j], arr[j + 1]);
				int maxx = max(arr[j], arr[j + 1]);
				if (y >= minn && y <= maxx)
				{
					count++;
				}

			}
			cout << count << endl;
		}


	}

}
