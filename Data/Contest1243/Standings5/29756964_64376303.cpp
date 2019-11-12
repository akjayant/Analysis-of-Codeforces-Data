#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vii vector<pair<int,int> >
#define vll vector<pair<ll,ll> >

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int ans=1;
        for(int i=2;i<=n;i++){
            int pos=lower_bound(a,a+n,i)-a;
            //cout<<pos<<' ';
            int temp=min(n-pos,i);
            ans=max(ans,temp);
        }
        cout<<ans<<'\n';
    }
	return  0;
}
