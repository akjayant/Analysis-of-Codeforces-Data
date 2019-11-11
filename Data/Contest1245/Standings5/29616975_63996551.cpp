//by (111110101)2
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
int t,a,b;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(__gcd(a,b)==1)
		{
			cout<<"Finite"<<endl;
		}
		else
		{
			cout<<"Infinite"<<endl;
		}
	}
	return 0;
}