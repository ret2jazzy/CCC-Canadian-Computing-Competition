#include <iostream>
#include <vector>

using namespace std;

int arraySum(vector<int>&lol)
{
	int sum = 0;
	for(int i = 0;i < lol.size(); ++i){
		sum += lol[i];
	}
	return sum;
}

int checkManyCars(vector<int>&lol, int max)
{
	int weight = 0;
	vector<int>rail;
	for(int i = 0; i < lol.size(); ++i){
		if(rail.size() != 4){
			rail.push_back(lol[i]);
		}else{
			rail.erase(rail.begin());
			rail.push_back(lol[i]);
		}
		if(arraySum(rail) > max){
			return i;
		}
	}
	return lol.size();
}

int main()
{
	int n, x;cin >> n >> x;
	vector<int>ans;
	for(int i = 0; i < x; ++i){
		int p;
		cin >> p;
		ans.push_back(p);
	}
	cout << checkManyCars(ans, n) << endl;
}