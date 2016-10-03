#include <iostream>
#include <string>
using namespace std;

bool isDistinct(int &x)
{
	string s = std::to_string(x);
	for(int i = 0; i < s.size(); ++i){
		for(int t = i; t < s.size(); ++t){
			if(s[t] == s[i] && t != i){
				return false;
			}
		}
	}
	return true;
}

int nextDistYear(int x)
{
	while(!isDistinct(x)){
		++x;
	}
	return x;
}

int main()
{
	int s;
	cin >> s;
	cout << nextDistYear(s+1) << endl;
}