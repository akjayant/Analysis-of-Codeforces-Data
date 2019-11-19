#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class UnionFind{
    public:
    //�e�̔ԍ����i�[����B�e�������ꍇ��-(���̏W���̃T�C�Y)
    vector<int> parent;

    //-1�ŏ������B�ŏ��͂��ׂăo���o��
    UnionFind(int N){
        parent = vector<int>(N,-1);
    }

    //A���ǂ̃O���[�v�ɑ����Ă��邩(A�̍�)�𒲂ׂ�
    int root(int A){
        if(parent[A] < 0) return A;
        return parent[A]=root(parent[A]);
    }

    //�����̂���O���[�v�̒��_���𒲂ׂ�
    int size(int A){
        return -parent[root(A)];
    }

    //A��B����������
    bool unite(int A, int B) {
    //A��B�𒼐ڂȂ��̂ł͂Ȃ��Aroot(A)��root(B)����������
        A = root(A);
        B = root(B);
        //���ɂ������Ă��邩�炭�����Ȃ�
        if(A == B) return false; 

        //�傫���ق�(A)�ɏ������ق�(B)����������
        //�召���t�Ȃ�Ђ�����Ԃ�
        if(size(A) < size(B)) swap(A,B);

        //A�̃T�C�Y���X�V����
        parent[A] += parent[B];
        //B�̐e��A�ɕύX����
        parent[B] = A;

        return true;
    }

    //A��B�������O���[�v�Ȃ�true��Ԃ�
    bool same(int A, int B){
        return root(A)==root(B);
    } 
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    ll n;
    cin>>n;
    ll x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    UnionFind uni(n);
    ll c[n],k[n];
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++) cin>>k[i];
    bool used[n]={};
    vector<array<ll,3>> v;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll dist = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            dist *= (k[i]+k[j]);
            array<ll,3> a = {dist,i,j};
            v.push_back(a);
        }
        array<ll,3> a = {c[i],i,i};
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    vector<ll> st;
    vector<pair<ll,ll>> pa;
    for(auto i:v){
        if(used[i[1]] && used[i[2]]) continue;
        if(i[1]==i[2]){
            st.push_back(i[1]);
            ans += i[0];
            used[i[1]] = true;
            for(int j=0;j<n;j++){
                if(uni.same(j,i[1])) used[j]=true;
            }
            continue;
        }
        if(uni.same(i[2],i[1])) continue;
        else{
            ans += i[0];
            bool pos = false;
            uni.unite(i[1],i[2]);
            for(int j=0;j<n;j++){
                if(uni.same(i[1],j)){
                    if(used[j]) pos = true;
                }
            }
            if(pos){
                used[i[1]] = true;
                used[i[2]] = true;
                for(int j=0;j<n;j++){
                    if(uni.same(i[1],j)) used[j]=true;
                }
            }
            pa.push_back(make_pair(i[1],i[2]));
        }
    }
    // for(auto i:v){
    //     if(used[i[1]] && used[i[2]]) continue;
    //     if(!used[i[2]] && !used[i[1]]){
    //         if(i[0] + min(c[i[1]],c[i[2]]) > c[i[1]] + c[i[2]]){
    //             ans += c[i[1]] + c[i[2]];
    //             st.push_back(i[1]);
    //             st.push_back(i[2]);
    //         }
    //         else{
    //             ans += i[0] + min(c[i[1]],c[i[2]]);
    //             pa.push_back(make_pair(i[1],i[2]));
    //             if(c[i[1]] > c[i[2]]) st.push_back(i[2]);
    //             else st.push_back(i[1]);
    //         }
    //     }
    //     else if(used[i[1]]){
    //         if(i[0] < c[i[2]]){
    //             ans += i[0];
    //             pa.push_back(make_pair(i[1],i[2]));
    //         }
    //         else{
    //             ans += c[i[2]];
    //             st.push_back(i[2]);
    //         }
    //     }
    //     else{
    //         if(i[0] < c[i[1]]){
    //             ans += i[0];
    //             pa.push_back(make_pair(i[1],i[2]));
    //         }
    //         else{
    //             ans += c[i[1]];
    //             st.push_back(i[1]);
    //         }
    //     }
    //     used[i[1]] = true;
    //     used[i[2]] = true;
    // }
    cout << ans << "\n";
    cout << st.size() << "\n";
    for(auto i:st){
        cout << i+1 << " ";
    }
    cout << "\n";
    cout << pa.size() << "\n";
    for(auto i:pa){
        cout << i.first+1 << " " << i.second+1 <<"\n";
    }
}