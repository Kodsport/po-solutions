#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;
    string seats;
    cin >> seats;
    ll ans = (ll)1e9;
    ll latest_seat = -(ll)1e9;
    rep(i, 0, n)
    {
        if (seats[i] == '.')
        {
            ans = min(ans, i - latest_seat - 1);
            latest_seat = i;
        }
    }
    cout << ans;
}
