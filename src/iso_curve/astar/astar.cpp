#include "astar.h"

#include <iostream>

float GetEuclidianDist(const YsShellExt &shl,YsShell::VertexHandle a,YsShell::VertexHandle b)
{
	auto aPos = shl.GetVertexPosition(a);
	auto bPos = shl.GetVertexPosition(b);
	auto dist = sqrt( (aPos.xf() - bPos.xf())*(aPos.xf() - bPos.xf()) +
					  (aPos.yf() - bPos.yf())*(aPos.yf() - bPos.yf()) +
					  (aPos.zf() - bPos.zf())*(aPos.zf() - bPos.zf()) );
	return dist;
}


std::vector <YsShellExt::VertexHandle> A_Star(const YsShellExt &shl,YsShellExt::VertexHandle startVtHd,YsShellExt::VertexHandle goalVtHd)
{

	float f_score, g_score, h;
	std::vector<YsShell::VertexHandle> todo;
	todo.push_back(startVtHd);
	auto goalPos = shl.GetVertexPosition(goalVtHd);
	std::vector <YsShellExt::VertexHandle> path;
	std::unordered_set <YSHASHKEY> closedSet;
	std::unordered_map <YSHASHKEY, float > fScore;
	std::unordered_map <YSHASHKEY, float > gScore;
	std::unordered_map <YSHASHKEY,YsShellExt::VertexHandle> cameFrom;
	YsAVLTree <YSHASHKEY,float> openSet;

	auto startKey = shl.GetSearchKey(startVtHd);
	gScore[startKey] = 0;
	fScore[startKey] = 0 + GetEuclidianDist(shl,startVtHd,goalVtHd);
	openSet.Insert(startKey,fScore[startKey]);

	while(openSet.size()>0)
	{

		auto currentNode = openSet.First();

		auto currentKey = openSet.GetKey(currentNode);

		auto currentVtHd = shl.FindVertex(currentKey);

		if(currentVtHd==goalVtHd)
		{

			return A_Star_ReconstructPath(shl,cameFrom,currentVtHd);
		}

		openSet.Delete(currentNode);

		auto neiVtHdList = shl.GetConnectedVertex(currentVtHd);

		for(auto neiVtHd : neiVtHdList)
		{

			auto tent_gScore = gScore[currentKey] + GetEuclidianDist(shl,currentVtHd,neiVtHd);
			auto neiKey = shl.GetSearchKey(neiVtHd);
			if(gScore.find(neiKey)==gScore.end() || tent_gScore < gScore[neiKey])
			{

				cameFrom[neiKey] = currentVtHd;
				gScore[neiKey] = tent_gScore;
				fScore[neiKey] = gScore[neiKey] + GetEuclidianDist(shl,neiVtHd,goalVtHd);
				auto neiNode = openSet.FindNode(neiKey);
				if(neiNode==openSet.Null())
				{

					openSet.Insert(neiKey,fScore[neiKey]);
				}
			}
		}
		
	}


	// std::cout << "Path not found !" <<std::endl;
	return std::vector <YsShellExt::VertexHandle>(); // Path not found.
}

std::vector <YsShellExt::VertexHandle> A_Star_ReconstructPath(
    const YsShellExt &shl,const std::unordered_map <YSHASHKEY,YsShellExt::VertexHandle> &cameFrom,YsShellExt::VertexHandle current)
{

	std::vector <YsShellExt::VertexHandle> path;
	path.push_back(current);
	auto currVtHd = current;
	auto currKey = shl.GetSearchKey(currVtHd);
	auto iter = cameFrom.find(currKey);
	while(iter!=cameFrom.end())
	{
		currVtHd = iter->second;
		path.push_back(currVtHd);
		currKey = shl.GetSearchKey(currVtHd);
		iter = cameFrom.find(currKey);
	}
	
	return path;
}
