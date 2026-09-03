/*
    File Name: program5.h
    Author: Evan Moore
    Date: 4/25/2021
    Purpose: Imperial mechanic vehicle program
                                                */
#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

struct Cost{
    float hoursLabor; //hours of labor required for vehicle
    float repairCost; //cost of repairs of vehicle
    float partsCost; //cost of parts for vehicle
    float matsCost; //cost of materials/supplies for vehicle
};
struct Vehicles{
    string vehicleName; //name of vehicle
    string vehicleDescription; //description of vehicle
    bool hasWeapons; //true or false if the weapon has weapons
    Cost costStructMembers; //holds the members of the cost structure
};
int enterVehicles(int numVehicles, Vehicles* vehiclesArray);
int deleteVehicle(int numVehicles, Vehicles* vehiclesArray);
bool moveArrayElements(string name, int numVehicles, Vehicles* vehiclesArray);
void printVehicles(int numVehicles, Vehicles* vehiclesArray);
void printStatistics(int numVehicles, Vehicles* vehiclesArray);
void saveVehiclesToFile(int numVehicles, Vehicles* vehiclesArray);
float convertToFloat(string s);
string wordWrap(Vehicles* vehiclesArray, size_t lineLength);

#endif