#include <bits/stdc++.h>
#define ll long long
#define db long double
#define prl(c) cout<<(c)<<"\n"
#define al(fu) (fu).begin(), (fu).end()
#define alr(fu) (fu).rbegin(), (fu).rend()
#define fr(i,l,n) for(ll i=l;i<(ll)n;i++)
#define mod 998244353LL
#define mods 1000000007LL
#define pi 3.14159265359
#define br cout<<"\n"
#define prv(v) fr(qz,0,v.size()) cout<<(v)[qz]<<' '; br
#define iosync ios::sync_with_stdio(0)
#define pump(a,b) push_back(make_pair(a,b))

using namespace std;

int main() {
	iosync;
	ll n;
	string s;
	cin>>n>>s;
	ll bl=0;
	queue<pair<ll,ll>> sd;
	fr(i,0,n){
	    if(s[i]=='(') {
            sd.push(make_pair(1,i+1));
            bl++;
        }
	    else {
            sd.push(make_pair(-1,i+1));
            bl--;
	    }
	}
	if(bl!=0){
        prl(0);
        prl("1 1");
        return 0;
	}
	ll c=0,l=1,r=1;
	bl=0;
    fr(i,0,n){
        if(s[i]=='(') bl++;
        else bl--;
        if(bl<0){
            c=0;
            break;
        }
        if(bl==0) c++;
    }
	fr(i,0,n){
	    vector<pair<ll,ll>> k;
	    while(!sd.empty()){
            k.push_back(sd.front());
            sd.pop();
	    }
	    fr(i,0,n) sd.push(k[i]);
	    if(k[0].first<0){
            ll ko=0,kj=0;
            bl=0;
            for(ll j=n-1;j>0;j--){
                bl+=k[j].first;
                if(bl>0){
                    kj=j;
                    swap(k[0],k[j]);
                    break;
                }
            }
            bl=0;
            fr(i,0,n){
                bl+=k[i].first;
                if(bl<0){
                    ko=0;
                    break;
                }
                if(bl==0) ko++;
            }
            if(ko>c){
                c=ko;
                l=k[0].second;
                r=k[kj].second;
            }
	    }
	    else{
            bl=0;
            ll ko=0;
            fr(i,0,n){
                bl+=k[i].first;
                if(bl<0){
                    ko=0;
                    break;
                }
                if(bl==0) ko++;
            }
            if(ko>c){
                c=ko;
                l=1;
                r=1;
            }
	    }
	    sd.push(sd.front());
	    sd.pop();
	}
	prl(c);
	cout<<l<<' '<<r;
	return 0;
}
