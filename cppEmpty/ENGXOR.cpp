#include<iostream>
using namespace std;
int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3,
						1, 2, 2, 3, 2, 3, 3, 4 };

unsigned int countSetBitsRec(unsigned int num)
{
	int nibble = 0;
	if (0 == num)
		return num_to_bits[0];

	nibble = num & 0xf;

	return num_to_bits[nibble] + countSetBitsRec(num >> 4);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n,q,TotalsetdigitsEVEN=0;
		cin >> n>>q;
		long int arr[100001] = {};
		
		for (int i = 0;i < n;i++)
		{
			cin >> arr[i];
		
		}
		for (int i = 0;i < n;i++)
		{
			
			if (countSetBitsRec(arr[i]) % 2 == 0)
			{
				TotalsetdigitsEVEN++;
			}
		}
		while (q--)
		{
			int p;
			cin >> p;
			int x = countSetBitsRec(p);
			if (x%2==0)
			{
				cout << TotalsetdigitsEVEN <<" "<<n - TotalsetdigitsEVEN<<"\n";

			}
			else
			{
				cout << n - TotalsetdigitsEVEN <<" "<< TotalsetdigitsEVEN<<"\n";
			}

					
			//system("pause");


		}
	}


}