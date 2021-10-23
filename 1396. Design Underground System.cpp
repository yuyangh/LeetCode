//
// Created by Yuyang Huang on 10/7/20.
//

#include <utility>

# include "LeetCodeLib.h"

/*
 * 1396. Design Underground System
 * Medium
 *
 * Implement the class UndergroundSystem that supports three methods:
 * 1. checkIn(int id, string stationName, int t)
 * A customer with id card equal to id, gets in the station stationName at time t.
 * A customer can only be checked into one place at a time.
 *
 * 2. checkOut(int id, string stationName, int t)
 * A customer with id card equal to id, gets out from the station stationName at time t.
 *
 * 3. getAverageTime(string startStation, string endStation)
 * Returns the average time to travel between the startStation and the endStation.
 * The average time is computed from all the previous traveling from startStation to endStation that happened directly.
 * Call to getAverageTime is always valid.
 * You can assume all calls to checkIn and checkOut methods are consistent.
 * That is, if a customer gets in at time t1 at some station,
 * then it gets out at time t2 with t2 > t1. All events happen in chronological order.
 *
 * Constraints:
 * There will be at most 20000 operations.
 * 1 <= id, t <= 10^6
 * All strings consist of uppercase, lowercase English letters and digits.
 * 1 <= stationName.length <= 10
 * Answers within 10^-5 of the actual value will be accepted as correct.
 */

/*
 * Time complexity: O(1)
 */
class UndergroundSystem {
public:
	/*
	 * Use two maps to memorize departure info and statistics
	 */
	UndergroundSystem() {
	
	}
	
	void checkIn(int id, string stationName, int t) {
		departureLocationTimeMap[id]=DepartInfo(std::move(stationName),t);
	}
	
	void checkOut(int id, string stationName, int t) {
		auto departureInfo = departureLocationTimeMap[id];
		// increase total duration
		stationToStationTravelInfoMap[departureInfo.station][stationName].duration += t - departureInfo.time;
		// increase times of taken
		stationToStationTravelInfoMap[departureInfo.station][stationName].count++;
	}
	
	double getAverageTime(string startStation, string endStation) {
		auto travelInfo = stationToStationTravelInfoMap[startStation][endStation];
		return 1.0 * travelInfo.duration / travelInfo.count;
	}

private:
	struct DepartInfo {
		string station;
		int time;
		DepartInfo(string s,int t):station(std::move(s)),time(t){};
		DepartInfo()= default;
	};
	
	struct Stat {
		int duration;
		int count;
	};
	
	unordered_map<int, DepartInfo> departureLocationTimeMap;
	unordered_map<string, unordered_map<string, Stat>> stationToStationTravelInfoMap;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main() {
	double ans;
	UndergroundSystem undergroundSystem = UndergroundSystem();
	undergroundSystem.checkIn(10, "Leyton", 3);
	undergroundSystem.checkOut(10, "Paradise", 8);
	ans = undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.00000
	PrintSingleResult(ans);
	undergroundSystem.checkIn(5, "Leyton", 10);
	undergroundSystem.checkOut(5, "Paradise", 16);
	ans = undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.50000
	PrintSingleResult(ans);
	undergroundSystem.checkIn(2, "Leyton", 21);
	undergroundSystem.checkOut(2, "Paradise", 30);
	ans = undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 6.66667
	PrintSingleResult(ans);
}