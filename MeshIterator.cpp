#include "MeshIterator.h"

#include "hds_mesh.h"

queue<pair<HDS_Vertex*,int>> MeshIterator::BFS(HDS_Mesh* mesh, int vidx)
{
  queue<pair<HDS_Vertex*, int>> Q;
  queue<pair<HDS_Vertex*, int>> Q0;
  unordered_set<HDS_Vertex*> visited;

  Q0.push(make_pair(mesh->vertMap[vidx], 0));
  cout << mesh->vertMap[vidx]->pos << endl;
  while (!Q0.empty()) {
    auto cur = Q0.front();
    Q0.pop();
    Q.push(cur);

    auto v = cur.first;
    int lev = cur.second;
    auto neighbors = v->neighbors();
    for (auto n : neighbors) {
      if (visited.find(n) == visited.end()) {
        Q0.push(make_pair(n, lev+1));
        visited.insert(n);
      }
    }
  }


  return Q;
}
