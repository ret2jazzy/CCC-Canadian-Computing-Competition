#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<string>ans;
string input;

void inputt()
{
	cin >> input;
	cin.ignore();
}

bool desc(string l, string m){return l.size() > m.size();}

void CheckPal()
{
	ans.push_back(input);
	for(int i = 0; i < input.size(); ++i){
		for(int t = i; t < input.size(); ++t){
			ans.push_back(input.substr(i,t));
		}
	}
	sort(ans.begin(), ans.end(), desc);
}

int Checkfin()
{
	for (auto l : ans){
		string m = l;
		reverse(l.begin(), l.end());
		if(l == m){
			return l.size();
		}
	}
	return 0;
}

int main()
{
	inputt();
	CheckPal();
	cout << Checkfin() << endl;;
	return 0;
}
