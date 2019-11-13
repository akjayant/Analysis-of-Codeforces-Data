#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
const int N = 1e5;
const int p = 1e9 + 7;
using namespace std;
int f[N + 5],n;
char ch[N + 5];
int main()
{
	scanf("%s",ch + 1);
	n = strlen(ch +  1);
	for (int i = 1;i <= n;i++)
		if (ch[i] == 'm' || ch[i] == 'w')
		{
			cout<<"0"<<endl;
			return 0;
		}
	f[0] = 1;
	for (int i = 1;i <= n;i++)
		if (ch[i] == ch[i - 1] && (ch[i] == 'u' || ch[i] == 'n'))
			f[i] = (0ll + f[i - 2] + f[i - 1]) % p;
		else
			f[i] = f[i - 1];
	cout<<f[n]<<endl;
	return 0;
}