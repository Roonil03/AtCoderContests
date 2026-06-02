#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve() {
    ll A, B, X, Y;
    if (!(cin >> A >> B >> X >> Y)) return;

    ll g = std::gcd(A, B);
    if (X % g != 0 || Y % g != 0) {
        cout << -1 << "\n";
        return;
    }
    A /= g; B /= g; X /= g; Y /= g;

    ll S = A + B;
    ll D = B - A; 

    ll U = X + Y;
    ll V = X - Y;

    ll x0, x1_0;
    ll d1 = extgcd(S, D, x0, x1_0);
    if (U % d1 != 0) { cout << -1 << "\n"; return; }
    ll mult1 = U / d1;
    x0 *= mult1; x1_0 *= mult1;

    ll y0, y1_0;
    ll d2 = extgcd(D, S, y0, y1_0);
    if (V % d2 != 0) { cout << -1 << "\n"; return; }
    ll mult2 = V / d2;
    y0 *= mult2; y1_0 *= mult2;

    ll step_x0 = D / d1;
    ll step_x1_0 = -S / d1;

    ll step_y0 = S / d2;
    ll step_y1_0 = -D / d2;

    ll t_mid1 = -x0 / step_x0;
    ll t_mid2 = -x1_0 / step_x1_0;
    ll s_mid1 = -y0 / step_y0;
    ll s_mid2 = -y1_0 / step_y1_0;

    vector<pair<ll, ll>> centers = {
        {t_mid1, s_mid1}, {t_mid1, s_mid2},
        {t_mid2, s_mid1}, {t_mid2, s_mid2}
    };

    auto add_center = [&](i128 A1, i128 B1, i128 C1, i128 A2, i128 B2, i128 C2) {
        i128 det = A1 * B2 - A2 * B1;
        if (det != 0) {
            i128 num_t = C1 * B2 - C2 * B1;
            i128 num_s = A1 * C2 - A2 * C1;
            auto div_round = [](i128 n, i128 d) {
                if (d < 0) { n = -n; d = -d; }
                if (n >= 0) return (ll)((n + d / 2) / d);
                else return (ll)((n - d / 2) / d);
            };
            centers.push_back({div_round(num_t, det), div_round(num_s, det)});
        }
    };
    i128 A1_1 = step_x0, B1_1 = -step_y0, C1_1 = y0 - x0;
    i128 A1_2 = step_x0, B1_2 = step_y0, C1_2 = -y0 - x0;
    i128 A2_1 = step_x1_0, B2_1 = -step_y1_0, C2_1 = y1_0 - x1_0;
    i128 A2_2 = step_x1_0, B2_2 = step_y1_0, C2_2 = -y1_0 - x1_0;
    add_center(A1_1, B1_1, C1_1, A2_1, B2_1, C2_1);
    add_center(A1_1, B1_1, C1_1, A2_2, B2_2, C2_2);
    add_center(A1_2, B1_2, C1_2, A2_1, B2_1, C2_1);
    add_center(A1_2, B1_2, C1_2, A2_2, B2_2, C2_2);
    ll ans = -1;
    for (auto [tc, sc] : centers) {
        for (ll t = tc - 5; t <= tc + 5; ++t) {
            for (ll s = sc - 5; s <= sc + 5; ++s) {
                ll x1 = x0 + t * step_x0;
                ll x2 = x1_0 + t * step_x1_0;
                ll y1 = y0 + s * step_y0;
                ll y2 = y1_0 + s * step_y1_0;

                if (abs(x1) % 2 == abs(y1) % 2 && abs(x2) % 2 == abs(y2) % 2) {
                    ll k1 = max(abs(x1), abs(y1));
                    ll k2 = max(abs(x2), abs(y2));
                    ll cur = k1 + k2;
                    if (ans == -1 || cur < ans) {
                        ans = cur;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}


/*
The problem is solved in O(1) time per test case by rotating the coordinate system to mathematically decouple the allowed movements. First, we scale the coordinates down by gcd(A, B); if the target isn't perfectly divisible, it is unreachable. By applying the transformation U = X + Y and V = X - Y, the available discrete moves decouple into two independent sets of 1D steps with magnitudes S = A + B and D = B - A. To reach the target, we must satisfy two independent linear Diophantine equations: x1*S + x2*D = U and y1*D + y2*S = V, along with parity constraints to ensure the discrete number of positive/negative steps cleanly match. We formulate finding the minimal steps as a piecewise linear convex optimization problem: F(t, s) = max(|x1(t)|, |y1(s)|) + max(|x2(t)|, |y2(s)|). Because the function is convex, its global minimum mathematically must lie at one of the critical "hinges" or intersections of these linear equations (where xi(t) = 0, yi(s) = 0, or |xi(t)| = |yj(s)|). The algorithm computes these O(1) exact algebraic intersection centers using an __int128 precision solver, evaluates a tightly bounded 11x11 grid around each vertex to safely round into the proper parity-matched integers, and dynamically minimizes the valid moves.
*/