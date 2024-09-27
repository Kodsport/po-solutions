#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define sz(container) ((int)container.size())
#define all(x) begin(x),end(x)

void fast() { ios::sync_with_stdio(0); cin.tie(0); }


signed main()
{
    fast();

    int n;
    cin >> n;
    string seats;
    cin >> seats;
    int ans = int(1e9);
    int latest_seat = -int(1e9);
    rep(i, n)
    {
        if (seats[i] == '.')
        {
            ans = min(ans, i - latest_seat - 1);
            latest_seat = i;
        }
    }
    cout << ans;

    return 0;
}
