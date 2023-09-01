#include <stdio.h>

// Define the time_struct structure
struct time_struct {
    int hour;
    int minute;
    int second;
};

// Function to input new time
void inputTime(struct time_struct *time) {
    printf("Enter hour (0-23): ");
    scanf("%d", &time->hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &time->minute);
    printf("Enter second (0-59): ");
    scanf("%d", &time->second);
}

// Function to display the time
void displayTime(struct time_struct time) {
    printf("Time: %02d:%02d:%02d\n", time.hour, time.minute, time.second);
}

// Function to update time by one second
void updateTime(struct time_struct *time) {
    time->second++;

    if (time->second == 60) {
        time->second = 0;
        time->minute++;

        if (time->minute == 60) {
            time->minute = 0;
            time->hour++;

            if (time->hour == 24) {
                time->hour = 0;
            }
        }
    }
}

int main() {
    struct time_struct myTime;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Input new time\n");
        printf("2. Display the time\n");
        printf("3. Update time by one second\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputTime(&myTime);
                break;
            case 2:
                displayTime(myTime);
                break;
            case 3:
                updateTime(&myTime);
                printf("Time updated by one second.\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}