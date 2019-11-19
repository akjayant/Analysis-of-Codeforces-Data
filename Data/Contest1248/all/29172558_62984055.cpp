#include <iostream>
#include <algorithm>
using namespace std;
long long cd,a[122345],sum,k;
int main()
{
		cin >> cd;
		for (long long i = 1 ; i <= cd ; i++)
		{
				cin >> a[i];
				sum += a[i];
		}
		sort(a + 1 , a + 1 + cd);
		for (long long i = 1 ; i <= cd/2 ; i++)
		{
				k += a[i];
		}
		cout <<k*k + (sum - k)*(sum - k);
}