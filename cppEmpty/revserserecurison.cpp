#include<iostream>
using namespace std;
#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int reversenumber(int num)
{
    static int rev_num = 0;
    static int base_pos = 1;
    if (num > 0)
    {
        reversenumber(num / 10);
        rev_num += (num % 10) * base_pos;
        base_pos *= 10;
    }
    return rev_num;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        cout << reversenumber(n) << endl;
    }
    system("pause");
}