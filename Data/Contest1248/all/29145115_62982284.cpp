#include<bits/stdc++.h>

using namespace std;

int main(){
#define int long long
        int t;
        cin>>t;
        while(t--){
                int n;
                cin>>n;
                int chet1=0,nechet1=0,chet2=0,nechet2=0;
                for(int i=0;i<n;i++){
                        int v;
                        cin>>v;
                        if(v%2==0)
                                chet1+=1;
                        else
                                nechet1+=1;
                }
                int m;
                cin>>m;
                for(int i=0;i<m;i++){
                        int b;
                        cin>>b;
                        if(b%2==0){
                                chet2+=1;
                        }
                        else{
                                nechet2+=1;
                        }
                }
                int ans=(nechet1*nechet2)+(chet1*chet2);
                cout<<ans<<'\n';
        }
}
