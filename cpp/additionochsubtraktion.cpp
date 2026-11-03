#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll x, y; // Notera att 0 < x, y < 10^10, ett 32 bitars heltal kan bara 
    // hantera tal upp till ~2*10^9. Eftersom 10^10 > 2*10^9 så måste x och y
    // vara 64 bitars heltal.
    cin >> x >> y;

    cout << x + y << '\n';
    cout << x - y << '\n';
}
