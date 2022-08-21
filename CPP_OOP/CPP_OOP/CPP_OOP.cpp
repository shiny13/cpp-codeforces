// CPP_OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cctype>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::isalpha;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
private:
    string Name;
    string Company;
    int Age;

    bool CheckAlphabet(string word)
    {
        bool checker = true;
        for (int i = 0; i < word.length(); i++) {
            if (!isalpha(word[i])) {
                checker = false;
                break;
            }
        }

        return checker;
    }

public:
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    void setName(string name) {
        if (!CheckAlphabet(name)) {
            cout << "Unable to set invalid name: " << name << endl;
            return;
        }

        Name = name;
    }

    string getName() {
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }

    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        if (age >= 18) {
            Age = age;
            cout << "Age is set to " << age << "." << endl;
        }
        else {
            cout << "Age less than 18 is invalid." << endl;
        }
    }

    int getAge() {
        return Age;
    }

    void IntroduceYourself() {
        cout << "Name: " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age: " << Age << endl;
    }

    void AskForPromotion() {
        if (Age > 30) {
            cout << Name << " has been promoted." << endl;
        }
        else {
            cout << Name << " is too young for a promotion." << endl;
        }
    }

    virtual void Work() {
        cout << Name << " is checking emails, task backlogs, and performs those tasks." << endl;
    }
};

class Developer : public Employee {
public:
    string FavouriteProgrammingLanguage;

    Developer(string name, string company, int age, string favouriteProgrammingLanguage)
        : Employee(name, company, age) {
        FavouriteProgrammingLanguage = favouriteProgrammingLanguage;
    }

    void FixBug() {
        cout << getName() << " fixes bugs using " << FavouriteProgrammingLanguage << "." << endl;
    }

    void Work() {
        cout << getName() << " writes code in " << FavouriteProgrammingLanguage << endl;
    }
};

class Teacher : public Employee {
public:
    string Subject;

    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age) {
        Subject = subject;
    }

    void PrepareLesson() {
        cout << getName() << " is preparing a lesson for " << Subject << "." << endl;
    }

    void Work() {
        cout << getName() << " teaches " << Subject << " class." << endl;
    }
};

int main()
{
    Employee emp1 = Employee("Shahnawaz Alam", "ABC", 34);
    /*emp1.Name = "Shahnawaz Alam";
    emp1.Company = "ABC";
    emp1.Age = 34;*/
    Employee emp2 = Employee("James Cook", "ABC", 22);

    emp1.IntroduceYourself();
    emp1.setAge(12);
    emp1.setName("code-forces");
    emp1.setAge(30);
    cout << emp1.getName() << " is " << emp1.getAge() << " years old." << endl;

    emp2.IntroduceYourself();
    emp2.Work();
    emp2.AskForPromotion();

    Developer dev = Developer("Saldina", "ABC", 28, "C++");
    dev.IntroduceYourself();
    dev.FixBug();
    dev.Work();
    dev.AskForPromotion();

    Teacher teacher = Teacher("James Maddison", "ABC", 28, "Maths");
    teacher.IntroduceYourself();
    teacher.PrepareLesson();
    teacher.Work();
    teacher.AskForPromotion();

    Employee* e1 = &dev;
    Employee* e2 = &teacher;

    cout << "************************************************************" << endl;
    e1->Work();
    e2->Work();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
