// https://www.hackerrank.com/challenges/c-tutorial-class
#include <iostream>
#include <sstream>
using namespace std;

class Student {
private:
    int i_age;
    string s_first;
    string s_last;
    int i_standard;

public:
    void set_age(int in_int) { i_age = in_int; }
    void set_standard(int in_int) { i_standard = in_int; }
    void set_first_name(string in_string) { s_first = in_string; }
    void set_last_name(string in_string) { s_last = in_string; }

    int get_age() { return i_age; }
    int get_standard() { return i_standard; }
    string get_first_name() { return s_first; }
    string get_last_name( ){ return s_last; }

    string to_string(){
        stringstream ss_age;
        stringstream ss_standard;
        ss_age << i_age;
        ss_standard << i_standard;
        
        return ss_age.str() + "," + s_first + "," + s_last + "," + ss_standard.str();
    }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
