#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=105;
char s[N];
int cnt[3];
int tag[N];

void init();
void work();
int ca=1;
int main(){
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    init();
    int T;cin>>T;
    while(T--)
    work();
    return 0;
}
void work(){
    int n;cin>>n;
    int a,b,c;cin>>a>>b>>c;
    cin>>s+1;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        if(s[i]=='R') cnt[0]++;
        else if(s[i]=='P') cnt[1]++;
        else cnt[2]++;
    }
    if((n+1)/2>min(cnt[0],b)+min(cnt[1],c)+min(cnt[2],a)){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    memset(tag,0,sizeof(tag));
    for(int i=1;i<=n;i++){
        if(s[i]=='R'){
            if(b) b--,s[i]='P',tag[i]=1;
        }else if(s[i]=='P'){
            if(c) c--,s[i]='S',tag[i]=1;
        }else{
            if(a) a--,s[i]='R',tag[i]=1;
        }
    }
    for(int i=1;i<=n;i++)if(!tag[i]){
        if(a) a--,s[i]='R';
        else if(b) b--,s[i]='P';
        else c--,s[i]='S';
    }
    cout<<s+1<<'\n';
}
