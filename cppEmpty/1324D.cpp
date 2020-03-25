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

	int n; cin >> n;
	mk(a, n, int);
	mk(b, n, int);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		cin >> b[i];

	mk(c, n, int);

	for (int i = 0; i < n; ++i)
		c[i] = b[i] - a[i];

	sort(c, c + n);

	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		//num of j's s.t cj<-ci;

		//find smallest j s.t. cj >= -ci;

		auto it = lower_bound(c + i + 1, c + n, -c[i]);
		int id = it - c;

		ans += id - (i + 1);
	}

	cout << ans << '\n';
	return 0;
}