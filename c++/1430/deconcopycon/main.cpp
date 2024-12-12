#include <iostream>
using namespace std;

class MyClass {
public:
   MyClass();
   MyClass(const MyClass& origObject); // Copy constructor
   ~MyClass();
   
   // Set member value dataObject
   void SetDataObject(const int setVal) {
      *dataObject = setVal;
   }
   
   // Return member value dataObject
   int GetDataObject() const {
      return *dataObject;
   }
private:
   int* dataObject;// Data member
};

// Default constructor
MyClass::MyClass() {
   cout << "Constructor called." << endl;
   dataObject = new int; // Allocate mem for data
   *dataObject = 0;
}

// Copy constructor
MyClass::MyClass(const MyClass& origObject) {
   cout << "Copy constructor called." << endl;
   dataObject = new int; // Allocate sub-object
   *dataObject = *(origObject.dataObject);
}

// Destructor
MyClass::~MyClass() {
   cout << "Destructor called." << endl;
   delete dataObject;
}

void SomeFunction(MyClass localObj) {
   // Do something with localObj
}

int main() {
   MyClass tempClassObject; // Create object of type MyClass
   
   // Set and print data member value
   tempClassObject.SetDataObject(9);
   cout << "Before: " << tempClassObject.GetDataObject() << endl;
   
   // Calls SomeFunction(), tempClassObject is passed by value
   SomeFunction(tempClassObject);
   
   // Print data member value
   cout << "After: " << tempClassObject.GetDataObject() << endl;
   
   return 0;
}