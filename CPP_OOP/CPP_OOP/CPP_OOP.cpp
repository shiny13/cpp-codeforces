// CPP_OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cctype>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::isalpha;

class Employee {
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
};

int main()
{
    Employee emp1 = Employee("Shahnawaz Alam", "ABC", 34);
    /*emp1.Name = "Shahnawaz Alam";
    emp1.Company = "ABC";
    emp1.Age = 34;*/

    emp1.IntroduceYourself();

    emp1.setAge(12);
    emp1.setName("code-forces");
    emp1.setAge(30);
    cout << emp1.getName() << " is " << emp1.getAge() << " years old." << endl;
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
