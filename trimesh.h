#ifndef TRIMESH_H
#define TRIMESH_H

#define _USE_MATH_DEFINES
#include "OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh"

using namespace OpenMesh;
using namespace OpenMesh::Attributes;

struct MyTraits : public OpenMesh::DefaultTraits
{
  HalfedgeAttributes(OpenMesh::Attributes::PrevHalfedge);
};

typedef OpenMesh::TriMesh_ArrayKernelT<MyTraits>  TriMesh;

#endif // TRIMESH_H
