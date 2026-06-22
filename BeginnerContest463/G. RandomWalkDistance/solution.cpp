#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'

const int N = 1e6+5;
const int B = 447;
const int mod = 998244353;

typedef pair<int,int> pii;

int Sum(int a, int b) { return (a+b)%mod; }
// int Sub(int a, int b) { return (a+mod-b)%mod; }
int Mult(int a, int b) { return (a*b)%mod; }
int Sum(vector<int> vet)
{
    int ans = 0;
    for(auto x : vet) ans = Sum(ans, x);
    return ans;
}

int q;
pii vet[N];
pair<pii,int> qu[N];
pii ans[N];

int inv[N], fat[N], ifat[N], ip2[N];
void Init()
{
    inv[1] = 1;
    for(int i = 2;i < N;i++) inv[i] = mod-Mult((mod/i), inv[mod%i]);
    fat[0] = 1;
    for(int i = 1;i < N;i++) fat[i] = Mult(fat[i-1], i);
    ifat[0] = 1;
    for(int i = 1;i < N;i++) ifat[i] = Mult(ifat[i-1], inv[i]);
    ip2[0] = 1;
    for(int i = 1;i < N;i++) ip2[i] = Mult(ip2[i-1], inv[2]);
    return;
}

int C(int n, int k)
{
    if(n<0 || k<0 || n-k<0) return 0;
    return Mult(fat[n], Mult(ifat[k], ifat[n-k]));
}

bool cmp(pair<pii,int> a, pair<pii,int> b)
{
    if((a.fi.fi/B)!=(b.fi.fi/B)) return (a.fi.fi/B)<(b.fi.fi/B);
    if(a.fi.se!=b.fi.se) return a.fi.se<b.fi.se;
    return a.se<b.se;
}

void Solv()
{
    sort(qu, qu+q, cmp);
    int n = 0, m = 0, f = 0, g = 0;
    for(int i = 0;i < q;i++)
    {
        auto [ran, id] = qu[i];
        auto [qn, qm] = ran;
        while(qn<n) // n--
        {
            n--;
            f = Mult(Sum(f, C(n,m-1)), inv[2]);
            g = Mult(Sum({g, mod-f, Mult(m, C(n,m-1))}), inv[2]);
        }
        while(n<qn) // n++
        {
            g = Sum({Mult(2, g), f, mod-Mult(m, C(n, m-1))});
            f = Sum(Mult(2, f), mod-C(n,m-1));
            n++;
        }
        while(m<qm) // m++
        {
            f = Sum(f, C(n, m));
            g = Sum(g, Mult(m, C(n,m)));
            m++;
        }
        while(qm<m) // m--
        {
            m--;
            f = Sum(f, mod-C(n, m));
            g = Sum(g, mod-Mult(m, C(n,m)));
        }
        ans[id] = {f,g};
    }
    return;
}

int32_t main() 
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();

    cin >> q;
    for(int i = 0;i < q;i++)
    {
        cin >> vet[i].fi >> vet[i].se;
        if(vet[i].se<0) vet[i].se *= -1;
        qu[i] = {{vet[i].fi, (vet[i].fi+vet[i].se+1)/2},i};
    }
    Solv();
    for(int i = 0;i < q;i++)
    {
        auto [f,g] = ans[i];
        auto [n,x] = vet[i];
        int resp = Sum(Mult(ip2[n-1], Sum(Mult(n+x, f), Mult(mod-2, g))), mod-x);
        if(n<=x) resp = x;
        cout << resp << endl;
    }

    return 0;
}

// Code by https://atcoder.jp/users/guilhermecpp
/*
This code solves the "Expected Absolute Difference" problem for a random walk by utilizing 
**Mo's Algorithm (Block Decomposition)** to process offline queries efficiently alongside a 
mathematical formulation of the combinations. Instead of computing the combinatorial sums 
$f = \sum_{k=0}^{m} \binom{n}{k}$ and $g = \sum_{k=0}^{m} k \binom{n}{k}$ from scratch for 
each test case—which would result in a prohibitive time complexity—the algorithm tracks $f$ 
and $g$ continuously and applies $O(1)$ transitions to adjust $n$ and $m$ step-by-step using 
known Pascal's identity relations. By sorting the queries using a custom block-comparator with 
a block size of $B \approx \sqrt{N}$, the total movement of the pointers is minimized. 
Consequently, the overall **time complexity** is bounded by $O((N + Q) \sqrt{N})$ due to the 
Mo's sorting and pointer transitions, while the precomputations take $O(N)$ time. The **space 
complexity** is $O(N + Q)$ to maintain the factorials, inverse powers of 2, offline queries, 
and stored answers in static arrays.
*/