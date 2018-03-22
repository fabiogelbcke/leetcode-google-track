struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		std::vector<Interval> ans;

		for (auto interval: intervals){
			if (ans.size() > 0 && ans.back().end >= interval.start)
				ans.back().end = std::max(interval.end, ans.back().end);
			else if (newInterval.start > interval.end)
				ans.push_back(interval);
			else if ((newInterval.start >= interval.start && newInterval.start <= interval.end)
					 || (newInterval.end >= interval.start && newInterval.end  <= interval.end)
					 || (interval.start >= newInterval.start && interval.end <= newInterval.end))
				ans.push_back(Interval(std::min(interval.start, newInterval.start), std::max(interval.end, newInterval.end)));
			else if (newInterval.end < interval.start && (ans.size() == 0 || ans.back().end < newInterval.start)){
				ans.push_back(newInterval);
				ans.push_back(interval);
			}
			else
				ans.push_back(interval);
		}
		if (ans.size() == 0 || ans.back().end < newInterval.start)
			ans.push_back(newInterval);
		return ans;
    }
};
