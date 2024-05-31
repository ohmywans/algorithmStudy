/* BOJ 1620번 : 나는야 포켓몬 마스터 이다솜 - 나: 런타임 에러, 시간복잡도 (N^2)
// 관건은 2개의 자료구조를 사용하여 시간 복잡도를 O(logN)으로 조절하는 것이다!

#include<bits/stdc++.h>
using namespace std;
int n, m;
string s; 
map<string, int> mp;
map<int, string> mp2;
string a[100004];
int main(){  
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m; 
	for(int i = 0; i < n; i++){
		cin >> s; 
		mp[s] = i + 1;  
		mp2[i + 1] = s; 
        a[i + 1] = s;
	}
	for(int i = 0; i < m; i++){
		cin >> s; 
		if(atoi(s.c_str()) == 0){
			cout << mp[s] << "\n";
		}else{
			cout << a[atoi(s.c_str())] << "\n"; 
			//cout << mp2[atoi(s.c_str())] << "\n"; 
		}
	} 
}
*/
