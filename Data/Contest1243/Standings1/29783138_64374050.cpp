#include<bits/stdc++.h>
using namespace std;
#define pfi(a) printf("%d",a);
#define pfl(a) printf("%lld",a);
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
const int M=1e9+7;
const int maxn=5e5+5;


 
int main(){
 ios_base::sync_with_stdio(false);
 	
 	int t;
 	cin>>t;

 	while(t--){
 		int n;
 		cin>>n;

 		vector<int> v(n);

 		f(i,0,n)
 		cin>>v[i];

 		sort(v.begin(),v.end(),greater<int>());

 		int maxans=-1;

 		int currw=-1,currh=INT_MAX;

 		for(int i=0;i<n;i++){
 			currh=min(currh,v[i]);
 			currw=i+1;
 			maxans=max(maxans,min(currw,currh));
 		}

 		cout<<maxans<<endl;
 	}
 	
 	
	return 0;
}