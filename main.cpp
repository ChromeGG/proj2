// Adam Tkaczyk [D3], Piotr Pakulski [D3]
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;
struct Student {
    string surname;
    double notes[5];
    double average;
};

void printStudent(Student student) {
    cout << "Nazwisko: " << student.surname << endl;
    cout << "Oceny: [";
    for (size_t i = 0; i < 5; i++) {
        cout << student.notes[i] << ", ";
    }
    cout << "]" << endl;
    cout << "Srednia: " << student.average << endl;
}

void printAllStudents(Student students[], size_t size) {

    for (size_t i = 0; i < size; i++) {
        cout << endl;
        printStudent(students[i]);
    }
}

double getRandomNote() {
    int note;

    do {
        note = rand() % (50 + 1 - 20) + 20;
    } while (note % 5 != 0);
    return (double)note / 10;
}

double average(double numbers[], int size) {
    double sum = 0.0;
    for (size_t i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

void printMenu() {
    cout << endl;
    cout << "1. Pokaz liste wszystkich studentow" << endl;
    cout << "2. Pokaz liste studentów powyzej sredniej" << endl;
    cout << "3. Pokaz studenta o najwyzszej sredniej" << endl;
    cout << "4. Pokaz studenta o podanym nazwisku" << endl;
    cout << "0. Wyjscie" << endl;
}

int main() {
    srand(time(NULL));
    int studentsNumber, choice;
    bool exit;
    cout << "Liczba studentów:";
    cin >> studentsNumber;

    Student students[studentsNumber];
    for (size_t i = 0; i < studentsNumber; i++) {
        cout << "Wprowadź nazwisko studenta: ";
        cin >> students[i].surname;

        for (size_t j = 0; j < 5; j++) {
            students[i].notes[j] = getRandomNote();
        }

        students[i].average = average(students[i].notes, 5);
    }

    while (!exit) {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            printAllStudents(students, studentsNumber);
            break;
        case 2:
            /* TODO */
            break;
        case 3:
            /* TODO */
            break;
        case 4:
            /* TODO */
            break;
        case 0:
            exit = true;
            break;

        default:
            cout << "Zly wybor, sproboj ponownie" << endl;
            break;
        }
    }

    return 0;
}