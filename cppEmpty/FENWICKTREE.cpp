
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

/**
 * Start from index+1 if you updating index in original array. Keep adding this value
 * for next node till you reach outside range of tree
 */


 /**
  * To get parent
  * 1) 2's complement to get minus of index
  * 2) AND this with index
  * 3) Subtract that from index
  */
int getParent(int index) {
	return index - (index & -index);
}

/**
 * To get next
 * 1) 2's complement of get minus of index
 * 2) AND this with index
 * 3) Add it to index
 */
int getNext(int index) {
	return index + (index & -index);
}
void updateBinaryIndexedTree(int binaryIndexedTree[],int bitsize, int val, int index)
{
	while (index < bitsize)
	{
		binaryIndexedTree[index] += val;
		index = getNext(index);
	}
}

/**
 * Start from index+1 if you want prefix sum 0 to index. Keep adding value
 * till you reach 0
 */
int getSum(int binaryIndexedTree[], int index) {
	index = index + 1;
	int sum = 0;
	while (index > 0) {
		sum += binaryIndexedTree[index];
		index = getParent(index);
	}
	return sum;
}

/**
 * Creating tree is like updating Fenwick tree for every value in array
 */
int* createTree(int input[],int inputsize)
{
	/*int binaryIndexedTree[] = new int[inputsize+ 1];*/
	mk(binaryIndexedTree, inputsize+1, int);
    fill(binaryIndexedTree, binaryIndexedTree+ inputsize + 1, 0);
	for (int i = 1; i <= inputsize; i++) {
		updateBinaryIndexedTree(binaryIndexedTree,inputsize+1, input[i - 1], i);
	}
	return binaryIndexedTree;
}



int32_t main()
{
    int input[] = { 1,2,3,4,5,6,7 };
    int inputsize = sizeof(input) / sizeof(input[0]);

    int *binaryIndexedTree = createTree(input,inputsize);

     cout<<getSum(binaryIndexedTree, 0)<<endl;/*
    assert 3 == ft.getSum(binaryIndexedTree, 1);
    assert 6 == ft.getSum(binaryIndexedTree, 2);
    assert 10 == ft.getSum(binaryIndexedTree, 3);
    assert 15 == ft.getSum(binaryIndexedTree, 4);
    assert 21 == ft.getSum(binaryIndexedTree, 5);*/
    cout<<getSum(binaryIndexedTree, 6)<<endl;
}

