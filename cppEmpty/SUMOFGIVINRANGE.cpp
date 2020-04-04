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
    int x = (int)log2(n);
    if (x * x == n)
        return 2 * pow(2, x) - 1;
    else
        return 2 * pow(2, x + 1) - 1;
}
void ConstructSegmentMIN(int input[], int segment[], int low, int high, int pos)
{
    if (input[low] == input[high])
    {
        segment[pos] = input[low];
        return;
    }
    int mid = (low + high) / 2;
    ConstructSegmentMIN(input, segment, low, mid, 2 * pos + 1);
    ConstructSegmentMIN(input, segment, mid + 1, high, 2 * pos + 2);
    segment[pos] = segment[2 * pos + 1]+ segment[2 * pos + 2];

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

    return RangeMinQuerey(segment, qlow, qhigh, low, mid, 2 * pos + 1)+ RangeMinQuerey(segment, qlow, qhigh, mid + 1, high, 2 * pos + 2);
}
 void updateSegmentTree(int segmentTree[], int index, int delta, int low, int high, int pos) 
{

    //if index to be updated is less than low or higher than high just return.
    if (index < low || index > high) {
        return;
    }

    //if low and high become equal, then index will be also equal to them and update
    //that value in segment tree at pos
    if (low == high) {
        segmentTree[pos] += delta;
        return;
    }
    //otherwise keep going left and right to find index to be updated 
    //and then update current tree position if min of left or right has
    //changed.
    int mid = (low + high) / 2;
    updateSegmentTree(segmentTree, index, delta, low, mid, 2 * pos + 1);
    updateSegmentTree(segmentTree, index, delta, mid + 1, high, 2 * pos + 2);
    segmentTree[pos] =segmentTree[2 * pos + 1]+ segmentTree[2 * pos + 2];
}
 void updateSegmentTree(int input[],int inputsize,int segmentTree[], int index, int delta)
 {
          input[index] += delta; 
          updateSegmentTree(segmentTree, index, delta, 0,inputsize-1, 0);
 }
 void updateSegmentTreeRange(int segmentTree[], int startRange, int endRange, int delta, int low, int high, int pos)
 {
     if (low > high || startRange > high || endRange < low) {
         return;
     }

     if (low == high) {
         segmentTree[pos] += delta;
         return;
     }

     int middle = (low + high) / 2;
     updateSegmentTreeRange(segmentTree, startRange, endRange, delta, low, middle, 2 * pos + 1);
     updateSegmentTreeRange(segmentTree, startRange, endRange, delta, middle + 1, high, 2 * pos + 2);
     segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
 }
 void updateSegmentTreeRange(int input[],int inputsize, int segmentTree[], int startRange, int endRange, int delta) 
 {
     for (int i = startRange; i <= endRange; i++)
     {
         input[i] += delta;
     }
     updateSegmentTreeRange(segmentTree, startRange, endRange, delta, 0, inputsize-1, 0);
 }

void updateSegmentTreeRangeLazy(int segmentTree[], int lazy[], int startRange, int endRange, int delta, int low, int high, int pos)
{
    if (low > high)
    {
        return;
    }

    //make sure all propagation is done at pos. If not update tree
    //at pos and mark its children for lazy propagation.
    if (lazy[pos] != 0) {
        segmentTree[pos] += lazy[pos];
        if (low != high) { //not a leaf node
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    //no overlap condition
    if (startRange > high || endRange < low) {
        return;
    }

    //total overlap condition
    if (startRange <= low && endRange >= high) {
        segmentTree[pos] += delta;
        if (low != high) {
            lazy[2 * pos + 1] += delta;
            lazy[2 * pos + 2] += delta;
        }
        return;
    }

    //otherwise partial overlap so look both left and right.
    int mid = (low + high) / 2;
    updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange,
        delta, low, mid, 2 * pos + 1);
    updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange,
        delta, mid + 1, high, 2 * pos + 2);
    segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
}
void updateSegmentTreeRangeLazy(int input[], int inputsize, int segmentTree[], int lazy[], int startRange, int endRange, int delta)
{
    updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange, delta, 0, inputsize - 1, 0);
}
int rangeMinimumQueryLazy(int segmentTree[], int lazy[], int qlow, int qhigh, int low, int high, int pos) {

    if (low > high)
    {
        return 0;
    }

    //make sure all propagation is done at pos. If not update tree
    //at pos and mark its children for lazy propagation.
    if (lazy[pos] != 0)
    {
        segmentTree[pos] += lazy[pos];
        if (low != high) { //not a leaf node
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    //no overlap
    if (qlow > high || qhigh < low) 
    {
        return 0;
    }

    //total overlap
    if (qlow <= low && qhigh >= high) {
        return segmentTree[pos];
    }

    //partial overlap
    int mid = (low + high) / 2;
    return rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh,
        low, mid, 2 * pos + 1)
        + rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh,
            mid + 1, high, 2 * pos + 2);

}

int rangeMinimumQueryLazy(int segmentTree[], int lazy[], int qlow, int qhigh, int len) 
{
     return rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh, 0, len - 1, 0);
 }



int32_t main()
{
    //int n;
    //cin >> n;
    //mk(input, n, int);
    //for (int i = 0; i < n; i++)    cin >> input[i];
    //int segsize = sizecalforsegment(n);

    //mk(segment, segsize, int);
    //fill(segment, segment + segsize, 0);

    //for (int i = 0; i < n; i++)
    //    cout << input[i] << " ";
    //cout << endl;

    //// low=0 high=n-1,pos=0

    //ConstructSegmentMIN(input, segment, 0, n - 1, 0);
    //cout << RangeMinQuerey(segment, 0, 2, 0, 3, 0) << endl;
    //cout << RangeMinQuerey(segment, 2, 3, 0, 3, 0) << endl;
    //for (int i = 0; i < segsize; i++)
    //    cout << segment[i] << " ";
    //updateSegmentTree(input,n, segment, 2, 10);
    //cout << endl;
    //cout << RangeMinQuerey(segment, 0, 2, 0, 3, 0) << endl;
    //cout << RangeMinQuerey(segment, 2, 3, 0, 3, 0) << endl;
    //for (int i = 0; i < segsize; i++)
    //    cout << segment[i] << " ";
    //updateSegmentTreeRange(input,n,segment, 1, 3, -5);

    //cout << endl;
    //for (int i = 0; i < segsize; i++)
    //    cout << segment[i] << " ";
   


    //lazy propagation 

    
    int input1[] = {1,2,3,4};
    int inputsize1 = sizeof(input1) / sizeof(input1[0]);
    int segsize1 = sizecalforsegment(inputsize1);


    int n = segsize1;
    mk(segTree1, segsize1, int);
    mk(lazy1, segsize1, int);
    
    fill(segTree1, segTree1 + segsize1, 0);
    fill(lazy1, lazy1 + segsize1, 0);
  
    
    ConstructSegmentMIN(input1, segTree1, 0, inputsize1 - 1, 0);

    for (int i = 0; i < inputsize1; i++)
        cout << input1[i] << " ";
    cout << endl;

    // low=0 high=n-1,pos=0

    for (int i = 0; i < n; i++)
        cout << segTree1[i] << " ";
    cout << endl;

    updateSegmentTreeRangeLazy(input1, inputsize1, segTree1, lazy1, 0, 3, 1);
   // updateSegmentTreeRangeLazy(input1, inputsize1, segTree1, lazy1, 0, 0, 2);
   cout<<rangeMinimumQueryLazy(segTree1, lazy1, 0, 3, inputsize1)<<endl<<endl;


    for (int i = 0; i < n; i++)
        cout << lazy1[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << segTree1[i] << " ";




}

