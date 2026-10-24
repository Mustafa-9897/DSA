class Solution {
public:
    int helper(int year,int month,int days){
        vector<int> totalmonthsnormal = {31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int> totalmonthsleap = {31,29,31,30,31,30,31,31,30,31,30,31};
        int total=0;
        for(int i=1970;i<year;i++){
            if(i%400==0 || (i%4==0 && i%100!=0)){
                total += 366;
            }
            else total += 365;
        }
        if(year%400==0 || (year%4==0 && year%100!=0)){
            for(int i=0;i<=month-2;i++){
                total += totalmonthsleap[i];
            }
        }
        else{
            for(int i=0;i<=month-2;i++){
                total += totalmonthsnormal[i];
            }
        }
        total += days;
        return total;
    }
    int daysBetweenDates(string date1, string date2) {
        int totaldays1=helper(stoi(date1.substr(0,4)),stoi(date1.substr(5,2)),stoi(date1.substr(8,2)));
        int totaldays2=helper(stoi(date2.substr(0,4)),stoi(date2.substr(5,2)),stoi(date2.substr(8,2)));

        return abs(totaldays1-totaldays2);
    }
};