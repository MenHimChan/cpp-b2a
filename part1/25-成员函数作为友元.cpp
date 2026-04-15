#include <iostream>
#include <string>

using namespace std;

class Patient;

/******************* 声明 *******************/
class Doctor {
public:
    // 未声明为友元的函数不允许使用Patient类的私有成员
    void greet(const Patient& patient);
    void analyzeDNA(const Patient& patient);
};

class Patient {
    friend void Doctor::analyzeDNA(const Patient& patient);
private: 
    int m_age;
    string m_DNACode;

public:
    Patient(string DNACode, int age);
};

/******************* 实现 *******************/
void Doctor::greet(const Patient& patient) {
        // cout << "patient age is : " << patient.m_age << endl; // error: 'int Patient::m_age' is private within this context 
        cout << "Greeting the Patient ! " << endl;
    }

void Doctor::analyzeDNA(const Patient& patient){
    cout << "The Patient DNA Code is : " << patient.m_DNACode << endl;
}

Patient::Patient(string DNACode, int age) : m_age(age), m_DNACode(DNACode) {

}

int main() {
    Patient patient("AGCTAGCTAGCTAGCT", 30);
    Doctor doctor;
    doctor.greet(patient);
    doctor.analyzeDNA(patient);

    return 0;
}