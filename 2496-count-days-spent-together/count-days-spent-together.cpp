class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // calculate at which day of the year (1-365) does alice and bob reach rome ;
        // we will consider the max of both reach day  as start of their common time;
        // now calculate which day of the year (1-365) do they leave rome;
        // now we will consider the min of their leave day as end of their common time;

        // eg alice (reach) rome= 45th day of year , bob reach rome = 55th day of the year

        // eg alice (leave) rome= 60th day of year , bob leave rome = 70th day of the year

        // now their common time start from max(45,55) = 55 = start
        // now their common time end at day min(60,70) = 60 = end

        // so common days=55,56,57,58,59,60  == end-start+1;

        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

        int arrivealice = 0, leavealice = 0, arrivebob = 0, leavebob = 0;

        int month = stoi(arriveAlice.substr(0,2));
        int day = stoi(arriveAlice.substr(3,2));
        for(int i = 0; i < month-1; i++) arrivealice += days[i];
        arrivealice += day;

        month = stoi(leaveAlice.substr(0,2));
        day = stoi(leaveAlice.substr(3,2));
        for(int i = 0; i < month-1; i++) leavealice += days[i];
        leavealice += day;

        month = stoi(arriveBob.substr(0,2));
        day = stoi(arriveBob.substr(3,2));
        for(int i = 0; i < month-1; i++) arrivebob += days[i];
        arrivebob += day;

        month = stoi(leaveBob.substr(0,2));
        day = stoi(leaveBob.substr(3,2));
        for(int i = 0; i < month-1; i++) leavebob += days[i];
        leavebob += day;

        int start = max(arrivealice,arrivebob);
        int end = min(leavealice,leavebob);

        if(start > end) return 0;

        return end-start+1;

    }
};