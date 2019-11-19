#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    long long arr[3][n];
    for(long long j = 0;j<3;j++) {
        for(long long i = 0;i<n;i++) {
            cin>>arr[j][i];
        }
    }
    vector<long long> adj[n];
    bool inv = false;
    for(long long i = 0;i<n-1;i++) {
        long long u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(adj[u].size()>2||adj[v].size()>2)
            inv = true;
    }
    if(inv) {
        cout<<-1<<endl;
        return 0;
    }
    vector<long long> order;
    for(long long i = 0;i<n;i++) {
        if(adj[i].size()==1) {
            order.push_back(i);
            order.push_back(adj[i][0]);
            break;
        }
    }
    long long last = order[0];
    long long now = order[1];
    while(order.size()!=n) {
        long long temp = adj[now][0]+adj[now][1]-last;
        order.push_back(temp);
        last = now;
        now = temp;
    }
    long long best = -1;
    vector<long long> charr;
    for(long long t1=0;t1<6;t1++) {
        vector<long long> tarr;
        long long sum = 0;
        long long ord = t1%2;
        long long a1 = t1/2;
        tarr.push_back(a1);
        if(ord) {
            tarr.push_back((a1+1)%3);
            tarr.push_back((a1+2)%3);
        }
        else {
            tarr.push_back((a1+2)%3);
            tarr.push_back((a1+1)%3);
        }
        for(long long i = 0;i<n;i++) {
            long long pos = order[i];
            sum+=arr[tarr[i%3]][pos];
        }
        if(best==-1||sum<best) {
            best = sum;
            charr = tarr;
        }

    }
    vector<long long> color(n);
    for(long long i = 0;i<n;i++) {
        color[order[i]]=charr[i%3]+1;
    }
    cout<<best<<endl;
    for(long long i = 0;i<n;i++) {
        cout<<color[i]<<" ";
    }
}

