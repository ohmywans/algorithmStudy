// BOJ 4375번: 1 - GG
#include<bits/stdc++.h>
using namespace std;  
typedef long long ll; 
int n;
int main(){ 
	while(scanf("%d", &n) != EOF){ // 속도를 위해 scanf를 사용함. while (cin >> n) 도 가능 but, 형식 지정 못함+속도 느림
		int cnt = 1, ret = 1; // ret는 자릿수 체크하는 수
		while(true){
			if(cnt % n == 0){
				printf("%d\n", ret);
				break;
			}else{
				cnt = (cnt * 10) + 1; 
				cnt %= n; 
				ret++;
			}
		} 
	}  
	return 0;
} 
