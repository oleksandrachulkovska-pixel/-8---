#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// ========================================
// БАЗОВИЙ КЛАС MAN
// ========================================

class Man
{
protected:
    string name;
    int age;
    string gender;
    double weight;

public:
    // Конструктор класу Man
    Man(string n, int a, string g, double w)
        : name(n), age(a), gender(g), weight(w)
    {
    }

    // Метод зміни імені
    void setName(const string& newName)
    {
        name = newName;
    }

    // Метод зміни віку
    void setAge(int newAge)
    {
        if (newAge >= 0)
            age = newAge;
        else
            cout << "Некоректний вік." << endl;
    }

    // Метод зміни ваги
    void setWeight(double newWeight)
    {
        if (newWeight > 0)
            weight = newWeight;
        else
            cout << "Некоректна вага." << endl;
    }

    // Метод виведення інформації
    virtual void display() const
    {
        cout << "Ім'я: " << name << endl;
        cout << "Вік: " << age << endl;
        cout << "Стать: " << gender << endl;
        cout << "Вага: " << weight << " кг" << endl;
    }

    // Віртуальний деструктор
    virtual ~Man() = default;
};


// ========================================
// ПОХІДНИЙ КЛАС STUDENT
// ========================================

class Student : public Man
{
private:
    int studyYear;

public:
    // Конструктор класу Student
    Student(string n, int a, string g,
        double w, int year)
        : Man(n, a, g, w), studyYear(year)
    {
    }

    // Метод зміни року навчання
    void setStudyYear(int newYear)
    {
        if (newYear > 0)
            studyYear = newYear;
        else
            cout << "Некоректний рік навчання." << endl;
    }

    // Метод збільшення року навчання
    void increaseStudyYear()
    {
        studyYear++;
    }

    // Перевизначення методу display()
    void display() const override
    {
        Man::display();

        cout << "Рік навчання: "
            << studyYear << endl;
    }
};


// ========================================
// ФУНКЦІЯ ОТРИМАННЯ ТА ПОВЕРНЕННЯ MAN
// ========================================

Man processMan(const Man& person)
{
    Man result = person;

    result.setName("Оновлене ім'я");

    return result;
}


// ========================================
// ДЕМОНСТРАЦІЯ ПРИНЦИПУ ПІДСТАНОВКИ
// ========================================

void showPerson(const Man& person)
{
    person.display();
}


// ========================================
// ГОЛОВНА ФУНКЦІЯ MAIN
// ========================================

int main()
{
    setlocale(LC_ALL, "");

    // Робота з базовим класом Man
    cout << "===== БАЗОВИЙ КЛАС MAN =====" << endl;

    Man man("Олександр", 25, "Чоловіча", 75.5);

    cout << "\nПочаткові дані:" << endl;
    man.display();

    man.setName("Андрій");
    man.setAge(26);
    man.setWeight(78.0);

    cout << "\nПісля зміни даних:" << endl;
    man.display();


    // Робота з похідним класом Student
    cout << "\n===== ПОХІДНИЙ КЛАС STUDENT =====" << endl;

    Student student("Марія", 19, "Жіноча", 58.0, 2);

    cout << "\nПочаткові дані студента:" << endl;
    student.display();

    student.setName("Олена");
    student.setAge(20);
    student.setWeight(60.0);
    student.setStudyYear(3);

    cout << "\nПісля зміни даних:" << endl;
    student.display();

    student.increaseStudyYear();

    cout << "\nПісля збільшення року навчання:" << endl;
    student.display();


    // Демонстрація принципу підстановки
    cout << "\n===== ПРИНЦИП ПІДСТАНОВКИ =====" << endl;

    cout << "\nПередаємо Student у функцію showPerson:" << endl;
    showPerson(student);


    // Виклик функції processMan()
    cout << "\nФункція отримує та повертає об'єкт Man:" << endl;

    Man updatedMan = processMan(student);
    updatedMan.display();


    cout << "\nПрограму завершено." << endl;

    return 0;
}