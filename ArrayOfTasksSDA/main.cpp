#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// ��������� ������
struct Task {
    string title;
    string date;
};

// ��������� � �������� �����
struct TaskManager {
    vector<Task> tasks;
};

// ������� ��� �������� ������
void createTask(TaskManager& manager, const string& title, const string& date)
{
    Task newTask = { title, date };
    manager.tasks.push_back(newTask);
}

// ������� ��� �������������� ������
void editTask(TaskManager& manager, size_t index, const string& newTitle, const string& newDate)
{
    if (index >= manager.tasks.size())
    {
        cerr << "�������� ������ ������." << endl;
        return;
    }
    manager.tasks[index].title = newTitle;
    manager.tasks[index].date = newDate;
}

// ������� ��� ������ ���� �����
void printTasks(const TaskManager& manager)
{
    for (size_t i = 0; i < manager.tasks.size(); ++i) {
        cout << "������ " << i + 1 << ": " << manager.tasks[i].title << ", ������: " << manager.tasks[i].date << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TaskManager manager;

    // �������� �����
    createTask(manager, "��������� ������", "2024-07-01");
    createTask(manager, "������ ��������", "2024-06-20");

    cout << "������ ����� ��������:" << endl;
    printTasks(manager);

    // �������������� ������ ������
    editTask(manager, 0, "����������� ������", "2024-07-05");

    cout << "������ ����� ��������������:" << endl;
    printTasks(manager);

    return 0;
}