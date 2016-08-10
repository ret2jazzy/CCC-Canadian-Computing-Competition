#include <iostream>
#include <string>
#include <vector>

using namespace std;

string junior3()
{
	int m;
	string final;
	string inp;
    cin >> inp;
    string constants = "bcdfghjklmnpqrstvwxyzz";
    string vowels = "aeiou";
    vector<string> nearby = {"bc", "dfg", "hjkl", "mnpqr", "stvwxyz"};
    for(int x = 0; x < inp.size(); ++x)
    {
        final += inp[x];
        if(constants.find(inp[x]) != string::npos)
        {
            for(int j = 0; j < 5; ++j)
            {
                if(nearby[j].find(inp[x]) != string::npos)
                {
                    final += vowels[j];
                    break;
                }
            }
            final += constants[constants.find(inp[x]) + 1];
        }
    }
    return final;
}

int main()
{
    cout << junior3() << endl;
    return 0;
}
