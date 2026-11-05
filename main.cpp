#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Expense {
    string name;
    string category;
    double amount;
};

vector<Expense> expenses;

void addExpense() {
    Expense e;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter expense name: ";
    getline(cin, e.name);

    cout << "Enter category: ";
    getline(cin, e.category);

    cout << "Enter amount: ";

    if (!(cin >> e.amount) || e.amount <= 0) {
        cout << "Invalid amount! Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    expenses.push_back(e);
    cout << "Expense added successfully!\n";
}

void listExpenses() {
    if (expenses.empty()) {
        cout << "No expenses recorded.\n";
        return;
    }

    cout << "\n--- Expense List ---\n";

    for (int i = 0; i < expenses.size(); i++) {
        cout << i + 1 << ". "
             << expenses[i].name << " | "
             << expenses[i].category << " | Rs. "
             << fixed << setprecision(2)
             << expenses[i].amount << endl;
    }
}

void categoryTotal() {
    string category;
    double total = 0;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter category: ";
    getline(cin, category);

    for (const auto& e : expenses) {
        if (e.category == category) {
            total += e.amount;
        }
    }

    cout << "Category total: Rs. "
         << fixed << setprecision(2) << total << endl;
}

void overallTotal() {
    double total = 0;

    for (const auto& e : expenses) {
        total += e.amount;
    }

    cout << "Overall expense: Rs. "
         << fixed << setprecision(2) << total << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. List Expenses\n";
        cout << "3. Category Total\n";
        cout << "4. Overall Total\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: addExpense(); break;
            case 2: listExpenses(); break;
            case 3: categoryTotal(); break;
            case 4: overallTotal(); break;
            case 5: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}