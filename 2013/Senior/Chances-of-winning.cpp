#include <iostream>
#include <vector>

using namespace std;

int winner = 0;

void checkWin(vector<int>scores, int teamIn){
	int teamsc = scores[teamIn-1];
	for(int i = 0; i < scores.size(); ++i){
		if(scores[i] >= teamsc && i != teamIn-1){
			return;
		}
	}
	++winner;
}

void compute(vector<int>scores, vector<vector<int> >games, int played, int team)
{
	if(played == 6){
		checkWin(scores, team);
		return;
	}
	for(int i = 0; i < games.size() -1; ++i){
		for(int t = i+1; t < games[i].size(); ++t){
			if(games[i][t] == 0){
				games[i][t] = 1;
				scores[i] += 3;
				compute(scores, games, played+1, team);
				scores[i] -= 3;
				scores[t] += 3;
				compute(scores, games, played+1, team);
				scores[t] -= 3;
				scores[t] += 1;
				scores[i] += 1;
				compute(scores, games, played+1, team);
				scores[i] -= 1;
				scores[t] -= 1;
				return;
			}
		}
	}
}

int main()
{
	vector<vector<int> >games (4, vector<int>(4,0));
	games[0][0] = 1; games[1][1] =1; games[2][2] = 1;games[3][3] = 1;
	vector<int>scores(4,0);
	int n; cin >>n;
	int t;cin >> t;
	for(int i = 0; i < t; ++i){
		int x, y, z, a;
		cin >> x >> y >> z >> a;
		games[x-1][y-1] = 1;
		games[y-1][x-1] = 1;
		if(z > a){
			scores[x-1] += 3;
		}else if(z == a){
			scores[x-1] += 1;
			scores[y-1] += 1;
		}else scores[y-1] += 3;
	}
	compute(scores, games, t, n);
	cout << winner << endl;
}
