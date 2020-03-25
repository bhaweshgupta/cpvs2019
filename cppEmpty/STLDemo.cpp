#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
void mapdemo()
{
	map<char, int> mp;
	string str = "bhawesh gupta";
	for (char c : str)
	{
		mp[c]++;
		//Nlog(N)
	}
	cout << mp['a'] << mp['z']<<endl;



	auto it = mp.find('a'); //logn time 
	if (it!=mp.end())
	{
		cout << "element present"<<mp.at('a')<<endl;
		cout << mp.size()<<endl;
	}	
	for (pair<char, int>c : mp)
	{
		cout<<c.first <<" "<< c.second<<endl;
	}
}
void setdemo()
{
	set<int> st;
	st.insert(11);
	st.insert(15);
	st.insert(10);
	st.insert(5);
	st.insert(22); //logn time

	st.erase(5); //logn time


	auto it=st.lower_bound(21);
	//cout<<it - st.begin();

	auto it1=st.upper_bound(5);
	if (it != st.end())
	{
		cout << *it;
	}
	if (it1!= st.end())
	{
		cout << *it1;
	}

}

void setinterval()
{
	//	 {a,c} < {b,d} iff (a < b) or (a == b and c < d)

	set<pair<int, int>> stpair;
	stpair.insert({ 2,40 });
	stpair.insert({ 50,200 });
	stpair.insert({ 201,350 });
	stpair.insert({ 300,400 });

	int point = 55;
	pair<int,int> p=make_pair(point, INT_MAX);
	auto it=stpair.upper_bound(p);
	  
	
	
	//corner cases
	//1
	if (it == stpair.begin())
	{
		cout << "no such range";
	}
	--it;
	pair<int, int> current = *it;


	if (current.first <= p.first && current.second >= p.first)
	{
		cout << current.first << " "<<current.second;
	}


	

	

}

void vectordemo()
{

}
int main()
{
	mapdemo();
	//	setdemo();
	//setinterval();

	system("pause");
}