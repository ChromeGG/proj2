// Adam Tkaczyk [D3], Piotr Pakulski [D2]
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

void printAllStudents(Student students[], size_t size, double avgAll) {
    if (avgAll > 0 ) {
        cout << "Serdnia wszystkich studentow: " << avgAll << ", studenci z wyzsza niz srednia wszystkich: " << endl;
    }
    for (size_t i = 0; i < size; i++) {
        if (students[i].average > avgAll) {
            cout << endl;
            printStudent(students[i]);
        }
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

void printHigehstAvg(Student students[], size_t size) {
    double higest{0};
    size_t theKey;
    for (size_t i = 0; i < size; i++) {
        if (students[i].average > higest) {
            higest = students[i].average;
            theKey = i;
        }
    }
    cout << "Student z najwyzsza srednia to: " << endl;
    printStudent(students[theKey]);
}

void printStudentBySurname(Student students[], size_t size) {
    string surname;

    cout << "Podaj nazwisko studenta ktorego szukasz:" << endl;
    cin >> surname;
    for (size_t i = 0; i < size; i++) {
        if (students[i].surname == surname) {
            printStudent(students[i]);
            break;
        }
    }

}

void printMenu() {
    cout << endl;
    cout << "1. Pokaz liste wszystkich studentow" << endl;
    cout << "2. Pokaz liste studentów powyzej sredniej wszystkich" << endl;
    cout << "3. Pokaz studenta o najwyzszej sredniej" << endl;
    cout << "4. Pokaz studenta o podanym nazwisku" << endl;
    cout << "0. Wyjscie" << endl;
}

int main() {
    srand(time(NULL));
    int studentsNumber, choice;
    double avgAll{0};
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
        avgAll += students[i].average;
    }
    avgAll = avgAll / (double)studentsNumber;

    while (!exit) {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            printAllStudents(students, studentsNumber, 0);
            break;
        case 2:
            printAllStudents(students, studentsNumber, avgAll);
            break;
        case 3:
            printHigehstAvg(students, studentsNumber);
            break;
        case 4:
            printStudentBySurname(students, studentsNumber);
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
