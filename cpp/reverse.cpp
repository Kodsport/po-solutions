#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define per(i, high) for (int i = high-1; i >= 0; i--)
#define perr(i, high, low) for(int i = high - 1, i >= low; i++)
#define sz(container) ((int)container.size())
#define all(x) begin(x),end(x)

void fast() { ios::sync_with_stdio(0); cin.tie(0); }


int main() {
    fast();

    int n;
    cin >> n;

    vector<string> lines(n);

    rep(i, n) {
        cin >> lines[i];
    }

    // vanligtvis skriver man reverse(lines.begin, lines.end())
    // men tack vare makrot "all" på rad 11 kan vi förenkla det till:
    reverse(all(lines));

    rep(i, n) {
        cout << lines[i] << '\n';
    }

    return 0;
}
