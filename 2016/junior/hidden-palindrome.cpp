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
	string nur = input;
	ans.push_back(nur);
	int m = nur.size()/2;
	for (int i = 0; i < m ; ++i){
		nur.erase(nur.begin());
		ans.push_back(nur);
		nur.pop_back();
		ans.push_back(nur);
	}
	string nur2 = input;
	for(int i = 0; i < nur2.size();){
		nur2.erase(nur2.begin());
		ans.push_back(nur2);
	}
	string nur3 = input;
	for(int i = 0; i < nur3.size();){
		nur3.pop_back();
		ans.push_back(nur3);
	}
	sort(ans.begin(), ans.end(), desc);
}

string Checkfin()
{
	for (auto l : ans){
		string m = l;
		reverse(l.begin(), l.end());
		if(l == m){
			return l;
			break;
		}
	}
	return NULL;
}

int main()
{
	inputt();
	CheckPal();
	cout << Checkfin() << endl;;
	return 0;
}