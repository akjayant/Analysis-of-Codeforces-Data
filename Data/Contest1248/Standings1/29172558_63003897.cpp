#include <iostream>
using namespace std;
int l,r,a[400000],kq,cd,mn[400000];
int check()
{
		int t = 0 , got = 0 , s=  0;
		for (int i = 1 ; i <= cd ; i++)
		{
				mn[i] = 1e9;
				s += a[i];
				if (i == 1)
				{
						mn[i] = a[i];
				}
				else
				{
						mn[i] = min(s , mn[i-1]);
				}
		}
		int sum = 0;
		for (int i = cd ; i >= 1 ; i--)
		{
				sum += a[i];
				if (i == cd)
				{
						t = a[cd];
				}
				else
				{
						t = min(t + a[i] , a[i]);
				}
				if (t < 0) continue;
				if (sum + mn[i-1] >= 0)
				{
						got++;
				}
		}
		if (sum != 0)
		{
				return 0;
		}
		return got;
}
int main()
{
		cin >> cd;
		for (int i = 1 ; i <= cd ; i++)
		{
				char c;
				cin >> c;
				a[i] = -1;
				if (c == '(')
				{
						a[i] = 1;
				}
		}
		kq = check();
		l = 1 , r = 1;
		for (int i = 1 ; i <= cd ; i++)
		{
				for (int e = i ; e <= cd ; e++)
				{		
						/*swap(a[i] , a[i]);
						int have = check();
						if (have >= kq)
						{
								kq = have;
								l = i;
								r = i;
						}*/

						swap(a[i] , a[e]);
						int have = check();
						if (have >= kq)
						{
								kq = have;
								l = i;
								r = e;
						}
						swap(a[i] , a[e]);
						}
		}
		cout << kq<<'\n';
		cout <<l<<" "<<r;
}
