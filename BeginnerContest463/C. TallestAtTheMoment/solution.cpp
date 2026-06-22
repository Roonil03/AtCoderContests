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
    cin >> n;
    // vector<int>arr(n);
    // cin >> arr;
    vi h(n), l(n);
    for(int i {0}; i < n; i++){
        cin >> h[i] >> l[i];
    }
    int q;
    cin >> q;
    vi t(q);
    cin >> t;
    vi suf(n);
    suf[n-1] = h[n-1];
    for(int i = n - 2; i >= 0; i--){
        suf[i] = max(h[i], suf[i+1]);
    }
    for(int i {0}; i < q; i++){
        auto it = upper_bound(l.begin(), l.end(), t[i]);
        int id = distance(l.begin(), it);
        cout << suf[id] << endl;
    }
    // cout << arr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t = 1;
    precomp();
    while(t--){
        solve();
    }
    return 0;
}