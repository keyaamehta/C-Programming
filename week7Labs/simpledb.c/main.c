#include <stdio.h>

#define MAX_LIMIT 2000

int main() {
    int time_hour, time_minutes;
    double measure;

    //code entry point 1
    printf("Enter the hours of the current time (0-23)\n");
    scanf("%d", &time_hour);
    printf("Enter the minutes of the current time (00-59):\n");
    scanf("%d", &time_minutes);
    printf("Enter the measurement value as a real number:\n");
    scanf("%lf", &measure);
    printf("New measurement entered successfully in simpledb.dat\n");

    // code entry point 2
    FILE *database;
    database = fopen("db.txt", "a+");

    fprintf(database, "HOUR: %d; MIN: %d; MEASUREMENT: %lf\n", time_hour, time_minutes, measure);

    fclose(database);
    return 0;
}
































