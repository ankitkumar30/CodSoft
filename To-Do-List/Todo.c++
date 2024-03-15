#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
 * size_t is a data type in C++ that represents the size of objects in memory. 
 * It's an unsigned integer type, which means it can only hold non-negative values.
 * The size of size_t is implementation-defined, 
 * but it's commonly used for representing sizes of arrays, memory allocations, and indices of collections. 
 * It's guaranteed to be able to represent the maximum size of any object on the particular platform.
*/
struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
        cout << "Task added successfully!" << endl;
    }

    void viewTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[Completed] ";
            cout << tasks[i].description <<endl;
        }
    }

    void markAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main() {
    ToDoList todoList;
    char choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();
                getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case '2':
                todoList.viewTasks();
                break;
            case '3': {
                size_t index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todoList.markAsCompleted(index);
                break;
            }
            case '4': {
                size_t index;
                cout << "Enter task index to remove: ";
                cin >> index;
                todoList.removeTask(index);
                break;
            }
            case '5':
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
