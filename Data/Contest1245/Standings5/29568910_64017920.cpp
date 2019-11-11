#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define MO 1000000007
#define mem(a,s) memset(a,s,sizeof(a))
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define lop(i,s,e) for(int i=s;i<=e;i++)
#define lopi(i,s,e) for(int i=s;i>=e;i--)
#define prina(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl; 
#define prin2da(a,n,m) lop(i,0,n-1){lop(j,0,m-1)cout<<a[i][j]<<" ";cout<<endl;} 
using namespace std;
ll n,m;
string s,t;

int main()
{
IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
string s;
cin>>s;
ll cntm=0,cntw=0;
ll ans=1;
ll fib[100001]={0};
fib[0]=0;
fib[1]=1;
fib[2]=1;
lop(i,3,100000)
fib[i]=(fib[i-2]+fib[i-1])%MO;
for(int i=0;i<s.length();i++)
{
	if(s[i]=='m')
		cntm++;
	else if(s[i]=='w')
		cntw++;
	int cnt=1;
	while(i+1<s.length()&& s[i+1]==s[i] && (s[i]=='n'||s[i]=='u'))
		i++,cnt++;	
    ans= (ans*(fib[cnt]+fib[cnt-1])) %MO;
}
if(cntw==0&&cntm==0)
cout<<ans<<endl;
else
cout<<0<<endl;

}

