/* BOJ 2559번: 수열 - 완성했으나, 시간복잡도 O(N*K)로 시간 초과
// N : 1 ~ 10만
// K : 1 ~ 10만-1 (K는 N 사이 값이라고 했으니까)
// 온도의 범위는 -100 ~ 100
// 연속된 온도의 합이 "최대"가 되는 값: 구간 합 떠올리기
// 구간 합, prefix sum: psum[i] = psum[i-1] + a[i]; 등
// 문제에서, 최댓값을 구하라고 한다면? 최솟값을 먼저 고려하라! 시간 복잡도를 위함. 반대로도 가능!
// 여기서 최솟값이란.. 최악의 경우를 떠올리기: -100 * 10만 = -1000만이 된다. 

// (Tip) 가끔 문제에서 -1000만 하고 1이라는 수를 고려하는 상황이 올 수 있음. 따라서 ret = 10,000,004 이렇게 
// 일종의 버퍼 같은 역할을 하도록 넉넉하게 선언을 해주는게 좋다. 맞왜틀 상황을 해소할 수 있음. 최솟값을 확인하라!
*/
#include<bits/stdc++.h> 

using namespace std;  

typedef long long ll;  
int n, k, temp, psum[100001], ret = -1000000; 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k; 
	
	for(int i = 1; i <= n; i++){
		cin >> temp; 
		psum[i] = psum[i - 1] + temp; 
	} 
	for(int i = k; i <= n; i++){
		ret = max(ret, psum[i] - psum[i - k]); // max 구하는 방법 알아두기
	}
	cout << ret << "\n";
    return 0;
}

// BOJ 2559번: 수열 - 복습(정답)
#include <iostream>
#include <algorithm>

using namespace std;
int N, K, a[100004], psum[100004], sum, ret = -1000004;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	// 입력
	for (int i=0; i<N; i++) {
		cin >> a[i];
	}
	// prefix sum 구하기
	for (int i = 1; i <= N; i++) {
		psum[i] = psum[i-1] + a[i-1];
	}
	// 위와 범위는 다르지만 의미는 같다!!
	for (int i = 0; i <= N-K; i++) {
		sum = psum[i+K] - psum[i];
		ret = max(ret, sum);
	}
	cout << ret << '\n';
	return 0;
}