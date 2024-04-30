#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <vector>
#include <string>

struct Task {
    int id;
    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;
    int nextId;

public:
    ToDoList();
    void addTask(const std::string& description);
    void markCompleted(int taskId);
    void viewTasks() const;
};

#endif

