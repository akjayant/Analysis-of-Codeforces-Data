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

int gcd(int a,int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
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
int printDivisors(int n) 
{ 
int ans=n;
    // Note that this loop runs till square root 
    for (int i=2; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            
			// If divisors are equal, print only one 
            if (n/i == i) 
            ans=gcd(ans,i);
                //printf("%d ", i); 
  
            else 
			{
				ans=gcd(ans,i);
				ans=gcd(ans,n/i);
			}
			// Otherwise print both 
                //printf("%d %d ", i, n/i); 
        } 
    }
	return ans; 
}
#undef int
int main()
{
	#define int long long int
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t=1,i,z,n;
	string s;
	//cin >> t;
	while(t--)
	{
	cin >> n;
	cout<<printDivisors(n)<<endl;
	


	}
	return 0;
}



