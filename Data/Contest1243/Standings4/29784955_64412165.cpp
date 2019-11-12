#include<bits/stdc++.h>

using namespace std;
const int N = 1234;
typedef pair<int,int> ii;

void solve(){
    int n;
    string a,b;
    cin>>n;
    cin>>a>>b;

set<int> loca[200],locb[200];
    for(int i = 0 ; i < n ; i ++){
        if(a[i] == b[i]) continue;
        loca[a[i]].insert(i);
        locb[b[i]].insert(i);

    }
    vector<ii> moves;
    for(int i = 0 ; i < n ; i ++){
        if(a[i] == b[i]) continue;
        loca[a[i]].erase(i);
        locb[b[i]].erase(i);
        if(loca[a[i]].size()){
            int idx = *(loca[a[i]].begin());
            loca[a[i]].erase(idx);
            loca[b[i]].insert(idx);
            a[idx] = b[i];
            if(a[idx]==b[idx]){
                loca[a[idx]].erase(idx);
                locb[b[idx]].erase(idx);
            }
            /// add move
            moves.push_back(ii(idx,i));
        } else if(locb[b[i]].size()){
            int idx = *(locb[b[i]].begin());
            locb[b[i]].erase(idx);
            locb[a[i]].insert(idx);
            b[idx] = a[i];
            if(a[idx]==b[idx]){
                loca[a[idx]].erase(idx);
                locb[b[idx]].erase(idx);
            }
            /// add move
            moves.push_back(ii(i,idx));
        } else if(locb[a[i]].size()){
            int idx = *(locb[a[i]].begin());
            locb[b[idx]].erase(idx);
            loca[a[idx]].erase(idx);
            locb[a[idx]].insert(idx);
            loca[b[idx]].insert(idx);
            b[idx] = a[idx];
            a[idx] = a[i];
            /// add move
            moves.push_back(ii(idx,idx));

            loca[a[i]].erase(idx);
            loca[b[i]].insert(idx);
            a[idx] = b[i];
            if(a[idx]==b[idx]){
                loca[a[idx]].erase(idx);
                locb[b[idx]].erase(idx);
            }
            moves.push_back(ii(idx,i));
        } else if(loca[b[i]].size()){
            int idx = *(loca[b[i]].begin());
            loca[a[idx]].erase(idx);
            locb[b[idx]].erase(idx);
            loca[b[idx]].insert(idx);
            locb[a[idx]].insert(idx);
            a[idx] = b[idx];
            b[idx] = b[i];
            /// add move
            moves.push_back(ii(idx,idx));

            locb[b[i]].erase(idx);
            locb[a[i]].insert(idx);
            b[idx] = a[i];
            if(a[idx]==b[idx]){
                loca[a[idx]].erase(idx);
                locb[b[idx]].erase(idx);
            }
            /// add move
            moves.push_back(ii(i,idx));

        } else {
            cout<<"No\n";
            return ;
        }

    }
    assert(moves.size()<=2*n);
    cout<<"Yes\n"<<moves.size()<<endl;;

    for(ii m : moves){
        cout<<m.first+1<<" "<<m.second+1<<endl;
    }
}
int main(){

    int k;
    scanf("%d",&k);
    while(k--){
        solve();
    }
    return 0;
}

