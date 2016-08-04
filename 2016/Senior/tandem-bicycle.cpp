#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int typeques;
int participants;
int totalsum;
vector<int>fag, lol;

int Greater(int &i, int &m)
{
	if (i > m)
	{
		return i;
	}
	return m;
}

bool sort_inc(int i, int l){return (i < l);}
bool sort_dec(int i, int l){return (i > l);}

void InpuSave()
{
	cin >> typeques;
	cin >> participants;
	cin.ignore();
	string mas;
	string pas;
	getline(cin, pas);
	istringstream iss(pas);
	for (int mk; iss >> mk;){
		lol.push_back(mk);
	}
	getline(cin, mas);
	istringstream iss2(mas);
	for (int gh; iss2 >> gh;){
		fag.push_back(gh);
	}
}

void comparebikers()
{
	sort(fag.begin(), fag.end(), sort_inc);

	if (typeques == 2)
	{
		sort(lol.begin(), lol.end(), sort_dec);
	}
	else{
		sort(lol.begin(), lol.end(), sort_inc);
	}
}
int computesum()
{
	for(int i = 0; i < participants; ++i)
	{
		totalsum += Greater(fag[i], lol[i]);
	}
	return totalsum;
}


int main()
{
	
	InpuSave();
	comparebikers();
	cout << computesum() << endl;

	return 0;
}

