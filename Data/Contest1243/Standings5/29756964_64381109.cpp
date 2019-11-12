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
        string s,t;
        cin>>s>>t;
        int pos1=-1,pos2=-1;
        int flag=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                if(pos1==-1){
                    pos1=i;
                }
                else if(pos2==-1){
                    pos2=i;
                }
                else{
                    flag=1;
                }
            }
        }
        if(flag){
            cout<<"No\n";
        }
        else{
            if(s[pos1]==s[pos2] && t[pos1]==t[pos2]){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
	return  0;
}
