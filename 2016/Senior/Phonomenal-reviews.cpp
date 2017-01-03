#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;
//Just ignore the comments, they will confuse you, but it works by removing all extra leaves, finding optimal starting node, and then 
//finding the diameter of the tree

vector<vector<int> >connections;
vector<bool>isPho;
vector<bool>visited;
vector<bool>isExtra;
int ans= 0;

bool isLeaf(int p)
{
	int cnter = 0;
	for(auto m : connections[p]){
		if(!isExtra[m]){
			++cnter;
		}
	}
	return bool(cnter==1);
}

void markExtra()
{
	for(int i = 0; i < connections.size(); ++i){
		if(connections[i].size() < 2 && !isPho[i] && !isExtra[i]){//Check if they arent pho and they arent processed and they dont have more than one connection
			list<int>que;//making que
			que.push_back(i);//ppushing the leaf
			isExtra[i] = true;//marking it extra
			while(!que.empty()){//simple BFS
				int m = que.front();
				que.pop_front();
				for(auto p: connections[m]){
					if(!isPho[p] && !isExtra[p]  && isLeaf(p)){//Checks if it isnt a pho, or already been marked, or it has more connections than needed(it can break the tree)
						que.push_back(p);
						isExtra[p] = true;
					}
				}
			}
		}
	}
}

void getStartingP(int now, int &maxNode, int &maxDistance, int distance)
{
	if(isPho[now]){
		if(distance > maxDistance){
			maxNode = now;
			maxDistance = distance;
		}
	}
	for(int i = 0; i < connections[now].size(); ++i){
		if(!visited[connections[now][i]] && !isExtra[connections[now][i]]){
			visited[connections[now][i]] = true;
			getStartingP(connections[now][i], maxNode, maxDistance, distance+1);
		}
	}
}

void anDFS(int now, int &curDistance)
{
	if(isPho[now]){
		ans+=curDistance;
		curDistance = 0;
	}
	bool isALeaf = true;
	for(int i = 0; i < connections[now].size(); ++i){
		if(!visited[connections[now][i]] && !isExtra[connections[now][i]]){
			++curDistance;
			visited[connections[now][i]] = true;
			anDFS(connections[now][i], curDistance);
			isALeaf = false;
		}
	}
	if(isALeaf){
		curDistance = 0;
	}
}



int main()
{
	int a, b;
	cin >> a >> b;
	connections.assign(a, vector<int>());
	visited.assign(a+1, false);//Initializing all global vectors
	isPho.assign(a+1, false);
	isExtra.assign(a+1, false);
	int phoR;
	while(b--){
		int i;
		cin >> i;
		isPho[i] = true;
		phoR = i;
	}
	a--;
	while(a--){
		int p,q;
		cin >> p >> q;
		connections[p].push_back(q);
		connections[q].push_back(p);
	}
	int maxMode = phoR;//The starting node for optimal starting point is the last node
	int maxDistance = 0;//The distance from this node(0)
	markExtra();//Marking out the extra leave nodes
	visited[phoR] = true;//Finding the starting point, so marking the starting one as 0
	getStartingP(phoR, maxMode, maxDistance, 0);//Finding the starting point
	visited.assign(a+1, false);//Since finding optimal starter uses visited, reassigning it
	int curDs = 0;//The variable for currect Distance
	visited[maxMode] = true;//Marking the starting node as visited
	anDFS(maxMode,curDs);//Getting the size of graph
	ans *= 2;//Multiplying the distance by 2
	int maxMode2 = maxMode;
	maxDistance = 0;//The distance from the starting points
	visited.assign(a+1, false);//Reinitiling the visited array
	visited[maxMode2] = true;//Marking starting one as visited
	getStartingP(maxMode2, maxMode,maxDistance,0);//Finding the distance to the longest node
	cout << ans-maxDistance << endl;//ans - maxDistance

}