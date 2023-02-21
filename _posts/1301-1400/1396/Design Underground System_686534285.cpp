class UndergroundSystem {
public:
    unordered_map<string, unordered_map< string, vector<int> >> m;
    
    unordered_map<int, pair<string, int>> c;
    
    UndergroundSystem() {
    
    }
    
    void checkIn(int id, string stationName, int t) {
        c[id] = {stationName, t};    
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> temp = c[id];
        if(m.find(temp.first) == m.end()){
            m[temp.first] = unordered_map<string, vector<int>>();
            m[temp.first][stationName] = vector<int> {t - temp.second};
        }
        else if(m[temp.first].find(stationName) == m[temp.first].end()){
            m[temp.first][stationName] = vector<int> {t - temp.second};
        }
        else {
            m[temp.first][stationName].push_back(t - temp.second);   
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        int n = m[startStation][endStation].size();
        double sum = 0;
        for(auto i:m[startStation][endStation]){
            sum += i;
        }
        return sum/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
