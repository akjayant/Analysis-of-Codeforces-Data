// :(
#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    
    set<int> r[h], c[w];
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        r[x].insert(y);
        c[y].insert(x);
    }
    
    for(int i = 0; i < h; i++)  r[i].insert(w), r[i].insert(-1);
    for(int i = 0; i < w; i++)  c[i].insert(h), c[i].insert(-1);

    ll vis = 0, all = (ll)h*w-k;

    int li = -1, ri = h, lj = -1, rj = w;
    int way = 0;
    
    int i = 0, j = 0, f = 0;
    while(true){
        if(way == 0){
            int nj = min(rj,*r[i].upper_bound(j));
            vis += min(nj,rj)-1-j;
            // if(nj > rj)  break;
            rj = min(rj, nj);
                    li = max(li, i);
            if(f && j == nj-1)   break;
            j = nj-1;
        }else if(way == 1){
            int ni = min(ri, *c[j].upper_bound(i));
            vis += min(ni,ri)-1-i;
            // if(ni > ri)  break;
            ri = min(ri, ni);
                    rj = min(rj, j);
            if(f && i == ni-1)   break;
            i = ni-1;
        }else if(way == 2){
            int nj = max(lj, *(--r[i].lower_bound(j)));
            vis += j-max(nj,lj)-1;
            // if(nj < lj)    break;
            lj = max(lj, nj);
                    ri = min(ri, i);
            if(f && j == nj+1)   break;
            j = nj+1;
        }else if(way == 3){
            int ni = max(li, *(--c[j].lower_bound(i)));
            vis += i-max(ni,li)-1;
            // if(ni < li)    break;
            li = max(li, ni);
                    lj = max(lj, j);            
            if(f && i == ni+1)   break;
            i = ni+1;
        }
        way = (way+1)%4;
        f = 1;
    }
    cout << (vis+1==all ? "Yes" : "No") << endl;

    return 0;
}