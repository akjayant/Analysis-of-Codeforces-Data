#include<bits/stdc++.h>
#define int long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define double long double
#define init(arr,val) memset(arr,val,sizeof(arr))
#define Pi 3.14159265358979323846264338327950288419716939937510
#define MAX_N 1000001
#define MAXN 100001
#define MAX_TREE (MAX_N << 2)
#define MID (left+right)/2
#define INF 987654321
#define ll long long
#define M 1000000007
using namespace std;
const int N=100005;
int n;

/*
int gcd(int a,int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
sort(arr, arr+n, greater<int>());
for(i=0;i<n;i++)
{
cin >> arr[i];
}
*/

#undef int
int main()
{
	#define int long long int
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t,i,z,cnt,flag1,flag2;
	string s1,s2;
	cin >> t;
	while(t--)
	{
		flag1=0;flag2=0;
		char a,b,c,d;cnt=0;
	cin >> n;
	cin>>s1;
	cin>>s2;
	for(i=0;i<n;i++){
		if(s1[i]==s2[i])
		cnt++;
		
	}
	if(cnt!=n-2)
	cout<<"No"<<endl;
	else
	{
		for(i=0;i<n;i++){
			if(s1[i]!=s2[i] && flag1==0)
			{
				a=s1[i];
				b=s2[i];
				flag1=1;
			}
				else if(s1[i]!=s2[i] && flag2==0)
			{
				c=s1[i];
				d=s2[i];
				flag2=1;
			}
		}
		if(a==c && b==d)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	}
	return 0;
}



