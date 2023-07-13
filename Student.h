#include "header.cpp"

class Student{
    char name[51];
    char id[21];
    char grade[21];
    char specialty[21];

public:
    // constructors
    // declaration and do not data transmission 
    Student(){
        name[0] = '\0';
        id[0] = '\0';
        grade[0] = '\0';
        specialty[0] = '\0';
    }

    // declaration 
    Student(const char* &name, const char* &id, const char* &grade, const char* &specialty){
        :name(name), id(id), grade(grade), specialty(specialty) {}
    }

    // declaration each element (Setter)
    void setName(const char* &newName){
        strncpy(name, newName, 50);
        name[50] = '\0';
    }
    void setID(const char* &newID){
        strncpy(id, newID, 50);
        id[20] = '\0';
    }
    void setgrade(const char* &newGrade){
        strncpy(grade, newGrade, 50);
        grade[20] = '\0';
    }
    void setSpecialty(const char* &newSpecialty){
        strncpy(specialty, newSpecialty, 50);
        specialty[20] = '\0';
    }

    // get vaue (getter)
    const char* getName() const { return name;}
    const char* getID() const { return id;}
    const char* getGrade() const { return getGrade;}
    const char* getSpecialty() const { return Specialty;}




};