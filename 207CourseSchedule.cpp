#include "LeetCodeLib.h"

class Solution {
public:
	map<int, set<int>> relation; // courseID, prerequisites courses
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// create the graph
		for(int i=0;i<prerequisites.size();i++){
			auto to=relation.find(prerequisites[i][0]);
			if(to==relation.end()){
				relation.insert(make_pair(prerequisites[i][0],
				                          set<int>({prerequisites[i][1]})));
			}else{
				to->second.insert(prerequisites[i][1]);
			}
			
			auto from=relation.find(prerequisites[i][1]);
			if(from==relation.end()){
				relation.insert(make_pair(prerequisites[i][1],set<int>()));
			}
		}
		
		// topological sort
		int courseNum;
		while(!relation.empty()){
			courseNum=findNoDepend();
			if(courseNum==~INT_MAX+1){
				return false;
			}else{
				for(auto begin=relation.begin();begin!=relation.end();++begin){
					begin->second.erase(courseNum);
				}
			}
		};
		return true;
	}
	
	// find courses without dependencies
	int findNoDepend(){
		for(auto begin=relation.begin();begin!=relation.end();++begin){
			if(begin->second.empty()){
				int result=begin->first;
				relation.erase(begin);
				return result;
			}
		}
		return ~INT_MAX+1;
	}
};
/*
* 2
* [[1,0],[0,1]]
*/