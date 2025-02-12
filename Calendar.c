#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getStartDay(int year) {
    return (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
}

void printCalendar(int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int startDay = getStartDay(year);
    
    if (isLeapYear(year)) daysInMonth[1] = 29;
    
    printf("\nCalendar for the Year %d\n", year);
    printf("-----------------------------\n");
    
    for (int i = 0; i < 12; i++) {
        printf("\n  %s\n", months[i]);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        
        for (int j = 0; j < startDay; j++) {
            printf("     ");
        }
        
        for (int day = 1; day <= daysInMonth[i]; day++) {
            printf("%5d", day);
            if ((startDay + day) % 7 == 0) printf("\n");
        }
        printf("\n");
        startDay = (startDay + daysInMonth[i]) % 7;
    }
}

void printNationalFestivals(int year) {
    struct { int day; char *name; } festivals[] = {
        {26, "Republic Day"},
        {15, "Independence Day"},
        {2, "Gandhi Jayanti"}
    };
    
    printf("\nImportant National Festivals in %d:\n", year);
    printf("----------------------------------\n");
    
    for (int i = 0; i < 3; i++) {
        printf("%2dth %s\n", festivals[i].day, festivals[i].name);
    }
}

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    
    printCalendar(year);
    printNationalFestivals(year);
    
    return 0;
}
