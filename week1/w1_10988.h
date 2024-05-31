// BOJ 10988번: 팰린드롬인지 확인하기
// 정답 코드와 로직은 같지만 더욱 심플한 코드라서 맨 밑에 달아둠

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// inputReverse에 입력 받기
	int answer = 1;
	string input, inputReverse;
	cin >> inputReverse;
	
	// input에 원래 값 복사해두고, inputReverse는 뒤집어두기
	input = inputReverse;
	reverse(inputReverse.begin(), inputReverse.end());
	
	// 요소 간 비교 시 값이 다르면 answer = 0 후, 리턴 -> 이렇게 하지말고 string이니까 그냥 같냐, 다르냐로 보는게 효율적
	for (int i = 0; i < input.size(); i++) {
		if (input[i] != inputReverse[i]) {
			answer = 0;
			cout << answer << '\n';
			
			return 0;
		}
	}
	cout << answer << '\n';
	
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;   
string s, temp; 
int main(){
    cin >> s; 
    temp = s; 
    reverse(temp.begin(), temp.end()); 
    if(temp == s) cout << 1 << "\n"; 
    else cout << 0 << "\n"; 
      
    return 0; 
}
*/