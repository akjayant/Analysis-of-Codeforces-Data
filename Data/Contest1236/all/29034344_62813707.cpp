#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> rows[100000+2];
vector<ll> cols[100000+3];

int main(int argc, char const *argv[])
{
    ll n,m,k;
    cin>>n>>m>>k;
    
    for(ll i=0;i<k;i++){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        rows[x].push_back(y);
        cols[y].push_back(x);
    }
    for(ll i=1;i<=n;i++){
        rows[i].push_back(0);
        rows[i].push_back(m+1);
        sort(rows[i].begin(), rows[i].end());
    }
    for(ll i=1;i<=m;i++){
        cols[i].push_back(0);
        cols[i].push_back(n+1);
        sort(cols[i].begin(), cols[i].end());
    }
    ll visit_count = 1;
    ll x = 1,y = 1;
    ll last_x=0,last_y=0;
    ll dir = 1;
    ll x_min = 0,x_max=n+1;
    ll y_min = 0,y_max=m+1;

    ll index = upper_bound(rows[x].begin(), rows[x].end(),y) - rows[x].begin();
    ll dest=rows[x][index]-1;
    if(dest>=y_max){
        dest=y_max-1;
    }
    visit_count += dest - y;
    y = dest;
    last_x = x;
    last_y = y;
    dir = 2;
    if(y_max>y)
        y_max = y;
    if(x_min<x)
        x_min = x;      
    ll counter = 0;
    while(1){
        // if(counter>10)
        //     break;
        // counter++;
        // cout<<"x: "<<x<<" y:"<<y<<" dir:"<<dir<<endl;
        // cout<<"x_min: "<<x_min<<" x_max:"<<x_max<<endl;
        // cout<<"y_min: "<<y_min<<" y_max:"<<y_max<<endl;
        ll x_copy = x;
        ll y_copy = y;
        if(dir==1){
            ll index = upper_bound(rows[x].begin(), rows[x].end(),y) - rows[x].begin();
            ll dest=rows[x][index]-1;
            if(dest>=y_max){
                dest=y_max-1;
            }
            if(dest==y)
                break;
            visit_count += dest - y;
            y = dest;
            if(y==last_y && x==last_x){
                break;
            }
            last_x = x;
            last_y = y;
            dir = 2;
            if(y_max>y)
                y_max = y;
            if(x_min<x)
                x_min = x;            
        }else if(dir==2){
            ll index = upper_bound(cols[y].begin(), cols[y].end(),x) - cols[y].begin();
            ll dest=cols[y][index]-1;
            if(dest>=x_max){
                dest=x_max-1;
            }
            if(dest==x)
                break;
            visit_count += dest - x;
            x = dest;
            if(y==last_y && x==last_x){
                break;
            }
            last_x = x;
            last_y = y;
            dir = 3;
            if(x_max>x)
                x_max = x;
            if(y_max>y)
                y_max = y;
            
        }else if(dir==3){
            ll index = upper_bound(rows[x].begin(), rows[x].end(),y) - rows[x].begin()-1;
            ll dest=rows[x][index]+1;
            if(dest<=y_min){
                dest=y_min+1;
            }
            if(dest==y)
                break;
            visit_count += y - dest;
            y = dest;
            if(y==last_y && x==last_x){
                break;
            }
            last_x = x;
            last_y = y;
            dir = 4;
            
            if(y_min<y)
                y_min = y;
            if(x_max>x)
                x_max = x;
        }else{
            ll index = upper_bound(cols[y].begin(), cols[y].end(),x) - cols[y].begin()-1;
            ll dest=cols[y][index]+1;
            // cout<<"dest is: "<<dest<<endl;
            if(dest<=x_min){
                dest=x_min+1;
            }
            if(dest==x)
                break;
            visit_count += x - dest;
            x = dest;
            if(y==last_y && x==last_x){
                break;
            }
            last_x = x;
            last_y = y;
            dir = 1;
            
            if(x_min<x)
                x_min = x;
            if(y_min<y)
                y_min = y;
        }
    }
    if(visit_count+k < m*n){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
    }

    return 0;
}