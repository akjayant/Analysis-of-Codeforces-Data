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
	int t,i,z,flag,j,k;
	string s1,s2;
	cin >> t;
	while(t--)
	{
	cin >> n;
	int arr[n*3],brr[n*3];
	cin>>s1;
	cin>>s2;k=0;
	for(i=0;i<n;i++){
		if(s1[i]==s2[i])
		continue;
		flag=0;
		for(j=i+1;j<n;j++){
			if(s1[i]==s2[j])
			{
				swap(s1[n-1],s2[j]);
				arr[k]=n-1;brr[k]=j;k++;
				swap(s1[n-1],s2[i]);
				arr[k]=n-1;brr[k]=i;k++;
				flag=1;
				break;
			}
		}
			if(flag==1)
			continue;
			for(j=i+1;j<n;j++){
				if(s1[i]==s1[j]){
					swap(s1[j],s2[i]);
				arr[k]=j;brr[k]=i;k++;
				break;
				}
			}
		
	}
	if(s1==s2)
	{
	cout<<"Yes"<<endl;
	cout<<k<<endl;
	for(i=0;i<k;i++){
		cout<<arr[i]+1<<" "<<brr[i]+1<<endl;
	}
	}
	else
	cout<<"No"<<endl;
}
	return 0;
}



