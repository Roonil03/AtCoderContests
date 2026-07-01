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
    for (int i = 0; i < sz(v); i++){
        os << v[i];
        if (i + 1 < sz(v)) os << " ";
    }
    return os;
}

template<int m> struct modint {
    unsigned int v;
    modint() : v(0) {}
    modint(long long x) { x %= m; if (x < 0) x += m; v = x; }
    modint& operator+=(const modint& rhs) { if ((v += rhs.v) >= m) v -= m; return *this; }
    modint& operator-=(const modint& rhs) { if (v < rhs.v) v += m; v -= rhs.v; return *this; }
    modint& operator*=(const modint& rhs) { v = 1ULL * v * rhs.v % m; return *this; }
    modint& operator/=(const modint& rhs) { return *this *= rhs.inv(); }
    friend modint operator+(modint lhs, const modint& rhs) { return lhs += rhs; }
    friend modint operator-(modint lhs, const modint& rhs) { return lhs -= rhs; }
    friend modint operator*(modint lhs, const modint& rhs) { return lhs *= rhs; }
    friend modint operator/(modint lhs, const modint& rhs) { return lhs /= rhs; }
    modint inv() const { return pow(m - 2); }
    modint pow(long long n) const {
        modint x = *this, r = 1;
        while (n) { if (n & 1) r *= x; x *= x; n >>= 1; }
        return r;
    }
};

using mint = modint<998244353>;
const int MAX = 200010;
mint fac[MAX], finv[MAX];

void precomp(){
    fac[0] = 1;
    for (int i = 1; i < MAX; i++) fac[i] = fac[i - 1] * i;
    finv[MAX - 1] = fac[MAX - 1].inv();
    for (int i = MAX - 2; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1);
}

using Poly = vector<mint>;

void ntt(Poly& a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        mint wlen = mint(3).pow((998244353 - 1) / len);
        if (inv) wlen = wlen.inv();
        for (int i = 0; i < n; i += len) {
            mint w = 1;
            for (int j = 0; j < len / 2; j++) {
                mint u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv) {
        mint n_inv = mint(n).inv();
        for (mint& x : a) x *= n_inv;
    }
}

Poly operator+(Poly a, const Poly& b) {
    if (a.size() < b.size()) a.resize(b.size(), 0);
    for (size_t i = 0; i < b.size(); i++) a[i] += b[i];
    while (!a.empty() && a.back().v == 0) a.pop_back();
    return a;
}

Poly operator*(Poly a, Poly b) {
    if (a.empty() || b.empty()) return {};
    int s = a.size() + b.size() - 1, n = 1;
    while (n < s) n <<= 1;
    a.resize(n); b.resize(n);
    ntt(a, 0); ntt(b, 0);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    ntt(a, 1);
    a.resize(s);
    while (!a.empty() && a.back().v == 0) a.pop_back();
    return a;
}

using Mat = vector<vector<Poly>>;

Mat mult(const Mat& a, const Mat& b) {
    Mat c(2, vector<Poly>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][k] = c[i][k] + a[i][j] * b[j][k];
            }
        }
    }
    return c;
}

mint solve_k(vector<long long> p, long long k) {
    int n = p.size();
    if (k > n) return 0;
    int u = k - 1, v = n - (k - 1);
    for (int i = 0; i < n; i++) {
        if (p[i] == -1) continue;
        if (p[i] < k) { p[i] = 0; u--; }
        else { p[i] = 1; v--; }
    }
    if (u < 0 || v < 0) return 0;
    mint q = fac[u] * fac[v];
    for (int i = 0; i + 2 < n; i += 2) {
        int c = 0;
        if (p[i] == 0) c++;
        if (p[i+1] == 0) c++;
        if (p[i+2] == 0) c++;
        if (c >= 2) return 0;
        if (c == 1) {
            if (p[i] == -1) { p[i] = 1; v--; }
            if (p[i+1] == -1) { p[i+1] = 1; v--; }
            if (p[i+2] == -1) { p[i+2] = 1; v--; }
        }
    }
    if (v < 0) return 0;
    vector<Mat> g;
    for (int i = 1; i + 1 < n; i += 2) {
        Mat f(2, vector<Poly>(2));
        for (int j = 0; j < 8; j++) {
            if (__builtin_popcount(j) <= 1) continue;
            bool ok = true;
            for (int s = 0; s < 3; s++) {
                if (p[i - 1 + s] == 0 && ((j >> s) & 1)) ok = false;
                if (p[i - 1 + s] == 1 && !((j >> s) & 1)) ok = false;
            }
            if (ok) {
                int val = __builtin_popcount(j % 4);
                if (i + 2 == n) val = __builtin_popcount(j);
                if (val >= sz(f[j % 2][(j >> 2) & 1])) {
                    f[j % 2][(j >> 2) & 1].resize(val + 1, 0);
                }
                f[j % 2][(j >> 2) & 1][val] += 1;
            }
        }
        g.push_back(f);
    }
    while (sz(g) > 1) {
        vector<Mat> g2;
        for (int i = 0; i < sz(g); i += 2) {
            if (i + 1 < sz(g)) g2.push_back(mult(g[i], g[i+1]));
            else g2.push_back(g[i]);
        }
        g = g2;
    }
    mint sum = 0;
    int req_v = v;
    for (auto e : p) if (e == 1) req_v++;
    if (!g.empty()) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (sz(g[0][i][j]) > req_v) sum += g[0][i][j][req_v];
            }
        }
    }
    return sum * q;
}

void solve(){
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> p(n);
    cin >> p;
    if (n % 2 == 0) {
        if (m != 1LL * n * (n + 1) / 2) cout << 0 << "\n";
        else {
            int c = 0;
            for (auto e : p) if (e == -1) c++;
            cout << fac[c].v << "\n";
        }
        return;
    }
    long long k = 1LL * n * (n + 1) / 2 - m;
    if (1 <= k && k <= n) {
        mint ans = solve_k(p, k) - solve_k(p, k + 1);
        cout << ans.v << "\n";
    } else {
        cout << 0 << "\n";
    }
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

// Solution referenced from https://atcoder.jp/users/PCTprobability

/*
The problem asks to find the number of valid original permutations given a partial permutation `p` of length `n` 
(where `-1` denotes an unknown element). For an odd length `n`, the constraints are equivalent to counting permutations 
where elements are thresholded by a value `k`. We binarize the array based on this threshold: values < k become 0, 
and values >= k become 1. A valid assignment requires that no three consecutive elements can contain two or more 0s 
(i.e., every sliding block of 3 has at least two 1s). 

To count the valid configurations for a given `k`, the function `solve_k` models this requirement as a state machine where 
states correspond to overlapping blocks of elements. It constructs 2x2 matrices mapping the transitions, where the elements 
of the matrices are polynomials. The exponent of a polynomial term tracks the number of 1s assigned. A Divide and Conquer 
approach with Number Theoretic Transform (NTT) evaluates the matrix chain multiplication of these polynomials. Finally, the 
answer for an exact `k` is obtained by calculating the difference between the number of configurations for >= k and >= k+1.

Time Complexity: O(N log^2 N) per test case. Setting up the states takes O(N). Merging the polynomial matrices via Divide 
and Conquer takes log N levels, and each polynomial multiplication at any level takes O(L log L) time using NTT, where the 
total sum of degrees L across a level is O(N).

Space Complexity: O(N). The polynomial arrays throughout the divide-and-conquer tree and NTT auxiliary arrays store at 
most O(N) coefficients simultaneously.
*/