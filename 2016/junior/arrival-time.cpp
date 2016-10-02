#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;
string inp;
vector<int> lol;
vector<string> fag;
int tm;


int roundUp(int numToRound)
{

    int remainder = abs(numToRound) % 10;
    if (remainder == 0)
        return numToRound;

    if (numToRound < 0)
        return -(abs(numToRound) - remainder);
    else
        return numToRound + 10 - remainder;
}

void Takeinput()
{
	cin >> inp;
	cin.ignore();
	istringstream iss(inp);
	string word;
	while(std::getline(iss, word, ':')) 
	{
		int xyz;
		istringstream ( word ) >> xyz;
    	lol.push_back(xyz);
	}
	lol[1] = lol[1] * 100/60;
	tm = lol[0] * 100 + lol[1];
}

int compute()
{

	if (tm <= 700){
		tm += 200;
		if (tm >= 700){
			int x = tm - 700;
			tm = tm - x;
			x = x * 2;
			tm += x;
			if (tm >= 700 && tm > 1000){
				int m = tm - 1000;
				tm = 1000 + m/2;
				return tm;
			}
			return tm;
		}
		return tm;
	}
	if (tm >= 700 && tm < 1000){
		int m = 1000 - tm;
		int x = 200 - m/2;
		tm = 1000 + x;
		return tm;
	}
	if (tm <= 1500 && tm > 1000 && tm < 1900){
		tm += 200;
		if(tm >= 1500){
			int x = tm - 1500;
			tm = tm - x;
			x *= 2;
			tm += x;
			return tm;
		}
		return tm;
	}
	if(tm >= 1500 && tm < 1900){
		int m = 1900 - tm;
		int x = 200 - m/2;
		tm = 1900 +x;
		return tm;
	}
	if (tm >= 1900 || tm >= 1000){
		tm += 200;
		return tm;
	}
}

void realvl()
{
	if (tm >= 2400){
		tm = tm - 2400;
	}
	stringstream ss;
	ss << tm;
	string hj = ss.str();
	if(hj.size() == 3){
		hj = "0" + hj;
	}
	int x = hj.size();
	fag.push_back(hj.substr(0, 2));
	fag.push_back(hj.substr(x-2, x));
	if (fag[1] == "33"||fag[1] == "34"||fag[1] == "32"){
		fag[1] = "20";
	}
	else if(fag[1] == "50"){
		fag[1] = "30";
	}
	else if(fag[1] == "66"||fag[1] == "67"||fag[1] == "65"){
		fag[1] = "40";
	}else fag[1] = to_string(atoi(fag[1].c_str()) * 60/100);
}

int main()
{
	Takeinput();
	compute();
	realvl();
	string s = to_string(roundUp(atoi(fag[1].c_str())));
	if(s.size() != 2){
		s += "0";
	}
	cout << fag[0] << ":" << s << endl;
	return 0;
}
