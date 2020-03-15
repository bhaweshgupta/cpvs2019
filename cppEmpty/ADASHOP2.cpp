#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r, c;
		cin >> r >> c;
		vector<pair<int, int>> vect;
		vect.push_back(make_pair(1, 1));
		vect.push_back(make_pair(2, 2));
		vect.push_back(make_pair(1, 3));
		vect.push_back(make_pair(3, 1));
		vect.push_back(make_pair(2, 2));
		vect.push_back(make_pair(3, 3));
		vect.push_back(make_pair(1, 5));
		vect.push_back(make_pair(5, 1));
		vect.push_back(make_pair(3, 3));
		vect.push_back(make_pair(4, 4));
		vect.push_back(make_pair(1, 7));
		vect.push_back(make_pair(7, 1));
		vect.push_back(make_pair(4, 4));
		vect.push_back(make_pair(5, 5));
		vect.push_back(make_pair(8, 2));
		vect.push_back(make_pair(2, 8));
		vect.push_back(make_pair(5, 5));
		vect.push_back(make_pair(6, 6));
		vect.push_back(make_pair(8, 4));
		vect.push_back(make_pair(4, 8));
		vect.push_back(make_pair(6, 6));
		vect.push_back(make_pair(7, 7));
		vect.push_back(make_pair(8, 6));
		vect.push_back(make_pair(6, 8));
		vect.push_back(make_pair(7, 7));
		vect.push_back(make_pair(8, 8));
	

		cout << vect.size()-1 << endl;
		for (auto v : vect)
		{
			cout << v.first << " " << v.second<<"\n";
		}

	}
	//system("pause");
}