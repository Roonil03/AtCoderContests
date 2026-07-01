#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("O3")
// #pragma GCC target("avx2, bmi, bmi2, popcnt")

#define sz(x) ((int)x.size())
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<long long>

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
    for (T& x : v) is >> x;
    return is;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
    for (int i = 0; i < v.size(); i++){
        os << v[i];
        if (i + 1 < v.size()) os << " ";
    }
    return os;
}

void precomp(){

}

struct query{
    int r, c;
    char x;
};

void solve(){
    int h, w, q1;
    cin >> h >> w >> q1;
    // vector<int>arr(n);
    // cin >> arr;
    vector<query> q(q1);
    for(int i {0}; i < q1; i++){
        cin >> q[i].r >> q[i].c >> q[i].x;
    }
    vector<string>res(h, string(w, 'A'));
    vi m(h, 0);
    for(int i = q1 - 1; i >= 0; i--){
        int r = q[i].r - 1;
        int c = q[i].c;
        char x = q[i].x;
        for(int j = r; j >= 0; j--){
            if(m[j] >= c){
                break;
            }
            for(int k = m[j]; k < c; k++){
                res[j][k] = x;
            }
            m[j] = c;
        }
    }
    for(int i {0}; i < h; i++){
        cout << res[i] << endl;
    }
    // cout << arr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t {1};    
    precomp();
    while(t--){
        solve();
    }
    return 0;
}