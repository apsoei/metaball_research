#ifndef ASTAR_IS_INCLUDED
#define ASTAR_IS_INCLUDED

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ysshellext.h>


float GetEuclidianDist(const YsShellExt &shl,YsShell::VertexHandle a,YsShell::VertexHandle b);
std::vector <YsShellExt::VertexHandle> A_Star(const YsShellExt &shl,YsShellExt::VertexHandle startVtHd,YsShellExt::VertexHandle goalVtHd);
std::vector <YsShellExt::VertexHandle> A_Star_ReconstructPath(
    const YsShellExt &shl,const std::unordered_map <YSHASHKEY,YsShellExt::VertexHandle> &cameFrom,YsShellExt::VertexHandle current);

#endif
