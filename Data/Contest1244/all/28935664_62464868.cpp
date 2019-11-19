#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int taille , A , B , D , K;
	cin>>A>>B>>D>>K>>taille;
	int premier = (A / D);
	if (A % D != 0) premier++;
	int second = (B / K);
	if (B % K != 0) second++;
	if (taille >= premier + second)
	{
		cout<<premier<<" "<<second<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
}
int main()
{
	int T;
	cin>>T;
	for (int i = 0 ; i < T ; i++)
	{
		solve();
	}
}