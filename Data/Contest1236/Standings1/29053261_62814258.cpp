#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007
#define F first
#define S second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll P(ll x,ll y){
    ll ret = 1;
    while(y){
        if(y%2)ret = (ret*x)%mod;
        x = (x*x)%mod;
        y/=2;
        
    }
    return ret;
}

int main(){
	FIO
    ll n,m,k;
    cin >> n >> m >> k;
    
    vector<ll> r[n+1],c[m+1];
    
    for(ll i = 1;i<=k;i++){
        ll x,y;
        cin >> x >> y;
        r[x].push_back(y);
        c[y].push_back(x);
    }
    for(ll i = 1;i<=n;i++){
        r[i].push_back(0);
        sort(r[i].begin(),r[i].end());
        r[i].push_back(m+1);
    }
    
    
    for(ll i = 1;i<=m;i++){
        c[i].push_back(0);
        sort(c[i].begin(),c[i].end());
        c[i].push_back(n+1);
    }
    
    ll cnt = 0;
    ll sx = 1,sy = 1,dir = 1,lim1 = m+1,lim2 = n+1,lim3 = 0,lim4= 1,fl = 0;
    while(1){
        ll cx = sx,cy = sy;
        if(dir == 1){
            ll ox = lower_bound(r[sx].begin(),r[sx].end(),sy)-r[sx].begin();
            ll upt = lim1;
            if(r[sx][ox]>=lim1)upt = lim1;
            else upt = r[sx][ox];
            cnt+=(upt-sy-1);
            sy = upt-1;
            dir+=1;
            lim1 = sy;
        }
        else if(dir == 2){
            ll oy = lower_bound(c[sy].begin(),c[sy].end(),sx)-c[sy].begin();
            
            ll upt = lim2;
            upt = min(c[sy][oy],lim2);
            
                cnt+=(upt-sx-1);
                sx = (upt-1);
                dir+=1;
                lim2 = sx;
            
        }
        else if(dir == 3){
            ll ox = lower_bound(r[sx].begin(),r[sx].end(),sy)-r[sx].begin();
            if(r[sx][ox]>=sy)ox--;
            
            ll upt = lim3;
            upt = max(r[sx][ox],lim3);
            
                cnt+=sy-upt-1;
                sy = upt+1;
                dir+=1;
                lim3 = sy;
        }
        else {
            ll oy = lower_bound(c[sy].begin(),c[sy].end(),sx)-c[sy].begin();
            if(c[sy][oy]>=sx)oy--;

            ll upt = max(c[sy][oy],lim4);
            
                cnt+=(sx-upt-1);
                sx = upt+1;
                dir = 1;
                lim4 = sx;
        }
        if(sx == cx && sy == cy){
            if(sx == 1 && cy == 1 && fl == 0){fl++;continue;}
            break;
        }
    }
    cnt++;
    if((cnt+k) == (n*m)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
	return 0;
}





