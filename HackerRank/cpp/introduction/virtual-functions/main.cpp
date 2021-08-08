// https://www.hackerrank.com/challenges/virtual-functions/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
    virtual void getdata(){};
    virtual void putdata(){};
    string name;
    int age;
};

class Professor : public Person {
public:
    Professor() {
        cur_id = next_id++;
    }

    void getdata() {
        cin >> name >> age >> publications;
    }

    void putdata() {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }

private:
    int publications;
    int cur_id;
    static int next_id;
};

class Student : public Person {
public:
    Student() {
        cur_id = next_id++;
    }

    void getdata() {
        cin >> name >> age;
        for(int i = 0; i < 6; ++i) {
            int tmp;
            cin >> tmp;
            marks[i] = tmp;
        }
    }

    void putdata() {
        int sum = 0;
        for(auto const i : marks) {
            sum += i;
        }
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }

private:
    int marks[6];
    int cur_id;
    static int next_id;
};

int Professor::next_id = 1;
int Student::next_id = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
