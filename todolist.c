#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TASKS 50
#define MAX_TASK_LENGTH 100

typedef struct {
    char todo_item[MAX_TASK_LENGTH];
    bool completed;
} Task;

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addTask(Task tasks[], int *numTasks) {
    if (*numTasks <= MAX_TASKS) {
        char input[MAX_TASK_LENGTH];
        printf("\nEnter a new task: \n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        strcpy(tasks[*numTasks].todo_item, input);
        tasks[*numTasks].completed = false;
        (*numTasks)++;
        printf("Task created successfully!\n");
    } else {
        printf("Sorry, list is full\n");
    }
}

void displayTasks(Task tasks[], int numTask) {
    printf("\nTodo-List:\n");
    for (int i = 0; i < numTask; i++)
        printf("%d. %s [%s]\n", i+1, tasks[i].todo_item, tasks[i].completed ? "Done" : "Pending");
}

void markAsCompleted(Task tasks[], int numTasks) {
    displayTasks(tasks, numTasks);
    printf("\nEnter the number of the item to mark completed:\n");
    int taskNumber;
    scanf("%d", &taskNumber);

    if (taskNumber > 0 && taskNumber <= numTasks) {
        tasks[taskNumber - 1].completed = true;
        printf("\nMarked as completed!\n");
    } else {
        printf("\nInvalid Task Number!\n");
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int numTasks = 0;
    int choice;
    printf("Welcome to the To-Do List!\n");
    
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addTask(tasks, &numTasks);
                break;
            case 2:
                displayTasks(tasks, numTasks);
                break;
            case 3:
                markAsCompleted(tasks, numTasks);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("Invalid option...\n");
                break;
        }
    } while (choice != 4);

    return 0;
}