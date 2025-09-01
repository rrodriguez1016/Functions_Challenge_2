//Rene Rodriguez 09/01/2025 Lab Activity: User Defined Functions
//Challenge 2: Student Grade Management with Reference Parameters
#include<iostream>
using namespace std;
#include <sstream>
#include <limits>
//Original prompt for users
void promptUser(){
    cout << "What would you like to do?" << endl;
    cout << "\t 1. Input Grades" << endl;
    cout << "\t 2. Calculate and Display Average" << endl;
    cout << "\t 3. Assign and Display Letter Grade" << endl;
    cout << "\t 4. Quit" << endl;
}
//Gets input from user while also validating the input and returns it as a double
double getInput(){
    double input;
    cin >> input;
    while(input < 0 || cin.fail()){
        if (cin.fail()) {
            cout << "Invalid input, try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        if(input < 0){
            cout << "Enter a positive number" << endl; 
        }
        cin >> input;

    }
    cout << "You entered " << input << endl;
    return input;
}
//Uses getInput() and stores it in the reference parameters
void inputGrades(double& g1, double& g2, double& g3){
    cout << "Enter grade 1" << endl;
    g1 = getInput();
    cout << "Enter grade 2" << endl;
    g2 = getInput();
    cout << "Enter grade 3" << endl;
    g3 = getInput();
}
//Parameters are passed by values and are used to find the average grade
double calculateAverage(const double g1, const double g2, const double g3){
    return (g1 + g2 + g3) / 3.0;
}
/*Takes average as a passed by parameter and uses an if else statement
to determine what the letter grade is returning it as a char*/
char getLetterGrade(const double average){
    if(average < 60.0){
        return 'F';
    } else if(average < 70.0){
        return 'D';
    } else if(average < 80.0){
        return 'C';
    } else if(average < 90.0){
        return 'B';
    } else if(average >= 90.0 ){
        return 'A';
    } else{
        return 'F';
        
    }
}
int main()
{
    double grade1 = 0.0, grade2 = 0.0, grade3 = 0.0;
    double avg;
    int userInput;
    //Will continuously prompt user as long as they dont enter 4 
    //and the input is valid
    do {
        promptUser();
        cin >> userInput;
        //Validates input
        if (cin.fail()) {
            cout << "Invalid input, try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }
        //Switch statement that uses userInput to determine which function to run
        switch (userInput) {
            case 1:
                cout << "You chose: Input Grades" << endl;
                inputGrades(grade1, grade2, grade3);
                break;
            case 2:
                cout << "You chose: Calculate and Display Average" << endl;
                avg = calculateAverage(grade1, grade2, grade3);
                cout << "The average grade is " << avg << endl;
                break;
            case 3: {
                cout << "You chose: Assign and Display Letter Grade" << endl;
                avg = calculateAverage(grade1, grade2, grade3);
                char letterGrade = getLetterGrade(avg);
                cout << "Letter grade is " << letterGrade << endl;
                break;
            }
            case 4:
                cout << "Byeee" << endl;
                break;
            default:
                cout << "Please enter a valid option" << endl;
        }


    } while (userInput != 4);

    return 0;
}