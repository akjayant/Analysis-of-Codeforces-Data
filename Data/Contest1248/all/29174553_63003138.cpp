#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(a) a.begin(),a.end()
#define ull unsigned long long
#define endl '\n'
#define y1 yaumru
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define iter vector<int>::iterator
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template<class T>
using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd1(chrono::steady_clock::now().time_since_epoch().count());

//find_by_order
//order_of_key

const int N=1e5+7;
const int inf=1e18+5;
const int mod=1e9+7;
const ld eps=1e-9;

stack< pair<int,int> >st;
stack< pair<int,int> >st1;
int k;

void add(int x)
{
    if (st1.size()<k){
        if (st1.size()==0){
            st1.push({x,x});
        }
        else {
            st1.push({min(st1.top().ff,x),x});
        }
    }
    else {
        while(st1.size()>0){
            int y=st1.top().ss;
            if (st.size()==0){
                st.push({y,y});
            }
            else {
                st.push({min(st.top().ff,y),y});
            }
            st1.pop();
        }
        st1.push({x,x});
    }
}

void del()
{
    st.pop();
}

int get()
{
    int ans=inf;
    if (st.size()>0)ans=min(ans,st.top().ff);
    if (st1.size()>0)ans=min(ans,st1.top().ff);
    return ans;
}

int check(string s)
{
    k=s.size();
    s=s+s;
    s.pop_back();
    int n=s.size();
    int pref[n];
    while(st.size()>0)st.pop();
    while(st1.size()>0)st1.pop();
    for (int i=0;i<n;++i){
        pref[i]=(s[i]==')') ? -1 : 1;
        if (i)pref[i]+=pref[i-1];
    }
    for (int i=0;i<k;++i){
        add(pref[i]);
    }
    int ans=0;
    if (pref[k-1]==0 && get()>=0){
        ++ans;
    }
    for (int i=k;i<n;++i){
        add(pref[i]);
        del();
        if (pref[i]-pref[i-k]==0 && get()-pref[i-k]>=0){
            ++ans;
        }
    }
    return ans;
}

main ()
{
    //ios;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int best=check(s);
    int ii=0,jj=0;
    for (int i=0;i<n;++i){
        for (int j=i;j<n;++j){
            if (s[i]==s[j])continue;
            swap(s[i],s[j]);
            if (check(s)>best){
                best=check(s);
                ii=i;
                jj=j;
            }
            swap(s[i],s[j]);
        }
    }
    cout<<best<<endl;
    cout<<ii+1<<' '<<jj+1<<endl;
}
