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
        int f[26]={0};
        for(int i=0;i<n;i++){
            f[s[i]-97]++;
            f[t[i]-97]++;
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(f[i]%2==1){
                flag=1;
            }
        }
        if(flag){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
            vii op;
            for(int i=0;i<n;i++){
                if(s[i]==t[i]) continue;
                int pos=-1;
                for(int j=i+1;j<n;j++){
                    if(t[j]==s[i]){
                        pos=j;
                        break;
                    }
                }
                if(pos==-1){
                    for(int j=i+1;j<n;j++){
                        if(s[j]==s[i]){
                            pos=j;
                            break;
                        }
                    }
                    op.pb(mp(pos,i));
                    char temp=s[pos];
                    s[pos]=t[i];
                    t[i]=s[pos];
                }
                else{
                    op.pb(mp(pos,pos));
                    op.pb(mp(pos,i));
                    char temp=t[i];
                    t[i]=t[pos];
                    char temp2=s[pos];
                    s[pos]=temp;
                    t[pos]=temp2;
                }
            }
            cout<<op.size()<<'\n';
            for(int i=0;i<op.size();i++){
                cout<<op[i].f+1<<' '<<op[i].s+1<<'\n';
            }
        }
    }
	return  0;
}
