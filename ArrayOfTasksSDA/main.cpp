#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// Структура задачи
struct Task {
    string title;
    string date;
};

// Структура с массивом задач
struct TaskManager {
    vector<Task> tasks;
};

// Функция для создания задачи
void createTask(TaskManager& manager, const string& title, const string& date)
{
    Task newTask = { title, date };
    manager.tasks.push_back(newTask);
}

// Функция для редактирования задачи
void editTask(TaskManager& manager, size_t index, const string& newTitle, const string& newDate)
{
    if (index >= manager.tasks.size())
    {
        cerr << "Неверный индекс задачи." << endl;
        return;
    }
    manager.tasks[index].title = newTitle;
    manager.tasks[index].date = newDate;
}

// Функция для вывода всех задач
void printTasks(const TaskManager& manager)
{
    for (size_t i = 0; i < manager.tasks.size(); ++i) {
        cout << "Задача " << i + 1 << ": " << manager.tasks[i].title << ", Данные: " << manager.tasks[i].date << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TaskManager manager;

    // Создание задач
    createTask(manager, "Завершить проект", "2024-07-01");
    createTask(manager, "Купить продукты", "2024-06-20");

    cout << "Задачи после создания:" << endl;
    printTasks(manager);

    // Редактирование первой задачи
    editTask(manager, 0, "Завершенный проект", "2024-07-05");

    cout << "Задачи после редактирования:" << endl;
    printTasks(manager);

    return 0;
}