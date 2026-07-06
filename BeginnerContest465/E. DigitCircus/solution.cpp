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

const ll mod = 998244353;
void precomp(){

}

void solve(){
    string s;
    cin >> s;
    int n = sz(s);
    // vector<int>arr(n);
    // cin >> arr;
    vi mem(n * 12288, -1);
    auto dfs = [&](auto& self, int id, bool fg1, bool fg2, int md, bool fg3, int mask) -> int{
        if(id == n){
            if(!fg2){
                return 0;
            }
            return ((md == 0) + fg3 + (__builtin_popcount(mask) == 3) == 1) ? 1 : 0;
        }
        int mid = id * 12288 + fg2 * 6144 + md * 2048 + fg3 * 1024 + mask;
        if(fg1 && mem[mid] != -1){
            return mem[mid];
        }
        int lim = fg1 ? 9 : s[id] - '0';
        int res {0};
        for(int i {0}; i <= lim; i++){
            res = (res + self(self, id + 1, fg1 || i < lim, fg2 || i != 0, (md + i) % 3, fg3 || i == 3, (fg2 || i != 0) ? (mask | (1 << i)) : 0)) % mod;
        }
        if(fg1){
            mem[mid] = res;
        }
        return res;
    };
    cout << dfs(dfs, 0, false, false, 0, false, 0) << endl;
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