#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

map<pair<int, int>, bool> g;
set<int> s;
queue<int> q;

int n,m;
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0,x,y;i<m;i++){
        scanf("%d%d", &x, &y);
        g[make_pair(x,y)] = true;
        g[make_pair(y,x)] = true;
    }
    for(int i=1;i<=n;i++) s.insert(i);
    int cnt = 0;
    while(!s.empty()){
        queue<int> q;
        int x = *s.begin();
        s.erase(x);
        cnt ++;
        q.push(x);
        while(!q.empty()){
            x = q.front(); q.pop();
            for(set<int>::iterator it=s.begin();it!=s.end();){
                int y = *it;
                if(g[make_pair(x,y)]){
                    it++;
                    continue;
                }else{
                    q.push(y);
                    it=s.erase(it);
                }
            }
        }
        
    }
    printf("%d\n", cnt-1);

    return 0;
}


