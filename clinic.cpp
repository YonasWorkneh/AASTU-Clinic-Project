#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

//since contacts have its own details we chose to define another structure
struct contact {
    string phoneNum;
    string subCity;
    string city;
    string homeAddress;
    string emergencyContactName;
    string emergencyContactPhone;
};
//since we might want to use the personal details in other places let's define a structure to store them.
struct personalDetails {
    string name;
    string dateOfBirth;
    int age;
    int height;
    int weight;
    char sex;
};
//here we defined a structure to store the important informations of the patient;
struct medicalRecord {
    personalDetails patient;
    contact addressInfo;
    string medicalRecordNum;
    string medicalHistory;
    string dateOfRegistration;
};
//this structure is defined to helps us store appointment details
struct appointmentRequest {
    personalDetails patient;
    contact addressOf;
    string medicalRecordNum;
    string appointmentDate;
    string appointmentTime;
    string department;
    string procedure;
};
struct stuffrecord {
    string name;
    string age;
    string profession;
    string specialization;
    string experience;
    string dateofregistration;
    string phoneNum;
    string subCity;
    string city;
    string homeAddress;
    string emergencyContactName;
    string emergencyContactPhone;

}stuff[10000];



//We declared a global variable numOfPatient and numOfApp to use it in multiple places

int numOfPatient = 0;
int numOfApp = 0;
int numofstuff = 0;

//we declared a global structure so as to use it in all functions

medicalRecord patient[10000];
appointmentRequest meeting[10000];

/*we try to avoid at least minimize the  parameters for our functions as the author of the famous book "Clean Code" Robert Cecil says
"The best functions are those without Parameters."*/
void menu();
void getRecord();
void Search();
void displayRecord();
void setAppointment();
void displayAppointments();
void storeRecord();
void storeAppointment();
void getStuffRecord();
void storeStuffRecord(int a);
void displayStuffRecord();

int main() {

    menu();


    return 0;

}

//this function is the only function we are going to call in the main functions so using switch we are going to call the other functions
//...inside this function
void menu() {
    int choice;
    int n;
    while (true) {
    cout << "\n----AASTU Student Clinic Menu----\n\n 1.Enter 1 if you are a patient\n 2.Enter 2 if you are a staff member\n 3.enter 0 to exit from the program";
    cout << "\nEnter your choice: ";
        cin >> choice;


        if (choice == 1) {
            cout << "1. Add patient record.\n2. Set appointment.\nEnter 1 or 2: ";
            label:
            cin >> n;

            if (n == 1) {
                getRecord();
            } else if (n == 2) {
                setAppointment();
            } else {
                cout << "Invalid input. Please try again: ";
                goto label;
            }

            break; // Exit the loop after processing the choice.
        } else if (choice == 2) {
            string pass;
            cout<<"first Enter the passcode which is given by head doctors to access all the informations"<<endl;
            cin>>pass;
            if(pass=="openinfo1234"){
            int z;
            loop:
            cout << "1. Display patient records\n2. Search patient record\n3. Display appointments\n4. Add new staff member information\n5. Display staff members info\n6. Exit\nEnter 1, 2, 3, 4, 5, or 6: ";
            choicee:
            cin >> z;

            switch (z) {
                case 1:
                    displayRecord();
                    goto loop;
                    break;
                case 2:
                    Search();
                    goto loop;
                    break;
                case 3:
                    displayAppointments();
                    goto loop;
                    break;
                case 4:
                    getStuffRecord();
                    goto loop;
                    break;
                case 5:
                    displayStuffRecord();
                    goto loop;
                    break;
                case 6:
                    exit(0);
                default:
                    cout << "Invalid input. Please try again: ";
                    goto choicee;
            }

            }

            break; // Exit the loop after processing the choice.
        }
        else if(choice==0) {
                exit(0);

        }
        else {
             cout << "Invalid input. Please try again: ";
        }

    }
}

void getRecord() {
    system("cls");
    int currentSize;
    cout << "\nEnter the number of patient records you want to add:";
    cin >> currentSize;
    cin.ignore();
    for (int i = numOfPatient; i < (currentSize + numOfPatient); ++i) {
        cout << "\nEnter the name of the patient: ";
        getline(cin, patient[i].patient.name);
        cout << "Enter the birth date of the patient: ";
        getline(cin, patient[i].patient.dateOfBirth);
        cout << "Enter the age of the patient: ";
        cin >> patient[i].patient.age;
        cout << "Enter the Sex (M/F) of the patient: ";
        cin >> patient[i].patient.sex;
        cout << "Enter the height of the patient: ";
        cin >> patient[i].patient.height;
        cout << "Enter the weight of the patient: ";
        cin >> patient[i].patient.weight;
        cout << "Enter the phone number of the patient: ";
        cin.ignore();
        getline(cin, patient[i].addressInfo.phoneNum);
        cout << "Enter the Sub-City where the Patient lives: ";
        getline(cin, patient[i].addressInfo.subCity);
        cout << "Enter the city where the patient currently lives: ";
        getline(cin, patient[i].addressInfo.city);
        cout << "Enter the home address of the patient: ";
        getline(cin, patient[i].addressInfo.homeAddress);
        cout << "Enter the name of Emergency contact name: ";
        getline(cin, patient[i].addressInfo.emergencyContactName);
        cout << "Enter the phone number of Emergency contact:";
        getline(cin, patient[i].addressInfo.emergencyContactPhone);
        cout << "Enter the medical record number for the patient: ";
        getline(cin, patient[i].medicalRecordNum);
        cout << "Enter a brief medical history for the patient: ";
        getline(cin, patient[i].medicalHistory);
        cout << "Enter the date of registration: ";
        getline(cin, patient[i].dateOfRegistration);
        system("cls");

    }

    numOfPatient += currentSize;
    storeRecord();
}
//We made this function to enable storing what we have accepted from the user in the console in an outside word file so even after closing/exiting
//...the console we can still find the record in the patient.doc file
void storeRecord() {
    ofstream fout;
    fout.open("patientRecords.doc", ios::app); // Open the file in append mode

    if (!fout.is_open()) {
        cout << "Error opening the file.";
        return;
    }

    fout << "\n------AASTU Clinic Patient Record------\n";
    for (int i = 0; i < numOfPatient; ++i) { // Only write the latest record
        fout << "\n\t\t\tDate of Registration: " << patient[i].dateOfRegistration << "\n\nName: " << patient[i].patient.name << "\tDate of Birth: "
            << patient[i].patient.dateOfBirth << "\nAge: " << patient[i].patient.age << "\tSex: " << patient[i].patient.sex << "\tHeight: " << patient[i].patient.height
            << "\tWeight: " << patient[i].patient.weight << "\nMedical Record Number: " << patient[i].medicalRecordNum << "\n\nPatient contact\n\n" << "Phone Number: "
            << patient[i].addressInfo.phoneNum << "\nSub-city: " << patient[i].addressInfo.subCity << "\nCity: " << patient[i].addressInfo.city << "\nHome Address: "
            << patient[i].addressInfo.homeAddress << "\n\nEmergency contact\n\nName: " << patient[i].addressInfo.emergencyContactName << "\nPhone Number: "
            << patient[i].addressInfo.emergencyContactPhone << "\n\nGeneral Medical History:\n\n" << patient[i].medicalHistory << endl;
    }
    fout.close();
}


void displayRecord() {
    system("cls");
    ifstream fin("patientRecords.doc");
    if (!fin.is_open()) {
        cout << "\nCurrently there are no Patient records!\n";
        return;
    }
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }

    fin.close();
}

void Search() {
    system("cls");
    int searchChoice;
    string searchKey;

    cout << "--Search--\n1. Search by Name\n2. Search by Medical Record Number\n";
    cout << "How do you want to search: ";
    cin >> searchChoice;

    ifstream fin("patientRecords.doc");
    if (!fin.is_open()) {
        cout << "Currently, There are No Patient Records to Search from!\n";
        return;
    }
    cin.ignore();
    cout << "Enter the Search Key: ";
    getline(cin, searchKey);
    bool found = false;
    string line;
   while (getline(fin, line)) {
        if (line.find(searchKey) != string::npos) {
            found = true;
            cout << "\n------AASTU Clinic Patient Record------\n";
            cout << line << endl;

            // Output the remaining lines until the next record's header
            while (getline(fin, line) && line.find("AASTU Clinic Patient Record") == string::npos) {
                cout << line << endl;
            }
            break;
        }
    }

    fin.close();

    if (!found) {
        cout << "No matching records found for the search key.\n";
    }
}

void setAppointment() {
    system("cls");
    int currentSize;
    cout << "How many appointments do you want to add:";
    cin >> currentSize;
    cin.ignore();
    for (int i = numOfApp; i < (numOfApp + currentSize); ++i) {
        cout << "\nEnter the name of the patient: ";
        getline(cin, meeting[i].patient.name);
        cout << "Enter the birth date of the patient: ";
        getline(cin, meeting[i].patient.dateOfBirth);
        cout << "Enter the age of the patient: ";
        cin >> meeting[i].patient.age;
        cout << "Enter the Sex (M/F) of the patient: ";
        cin >> meeting[i].patient.sex;
        cout << "Enter the height of the patient: ";
        cin >> meeting[i].patient.height;
        cout << "Enter the weight of the patient: ";
        cin >> meeting[i].patient.weight;
        cout << "Enter the phone number of the patient: ";
        cin.ignore();
        getline(cin, meeting[i].addressOf.phoneNum);
        cout << "Enter the Sub-City where the Patient lives: ";
        getline(cin, meeting[i].addressOf.subCity);
        cout << "Enter the city where the patient currently lives: ";
        getline(cin, meeting[i].addressOf.city);
        cout << "Enter the home address of the patient: ";
        getline(cin, meeting[i].addressOf.homeAddress);
        cout << "Enter the medical number of the patient:";
        getline(cin, meeting[i].medicalRecordNum);
        cout << "Enter the department the appointment is intended for:";
        getline(cin, meeting[i].department);
        cout << "Enter the procedure in which the appointment is intended for:";
        getline(cin, meeting[i].procedure);
        cout << "Enter the preferred Date of appointment:";
        getline(cin, meeting[i].appointmentDate);
        cout << "Enter the time of the appointment:";
        getline(cin, meeting[i].appointmentTime);
        system("cls");

    }
    numOfApp += currentSize;
    storeAppointment();
}
void storeAppointment() {
    ofstream fout;
    fout.open("patientAppointments.doc", ios::app); // Open the file in append mode

    if (!fout.is_open()) {
        cout << "Error opening the file.";
        return;
    }

    fout << "---------Available Appointments--------\n";
    for (int i = 0; i < numOfApp; ++i) { // Only write the latest appointment
        fout << "\n\t\t\tDate of appointment: " << meeting[i].appointmentDate << "\n\t\t\tAppointment Time: " << meeting[i].appointmentTime << "\n\nName: "
            << meeting[i].patient.name << "\tDate of Birth: " << meeting[i].patient.dateOfBirth << "\nAge: " << meeting[i].patient.age << "\tSex: "
            << meeting[i].patient.sex << "\tHeight: " << meeting[i].patient.height << "\tWeight: " << meeting[i].patient.weight
            << "\nMedical Record Number: " << meeting[i].medicalRecordNum << "\n\nPatient contact\n\n" << "Phone Number: " << meeting[i].addressOf.phoneNum
            << "\nSub-city: " << meeting[i].addressOf.subCity << "\nCity: " << meeting[i].addressOf.city << "\nHome Address: " << meeting[i].addressOf.homeAddress
            << "\n\nDepartment: " << meeting[i].department << "\nProcedure: " << meeting[i].procedure << endl;
    }
    fout.close();
}

void displayAppointments() {
    system("cls");
    ifstream fin("patientAppointments.doc");
    if (!fin.is_open()) {
        cout << "There are no available appointments.\n";
        return;
    }

    cout << "\n----Available Appointments-------\n";
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }

    fin.close();
}
void getStuffRecord() {
    system("cls");
    int sizee;
    cout << "\nEnter the number of staff member records you want to add: ";
    cin >> sizee;
    cin.ignore();

    for (int i = numofstuff; i < (sizee + numofstuff); ++i) {
        system("cls");
        cout << "Enter the name of staff member: ";
        getline(cin, stuff[i].name);
        cout << "Enter age: ";
        getline(cin, stuff[i].age);
        cout << "Enter the profession: ";
        getline(cin, stuff[i].profession);
        cout << "Enter specialization: ";
        getline(cin, stuff[i].specialization);
        cout << "Enter date of registration: ";
        getline(cin, stuff[i].dateofregistration);
        cout << "Enter phone number: ";
        getline(cin, stuff[i].phoneNum);
        cout << "Enter subcity: ";
        getline(cin, stuff[i].subCity);
        cout << "Enter city: ";
        getline(cin, stuff[i].city);
        cout << "Enter home address: ";
        getline(cin, stuff[i].homeAddress);
        cout << "Enter experience years: ";
        getline(cin, stuff[i].experience);
        cout << "Enter emergency contact name: ";
        getline(cin, stuff[i].emergencyContactName);
        cout << "Enter emergency contact phone: ";
        getline(cin, stuff[i].emergencyContactPhone);
        system("cls");
    }

    numofstuff += sizee;
    storeStuffRecord(sizee);
}

void storeStuffRecord(int a) {
    ofstream fout("stuffRecords.doc", ios::app);
    if (!fout.is_open()) {
        cout << "Error opening the file.";
        return;
    }

    fout << "\n------AASTU Clinic Staff Member Records------\n";
    for (int i = numofstuff - a; i < numofstuff; ++i) { // Write all the new records added
        fout<< "\n\t\t\tName of staff member: " << stuff[i].name << "\n\t\t\tAge: "
            << stuff[i].age << "\n\t\t\tProfession: " << stuff[i].profession << "\n\t\t\tSpecialization: " << stuff[i].specialization << "\n\t\t\tDate of Registration: " << stuff[i].dateofregistration
            << "\n\t\t\tPhone number: " << stuff[i].phoneNum << "\n\t\t\tSubcity: " << stuff[i].subCity << "\n\t\t\tCity: " << stuff[i].city << "\n\t\t\tHome address: " << stuff[i].homeAddress
            << "\n\t\t\tExperience: " << stuff[i].experience << "\n\t\t\tEmergency contact name: " << stuff[i].emergencyContactName << "\n\t\t\tEmergency contact phone: " << stuff[i].emergencyContactPhone << endl;
    }

    fout.close();
}
void displayStuffRecord() {
    system("cls");
    ifstream myfile("stuffRecords.doc");
    if (!myfile.is_open()) {
        cout << "Currently there is no record of stuff members.";
        return;
    }
    string line;
    while (getline(myfile, line)) {
        cout << line << endl;
    }

    myfile.close();
}
