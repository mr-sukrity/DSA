class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //sort intervals..ascending by start and descending by end (to handle coverage property)
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        //traverse and count the uncovered intervals
        int count=0;
        int prevEnd=0;

        for(auto & interval : intervals){
            int start=interval[0],end=interval[1];

            //if current interval is not covered
            if(end>prevEnd){
                count++;
                prevEnd=end;
            }
            //if interval is covered then skip it

        }
        return count;

    }
};