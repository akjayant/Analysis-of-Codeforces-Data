#include<bits/stdc++.h>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pr pair<int,int>
#define pll pair<long long,long long>
#define ll long long
#define v vector
#define all(a) a.begin(),a.end()
#define ina(a,i,n) for(i=0;i<n;i++)cin>>a[i]
#define mmst(a) memset(a,0,sizeof(a))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define pi 3.14159265358979
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);   
    #endif
    int i,j,k,n;
    int a,b,c,d;
    int t;
    cin>>t;
    while(t--) {
    	cin>>a>>b>>c>>d>>k;
    	int x = a/c;
    	if(a%c)
    		x++;
    	int y = b/d;
    	if(b%d)
    		y++;
    	if(x + y > k) {
    		cout<<-1<<endl;
    	}
    	else 
    		cout<<x<<" "<<y<<endl;
    }

  	return 0;
}
