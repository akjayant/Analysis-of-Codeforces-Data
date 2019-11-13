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
	int t,i,z,j,cnt=0,maxi;
	string s;
	cin >> t;
	while(t--)
	{
		cnt=0;maxi=0;
	cin >> n;int arr[n+1];
	for(i=1;i<=n;i++)
{
cin >> arr[i];
}
for(i=1;i<=1000;i++){
	cnt=0;
	for(j=1;j<=n;j++){
		if(arr[j]>=i)
		cnt++;
	}
	if(cnt>=i)
	maxi=i;
}
cout<<maxi<<endl;


	}
	return 0;
}



