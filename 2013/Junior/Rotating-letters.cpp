#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == 'I' || s[i] == 'Z' || s[i] == 'X' || s[i] == 'N' || s[i] == 'H'||s[i] == 'O'||s[i] == 'S'){

		}else{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}