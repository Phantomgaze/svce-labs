#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char *name;
    int date;
    char *activity;
};

void create(struct Day calendar[]) {
    for (int i = 0; i < 7; i++) {
        calendar[i].name = (char*)malloc(sizeof(char) * 20);
        calendar[i].activity = (char*)malloc(sizeof(char) * 50);
    }
}

void read(struct Day calendar[]) {
    for (int i = 0; i < 7; i++) {
        printf("Enter the name of day %d: ", i + 1);
        scanf("%s", calendar[i].name);
        printf("Enter the date of day %d: ", i + 1);
        scanf("%d", &calendar[i].date);
        printf("Enter the activity for day %d: ", i + 1);
        scanf("%s", calendar[i].activity);
    }
}

void display(struct Day calendar[]) {
    printf("Week's Activity Details Report:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: %s, %d - %s\n", i + 1, calendar[i].name, calendar[i].date, calendar[i].activity);
    }
}

int main() { 
    struct Day calendar[7];
    create(calendar);
    read(calendar);
    display(calendar);

    // Free dynamically allocated memory
    for (int i = 0; i < 7; i++) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }

    return 0;
}