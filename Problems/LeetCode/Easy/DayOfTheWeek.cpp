// https://leetcode.com/problems/day-of-the-week/

class Solution {
public:
    bool isLeapYear(int year) {
        return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    }
    
    int daysSinceStart(int day, int month, int year) {
        int count = 0;
        for (int i = 1970; i < year; i++) {
            count += 365;
            
            if (isLeapYear(i))
                count++;
        }
        
        vector<int> daysInMonth ({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
        for (int i = 0; i < month-1; i++) {
            count += daysInMonth[i];
        }
        if (month > 2 && isLeapYear(year))
            count++;
        
        count += day-1;
        
        return count;
    }
    
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> dayNames ({"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"});
        
        int days = daysSinceStart(day, month, year);
        
        return dayNames[days % 7];
    }
};