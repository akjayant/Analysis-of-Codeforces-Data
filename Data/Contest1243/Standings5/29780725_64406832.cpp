#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;

// void easy() {
//     int N;
//     string S, T;
//     cin >> N >> S >> T;
//     int cnt = 0;
//     rep(i, 0, N) {
//         if (S[i] != T[i]) {
//             ++cnt;
//         }
//     }
//     if (cnt == 0) {
//         cout << "Yes" << endl;
//         return;
//     }
//     if (cnt != 2) {
//         cout << "No" << endl;
//         return;
//     }
//     vector<int> cnt1(26, 0), cnt2(26, 0);
//     rep(i, 0, N) {
//         if (S[i] != T[i]) {
//             ++cnt1[S[i] - 'a'];
//             ++cnt2[T[i] - 'a'];
//         }
//     }
//     int two1 = 0, two2 = 0;
//     rep(i, 0, 26) {
//         if (cnt1[i] == 2) ++two1;
//         if (cnt2[i] == 2) ++two2;
//     }
//     if (two1 == 1 && two2 == 1) {
//         cout << "Yes" << endl;
//     }
//     else cout << "No" << endl;
// }

void hard() {
    int N;
    string S, T;
    cin >> N >> S >> T;
    string s(S), t(T);
    vector<int> cnt1(26, 0), cnt2(26, 0);
    rep(i, 0, N) {
        ++cnt1[S[i] - 'a'];
        ++cnt2[T[i] - 'a'];
    }
    rep(i, 0, 26) {
        if ((cnt1[i] + cnt2[i]) % 2) {
            cout << "No" << endl;
            return;
        }
    }
    vector<int> si, tj;
    rep(i, 0, N) {
        if (S[i] == T[i]) {
            --cnt1[S[i] - 'a'];
            --cnt2[T[i] - 'a'];
            continue;
        }
        if (cnt1[S[i] - 'a'] > 1) {
            tj.push_back(i);
            rep(j, i + 1, N) {
                if (S[j] == S[i]) {
                    si.push_back(j);
                    --cnt1[S[j] - 'a'];
                    --cnt2[T[i] - 'a'];
                    ++cnt1[T[i] - 'a'];
                    ++cnt2[S[j] - 'a'];
                    swap(S[j], T[i]);
                    break;
                }
            }
        }
        else {
            si.push_back(i + 1);
            rep(j, i + 1, N) {
                if (T[j] == S[i]) {
                    tj.push_back(j);
                    --cnt1[S[i + 1] - 'a'];
                    --cnt2[T[j] - 'a'];
                    ++cnt1[T[j] - 'a'];
                    ++cnt2[S[i + 1] - 'a'];
                    swap(S[i + 1], T[j]);
                    si.push_back(i + 1);
                    tj.push_back(i);
                    --cnt1[S[i + 1] - 'a'];
                    --cnt2[T[i] - 'a'];
                    ++cnt1[T[i] - 'a'];
                    ++cnt2[S[i + 1] - 'a'];
                    swap(S[i + 1], T[i]);
                    break;
                }
            }
        }
        --cnt1[S[i] - 'a'];
        --cnt2[T[i] - 'a'];
    }
    cout << "Yes" << endl;
    cout << si.size() << endl;
    rep(i, 0, si.size()) {
        cout << si[i] + 1 << ' ' << tj[i] + 1 << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int K;
    cin >> K;
    rep(i, 0, K) hard();
    return 0;
}