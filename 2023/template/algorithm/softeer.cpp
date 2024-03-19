#include <bits/stdc++.h>
using namespace std;
int n, cnt, temp;
vector<int> v;
char a[100][100];

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, -1, 0, 1};
string s;

void dfs(int y, int x) {
    a[y][x] = '0';
    temp++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == '0') continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int y = 0; y < n; y++) {
        cin >> s;
        for (int x = 0; x < n; x++) {
            a[y][x] = (int)(s[x]);
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (a[y][x] == '1') {
                cnt++;
                dfs(y, x);
                v.push_back(temp);
                temp = 0;
            }
        }
    }

    cout << cnt << '\n';
    sort(v.begin(), v.end());
    for (int num : v) {
        cout << num << " ";
    }
    cout << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, mx[9], a[9], cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mx[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mx[i] < a[i]) {
            cout << -1;
            return 0;
        }
    }
    cin >> cnt;
    int temp = (a[n - 1] + cnt);
    int over = 0;
    a[n - 1] = temp % (mx[n - 1] + 1);
    over = temp / (mx[n - 1] + 1);
    for (int i = n - 2; i >= 0; i--) {
        temp = a[i] + over;
        a[i] = temp % (mx[i] + 1);
        over = temp / (mx[i] + 1);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<char> a[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, rot;
string a[104][104];

void goRight(int start, int end) {
    string tempP = a[start][start], tempN = "";
    for (int i = start; i < end; i++) {
        tempN = a[start][i + 1];
        a[start][i + 1] = tempP;
        tempP = tempN;
    }
    for (int j = start; j < end; j++) {
        tempN = a[j + 1][end];
        a[j + 1][end] = tempP;
        tempP = tempN;
    }
    for (int i = end; i > start; i--) {
        tempN = a[end][i - 1];
        a[end][i - 1] = tempP;
        tempP = tempN;
    }
    for (int j = end; j > start; j--) {
        tempN = a[j - 1][start];
        a[j - 1][start] = tempP;
        tempP = tempN;
    }

    return;
}

void goLeft(int start, int end) {
    string tempP = a[start][start], tempN = "";

    for (int j = start; j < end; j++) {
        tempN = a[j + 1][start];
        a[j + 1][start] = tempP;
        tempP = tempN;
    }

    for (int i = start; i < end; i++) {
        tempN = a[end][i + 1];
        a[end][i + 1] = tempP;
        tempP = tempN;
    }

    for (int j = end; j > start; j--) {
        tempN = a[j - 1][end];
        a[j - 1][end] = tempP;
        tempP = tempN;
    }

    for (int i = end; i > start; i--) {
        tempN = a[start][i - 1];
        a[start][i - 1] = tempP;
        tempP = tempN;
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> rot;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> a[y][x];
        }
    }
    if (rot == 0) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                cout << a[y][x] << " ";
            }
            cout << '\n';
        }
        return 0;
    }

    for (int start = 0; start <= n / 2 - 1; start++) {
        int end = n - 1 - start;
        for (int i = 0; i < abs(rot) % ((end - start) * 4); i++) {
            if (rot > 0) {
                if (start % 2 == 0) {
                    goRight(start, end);
                } else {
                    goLeft(start, end);
                }
            } else {
                if (start % 2 == 0) {
                    goLeft(start, n - 1 - start);
                } else {
                    goRight(start, n - 1 - start);
                }
            }
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << a[y][x] << " ";
        }
        cout << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> arr[26];
int n, edge, mxFuel, fuel, mx, visited[26], cnt;
vector<char> ch;
string mxRoad;
char here, there;

void dfs(int here) {
    if (here == n - 1) {
        if (mx < cnt) {
            mx = cnt;
            mxFuel = fuel;
            mxRoad = "";
            for (int i = 0; i < ch.size(); i++) {
                mxRoad += stringch[i];
            }
        }
        return;
    }
    for (int i = 0; i < arr[here].size(); i++) {
        int there = 0, dist = 0;
        tie(there, dist) = arr[here][i];
        if (visited[there] || dist > fuel) continue;
        visited[there] = 1;
        cnt++;
        ch.push_back((char)there);
        fuel += 10;
        dfs(there);
        fuel -= 10;
        ch.pop_back();
        cnt--;
        visited[there] = 0;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> fuel >> edge;

    for (int i = 0; i < edge; i++) {
        int dist;
        cin >> here >> there >> dist;
        arr[here - 'A'].push_back({there - 'A', dist});
    }
    visited[0] = 1;
    dfs(0);
    for (char c : mxRoad) {
        cout << c << " ";
    }
    cout << mx * 200 + 100 << " " << mxFuel;
    return 0;
}
