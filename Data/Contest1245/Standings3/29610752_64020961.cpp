#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9+7;
void LSH()
{
	#ifndef ONLINE_JUDGE
		freopen("1245C.INP","r",stdin);
		freopen("1245C.OUT","w",stdout);
	#endif // ONLINE_JUDGE
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
string s;
long long d[100005];
int main()
{
	LSH();
    cin>>s;
    s=" "+s;
    for (int i = 1 ; i < s.size() ; ++i )
        if (s[i]=='m' || s[i]=='w')
        {
            cout<<0;
            exit(0);
        }
    d[0]=1;
    for (int i = 1 ; i < s.size() ; ++i )
        if ((s[i]=='u' && s[i-1]=='u') || (s[i]=='n' && s[i-1]=='n'))
            d[i]=(d[i-1]+d[i-2])%oo;
        else d[i]=d[i-1]%oo;
    cout<<d[s.size()-1];
}