#include "dha.h"

#include <unordered_set>

#include <iostream>
#include <algorithm>

// Input parameters are a mesh and dihedral-angle threshold.
// The return value is a map from a polygon search key to a segment identifier.
std::unordered_map <YSHASHKEY,int> MakeDihedralAngleBasedSegmentation(const YsShellExt &mesh,const double dhaThr)
{
	// Use GetSearchKey to get a search key from a polygon handle,
	// and FindPolygon to get a polygon handle from a search key.
	std::unordered_map <YSHASHKEY,int> faceGrp;
	// mesh.EnableSearch();
	YsVec3 myNom;
	YsVec3 neiNom;
	YsColor col;
	int newVal = 0;
	
	for(auto plHd : mesh.AllPolygon())
	{
		
		// faceGrp[key] = 1;
		std::vector<YsShell::PolygonHandle> todo;
		auto key = mesh.GetSearchKey(plHd);
		
		if(faceGrp.find(key)==faceGrp.end())
		{
			todo.push_back(plHd);
			faceGrp[key] = newVal;
			newVal++;
			while(0<todo.size())
			{
				auto curr = todo.back();
				todo.pop_back();
				// mesh.GetNormalOfPolygon(myNom,curr);
				auto myNom = mesh.GetNormal(curr);
				for(int i=0; i<3; ++i)
				{
					auto nei = mesh.GetNeighborPolygon(curr,i);
					auto neiKey = mesh.GetSearchKey(nei);
					if(mesh.NullPolygon()!=nei && faceGrp.find(neiKey)==faceGrp.end())
					{
						// mesh.GetNormalOfPolygon(neiNom,nei);
						auto neiNom = mesh.GetNormal(nei);


						auto dot = neiNom.x()*myNom.x() + neiNom.y()*myNom.y() + neiNom.z()*myNom.z();
						// auto magnitude = neiNom.GetLength() * myNom.GetLength();
						// auto dot = neiNom*myNom;
						// if(dot/magnitude > cos(dhaThr))
						if(dot > cos(dhaThr))
						{
							
							// faceGrp[neiKey] = newVal;
							faceGrp[neiKey] = faceGrp[key];
							todo.push_back(nei);
						}
					}
					
				}
			}
		}
	}


	return faceGrp;
}

// Input parameters are a mesh and the segmentation (face grouping) obtained from MakeDihedralAngleBasedSegmentaion.
// Output is a vertex array that can be drawn as GL_LINES.
std::vector <float> MakeGroupBoundaryVertexArray(const YsShellExt &mesh,const std::unordered_map <YSHASHKEY,int> &faceGroupInfo)
{
	std::vector <float> vtxArray;
	int prev = 0;
	
	for(auto iter = faceGroupInfo.begin(); iter!=faceGroupInfo.end(); ++iter)
	{
		auto currKey = iter->first;
		auto currVal = iter->second;
		auto plHd = mesh.FindPolygon(currKey);
		for(int i =0; i< 3;++i)
		{
			auto neiHd = mesh.GetNeighborPolygon(plHd,i);
			if(neiHd!=mesh.NullPolygon())
			{
				auto neiKey = mesh.GetSearchKey(neiHd);
				auto nei = faceGroupInfo.find(neiKey);
				auto neiVal = nei->second;
				if(currVal!=neiVal)
				{
					YsShellVertexHandle edVtHd[2];
					mesh.GetPolygonEdgeVertex(edVtHd,plHd,i);
					auto ln0 = mesh.GetPosition(edVtHd[0]);
					auto ln1 = mesh.GetPosition(edVtHd[1]);
					vtxArray.push_back(ln0.xf());vtxArray.push_back(ln0.yf());vtxArray.push_back(ln0.zf());
					vtxArray.push_back(ln1.xf());vtxArray.push_back(ln1.yf());vtxArray.push_back(ln1.zf());
				}
			}
		}
	}

	return vtxArray;
}

// For bonus questions:
// Input parameters are a mesh and the segmentation (face grouping) obtained from MakeDihedralAngleBasedSegmentaion.
// Paint polygons so that no two neighboring face groups have a same color.
void MakeFaceGroupColorMap(YsShellExt &mesh,const std::unordered_map <YSHASHKEY,int> &faceGroupInfo)
{

	std::unordered_map <int, std::vector<YsShell::PolygonHandle> > reverseGrp;

	std::vector <YsColor> palette;
	std::vector <bool> usedColor;
	
	palette.push_back(YsYellow());
	palette.push_back(YsWhite());
	palette.push_back(YsBlack());
	palette.push_back(YsRed());
	palette.push_back(YsMagenta());
	palette.push_back(YsGreen());
	palette.push_back(YsCyan());
	
	
	

	usedColor.resize(palette.size());

	for(auto iter = faceGroupInfo.begin(); iter!=faceGroupInfo.end(); ++iter)
	{
		auto currKey = iter->first;
		auto currVal = iter->second;
		auto plHd = mesh.FindPolygon(currKey);

		reverseGrp[currVal].push_back(plHd);

	}
	
	for(auto iter = reverseGrp.begin(); iter!=reverseGrp.end(); ++iter)
	{
		auto plHdList = iter->second;
		YsColor choice;
		for(auto &&b : usedColor)
		{
			b=false;
		}
		for(auto plHd : plHdList)
		{
			
			for(int i=0; i<mesh.GetPolygonNumVertex(plHd); ++i)
			{
				auto neiPlHd=mesh.GetNeighborPolygon(plHd,i);
				
				// if(std::find(plHdList.begin(), plHdList.end(), neiPlHd) == plHdList.end())
				auto key = mesh.GetSearchKey(plHd);
				auto neiKey = mesh.GetSearchKey(neiPlHd);
				auto myVal = faceGroupInfo.find(key)->second;
				auto neiVal = faceGroupInfo.find(neiKey)->second;
				if(myVal!=neiVal)
				{
					auto col=mesh.GetColor(neiPlHd);

					for(int j=0; j<palette.size(); ++j)
					{
						if(col==palette[j])
						{

							usedColor[j]=true;
							break;
						}
					}
				} 
				
			}
		}
		for(int i=0; i<palette.size(); ++i)
		{
			if(true!=usedColor[i])
			{
				choice = palette[i];
				break;
			}
		}
		for(auto plHd : plHdList)
		{
			mesh.SetPolygonColor(plHd,choice);
		}
	}
}

