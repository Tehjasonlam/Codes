#include "student.h"

student & student::operator = (const student & RHS)
{
    if (this != &RHS)
    {
        name = RHS.name;
        id = RHS.id;
        ngrades = RHS.ngrades;
        if (grades!= nullptr)
            delete[] grades;
        grades = new int [ngrades];
        for (int i=0;i<ngrades;i++)
            grades[i] = RHS.grades[i];
    }
    return *this;
}

#include "intVector.h"

intVector operator * (int value, const intVector &RHS)
{
    intVector result;
    result.nElements = RHS.nElements;
    for (int i=0;i<result.nElements;i++)
        result.values[i] = value * RHS.values[i];
    return result;
}


appointment::appointment(const custumDate & _date, const string & _description): date(_date),description(_description)
{

}