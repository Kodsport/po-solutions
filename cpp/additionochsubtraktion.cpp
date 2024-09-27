#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define sz(container) ((int)container.size())
#define all(x) begin(x),end(x)

void fast() { ios::sync_with_stdio(0); cin.tie(0); }


int main() {
    fast();

    ll x, y; // Notera att 0 < x, y < 10^10, ett 32 bitars heltal kan bara 
    // hantera tal upp till ~2*10^9. Eftersom 10^10 > 2*10^9 så måste x och y
    // vara 64 bitars heltal.
    cin >> x >> y;

    cout << x + y << '\n';
    cout << x - y << '\n';

    return 0;
}
