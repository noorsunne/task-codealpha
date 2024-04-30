#include "work.h"
#include <iostream>

work::work() : nextId(1) {}

void Work::addTask(const std::string& description) {
    tasks.push_back({nextId++, description, false});
}

void ToDoList::markCompleted(int taskId) {
    for (auto& task : tasks) {
        if (task.id == taskId) {
            task.completed = true;
            break;
        }
    }
}

void Work::viewTasks() const {
    std::cout << "Current Tasks:\n";
    for (const auto& task : tasks) {
        std::cout << task.id << ". ";
        if (task.completed) {
            std::cout << "[Done] ";
        }
        std::cout << task.description << std::endl;
    }
}

