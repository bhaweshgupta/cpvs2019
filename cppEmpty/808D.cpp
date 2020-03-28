#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1


int32_t main()
{

	//10
		//9 6 8 5 5 2 8 9 2 2
	int n; cin >> n;

	vi arr(n+5, 0);
	int sum = 0;
	for (int i = 0; i < n; i++)	cin >> arr[i],sum+=arr[i];

	if (sum & 1)
	{
		cout << "NO \n";
		return 0;

	}
	map<int, int> f, s;
	f[arr[0]] = 1;

	for (int i = 1; i < n; i++) s[arr[i]]++;

	int tempsum = 0;
	for (int i = 0; i < n; i++)
	{
		tempsum +=arr[i];
		if (tempsum == sum / 2)
		{
			cout << "YES\n";
			return 0;

		}

		if (tempsum < sum / 2)
		{
			int x=sum / 2 - tempsum;
			if (s[x] > 0)
			{
				cout << "YES\n";
				return 0;
			}
		}
		else
		{
			int y = tempsum- sum / 2;
			if (f[y] > 0)
			{
				cout << "YES\n";
				return 0;
			}
		}

		f[arr[i+1]]++;
		s[arr[i+1]]--;
	}

	cout << "NO";

	
}
