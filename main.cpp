#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 20;
const int INF = 99999;
//정점의 개수
int V;
//그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치)
vector<pair<int, int>> adj [MAX_V];
vector<int> dijkstra(int src) {
  vector<int> dist(V,INF);
  dist[src]=0;
  priority_queue<pair<int,int>>pq;
  pq.push(make_pair(0,src));
  while(!pq.empty()) {
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    if(dist[here] < cost) continue;
    for(int i=0;i <adj[here].size();++i) {
      int there = adj[here][i].first;
      int nextDist = cost + adj[here][i].second;
      if(dist[there] > nextDist) {
        dist[there] = nextDist;
        pq.push(make_pair(-nextDist, there));
      }
    }
  }
  return dist;
}
int main() {
  std::cout << "Hello World!\n";
}