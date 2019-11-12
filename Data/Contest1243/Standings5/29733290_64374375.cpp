#include<bits/stdc++.h>
using namespace std;

int n,a[200009];
int f[1009];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        memset(f,0,sizeof(f));
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }
        for(int i=1000;i>=0;i--){
            f[i]+=f[i+1];
        }
        for(int i=n;i>=1;i--){
            if(f[i] >= i){
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}