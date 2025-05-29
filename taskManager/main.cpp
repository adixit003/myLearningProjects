/*As a user, you should be able to :
Add a task.
Edit a task.
List tasks.
Search for a task.
Mark a task as completed.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct task {
    int id;
    string taskName;
    string description;
    bool isCompleted;

    task(int id, const string &taskName, const string &description)
        : id(id), taskName(taskName), description(description), isCompleted(false) {
    }
};

class taskManager {
private:
    vector<task> subtasks;
    int nextId{ 1 }; // To keep track of the next task ID

    task* findTaskById(int id)
    {
        for (auto& t : subtasks)
        {
            if (t.id == id)
                return &t;
        }
        return nullptr; // Return nullptr if task not found
    }
public:
    void addTask(const string& taskName, const string& description);
    void editTask(int id, const string& taskName, const string& description);
    void listTasks() const;
    void searchTask(const string& keyword) const;
    void markTaskAsCompleted(int id);
};

void taskManager::addTask(const string& taskName, const string& description)
{
    subtasks.emplace_back(nextId++, taskName, description);
    cout << "task added successfuly\n" << endl;
}

void taskManager::editTask(int id, const string& newTaskName, const string& newDescription)
{
    task* t = findTaskById(id);
    if (t)
    {
        t->taskName = newTaskName;
        t->description = newDescription;
        cout << "Task updated successfuly!\n" << endl;
    }
    else
        cout << "Task not found!\n" << endl;
}

void taskManager::listTasks() const
{
    if (subtasks.empty())
        cout << "No task avaliable!\n" << endl;
    else
    {
        for (auto& task : subtasks)
        {
            cout << "id: " << task.id << endl
                << "task name: " << task.taskName << endl
                << "task description: \n" << task.description << endl;
        }
    }
}

void taskManager::searchTask(const string& keyword) const
{
    bool found = false;
    for (auto& task : subtasks)
    {
        if ((task.description.find(keyword) != string::npos) || (task.taskName.find(keyword) != string::npos))
        {
            cout << "id: " << task.id << endl
                << "task name: " << task.taskName << endl
                << "task description: " << task.description << endl
                << "task status: \n" << (task.isCompleted ? "task completed" : "task not completed") << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Task not found!\n" << endl;
    }
}

void taskManager::markTaskAsCompleted(int id)
{
    task* t = findTaskById(id);
    if (t)
    {
        t->isCompleted = true;
        cout << "Task marked as completed!\n" << endl;
    }
    else
        cout << "Task not found!\n" << endl;
}

int main()
{
    taskManager manager;
    int choose = 0;
    do
    {
        cout << "Select an option:" << endl;
        cout << "1. Add an task" << endl;
        cout << "2. Edit an task" << endl;
        cout << "3. List all the task" << endl;
        cout << "4. Search task" << endl;
        cout << "5. Mark task as completed" << endl;
        cin >> choose;
        cin.ignore();

        switch (choose)
        {
           case 1:
           {
              string name, description;
              cout << "Enter task name: " << endl;
              getline(cin, name);
              cout << "Enter task description: " << endl;
              getline(cin, description);
              manager.addTask(name, description);
              break;
           }
           case 2:
           {
               int id { 0 };
               string name, description;
               cout << "ENter task id: " << endl;
               cin >> id;
               cin.ignore();
               cout << "Enter new task name: " << endl;
               getline(cin, name);
               cout << "Enter new task description: " << endl;
               getline(cin, description);
               manager.editTask(id, name, description);
               break;
           }
           case 3:
           {
               manager.listTasks();
               break;
           }
           case 4:
           {
               string keyword;
               cout << "Enter the keyword which want to search: " << endl;
               getline(cin, keyword);
               manager.searchTask(keyword);
               break;
           }
           case 5:
           {
               int id {0};
               cout << "Enter task id to mark as completed: " << endl; 
               cin >> id;
               cin.ignore();
               manager.markTaskAsCompleted(id);
               break;
           }
           case 0:
           {
               cout << "Exiting from task manager!\n" << endl;
               break;
           }
           default:
           {
               cout << "Invaid option!\n" << endl;
               break;
           }
        }
    } while (choose != 0);
    return 0;
}