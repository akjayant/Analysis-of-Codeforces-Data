#include <bits/stdc++.h>

using namespace std;
int n,q,c,k,s,r,p,sc,a,b,o,aa,lsc,bb,cc,jj,arr[1002];
map<int,int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;
    for(int l=0;l<q;l++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        s=1;
        for(int i=0;i<n;i++){
            if(n-i>=arr[i]) s=arr[i];
            else s=max(s,n-i);
        }
        cout<<s<<'\n';
    }

}
