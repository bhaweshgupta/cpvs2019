#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int s;
	cin >> s;
	while (t--)
	{
		int n;
		cin >> n;
		long long int chef[100001], player[100001];
		for (int i = 0;i < n;i++)
			cin >> chef[i];
		for (int i = 0;i < n;i++)
			cin >> player[i];
		sort(chef, chef + n);
		sort(player, player + n);
		set<int> s;
		int flag = 1;
		for (int i = 0;i < n;i++)
		{
			if (player[i] > chef[i])
			{
				
				if (i > 0)
				{
					if (!s.count(chef[i]))
					{
						flag=0;
						break;
					}
				}
				s.insert(player[i]);
				s.insert(chef[i]);
			}
			else
			{
				flag =0;
				break;
			}

		}

		if (flag == 0)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}

}



		
	
		


	

	//
