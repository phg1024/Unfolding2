#include "GeodesicComputer.h"

GeodesicComputer::GeodesicComputer()
{}

GeodesicComputer::GeodesicComputer(const string &filename)
{
  cout << "computing geodesics ..." << endl;
  const int fixed_K = 50;
  string svg_file_name = "svg.binary";
  svg_precompute(filename, fixed_K, svg_file_name);

  s_graph.reset(new LC_LLL<float>());
  s_graph->read_svg_file_binary(svg_file_name);
  cout << "done." << endl;
}

GeodesicComputer::~GeodesicComputer()
{
}

vector<double> GeodesicComputer::distanceTo(int vIdx) const
{
  s_graph->findShortestDistance(vIdx);
  vector<double> dists(s_graph->NodeNum());
  for (int i = 0; i < s_graph->NodeNum(); ++i) {
     dists[i] = s_graph->distanceToSource(i);
  }
  return dists;
}

