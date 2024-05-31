// BOJ 10709번: 기상캐스터 - 성공
#include <iostream> 
using namespace std;
int H, W, b[104][104];
char a[104][104];
bool toggle;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a[i][j];
			// 1. c 나오기 전 . : false, b = -1
			if (a[i][j] != 'c') {
				b[i][j] = -1;
			}
			// 2. c 등장: true, b = 0
			else if (a[i][j] == 'c') {
				toggle = true;
				b[i][j] = 0;
			} // 3. c 등장 후 . : true, b = 1씩 증가
			if (toggle && a[i][j] != 'c') {
				b[i][j] = b[i][j-1] + 1;
			}
		} toggle = false;
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << b[i][j] << " ";
		} cout << '\n';
	}
	return 0;
}
//////////////////////////////////////// 내가 한게 더 직관적인 듯?
#include <bits/stdc++.h>
using namespace std;  
int n, m, a[104][104];
string s; 
int main () {
	cin >> n >> m; 
	for(int i = 0; i < n; i++){
		cin >> s; 
		for(int j = 0; j < m; j++){ 
			if(s[j] == '.')a[i][j] = -1;
			else a[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0){ 
				int cnt = 1;
				while(a[i][j + 1] == -1){
					a[i][j + 1] = cnt++;
					j++;
				} 
			}
		} 
	} 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << a[i][j] << " ";
		cout << "\n";
	} 
	return 0;
}