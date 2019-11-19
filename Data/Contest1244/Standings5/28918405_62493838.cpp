#include <bits/stdc++.h>

using namespace std;

long long n,a[100007],b[100007],c[100007],x,y,f,d[100007],t[100007],e[17],p;
string s;
vector <long long>v[100007];
void S(long long r,long long l){
    d[l]=r;
    if(r==1){
        for(int i=0;i<v[l].size();i++){
            if(t[v[l][i]]==0){
                t[v[l][i]]=1;
                S(2,v[l][i]);
            }
        }
    }else if(r==2){
        for(int i=0;i<v[l].size();i++){
            if(t[v[l][i]]==0){
                t[v[l][i]]=1;
                S(3,v[l][i]);
            }
        }
    }else if(r==3){
        for(int i=0;i<v[l].size();i++){
            if(t[v[l][i]]==0){
                t[v[l][i]]=1;
                S(1,v[l][i]);
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        if(v[x].size()>2 || v[y].size()>2)f=1;
    }
    if(f==1){
        cout<<-1<<endl;
        return 0;
    }p=100000000000000;
    for(int i=1;i<=n;i++){
        if(v[i].size()==1){
            t[i]=1;
            S(1,i);
            break;
        }
    }

    for(int i=1;i<=n;i++){
        if(d[i]==1)e[1]+=a[i];
        if(d[i]==2)e[1]+=b[i];
        if(d[i]==3)e[1]+=c[i];
    }
    for(int i=1;i<=n;i++){
        if(d[i]==2)e[2]+=a[i];
        if(d[i]==3)e[2]+=b[i];
        if(d[i]==1)e[2]+=c[i];
    }
    for(int i=1;i<=n;i++){
        if(d[i]==3)e[3]+=a[i];
        if(d[i]==1)e[3]+=b[i];
        if(d[i]==2)e[3]+=c[i];
    }
    for(int i=1;i<=n;i++){
        if(d[i]==1)e[4]+=a[i];
        if(d[i]==3)e[4]+=b[i];
        if(d[i]==2)e[4]+=c[i];
    }
    for(int i=1;i<=n;i++){
        if(d[i]==2)e[5]+=a[i];
        if(d[i]==1)e[5]+=b[i];
        if(d[i]==3)e[5]+=c[i];
    }
    for(int i=1;i<=n;i++){
        if(d[i]==3)e[6]+=a[i];
        if(d[i]==2)e[6]+=b[i];
        if(d[i]==1)e[6]+=c[i];
    }
    p=min(min(min(e[1],e[2]),min(e[3],e[4])),min(e[5],e[6]));
    cout<<p<<endl;
    if(p==e[1]){
        for(int i=1;i<=n;i++){
            if(d[i]==1)cout<<1<<" ";
            if(d[i]==2)cout<<2<<" ";
            if(d[i]==3)cout<<3<<" ";
        }
    }else if(p==e[2]){
        for(int i=1;i<=n;i++){
            if(d[i]==2)cout<<1<<" ";
            if(d[i]==3)cout<<2<<" ";
            if(d[i]==1)cout<<3<<" ";
        }
    }else if(p==e[3]){
        for(int i=1;i<=n;i++){
            if(d[i]==3)cout<<1<<" ";
            if(d[i]==1)cout<<2<<" ";
            if(d[i]==2)cout<<3<<" ";
        }
    }else if(p==e[4]){
        for(int i=1;i<=n;i++){
            if(d[i]==1)cout<<1<<" ";
            if(d[i]==3)cout<<2<<" ";
            if(d[i]==2)cout<<3<<" ";
        }
    }else if(p==e[5]){
        for(int i=1;i<=n;i++){
            if(d[i]==2)cout<<1<<" ";
            if(d[i]==1)cout<<2<<" ";
            if(d[i]==3)cout<<3<<" ";
        }
    }else if(p==e[6]){
        for(int i=1;i<=n;i++){
            if(d[i]==3)cout<<1<<" ";
            if(d[i]==2)cout<<2<<" ";
            if(d[i]==1)cout<<3<<" ";
        }
    }


    return 0;
}
