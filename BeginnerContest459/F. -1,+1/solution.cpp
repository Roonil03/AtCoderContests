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
    for (int i = 0; i < (int)v.size(); i++){
        os << v[i];
        if (i + 1 < (int)v.size()) os << " ";
    }
    return os;
}

struct bb{
    ll sum;
    int len;
};

inline ll h_min(ll sum, int len){
    if (sum >= 0){
      return sum / len;
    }
    return (sum - len + 1) / len;
}

inline ll h_max(ll sum, int len){
    if (sum >= 0){
      return (sum + len - 1) / len;
    }
    return sum / len;
}

void solve(){
    int n;
    cin >> n;
    vll a(n);
    cin >> a;    
    vector<bb> st;
    for(int i {0}; i < n; ++i){
        bb cur = {a[i] - (i + 1), 1};
        while(!st.empty() && h_max(st.back().sum, st.back().len) > h_min(cur.sum, cur.len)){
            cur.sum += st.back().sum;
            cur.len += st.back().len;
            st.pop_back();
        }
        st.push_back(cur);
    }    
    ll res {0};
    ll curs {0};
    ll tars {0};
    int id {0};    
    for(auto& i : st){
        ll mv = h_min(i.sum, i.len);
        ll r = i.sum - mv * i.len;
        for(int k {0}; k < i.len; ++k){
            ll bp = mv + (k >= i.len - r ? 1 : 0);
            ll ap = bp + (id + 1);
            curs += a[id];
            tars += ap;
            res += (curs - tars);
            id++;
        }
    }
    cout << res <<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
