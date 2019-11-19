#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll i,j,k,n,m,x,y,ans=0,b;
        //ll a,b,c,d,k,pn,pc;

        cin>>n;
        string S;
        cin>>S;
        ll temp = 0;

        for(i=0;i<n;i++){
            if(S[i]=='1')
                temp = max(temp,max(i+1,n-i));
        }

        if(temp==0) cout<<n<<endl;
        else cout<<2*temp<<endl;
    }


}

