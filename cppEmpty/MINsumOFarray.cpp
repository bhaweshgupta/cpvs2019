
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
	int n; cin>>n;
	mk(arr,n,int);
	multiset<int> mst;

	for(int i=0;i<n;i++) cin>>arr[i],mst.insert(arr[i]);

	w(k)
	{
		int x=*--mst.end();
		mst.insert(x/2);
		mst.erase(--mst.end());
	}

	int sum=0;
	for(auto x:mst)
	{
		sum+=x;
	}
}