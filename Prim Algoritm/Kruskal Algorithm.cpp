
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>



using namespace std;

//disjoint set
unordered_map<char, char> PARENT;
unordered_map<char, int> RANK;
char Find(char vertex) {
	if (PARENT[vertex] == vertex)
		return PARENT[vertex];
	else return Find(PARENT[vertex]);
}
void Union(char root1, char root2) {
	if (RANK[root1] > RANK[root2]) {
		PARENT[root2] = PARENT[root1];
	}
	else if (RANK[root2] > RANK[root1]) {
		PARENT[root1] = root2;
	}
	else {
		PARENT[root1] = root2;
		RANK[root2]++;
	}
}
void MakeSet(char vertex) {
	PARENT[vertex] = vertex;
	RANK[vertex] = 0;
}


//define graph
struct Edge {
	char vertex1;
	char vertex2;
	int weight;
	Edge(char v1, char v2, int w):vertex1(v1), vertex2(v2), weight(w) {}
};
struct Graph {
	vector<char> vertices;
	vector<Edge> edges;
	vector<pair<char, Edge>> adjacent(char u) {
		vector<pair<char, Edge>> res;
		for(Edge e:edges){
			if(e.vertex1 == u){
				res.push_back(make_pair(e.vertex2, e));
			}
			else if(e.vertex2 == u){
				res.push_back(make_pair(e.vertex1, e));
			}
		}
		return res;
	}
};


void Prim(Graph& g) {
	unordered_map<char,char> A;
	unordered_map<char, char> PARENT;
	unordered_map<char, int> KEY;

	for(auto c:g.vertices){
		PARENT[c] = '\0';
		KEY[c] = INT_MAX;
	}
	 KEY['a'] = 0; //root
	 vector<char> Q = g.vertices;

	 while(!Q.empty()){    //O(V)
		 char u = *std::min_element(Q.begin(), Q.end(),
		 [&](char x,char y){
			 return KEY[x]<KEY[y];
		 });
		 vector<char>::iterator itr = remove(Q.begin(),Q.end(), u);
		 Q.erase(itr, Q.end());//erase() following remove

		 if(PARENT[u] != '\0'){
			 A[u] = PARENT[u];
		 }
		 std::vector<pair<char, Edge>> adj=g.adjacent(u);//O(E)
		 for(pair<char,Edge> v:adj){
			 if(find(Q.begin(), Q.end(), v.first) != Q.end()) {
				 if(v.second.weight <KEY[v.first]) {
					 PARENT[v.first] = u;
					 KEY[v.first] =v.second.weight;
				 }
			 }
		 }

	 }

	 for(auto e:A) {
		 cout<<e.first<<"--"<<e.second<<endl;
	 }
}

int main(){
	char t[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	Graph g;
	g.vertices = vector<char>(t, t + sizeof(t) / sizeof(t[0]));

	g.edges.push_back(Edge('a', 'b', 4));
	g.edges.push_back(Edge('a', 'f', 2));
	g.edges.push_back(Edge('f', 'b', 5));
	g.edges.push_back(Edge('c', 'b', 6));
	g.edges.push_back(Edge('c', 'f', 1));
	g.edges.push_back(Edge('f', 'e', 4));
	g.edges.push_back(Edge('d', 'e', 2));
	g.edges.push_back(Edge('d', 'c', 3));

	Prim(g);

	getchar();
	return 0;
}
