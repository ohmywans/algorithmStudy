/* BOJ 1992번: 쿼드트리 (GG)
강의 후 기억으로 코드 복원
#include <iostream>
using namespace std;
string input;
int N;
char a[64][64] = {' ', };

string go(int y, int x, int size) {
	if (size == 1) return string(1, a[y][x]);
	string ret = "";
	char b = a[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (b != a[i][j]) {
				ret += '(';
				ret += go(y, x, size/2);
				ret += go(y, x+size/2, size/2);
				ret += go(y+size/2, x, size/2);
				ret += go(y+size/2, x+size/2, size/2);
				ret += ')';
				
				return ret;
			}
		}
	}
	return string(1, a[y][x]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			a[i][j] = input[j]; // char형태로 a 행렬에 저장
		}
	}
	cout << go(0, 0, N) << '\n';

	return 0;
}
*/
/* 
정답코드: 
#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;     
int n; 
string s;   
char a[101][101];

// y, x = start_y, start_x 즉, 시작점으로 봐라
string quard(int y, int x, int size){
	// 재귀함수의 기저사례: 더이상 쪼개지지 않을 size = 1 일때 char->string으로 변환하는 함수
    if(size == 1) return string(1, a[y][x]); 
    // 순수한 0인지 1인지 확인하기 위해 일단 원소 한개를 뽑아냄
	char b = a[y][x]; // 원소 하나 저장해두고
    string ret = "";  
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){ 
			// 순수 무결한 1 또는 0이 아니면~
            if(b != a[i][j]){ // 저장한 원소가 for문을 돌면서 만나는 구역 내의 다른 원소와 다르면 순수한 0 또는 1이 아닌거니까~!!!!
                ret += '(';
                ret += quard(y, x, size / 2); 						// 왼쪽 위
                ret += quard(y, x + size / 2, size / 2);			// 오른쪽 위
                ret += quard(y + size / 2, x, size / 2);			// 왼쪽 아래
                ret += quard(y + size / 2, x + size / 2, size / 2); // 오른쪽 아래
                ret += ')';
                return ret;  
            }
        } 
    }
    return string(1, a[y][x]); 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        for(int j = 0; j < n; j++){
			// string으로 저장해서 char로 원소를 저장, 애초에 숫자로 접근 X
            a[i][j] = s[j];
        }
    }
    cout << quard(0, 0, n) << '\n'; 
	return 0; 
}
*/