// Assignment by: Ayden Hocking, 

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//  Declaring a new struct to store patient data
struct patient {
    int age;
    char name[20];
    float balance;
};
void displayPatientList(const struct patient* patient_list, int total_patients) {
    for (int i = 0; i < total_patients; i++) { //iterate through patients displaying each one's age, name, and balance
        cout << "Age= " << patient_list[i].age
             << " Name= " << patient_list[i].name
             << " Balance= " << patient_list[i].balance 
             << endl;
    }
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY AGE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE AGE OF THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S AGE
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
int comparePatientsByAge(const void* p1,const void* p2){
    struct patient* patient1 = (struct patient*) p1; //creates patient1 pointer from generic pointer of p1
    struct patient* patient2 = (struct patient*) p2; //creates patient2 pointer from generic pointer of p2

    if(patient1->age<patient2->age){ //compare statement for comparing two patients by age
        return -1;
    }else if(patient2->age == patient1->age){
        return 0;
    }else{
        return 1;
    }
}


//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY BALANCE DUE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE BALANCE FOR THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S BALANCE
//       0 IF THE BALANCES ARE EQUAL
//       1 OTHERWISE
int comparePatientsByBalance(const void* p1,const void* p2){
    struct patient* patient1 = (struct patient*) p1; //creates patient1 pointer from generic pointer of p1
    struct patient* patient2 = (struct patient*) p2; //creates patient2 pointer from generic pointer of p2

    if(patient1->balance<patient2->balance){ //compare statement for comparing two patients by balance
        return -1;
    }else if(patient2->balance == patient1->balance){
        return 0;
    }else{
        return 1;
    }
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY NAME

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE NAME OF THE FIRST PATIENT GOES BEFORE
//         THE SECOND PATIENT'S NAME
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
int comparePatientsByName(const void* p1,const void* p2){
    struct patient* patient1 = (struct patient*) p1; //creates patient1 pointer from generic pointer of p1
    struct patient* patient2 = (struct patient*) p2; //creates patient2 pointer from generic pointer of p2
    return strncmp(patient1->name,patient2->name, 20); //strncmp function used as stated on http://www.cplusplus.com/reference/cstring/strncmp/
}

//  The main program
int main()
{
    int total_patients = 6; //added one for my name
    
    //  Storing some test data
    struct patient patient_list[6] = {
        {25, "Juan Valdez   ", 1250},
        {15, "James Morris  ", 2100},
        {32, "Tyra Banks    ", 750},
        {62, "Mario O'Donell", 375},
        {53, "Pablo Picasso ", 615}
    };
    
    cout << "Input Age: "; //Input for adding my own name to patient_list
    cin >> patient_list[5].age;
    cout << "Input Balance: "; 
    cin >> patient_list[5].balance;
    cout << "Input Last Name: "; 
    cin >> patient_list[5].name;
    
    cout << "Patient List: " << endl;
    
    //  TODO:
    //  IMPLEMENT THE CODE TO DISPLAY THE CONTENTS
    //  OF THE ARRAY BEFORE SORTING
    displayPatientList(patient_list,total_patients); //ref to displayPatientList
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT AGE
    qsort(patient_list, total_patients, sizeof(struct patient), comparePatientsByAge); //qsort for age as stated on http://www.cplusplus.com/reference/cstdlib/qsort/
    cout << "Patient List - Sorted by Age: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY AGE
    displayPatientList(patient_list,total_patients); //ref to updated displayPatientList
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT BALANCE
    qsort(patient_list, total_patients, sizeof(struct patient), comparePatientsByBalance); //qsort for balance as stated on http://www.cplusplus.com/reference/cstdlib/qsort/
    cout << "Patient List - Sorted by Balance Due: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY BALANCE
    displayPatientList(patient_list,total_patients); //ref to updated displayPatientList
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT NAME
    qsort(patient_list, total_patients, sizeof(struct patient), comparePatientsByName); //qsort for name as stated on http://www.cplusplus.com/reference/cstdlib/qsort/
    cout << "Patient List - Sorted by Name: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY NAME
    displayPatientList(patient_list,total_patients); //ref to updated displayPatientList
    cout << endl;
    
    return 0;
}
