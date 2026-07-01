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

void solve(){
    int n, m;
    cin >> n >> m;
    // vector<int>arr(n);
    // cin >> arr;
    vi col(n + 1);
    vi colcnt(n + 1,  0);
    int res {0};
    vector<vector<pii>> up(m + 2);
    for(int i {1}; i <= n; i++){
        int a, d, b;
        cin >> a >> d >> b;
        up[1].push_back({i, a});
        up[d].push_back({i, b});
    }
    for(int i {1}; i <= m; i++){
        for(auto&[f, s] : up[i]){
            int o = col[f];
            if(o != 0){
                colcnt[o]--;
                if(colcnt[o] == 0){
                    res--;
                }
            }
            col[f] = s;
            if(colcnt[s] == 0){
                res++;
            }
            colcnt[s]++;
        }
        cout << res << endl;
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