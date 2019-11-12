#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream fin("AAtest.in.txt");
ll k,n,mit['z'+1],l;
string s,s1;
vector<pair<ll,ll> > v;
bool b,sai;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    cin>>k;
    while(k--){
        cin>>n;
        cin>>s>>s1;
        memset(mit,0,sizeof(mit));
        v.resize(0);
        for(int i=0; i<n; i++) mit[s[i]]++,mit[s1[i]]++;
        b=0;
        for(char c='a'; c<='z'; c++) if(mit[c]%2){
            cout<<"No\n";
            b=1;
            break;
        }
        if(!b){
            cout<<"Yes\n";
            char c;
            for(int l=0; l<n; l++) if(s[l]!=s1[l]){
                c=s[l];
                sai=0;
                for(int i=l+1; i<n; i++) if(s[i]==c){
                    v.push_back({i,l});
                    swap(s[i],s1[l]);
                    sai=1;
                    break;
                }
                if(!sai){
                    c=s1[l];
                    for(int i=l+1; i<n; i++) if(s1[i]==c){
                        v.push_back({l,i});
                        swap(s[l],s1[i]);
                        sai=1;
                        break;
                    }
                }
                if(!sai){
                    for(int i=l+1; i<n; i++) if(s[i]==c){
                        v.push_back({i,n-1});
                        v.push_back({l,n-1});
                        swap(s[i],s1[n-1]);
                        swap(s[l],s1[n-1]);
                    }
                }
            }
            cout<<v.size()<<"\n";
            for(int i=0; i<v.size(); i++) cout<<v[i].first+1<<" "<<v[i].second+1<<"\n";
        }
    }
}
