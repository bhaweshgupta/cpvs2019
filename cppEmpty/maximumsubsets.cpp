#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
void allsubs(string str,string curr=" ",int index=0)
{
	if (index == str.length())
	{
		cout << curr << endl;
		return;
	}
	
	allsubs(str, curr, index + 1);
	allsubs(str, curr + str[index], index + 1);
	
}
int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		allsubs(str);
	}
	system("pause");

}