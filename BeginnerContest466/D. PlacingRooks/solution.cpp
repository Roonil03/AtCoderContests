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
    vi r(m), c(m);
    for(int i {0}; i < m; i++){
        cin >> r[i] >> c[i];
    }
    vector<bool> sr(n + 1, false), sc(n + 1, false);
    int res {0};
    for(int i = m - 1; i >= 0; i--){
        if(!sr[r[i]] && !sc[c[i]]){
            res++;
        }
        sr[r[i]] = true;
        sc[c[i]] = true;
    }
    cout << res << endl;
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