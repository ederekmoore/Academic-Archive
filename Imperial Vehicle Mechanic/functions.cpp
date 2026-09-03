/*
    File Name: functions.cpp
    Author: Evan Moore
    Date: 4/25/2021
    Purpose: Imperial mechanic vehicle program
                                                */
    #include "program5.h"

/* input vehicles */
int enterVehicles(int numVehicles, Vehicles* vehiclesArray){
    int enterVehiclesChoice;
    string enterVehiclesFileName;
    char addMore;
    string nameVehicle;
    string descriptionVehicle;
    string fileInput;
    ifstream infile;
    char weaponInput;
    bool weaponInputBool;
    int i = 0;
    float x;
    bool fileInputBool;
    if (numVehicles == 100){
        cout << "Your garage is already full, you cannot add any more vehicles.";
        return numVehicles;
    }
    else{
        cout << "What would you like to do?\n";
        cout << "       1.  Load my vehicles from a file.\n";
        cout << "       2.  Enter one vehicle manually.\n";
        cout << "       Choose 1 or 2.\n";
        cout << "CHOICE:  ";
        cin >> enterVehiclesChoice;
        while(enterVehiclesChoice != 1 && enterVehiclesChoice != 2){
            cin.clear();
            cin.ignore();
            cout << "Invalid Input please enter 1 or 2\n";
            cout << "CHOICE:  ";
            cin >> enterVehiclesChoice;
        }
        
        switch (enterVehiclesChoice){

            case 1: cout << "What is the name of the file with you list of vehicles? (ex: filename.txt)\n";
                    cout << "FILENAME:  ";
                    cin >> enterVehiclesFileName;
                    infile.open(enterVehiclesFileName);
                        if (infile.is_open()){
                            while (!infile.eof()){
                                getline(infile, fileInput, '#');
                                    vehiclesArray[i].vehicleName = fileInput; //vehicle name
                                getline(infile, fileInput, '#');
                                    vehiclesArray[i].vehicleDescription = fileInput; //vehicle description
                                getline(infile, fileInput, '#');
                                        if (fileInput == "y" || fileInput == "Y" || fileInput == "1"){ //has weapons
                                        fileInputBool = true;
                                        }
                                        else{
                                        fileInputBool = false;
                                        }
                                    vehiclesArray[i].hasWeapons = fileInputBool;
                                getline(infile, fileInput, '#');
                                        x = convertToFloat(fileInput);
                                    vehiclesArray[i].costStructMembers.hoursLabor = x; //hours of labor
                                getline(infile, fileInput, '#');
                                        x = convertToFloat(fileInput);
                                    vehiclesArray[i].costStructMembers.repairCost = x; //repair cost
                                getline(infile, fileInput, '#');
                                        x = convertToFloat(fileInput);
                                    vehiclesArray[i].costStructMembers.partsCost = x; //parts cost
                                getline(infile, fileInput, '#');
                                        x = convertToFloat(fileInput);
                                    vehiclesArray[i].costStructMembers.matsCost = x; //materials/supplies cost
                                numVehicles = numVehicles + 1;
                                i++;
                            }
                            infile.close();
                        }
                    cout << "All vehicles from " <<  enterVehiclesFileName << " have been added to the program\n";
                    break;
            
            case 2: do{
                    cin.ignore();
                    cout << "\n\n\nName:  ";
                    getline(cin, nameVehicle);
                    vehiclesArray[numVehicles].vehicleName = nameVehicle; //vehicle name
                    cout << "\n\nDescription:  ";
                    getline(cin, descriptionVehicle);
                    vehiclesArray[numVehicles].vehicleDescription  = descriptionVehicle; //vehicle description
                    cout << "\n\nDoes this vehicle have weapons? (y or n):  ";
                    cin >> weaponInput;
                        if(weaponInput == 'y' || weaponInput == 'Y'){
                            weaponInputBool = true;
                        }
                        else{
                            weaponInputBool = false;
                        }
                    vehiclesArray[numVehicles].hasWeapons = weaponInputBool; //has weapons
                    cout << "\n\nHow many hours do you spend repairing the " << nameVehicle << "?";
                    cout << "\nNUM HOURS:  ";
                    cin >> vehiclesArray[numVehicles].costStructMembers.hoursLabor; //hours of labor
                    cout << "\n\nWhat is the cost per hour for repairing the " << nameVehicle << "?";
                    cout << "\nCOST PER HOUR:  ";
                    cin >> vehiclesArray[numVehicles].costStructMembers.repairCost; // cost per hour
                    cout << "\n\nHow much money do you spend on parts for the " << nameVehicle << "?";
                    cout << "\nPART COST:  ";
                    cin >> vehiclesArray[numVehicles].costStructMembers.partsCost; //cost for parts
                    cout << "\n\nHow much money do you spend on supplies for the " << nameVehicle << "?";
                    cout << "\nSUPPLY COST:  ";
                    cin >> vehiclesArray[numVehicles].costStructMembers.matsCost; //cost for materials/supplies
                    cout << "\n\nThe " << nameVehicle << " has been added.";
                    numVehicles = numVehicles + 1;
                    cout << "\n\n\nWhant to add more vehicles? (y or n)  ";
                    cin >> addMore;
            }while(addMore == 'y' || addMore == 'Y');
        }

    }
    return numVehicles;
}
/* Delete Vehicles */
int deleteVehicle(int numVehicles, Vehicles* vehiclesArray){
    string nameVehicle;
    bool isDeleted;
    cout << "The following is a list of all the vehicles you take care of:\n";
    for (int i = 0; i < numVehicles; i++){
            cout << vehiclesArray[i].vehicleName << "\n";
        }
    cout << "\n\nWhat vehicle do you wish to remove?";
    cin.clear();
    cin.ignore();
    cout << "\nVEHICLE NAME:  ";
    getline(cin, nameVehicle);
    isDeleted = moveArrayElements(nameVehicle, numVehicles, vehiclesArray);
    if (isDeleted == true){
        cout << "\n\nYou have removed " << nameVehicle << ".\n\n";
        numVehicles = numVehicles - 1;
    }
    else{
        cout << "\n\nSorry, a vehicle by the name " << nameVehicle << " could not be found.";
    }
return numVehicles;
}
/* Move elements in array
   used in vehicle deletion */
bool moveArrayElements(string nameVehicle, int numVehicles, Vehicles* vehiclesArray){
    int vehicleLocation;
    for (int i = 0; i < numVehicles; i++){
        if (nameVehicle == vehiclesArray[i].vehicleName){
            vehicleLocation = i;
            for (int x = vehicleLocation; x < numVehicles; x++){
                vehiclesArray[x] = vehiclesArray[x+1];
            }
            return true;
        }
    }
    return false;
}
/* Print vehicles to
   screen or text file */
void printVehicles(int numVehicles, Vehicles* vehiclesArray){
    ofstream outFile;
    string writeFile;
    int printOption;
    string hasWeapons;
    cout << "What would you like to do?\n";
    cout << "       1.  Print Vehicles to the Screen.\n";
    cout << "       2.  Print Vehicles to a File.\n";
    cout << "       Choose 1 or 2.\n";
    cin.clear();
    cin.ignore();
    cout << "CHOICE:  ";
    cin >> printOption;
        while(printOption != 1 && printOption != 2){
            cin.clear();
            cin.ignore();
            cout << "\nInvalid Input please enter 1 or 2\n";
            cout << "CHOICE:  ";
            cin >> printOption;
        }
    
    switch (printOption){

        case 1: for (int z = 0; z < numVehicles; z++){
                    cout << "\n------------------------------------------------------------";
                    cout << "\nVehicle " << z + 1 << ":";
                    cout << "\nName:        " << vehiclesArray[z].vehicleName;
                    cout << "\nDescription:     \n\n";
                    cout << wordWrap(&vehiclesArray[z], 60);
                    cout << "\n\nHas Weapons?     ";
                        if (vehiclesArray[z].hasWeapons == true){
                            hasWeapons = "Yes";
                        }
                        else{
                            hasWeapons = "No";
                        }
                    cout << hasWeapons;
                    cout << "\nNumber of hours to repair the Vehicle:     " << vehiclesArray[z].costStructMembers.hoursLabor;
                    cout << "\nCost Per Hour:       $" << vehiclesArray[z].costStructMembers.repairCost;
                    cout << "\nCost for Parts:      $" << vehiclesArray[z].costStructMembers.partsCost;
                    cout << "\nSupplies Cost:       $" << vehiclesArray[z].costStructMembers.matsCost;
                    cout << "\n";
                    cout << "\n------------------------------------------------------------";
                }
                break;
        case 2: 
            cout << "What is the name of the file you wish to write to?\n";
            cin.clear();
            cin.ignore();
            getline(cin, writeFile);
            outFile.open(writeFile);
            for (int z = 0; z < numVehicles; z++){
                    outFile << "\n------------------------------------------------------------";
                    outFile << "\nVehicle " << z + 1 << ":";
                    outFile << "\nName:        " << vehiclesArray[z].vehicleName;
                    outFile << "\nDescription:     \n\n";
                    outFile << wordWrap(&vehiclesArray[z], 60);
                    outFile << "\n\nHas Weapons?     ";
                        if (vehiclesArray[z].hasWeapons == true){
                            hasWeapons = "Yes";
                        }
                        else{
                            hasWeapons = "No";
                        }
                    outFile << hasWeapons;
                    outFile << "\nNumber of hours to repair the Vehicle:     " << vehiclesArray[z].costStructMembers.hoursLabor;
                    outFile << "\nCost Per Hour:       $" << vehiclesArray[z].costStructMembers.repairCost;
                    outFile << "\nCost for Parts:      $" << vehiclesArray[z].costStructMembers.partsCost;
                    outFile << "\nSupplies Cost:       $" << vehiclesArray[z].costStructMembers.matsCost;
                    outFile << "\n";
                    outFile << "\n------------------------------------------------------------";
                }
            outFile.close();
    }

}
/* Print stats to screen */
void printStatistics(int numVehicles, Vehicles* vehiclesArray){
    float total = 0;
    cout << "\n\nCost of Each Vehicle:\n";
    cout << setw(10) << left << "Vehicle" << setw(31) << right << "Cost\n";
    for (int i = 0; i < numVehicles; i++){
        float cost = (vehiclesArray[i].costStructMembers.hoursLabor * vehiclesArray[i].costStructMembers.repairCost) + vehiclesArray[i].costStructMembers.partsCost + vehiclesArray[i].costStructMembers.matsCost;
        cout << setw(15) << left << vehiclesArray[i].vehicleName << right << setw(5) << "$" << right << setw(20) << fixed << setprecision(2.0) << cost << "\n";
        total = total + cost;
    }
    cout << "\n" << setw(15) << left << "TOTAL COST:" << right << setw(5) << "$" << right << setw(20) << fixed << setprecision(2.0) << total << "\n";
}
/* save vehicles to a
   file beofre exiting
   the program */
void saveVehiclesToFile(int numVehicles, Vehicles* vehiclesArray){
    string saveFile;
    ofstream outFile;
    cout << "\nWhat is the name of the file you want to save your vehicles to?";
    cout << "\nFILENAME:  ";
    cin.clear();
    cin.ignore();
    getline(cin, saveFile);
    outFile.open(saveFile);
    for (int i = 0; i < (numVehicles - 1); i++){
        outFile << vehiclesArray[i].vehicleName << "#";
        outFile << vehiclesArray[i].vehicleDescription << "#";
        outFile << vehiclesArray[i].hasWeapons << "#";
        outFile << vehiclesArray[i].costStructMembers.hoursLabor << "#";
        outFile << vehiclesArray[i].costStructMembers.repairCost << "#";
        outFile << vehiclesArray[i].costStructMembers.partsCost << "#";
        outFile << vehiclesArray[i].costStructMembers.matsCost << "#";
    }
        outFile << vehiclesArray[numVehicles - 1].vehicleName << "#";
        outFile << vehiclesArray[numVehicles - 1].vehicleDescription << "#";
        outFile << vehiclesArray[numVehicles - 1].hasWeapons << "#";
        outFile << vehiclesArray[numVehicles - 1].costStructMembers.hoursLabor << "#";
        outFile << vehiclesArray[numVehicles - 1].costStructMembers.repairCost << "#";
        outFile << vehiclesArray[numVehicles - 1].costStructMembers.partsCost << "#";
        outFile << vehiclesArray[numVehicles - 1].costStructMembers.matsCost;
    outFile.close();
    cout << "\n\nYour vehicles were succesfully saved to the " << saveFile << " file.\n";
    cout << "\n\nGOODBYE!";

}
/* Given Convert to float */
float convertToFloat(string s){
    istringstream i(s);
    float x;
    if (!(i >> x))
    x = 0;
    return x;
}
/* implement word wrap
   in the output of 
   descriptions for
   print to screen */
string wordWrap(Vehicles* vehiclesArray, size_t lineLength){
    istringstream vehicleDescription(vehiclesArray->vehicleDescription);
    ostringstream wrappedDescription;
    string word;

    if (vehicleDescription >> word){
        wrappedDescription << word;
        size_t spaceLeft = lineLength - word.length();
        while (vehicleDescription >> word){
            if(spaceLeft < word.length() + 1){
                wrappedDescription << '\n' << word;
                spaceLeft = lineLength - word.length();
            }
            else{
                wrappedDescription << ' ' << word;
                spaceLeft -= word.length() + 1;
            }
        }
    }
    return wrappedDescription.str();
}