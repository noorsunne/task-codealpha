#include "todo_list.h"
#include <iostream>
#include <limits> // Include for std::numeric_limits

int main() {
    ToDoList todoList;
    int choice;
    int taskId; // Declare taskId outside the switch statement

    while (true) {
        std::cout << "1. Add Task\n2. Mark Task as Completed\n3. View Tasks\n4. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                std::string description; // Declare description inside the case block
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                todoList.addTask(description);
                break;
            }
            case 2: {
                std::cout << "Enter task ID to mark as completed: ";
                std::cin >> taskId;

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a valid task ID.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                    todoList.markCompleted(taskId);
                }
                break;
            }
            case 3:
                todoList.viewTasks();
                break;
            case 4:
                std::cout << "Exiting...";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        }
    }

    return 0;
}

