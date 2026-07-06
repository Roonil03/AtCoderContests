#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("O3")

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

ll mod_inv(ll val, ll mod) {
    if (mod == 0) return 0;
    mod = abs(mod);
    val %= mod;
    if (val < 0) val += mod;
    ll a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
        t = a / b;
        swap(a -= t * b, b), swap(u -= t * v, v);
    }
    if (u < 0) u += mod;
    return u;
}

struct FastSet {
    static constexpr uint32_t B = 64;
    int n, lg;
    vector<vector<uint64_t>> seg;
    FastSet() {}
    FastSet(int m) {
        n = m;
        while (m > 1) {
            seg.push_back(vector<uint64_t>((m + B - 1) / B, 0));
            m = (m + B - 1) / B;
        }
        seg.push_back(vector<uint64_t>(1, 0));
        lg = seg.size();
    }
    bool operator[](int i) const { return seg[0][i / B] >> (i % B) & 1; }
    void insert(int i) {
        for (int h = 0; h < lg; h++) {
            seg[h][i / B] |= uint64_t(1) << (i % B);
            i /= B;
        }
    }
    void erase(int i) {
        uint64_t x = 0;
        for (int h = 0; h < lg; h++) {
            seg[h][i / B] &= ~(uint64_t(1) << (i % B));
            seg[h][i / B] |= x << (i % B);
            x = bool(seg[h][i / B]);
            i /= B;
        }
    }
    int next(int i) {
        if (i < 0) i = 0;
        for (int h = 0; h < lg; h++) {
            if (i / B == seg[h].size()) break;
            uint64_t d = seg[h][i / B] >> (i % B);
            if (!d) {
                i = i / B + 1;
                continue;
            }
            i += __builtin_ctzll(d);
            for (int g = h - 1; g >= 0; g--) {
                i *= B;
                i += __builtin_ctzll(seg[g][i / B]);
            }
            return i;
        }
        return n;
    }
    int prev(int i) {
        if (i >= n) i = n - 1;
        for (int h = 0; h < lg; h++) {
            if (i == -1) break;
            uint64_t d = seg[h][i / B] << (63 - i % B);
            if (!d) {
                i = i / B - 1;
                continue;
            }
            i -= __builtin_clzll(d);
            for (int g = h - 1; g >= 0; g--) {
                i *= B;
                i += 63 - __builtin_clzll(seg[g][i / B]);
            }
            return i;
        }
        return -1;
    }
};

void precomp(){}

void solve(){
    ll N, M, C, K;
    if (!(cin >> N >> M >> C >> K)){
        return;
    }
    vll A(N);
    cin >> A;
    int Q;
    cin >> Q;
    vector<pll> query(Q);
    for (int i = 0; i < Q; i++) {
        cin >> query[i].first >> query[i].second;
        query[i].first--;
    }
    vll X = A;
    for (auto& q : query){
        X.push_back(q.second);
    }
    vll aux;
    for (auto& x : X) {
        aux.push_back(x);
        aux.push_back((x + 1) % M);
    }
    X = aux;
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    ll n = X.size();
    FastSet FS0(3 * n), FS1(3 * n);
    vll F(n, 0);
    for (auto& x : A) {
        int k = lower_bound(X.begin(), X.end(), x) - X.begin();
        F[k]++;
    }
    for (int i = 0; i < n; i++) {
        if (F[i] == 0) {
            FS0.insert(i); FS0.insert(n + i); FS0.insert(n + n + i);
        }
        if (F[i] == 1) {
            FS1.insert(i); FS1.insert(n + i); FS1.insert(n + n + i);
        }
    }
    ll g = std::gcd(C, M);
    ll c = C / g, m = M / g;
    ll ic = mod_inv(c, m);
    vll cnt(n, 0);
    for (int i = 0; i < n; i++) {
        ll a = X[i];
        if (a % g != 0){
            continue;
        }
        ll t = (-a / g) * ic % m;
        if (t < 0){
            t += m;
        }
        if (K <= t){
            continue;
        }
        ll x = (K - 1 - t) / m;
        cnt[i] = x + 1;
    }
    for (int i = 0; i < 2 * n; i++){
        X.push_back(X[i] + M);
    }
    for (int i = 0; i < 2 * n; i++){
        cnt.push_back(cnt[i]);
    }
    auto calc = [&](int i) -> uint64_t {
        int j = FS0.next(i);
        if (j == 3 * n){
            return M;
        }
        return X[j] - X[i];
    };
    uint64_t ANS = 0;
    for (int i = 0; i < n; i++){
        ANS += calc(i) * cnt[i];
    }
    vll CC(3 * n + 1, 0), CX(3 * n + 1, 0);
    for (int i = 0; i < 3 * n; i++){
        CC[i + 1] = CC[i] + cnt[i];
    }
    for (int i = 0; i < 3 * n; i++){
        CX[i + 1] = CX[i] + (cnt[i] * X[i]);
    }
    auto add = [&](int i) -> void {
        F[i]++;
        if (F[i] >= 2){
            return;
        }
        FS1.insert(i);
        FS1.insert(i + n);
        FS1.insert(i + n + n);
        FS0.erase(i);
        FS0.erase(i + n);
        FS0.erase(i + n + n);
        i += n;
        int j = FS0.next(i);
        if (j < 3 * n){
            ANS += cnt[i] * (uint64_t)(X[j] - X[i]);
        } else{
            ANS += cnt[i] * (uint64_t)(M);
        }
        int k = FS0.prev(i);
        if (k == -1){
            k = i - n;
        }
        ANS -= (CC[i] - CC[k + 1]) * X[i];
        ANS += (CX[i] - CX[k + 1]);
        if (j == 3 * n){
            ANS += (CC[i] - CC[k + 1]) * M;
        } else {
            ANS += (CC[i] - CC[k + 1]) * X[j];
            ANS -= (CX[i] - CX[k + 1]);
        }
    };
    auto rm = [&](int i) -> void {
        F[i]--;
        if (F[i] > 0){
            return;
        }
        i += n;
        int j = FS0.next(i);
        if (j < 3 * n){
            ANS -= cnt[i] * (X[j] - X[i]);
        } else{
            ANS -= cnt[i] * M;
        }
        int k = FS0.prev(i);
        if (k == -1){
            k = i - n;
        }
        ANS += (CC[i] - CC[k + 1]) * X[i];
        ANS -= (CX[i] - CX[k + 1]);
        if (j == 3 * n){
            ANS -= (CC[i] - CC[k + 1]) * M;
        } else {
            ANS -= (CC[i] - CC[k + 1]) * X[j];
            ANS += (CX[i] - CX[k + 1]);
        }
        i -= n;
        FS1.erase(i);
        FS1.erase(i + n);
        FS1.erase(i + n + n);
        FS0.insert(i);
        FS0.insert(i + n);
        FS0.insert(i + n + n);
    };
    for (int q = 0; q < Q; q++) {
        ll idx = query[q].first;
        ll val = query[q].second;
        int s = lower_bound(X.begin(), X.end(), A[idx]) - X.begin();
        int t = lower_bound(X.begin(), X.end(), val) - X.begin();
        add(t);
        rm(s);
        A[idx] = val;
        cout << ANS << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    int t = 1;
    precomp();
    while(t--){
        solve();
    }
    return 0;
}

// Solution referenced from https://atcoder.jp/users/maspy

/*
The algorithm efficiently tracks the sum of mex (Minimum Excluded value) changes over array dynamic updates using coordinate 
compression and a 64-ary fenwick/bitset tree layout (FastSet). It tracks how many times elements drop to 0 under modular linear 
steps by calculating occurrences via the Extended Euclidean Algorithm and number theory rules. The compressed values are 
triplicated to cleanly handle wrap-around periodic modulos. Whenever a value changes count, its presence/absence flips in the 
FastSet. The change in the total sum is computed efficiently by querying adjacent missing keys using the tree's bitwise next/prev 
jumps combined with prefix sum lookups. The time complexity per query is optimized to O(log_64(N + Q)) thanks to FastSet bit
manipulation operations, while the initial structure takes O((N + Q) log(N + Q)) time to sort and build. The total space 
complexity is O(N + Q) to house the compressed structures and tree levels.
*/