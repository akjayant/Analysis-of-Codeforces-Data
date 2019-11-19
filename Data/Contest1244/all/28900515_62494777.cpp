#include<bits/stdc++.h>
#define rep(i,b,e) for(LL i=(b);i<(e);++i)
#define dep(i,b,e) for(LL i=(b);i>=(e);--i)
#define LL long long

using namespace std;

int n;LL k;
set<int> a;
map<int,int> cnt;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;int t;
    rep(i,0,n){
        cin>>t;a.insert(t);
        cnt[t]++;
    }
    while(a.size()>1){
        auto it=a.begin();auto rit=a.rbegin();
        LL minv=*(it++),cmin=*it,maxv=*(rit++),cmax=*rit;
        LL c1=cnt[minv],c2=cnt[maxv];
        if(cnt[minv]<cnt[maxv]){
            LL kp=min(k/c1,cmin-minv);
            minv+=kp;
            if(minv<cmin){
                cout<<maxv-minv<<endl;
                //system("pause");
                return 0;
            }
            k-=kp*c1;
            cnt.erase(*(a.begin()));a.erase(a.begin());
            cnt[cmin]+=c1;
        }
        else{
            LL kp=min(k/c2,maxv-cmax);
            maxv-=kp;
            if(maxv>cmax){
                cout<<maxv-minv<<endl;
                //system("pause");
                return 0;
            }
            k-=kp*c2;
            cnt.erase(*(a.rbegin()));a.erase(*a.rbegin());
            cnt[cmax]+=c2;
        }
    }
    cout<<0<<endl;
    //system("pause");
    return 0;
}
