#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;



bool computeVec(vector<string>&lol, vector<string>&lmao)
{
	bool isright = true;

	map<string, string>answer;
	for(int i = 0; i < lol.size(); ++i){
		answer[lol[i]] = lmao[i];
 	}
 	for(int i = 0; i < lol.size(); ++i){
 		string g = lol[i];
 		string s = answer[g];
 		if(g == s){
 			isright =false;
 			break;
 		}
 		string m = answer[s];
 		if(g != m){
 			isright = false;
 			break;
 		}
 	}
 	return isright;
}

int main()
{
	vector<string>a;
	vector<string>b;
	int f;cin >>f;
	for(int i = 0; i < f; ++i){
		string s;
		cin >> s;
		a.push_back(s);
	}
	for(int i = 0; i < f; ++i){
		string s;
		cin >> s;
		b.push_back(s);
	}
	if(computeVec(a, b)){
		cout << "YES" << endl;;
	}else cout << "NO" << endl;
}
