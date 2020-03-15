#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{

	int t;
	std::cin >> t;
	while (t--)
	{
		int n, m;
		std::cin >> n >> m;
		int arr1[100], arr2[100];
		int flag[100] = {};

		



		int arrsum[100] = {};


		for (int i = 0;i < n;i++)
		{
			std::cin >> arr1[i];
			flag[arr1[i]] = 1;

		}
		for (int i = 0;i < n;i++)
		{
			std::cin >> arr2[i];  
		}

		for (int i = 0;i < n;i++)
		{

			arrsum[arr1[i]] = arrsum[arr1[i]] + arr2[i];

		}

		std::vector<pair<int, int>> v;

		for (int i = 0;i <= m;i++)
		{
			//  cout<<arrsum[i]<<" "<<flag[i]<<endl;
			v.push_back(make_pair(arrsum[i], flag[i]));
		}
		sort(v.begin(), v.end());
		for (int i = 0;i < v.size();i++)
		{
			if (v[i].second)
			{
				cout << v[i].first << endl;
				break;
			}
		}
		//   sort(arrsum,arrsum+m);




	}
}
