/*
    File Name: program5.cpp
    Author: Evan Moore
    Date: 4/25/2021
    Purpose: Imperial mechanic vehicle program
                                                */
    #include "program5.h"

    int main(){
        int userChoice;
        char saveToFile;
        string fileName;
        Vehicles vehiclesArray[100];
        int numVehicles = 0;

        while (1){
        cout << "\nWhat would you like to do?\n";
        cout << "       1.  Enter some Vehicles.\n";
        cout << "       2.  Delete a Vehicle.\n";
        cout << "       3.  List/Print Vehicles.\n";
        cout << "       4.  Print Statistics on Vehicle Cost.\n";
        cout << "       5.  End Program.\n";
        cout << "       Enter 1, 2, 3, 4, or 5.\n";
        cout << "CHOICE:  ";
        cin >> userChoice;
        while (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5){
            cin.clear();
            cin.ignore();
            cout << "Invalid Input Please Enter 1, 2, 3, 4, or 5\n";
            cout << "CHOICE:  ";
            cin >> userChoice;
        }

        switch (userChoice){

                case 1: numVehicles = enterVehicles(numVehicles, vehiclesArray);
                        break;
                
                case 2: numVehicles = deleteVehicle(numVehicles, vehiclesArray);
                        break;
                
                case 3: printVehicles(numVehicles, vehiclesArray);
                        break;
                
                case 4: printStatistics(numVehicles, vehiclesArray);
                        break;

                case 5: cout << "Would you like to save your vehicles to a file? (y or n) ";
                        cin >> saveToFile;
                        if (saveToFile == 'y' || saveToFile == 'Y'){
                            saveVehiclesToFile(numVehicles, vehiclesArray);
                            exit(0);
                        }
                        else{
                            cout << "GOODBYE!";
                            exit(0);
                        }
                            
                    
        }     
    } 
    
        return 0;
    }