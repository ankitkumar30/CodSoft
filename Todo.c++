#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back({description, false});
        std::cout << "Task added successfully!" << std::endl;
    }

    void viewTasks() {
        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (tasks[i].completed)
                std::cout << "[Completed] ";
            std::cout << tasks[i].description << std::endl;
        }
    }

    void markAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed!" << std::endl;
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task removed successfully!" << std::endl;
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }
};

int main() {
    ToDoList todoList;
    char choice;

    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case '2':
                todoList.viewTasks();
                break;
            case '3': {
                size_t index;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                todoList.markAsCompleted(index);
                break;
            }
            case '4': {
                size_t index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                todoList.removeTask(index);
                break;
            }
            case '5':
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '5');

    return 0;
}
