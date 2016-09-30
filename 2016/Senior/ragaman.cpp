#include <iostream>
#include <string>
using namespace std;

bool CheckAnagram(string &f, string &m)
{
	int q = 0;
	if (f.size() != m.size())
		return false;
	for (int k = 0; k < f.size(); ++k){
		for(int g = 0; g < m.size(); ++g){
			if(m[g] == f[k]){
				f[k] = '#';
				m[g] = '&';
				++q;
			}
		}
	}
	for (int as = 0;as < m.size(); ++as){
			if (m[as] == '*'){
				++q;
			}
	}
	if (q == m.size()){
		return true;
	}
	else{
		return false;
	}
}

int main()
{
	string s;
	string z;
	cin >> s >> z;
	cout << (CheckAnagram(s, z) ? "A" : "N") << endl;
	return 0;
}
