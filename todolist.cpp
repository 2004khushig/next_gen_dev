#include<iostream>
#include<vector>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

void displayMenu(){
    cout << "******************** TO DO LIST **************************\n";
    cout << "1. Add Task \n";
    cout << "2. Remove Task \n";
    cout << "3. View Tasks \n";
    cout << "4. Mark Task as Completed \n";
    cout << "5. Exit \n";
    cout << "Enter your choice: ";
}

void addTask(vector<Task> &tasks){
    string description;
    cout << "Enter task description: ";
    getline(cin, description);
    tasks.push_back(Task(description));
    cout << "Task added successfully.\n";
}

void removeTask(vector<Task> &tasks){
    if(tasks.empty()){
        cout << "Task list is empty!\n";
        return;
    }
    int num;
    cout << "Enter index to remove (1-" << tasks.size() << "): ";
    cin >> num;
    cin.ignore(); 
    if(num >= 1 && num <= tasks.size()){
        tasks.erase(tasks.begin() + num - 1);
        cout << "Task removed successfully.\n";
    }
    else{
        cout << "Invalid task number.\n";
    }
}

void viewTasks(const vector<Task> &tasks){
    if(tasks.empty()){
        cout << "Task list is empty.\n";
    }
    else{
        cout << "************************ TASK STATUS *************************\n";
        for(size_t i = 0; i < tasks.size(); ++i){
            cout << i+1 << ". ";
            if(tasks[i].completed)
                cout << "[COMPLETED] ";
            else
                cout << "[PENDING] ";
            cout << tasks[i].description << endl;
        }
    }
}

void markTaskCompleted(vector<Task> &tasks){
    if(tasks.empty()){
        cout << "Task list is empty.\n";
        return;
    }
    int num;
    cout << "Enter index of the task to mark as completed (1-" << tasks.size() << "): ";
    cin >> num;
    cin.ignore(); 
    if(num >= 1 && num <= tasks.size()){
        tasks[num - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
    else{
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
    char choice;

   do {
    displayMenu();
    cin >> choice;
    cin.ignore(); 

    switch(choice) {
        case '1':
            addTask(tasks);
            break;
        case '2':
            removeTask(tasks);
            break;
        case '3':
            viewTasks(tasks);
            break;
        case '4':
            markTaskCompleted(tasks);
            break;
        case '5':
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
    }
} while(choice != '5');

}
