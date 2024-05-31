/* BOJ 2828번: 사과 담기 게임 - 문제 이해가 잘 안됐어서 게시판을 확인함. 단순 구현으로 풀었지만 시간 많이 오바됨 */
#include <iostream>
using namespace std;
int N, M, J, apple, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cin >> J;
	int a[M];
	// M개의 행렬 a[]을 1부터 M까지의 수로 초기화
	for (int i = 0; i < M; i++) {
		a[i] = i + 1; 				// a[]: 바구니(의 길이만큼 초기화된) 배열
	}
	// J번 반복하여 해결
	for (int i = 0; i < J; i++) {
		int cnt = 0; 				// cnt 반복마다 초기화
		cin >> apple;
		for (int j = 0; j < M; j++) {
			if (a[j] == apple) cnt++;
		}
		if (!cnt) { 				// cnt: 현재 a[]에 apple 값이 있는지 확인하는 용도
			if (apple < a[0]) {		// apple 값이 a[]의 최솟값보다 작으면 배열의 앞쪽으로 이동해야함
				int first = a[0];	// first에 최솟값을 저장하고 받은 apple 값까지의 거리를 계산해 모든 요소에 빼기
				for (int k = 0; k < M; k++) {
					a[k] -= first - apple;
				}
				ret += first - apple; // 거리 자체가 바구니를 이동시킨 횟수가 되므로 누적해서 합함
			} else {				// apple 값이 a[]의 최댓값보다 크면 배열의 뒤쪽으로 이동해야함
				int last = a[M-1];	// first에 최댓값을 저장하고 받은 apple 값까지의 거리를 계산해 모든 요소에 더하기
				for (int k = 0; k < M; k++) {
					a[k] += apple - last;
				}
				ret += apple - last; // 거리 자체가 바구니를 이동시킨 횟수가 되므로 누적해서 합함
			}
		}
		// 디버깅
		// for (int i = 0; i < M; i++) {
		// 	cout << a[i] << " ";
		// } cout << '\n';
	}
	
	cout << ret << '\n';
		
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std; 
int n, m, j, l, r, temp, ret;
int main () {
	cin >> n >> m >> j; 
	l = 1;  
	for(int i = 0; i < j; i++){
		r = l + m - 1; 
		cin >> temp;
		if(temp >= l && temp <= r) continue;
		else{ 
			if(temp < l){  
				ret += (l - temp);
				l = temp; 
			}else{
				l += (temp - r);
				ret += (temp - r); 
			}
		} 
	} 
	cout << ret << "\n"; 
	return 0;
}
*/