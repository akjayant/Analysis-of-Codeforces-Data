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
// modeling stuff as num going below 0 above n
// number theory infinite due to multple of each other
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
struct freq{

};
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

// accessing operators in circular shiz
int ind(int i, int n){
    if(i%n>=0){
        return i%n;
    }
    return (i%n)+n;
}
struct graph{};


// NUMBER THEORY

set<int> divisors(int n){
    set<int> s;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            // If divisors are equal, print only one
            if (n/i == i){
                s.insert(i);
            }
            else{ // Otherwise print both
                s.insert(i);
                s.insert(n/i);
            }
        }
    }
    return s;
}
set<int> pf(int n){
    set<int> s;
    // Print the number of 2s that divide n
    while (n % 2 == 0){
        if(s.find(2)==s.end()){
            s.insert(2);
        }
        n = n/2;
    }
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2){
        // While i divides n, print i and divide n
        while (n % i == 0){
            if(s.find(i)==s.end()){
            s.insert(i);
            }
            n = n/i;
        }
    }
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2){
        if(s.find(n)==s.end()){
        s.insert(n);
        }
    }
    return s;
}



// bitstring generation and backwards?? combinatorialist function, number theory prime detection, densities prime factorization, modular exponeation //make mody dependent
//, turning into a bit, printin and preparing dp vectors use blocked for ranges intersection
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll o=0;
        ll e=0;
        while(n--){
            int k;
            cin>>k;
            if(k%2==0){
                e++;
            }else{
                o++;
            }
        }
        int n2;
        cin>>n2;
        ll o2=0;
        ll e2=0;
        while(n2--){
            int k;
            cin>>k;
            if(k%2==0){
                e2++;
            }else{
                o2++;
            }
        }
        cout<<(o2*o)+(e*e2)<<endl;
    }
}
