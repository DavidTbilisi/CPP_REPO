#include <iostream>
#include <string>
using namespace std;

// https://www.soa.org/news-and-publications/newsletters/compact/2013/july/com-2013-iss48/mental-math/
// https://youtu.be/pdMUk16675U?t=71

string daysOfWeek[7] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
};

int monthsCodes[13] = {
    0,
    6,2,2,
    5,0,3,
    5,1,4,
    6,2,4
};

int year = 2022, month, day;
bool isLeap(int year) {
    if ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0)){
        return true;
    } else {
        return false;
    }
}

int yearCode(int year){
    
    int lastTwoDigits = year%100;
    int twiceHalf = lastTwoDigits / 4;
    
    if (isLeap(year)) {
        cout << "Year" << year <<" is Leap" << endl;
        twiceHalf--;
    }

    if (year >= 1800 && year < 1900) { twiceHalf += 3;}
    if (year >= 1900 && year < 2000) { twiceHalf += 1;}
    if (year >= 2000 && year < 2100) { twiceHalf += 0;}
    if (year >= 2100 && year < 2200) { twiceHalf += 5;}

    return (twiceHalf + lastTwoDigits) % 7;
}


int dayOfWeekFromDate(int year, int month, int date){
    int yCode = yearCode(year);
    int monthCode = monthsCodes[month];
    // cout << "YearCode:" << yCode << " + MonthCode:"<< monthCode<< " + Date:"<< date%7<< endl; 
    return (yCode + monthCode + date) % 7;
}



int main(){
    // cout << "Enter date (yyyy-mm-dd): " << endl;
    // cout << "Example: 2022-05-23" << endl;

    cout << "Enter Month: ";
    cin >> month;
    cout << "Enter Day: ";
    cin >> day;

    string weekDay = daysOfWeek[dayOfWeekFromDate(year, month, day)];

    cout << year << "-" << month << "-" << day  << endl;
    cout << weekDay << endl;

    return 0;
}


