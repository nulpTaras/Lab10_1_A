#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

#pragma region enums
enum Majors { RI = 1, IK, PZ, AI, KN, SA };
#pragma endregion enums

#pragma region student_struct
#pragma pack(push, 1)
struct Student {
    string return_prizv() {
        return this->prizv;
    }
    unsigned short return_course() {
        return this->course;
    }
    string return_major() {
        switch (this->major) {
        case RI:
            return "RI";
        case IK:
            return "IK";
        case PZ:
            return "PZ";
        case AI:
            return "AI";
        case KN:
            return "KN";
        case SA:
            return "SA";
        }
    }
    unsigned short return_physics() {
        return this->physics;
    }
    unsigned short return_math() {
        return this->math;
    }
    unsigned short return_it() {
        return this->it;
    }
    void fill_class(int i) {
        int temp;
        cout << "Студент №" << i + 1 << endl;
        cout << "Прізвище: "; cin >> this->prizv;
        cout << "Курс: "; cin >> this->course;
        cout << "Спеціальність (RI=1, IK=2, PZ=3, AI=4, KN=5, SA=6): "; cin >> temp;
        this->major = (Majors)temp;
        cout << "Оцінка з фізики: "; cin >> this->physics;
        cout << "Оцінка з математики: "; cin >> this->math;
        cout << "Оцінка з інформатики: "; cin >> this->it;
    }
private:
    string prizv;
    unsigned short course;
    Majors major;
    unsigned short physics;
    unsigned short math;
    unsigned short it;
};
#pragma pack(pop)
#pragma endregion student_struct

#pragma region functions
void fill_arr(Student* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = Student();
        arr[i].fill_class(i);
        cout << endl;
    }
}

void print_students_without_triples(Student* arr, int n) {
    cout << "Студенти без трійок (на \"відмінно\" і \"добре\"):" << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i].return_physics() >= 4 &&
            arr[i].return_math() >= 4 &&
            arr[i].return_it() >= 4) {
            cout << arr[i].return_prizv() << endl;
        }
    }
}

int count_students_with_5_in_physics(Student* arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].return_physics() == 5) {
            count++;
        }
    }
    return count;
}
#pragma endregion functions

int main()
{
    int n;
    cout << "Введіть кількість студентів: "; cin >> n;

    Student* arr = new Student[n];
    fill_arr(arr, n);

    print_students_without_triples(arr, n);

    cout << "Кількість студентів, які отримали 5 з фізики: "
         << count_students_with_5_in_physics(arr, n) << endl;

    delete[] arr;
}
