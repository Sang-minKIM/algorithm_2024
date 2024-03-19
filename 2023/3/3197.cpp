// 백조의 호수

#include<bits/stdc++.h>
using namespace std;

int day, n, m, swanX, swanY, y, x; 

const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};

char a[1504][1504];
int visitSwan[1504][1504], visitWater[1504][1504];

string s;
queue<pair<int, int>> swanQ, waterQ, tempSwanQ, tempWaterQ;


void clearQ(queue<pair<int,int>> &q) {
    queue<pair<int, int>> empty;
    swap(q, empty);
}

bool moveSwan() {
    while(swanQ.size()) {
        
        tie(y, x) = swanQ.front();
        swanQ.pop();
        for(int i = 0; i < 4; i++ ) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visitSwan[ny][nx]) continue;
            visitSwan[ny][nx] = 1;
            if(a[ny][nx] == '.') swanQ.push({ny, nx});
            else if(a[ny][nx] == 'X') tempSwanQ.push({ny, nx});
            else if(a[ny][nx] == 'L') return true;
        }
    }
    return false;
}

void waterMelt() {
    while(waterQ.size()) {
        tie(y, x) = waterQ.front();
        waterQ.pop();
        for(int i = 0; i < 4; i++ ) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visitWater[ny][nx]) continue;
            if(a[ny][nx] == 'X') {
                visitWater[ny][nx] = 1;
                a[ny][nx] = '.';
                tempWaterQ.push({ny, nx});
            } 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int y = 0; y < n; y++) {
        cin >> s;
        for(int x = 0; x < m; x++) {
            a[y][x] = s[x];
            if(s[x] == 'L') {
                swanY = y;
                swanX = x;
            }
            if(s[x] == '.' || s[x] == 'L') {
                visitWater[y][x] = 1;
                waterQ.push({y, x});
            }
        }
    }
    swanQ.push({swanY, swanX});
    visitSwan[swanY][swanX] = 1;
    while(true) {
        if(moveSwan()) break;
        waterMelt();
        swanQ = tempSwanQ;
        waterQ = tempWaterQ;
        clearQ(tempSwanQ);
        clearQ(tempWaterQ);
        day++;
    }
    cout << day << "\n";
    return 0;
}