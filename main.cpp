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
    for (size_t i = 0; i < 4; i++) {
        cout << student.notes[i] << ", ";
    }
    cout << "]" << endl;
    cout << "Średnia: " << student.average << endl;
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

int main() {
    srand(time(NULL));
    int studentsNumber;
    cout << "Liczba studentów:";
    cin >> studentsNumber;

    Student students[studentsNumber];
    for (size_t i = 0; i < studentsNumber; i++) {
        cout << "Wprowadź nazwisko studenta: ";
        cin >> students[i].surname;

        for (size_t j = 0; j < 4; j++) {
            students[i].notes[j] = getRandomNote();
        }

        students[i].average = average(students[i].notes, 4);

        printStudent(students[i]);
    }

    return 0;
}