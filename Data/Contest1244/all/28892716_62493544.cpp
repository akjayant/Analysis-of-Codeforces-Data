//careful references in recursion
//careful long long int and mod always
//careful return types of std such as int(ceil)
//io manip lookup for decimal control
//WATCH OUT GOING OVER MAX thru operations spam mod
// vectors overflow arrays do NOT
//lower bound is first greater or equal
//uper is first greater
// if TLE play around with compiler
// use static is helpful!!
//take note of test stuff that need to be changed before submission
// careful when u use garbage from abroad
//careful not finding stuff in dictionaries
//stupid cout precision and sci notations
#include<bits/stdc++.h>
using namespace std;

//macros and shortcuts
#define loop(i, n) for(int i = 0; i < n; i++)
#define scan(it, d) for(auto it=d.begin(); it!=d.end(); it++)

typedef long long ll; //can be modified to long/int in emergencies.
typedef long long lll;

const int maxint=2147483646;
const int minint=-2147483646;
const lll maxlll=9223372036854775805;
const lll minlll=-9223372036854775805;
const ll mody=1000000007;

// here lie the output functions
template<class T>
ostream& operator<<(ostream& os, vector<T>& v){
    os<<"[";
    for(int i=0; i<v.size(); i++){
        os<<v[i];
        if(i!=v.size()-1){
            os<<", ";
        }
    }
    os<<"]";
    //cout<<endl;
    return os;
}
template<class T, class U>
ostream& operator<<(ostream& os, unordered_map<T,U>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<i->first<<": "<<i->second;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    //os<<endl;
    return os;
}
template<class T, class U>
ostream& operator<<(ostream& os, pair<T,U>& dt){
    os<<"<"<<dt.first<<","<<dt.second<<">";
    return os;
}
template <typename T, unsigned int N>
typename std::enable_if<!std::is_same<T, char>::value, std::ostream &>::type
operator<<(std::ostream & os, const T (&a)[N]){
    for (size_t i = 0; i < N; ++i)
    {
        os << a[i];
        if(i<N-1){
            cout<<" ";
        }
    }
    os <<endl;
  return os;
}


// less useful prints note that stack and queue modify the info and put it back whereas pq takes nlogn

template<class T, class U>
ostream& operator<<(ostream& os, map<T,U>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<i->first<<": "<<i->second;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, set<T>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<*i;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, stack<T>& dt){
    stack<T> t;
    os<<"[";
    while(!dt.empty()){
        T temp=dt.top();
        os<<temp;
        dt.pop();
        t.push(temp);
        if(!dt.empty()){
            os<<", ";
        }
    }
    os<<"]";
    while(!t.empty()){
        T temp=t.top();
        dt.push(temp);
        t.pop();
    }
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, queue<T>& dt){
    queue<T> t;
    os<<"[";
    while(!dt.empty()){
        T temp=dt.front();
        os<<temp;
        dt.pop();
        t.push(temp);
        if(!dt.empty()){
            os<<", ";
        }
    }
    os<<"]";
    while(!t.empty()){
        T temp=t.front();
        dt.push(temp);
        t.pop();
    }
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, list<T>& dt){
    os<<"[";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<*i;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"]";
    //os<<endl;
    return os;
}
template<class T>
ostream& operator<<(ostream& os, priority_queue<T>& dt){
    queue<T> t;
    os<<"[";
    while(!dt.empty()){
        T temp=dt.top();
        os<<temp;
        dt.pop();
        t.push(temp);
        if(!dt.empty()){
            os<<", ";
        }
    }
    os<<"]";
    while(!t.empty()){
        T temp=t.front();
        dt.push(temp);
        t.pop();
    }
    //os<<endl;
    return os;
}
//here lie the input functions
template <class T=ll>
vector<T> clist(int n){
    std::vector<T> v;
    while(n--){
        T k;
        cin>>k;
        v.push_back(k);
    }
    return v;
}
template<class T=ll, class U=ll>
vector<pair<T,U>> clist2(int n){
    std::vector<pair<T,U>> v;
    while(n--){
        T a;
        U b;
        cin>>a>>b;
        pair<T,U> p(a,b);
        v.push_back(p);
    }
    return v;
}

// this is a special string to vector function
vector<char> cstrtv(string& s){
    vector<char> v;
    for(int i=0; i<s.size(); i++){
        v.push_back(s[i]);
    }
    return v;
}

//these two codes are responsible for counting frequencies in arrays
template<class T>
unordered_map<T,int> ccount(vector<T>& v){
    unordered_map<T,int> m;
    for(int i=0; i<v.size(); i++){
        m[v[i]]+=1;
    }
    return m;
}
template<class T>
unordered_map<T,vector<int>> indexify(vector<T>& s){
    unordered_map<T,vector<int>> m;
    for(int i=0; i<s.size(); i++){
        if(m.find(s[i])==m.end()){
            vector<int> v;
            m[s[i]]=v;
        }
        m[s[i]].push_back(i);
    }
    return m;
}


//here lie common vector processing functions
template<class T>
int maxind(vector<T>& v){
    int maxi=0;
    for(int i=1; i<v.size(); i++){
        maxi=(v[maxi]<v[i])? i:maxi;
    }
    return maxi;
}
template<class T>
T maxel(vector<T>& v){
    return v[maxind(v)];
}
template<class T>
int minind(vector<T>& v){
    int mini=0;
    for(int i=1; i<v.size(); i++){
        mini=(v[mini]>v[i])? i:mini;
    }
    return mini;
}
template<class T>
T minel(vector<T>& v){
    return v[minind(v)];
}
template<class T>
vector<ll> partialsums(vector<T>& v){
    vector<ll> ps(v.size());
    ps[0]=v[0];
    for(int i=1; i<v.size();i++){
        ps[i]=ps[i-1]+v[i];
    }
    return ps;
}
template<class T>
ll sumy(vector<T>& v){
    ll s=0;
    for(int i=0; i<v.size(); i++){
        s+=v[i];
    }
    return s;
}
template<class T>
vector<int> pminin(vector<T>& v){
    vector<int> ret={0};
    int curi=0;
    for(int i=1; i<v.size(); i++){
        if(v[i]<v[curi]){
            curi=i;

        }
        ret.push_back(curi);
    }
    return ret;
}
template<class T>
vector<int> pmaxin(vector<T>& v){
    vector<int> ret={0};
    int curi=0;
    for(int i=1; i<v.size(); i++){
        if(v[i]>v[curi]){
            curi=i;

        }
        ret.push_back(curi);
    }
    return ret;
}
template<class T>
vector<T> pmin(vector<T>& v){
    vector<T> ret;
    vector<int> temp=pminin(v);
    for(int i=0; i<temp.size(); i++){
        ret.push_back(v[temp[i]]);
    }
    return ret;
}
template<class T>
vector<T> pmax(vector<T>& v){
    vector<T> ret;
    vector<int> temp=pmaxin(v);
    for(int i=0; i<temp.size(); i++){
        ret.push_back(v[temp[i]]);
    }
    return ret;
}
//based on count
template<class T>
int mode(unordered_map<T,int>& m){
    int maxfrq=0;
    T maxel;
    for(auto it=m.begin(); it!=m.end(); it++){
        if(it->second>maxfrq){
            maxfrq=it->second;
            maxel=it->first;
        }
    }
    return maxel;
}
int n;
int ind(int i){
    if(i%n<0){
        return (i%n)+n;
    }
    return i%n;
}
struct graph{};
// bitstring generation and backwards?? combinatorialist function, number theory prime detection, densities prime factorization,modular exponeation //make mody dependent
//, turning into a bit, printin and preparing dp vectors use blocked for ranges intersection
int main(){
        ll k;
        cin>>n>>k;
        bool fort[200001];
        int lfdt[200001];
        int rfdt[200001];
        for(int i=0; i<200001; i++){
            fort[i]=0;
            lfdt[i]=0;
            rfdt[i]=0;
        }
        string s;
        cin>>s;
        if(s[0]==s[n-1]){
            fort[0]=1;
            fort[n-1]=1;
        }
        int smfort=-1;
        for(int i=0; i<s.size(); i++){
            if(s[ind(i-1)]==s[ind(i)] || s[ind(i+1)]==s[ind(i)]){
                fort[i]=1;
                smfort=i;
            }
        }
    //    cout<<smfort<<endl;
        if(smfort==-1){
            for(int i=0; i<n; i++){
            if(k%2==0){
                cout<<s[i];
            }else{
                if(s[i]=='B'){
                    cout<<'W';
                }else{
                    cout<<'B';
                }
            }
        }
        }else{
            //cout<<fort<<endl;
            int dist=0;
            for(int i=smfort; i<s.size()+smfort; i++){
                dist++;
                if(fort[ind(i)]==1){
                    dist=0;
                }
                lfdt[ind(i)]=dist;
            }
            //cout<<lfdt<<endl;
            //cout<<smfort-s.size()<<endl;
            int distr=0;
            //cout<<s.size()<<endl;
            //cout<<smfort<<" "<<smfort-n;
            for(int i=smfort; i>=smfort-n; i--){
            //    cout<<"hi";
                distr++;
                if(fort[ind(i)]==1){
                    distr=0;
                }
                //cout<<distr<<endl;
                rfdt[ind(i)]=distr;
            }
            //cout<<rfdt<<endl;
            for(int i=0; i<s.size(); i++){
                if(lfdt[i]<rfdt[i]){
                    lfdt[i]=-lfdt[i];
                }else{
                    lfdt[i]=rfdt[i];
                }
            }
            //cout<<lfdt<<endl;
            for(int i=0; i<n; i++){
                if(k>=abs(lfdt[i])){
                    cout<<s[ind(i+lfdt[i])];
                }else{
                    if(k%2==0){
                        cout<<s[i];
                    }else{
                        if(s[i]=='B'){
                            cout<<'W';
                        }else{
                            cout<<'B';
                        }
                    }
                }
            }
        }
}
