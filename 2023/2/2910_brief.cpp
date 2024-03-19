#include <bits/stdc++.h>
using namespace std;  
int n, c, a[1004];
vector<pair<int, int>> v; 
map<int, int> mp, mp_fast; 

bool cmp(pair<int,int> a, pair<int, int> b){
	if(a.second == b.second){
		return mp_fast[a.first] < mp_fast[b.first];
	}
	return a.second > b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c; 
	for(int i = 0; i < n; i++){
		cin >> a[i];
        mp[a[i]]++;
		if(mp_fast[a[i]] == 0) mp_fast[a[i]] = i + 1; 
	} 
	for(auto num : mp){
		v.push_back({num.first, num.second});
	}
	sort(v.begin(), v.end(), cmp);
	for(auto i : v){
		for(int j = 0; j < i.second; j++){
			cout << i.first << " ";
		}
	} 
	 
	return 0;
}