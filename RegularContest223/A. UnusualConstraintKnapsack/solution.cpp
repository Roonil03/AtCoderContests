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
    int n;
    ll ww;
    cin >> n >> ww;
    // vector<int>arr(n);
    // cin >> arr;
    vll w(n), v(n), s(n + 1), sv(n + 1);
    s[0] = 0;
    sv[0] = 0;
    for(int i {0}; i < n; i++){
        cin >> w[i] >> v[i];
        s[i + 1] = s[i] + w[i];
        sv[i + 1] = sv[i] + v[i];
    }
    ll res {0}, curw = ww, curv = 0;
    for(int i = n; i >= 1; i--){
        if(curw >= s[i]){
            res = max(res, curv + sv[i]);
            break;
        }
        if(curw < w[i - 1]){
            continue;
        }
        res = max(res, curv + sv[i - 1]);
        curv += v[i - 1];
        curw -= w[i - 1];
    }
    res = max(res, curv);
    cout << res << endl;
    // cout << arr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;    
    precomp();
    while(t--){
        solve();
    }
    return 0;
}