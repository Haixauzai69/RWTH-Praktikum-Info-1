//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe(std::ostream& ausgabe) const;
// alle 3 sortiert nach MatNr
    bool operator==(const Student& comp);
    bool operator>(const Student& comp);
    bool operator<(const Student& comp);
private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

std::ostream& operator<<(std::ostream& out, const Student& student);

#endif
