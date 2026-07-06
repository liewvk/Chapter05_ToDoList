#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

struct Task
{
    int id;
    std::string description;
    std::string priority;
    bool completed;
};

void displayMenu()
{
    std::cout << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "          To-Do List App" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Display All Tasks" << std::endl;
    std::cout << "3. Display Pending Tasks" << std::endl;
    std::cout << "4. Display Completed Tasks" << std::endl;
    std::cout << "5. Mark Task as Completed" << std::endl;
    std::cout << "6. Update Task" << std::endl;
    std::cout << "7. Delete Task" << std::endl;
    std::cout << "8. Save Tasks to File" << std::endl;
    std::cout << "9. Load Tasks from File" << std::endl;
    std::cout << "10. Exit" << std::endl;
    std::cout << "Please choose an option: ";
}

int generateTaskId(const std::vector<Task>& tasks)
{
    int maxId = 0;

    for (const Task& task : tasks)
    {
        if (task.id > maxId)
        {
            maxId = task.id;
        }
    }

    return maxId + 1;
}

void addTask(std::vector<Task>& tasks)
{
    Task newTask;

    newTask.id = generateTaskId(tasks);

    std::cout << "Enter task description: ";
    std::getline(std::cin, newTask.description);

    std::cout << "Enter priority (Low, Medium, High): ";
    std::getline(std::cin, newTask.priority);

    newTask.completed = false;

    tasks.push_back(newTask);

    std::cout << "Task added successfully." << std::endl;
}

void displayTask(const Task& task)
{
    std::cout << "Task ID    : " << task.id << std::endl;
    std::cout << "Description: " << task.description << std::endl;
    std::cout << "Priority   : " << task.priority << std::endl;
    std::cout << "Status     : " << (task.completed ? "Completed" : "Pending") << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

void displayAllTasks(const std::vector<Task>& tasks)
{
    if (tasks.empty())
    {
        std::cout << "No tasks found." << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "========== All Tasks ==========" << std::endl;

    for (const Task& task : tasks)
    {
        displayTask(task);
    }
}

void displayPendingTasks(const std::vector<Task>& tasks)
{
    bool found = false;

    std::cout << std::endl;
    std::cout << "========== Pending Tasks ==========" << std::endl;

    for (const Task& task : tasks)
    {
        if (!task.completed)
        {
            displayTask(task);
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No pending tasks found." << std::endl;
    }
}

void displayCompletedTasks(const std::vector<Task>& tasks)
{
    bool found = false;

    std::cout << std::endl;
    std::cout << "========== Completed Tasks ==========" << std::endl;

    for (const Task& task : tasks)
    {
        if (task.completed)
        {
            displayTask(task);
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No completed tasks found." << std::endl;
    }
}

int findTaskIndexById(const std::vector<Task>& tasks, int id)
{
    for (int i = 0; i < static_cast<int>(tasks.size()); ++i)
    {
        if (tasks[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

void markTaskCompleted(std::vector<Task>& tasks)
{
    int id;

    std::cout << "Enter task ID to mark as completed: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int index = findTaskIndexById(tasks, id);

    if (index == -1)
    {
        std::cout << "Task not found." << std::endl;
        return;
    }

    tasks[index].completed = true;

    std::cout << "Task marked as completed." << std::endl;
}

void updateTask(std::vector<Task>& tasks)
{
    int id;

    std::cout << "Enter task ID to update: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int index = findTaskIndexById(tasks, id);

    if (index == -1)
    {
        std::cout << "Task not found." << std::endl;
        return;
    }

    std::cout << "Enter new task description: ";
    std::getline(std::cin, tasks[index].description);

    std::cout << "Enter new priority (Low, Medium, High): ";
    std::getline(std::cin, tasks[index].priority);

    std::cout << "Task updated successfully." << std::endl;
}

void deleteTask(std::vector<Task>& tasks)
{
    int id;

    std::cout << "Enter task ID to delete: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int index = findTaskIndexById(tasks, id);

    if (index == -1)
    {
        std::cout << "Task not found." << std::endl;
        return;
    }

    tasks.erase(tasks.begin() + index);

    std::cout << "Task deleted successfully." << std::endl;
}

void saveTasksToFile(const std::vector<Task>& tasks, const std::string& filename)
{
    std::ofstream file(filename);

    if (!file)
    {
        std::cout << "Error: Could not open file for writing." << std::endl;
        return;
    }

    for (const Task& task : tasks)
    {
        file << task.id << "|"
            << task.description << "|"
            << task.priority << "|"
            << task.completed << std::endl;
    }

    file.close();

    std::cout << "Tasks saved successfully." << std::endl;
}

void loadTasksFromFile(std::vector<Task>& tasks, const std::string& filename)
{
    std::ifstream file(filename);

    if (!file)
    {
        std::cout << "No existing task file found. Starting with an empty task list." << std::endl;
        return;
    }

    tasks.clear();

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string idText;
        std::string completedText;
        Task task;

        std::getline(ss, idText, '|');
        std::getline(ss, task.description, '|');
        std::getline(ss, task.priority, '|');
        std::getline(ss, completedText, '|');

        task.id = std::stoi(idText);
        task.completed = (completedText == "1");

        tasks.push_back(task);
    }

    file.close();

    std::cout << "Tasks loaded successfully." << std::endl;
}

int main()
{
    std::vector<Task> tasks;
    const std::string filename = "data/tasks.txt";
    int choice;

    loadTasksFromFile(tasks, filename);

    while (true)
    {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            addTask(tasks);
            break;

        case 2:
            displayAllTasks(tasks);
            break;

        case 3:
            displayPendingTasks(tasks);
            break;

        case 4:
            displayCompletedTasks(tasks);
            break;

        case 5:
            markTaskCompleted(tasks);
            break;

        case 6:
            updateTask(tasks);
            break;

        case 7:
            deleteTask(tasks);
            break;

        case 8:
            saveTasksToFile(tasks, filename);
            break;

        case 9:
            loadTasksFromFile(tasks, filename);
            break;

        case 10:
            saveTasksToFile(tasks, filename);
            std::cout << "Thank you for using the To-Do List App." << std::endl;
            return 0;

        default:
            std::cout << "Invalid option. Please choose again." << std::endl;
        }
    }
}
