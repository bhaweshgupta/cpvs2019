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

int sizecalforsegment(int n)
{
    int x = log2(n);
    if (x * x == n)
        return 2 * pow(2, x) - 1;
    else
        return 2 * pow(2, x + 1) - 1;
}

void ConstructSegmentMIN(int input[], int segment[], int low, int high, int pos)
{
    if (input[low] == input[high])
    {
        if (input[low] % 5 == 0)
        {
            segment[pos] = 1;
        }
        else
        {
            segment[pos] = 0;
        }
        return;
    }
    int mid = (low + high) / 2;
    ConstructSegmentMIN(input, segment, low, mid, 2 * pos + 1);
    ConstructSegmentMIN(input, segment, mid + 1, high, 2 * pos + 2);
    segment[pos] = segment[2 * pos + 1] + segment[2 * pos + 2];

}


int RangeMinQuerey(int segment[], int qlow, int qhigh, int low, int high, int pos)
{
    if (qlow <= low && qhigh >= high)
    {
        return segment[pos];
    }
    if (qlow > high || low > qhigh)
    {
        return 0;
    }
    int mid = (low + high) / 2;

    return RangeMinQuerey(segment, qlow, qhigh, low, mid, 2 * pos + 1) + RangeMinQuerey(segment, qlow, qhigh, mid + 1, high, 2 * pos + 2);
}


int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        mk(input, n, int);
        for (int i = 0; i < n; i++)    cin >> input[i];

        int segsize = sizecalforsegment(n);
        mk(segment, segsize, int);
        fill(segment, segment + segsize, 0);
        ConstructSegmentMIN(input, segment, 0, n - 1, 0);

       /* for (int i = 0; i < segsize; i++)
        {
            cout << segment[i] <<" ";
        }
        cout << endl;*/

        while (q--)
        {
            int x, y;
            cin >> x >> y;
            cout << RangeMinQuerey(segment, x - 1, y - 1, 0, n - 1, 0) << " ";


        }
        cout << endl;

    }

    
}

