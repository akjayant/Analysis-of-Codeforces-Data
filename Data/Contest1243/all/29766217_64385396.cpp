#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#define smallMaxi 1001
#define bigMaxi 5000005
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
ll n,t,a,b;

int main()
{
	cin >> t;
	while(t--)
	{
		 cin >> n ;
		 ll arr[n+1];
		 for(int i=0;i<n;i++)
		 {
		 	cin >> arr[i];
		 }
		 sort(arr,arr+n);
		 ll ans = 0;
		 for(int i=0;i<n;i++)
		 {
		 	 if(i+arr[i]<n)
		 	 {
		 	 	ans = max(ans,arr[i]);
		 	 }
		 	 else
		 	 {
		 	 	ans = max(ans,(ll)n-i);
		 	 }
		 }
		 cout<<ans<<endl;
	}
   return 0;
}