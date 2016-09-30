#include <iostream>
#include <deque>
#include <string>

using namespace std;

bool isPossible(deque<int>&lol)
{
	bool possible = true;
	deque<int>temp;
	int cnter = 1;
	while(lol.size() != 0){
		if(lol[0] == cnter){
			lol.pop_front();
			++cnter;
		}else if((temp.size() != 0) && (temp[0] == cnter)){
			temp.pop_front();
			++cnter;
		}else{
			temp.push_front(lol[0]);
			lol.pop_front();
		}
		
	}
	while(temp[0] == cnter){
		temp.pop_front();
		++cnter;
	}
	if(temp.size() != 0){
		possible = false;
	}
	return possible;
}

int main()
{
	int n; cin >> n;
	for(int i = 0; i < n; ++i){
		int f;
		cin >> f;
		deque<int>abc;
		for(int a = 0; a < f; ++a){
			int t;
			cin >> t;
			abc.push_front(t);
		}
		if(isPossible(abc)){
			cout << "YES" << endl;
		}else cout << "NO" << endl;
	}
}