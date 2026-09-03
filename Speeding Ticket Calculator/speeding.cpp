/* Program Name: speeding.cpp
 * Student Name: Evan Moore
 * Net ID: emoore92
 * Student ID: 00061291
 * Program Description: This program takes information from a file to calculate a speeding ticket price for the user.
 *																                                		             */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const string THREE_LETTER_MONTHS[] = { //constant vector containing three letter months
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
};

const double INTERSTATE_MULTIPLIER = 5.2243;
const double HIGHWAY_MULTIPLIER = 9.4312;
const double RESIDENTIAL_MULTIPLIER = 17.2537;
const double DEFAULT_MULTIPLIER = 12.916;

int main(){
    int sDay, sMonth, sYear;
    int eDay, eMonth, eYear;
    string ticketFile;
    string reportFile;
    ifstream fin;
    ofstream fout;


    cout << "Enter a ticket file: ";
    cin >> ticketFile;
    ticketFile += ".txt";
    cout << "Enter a report file: ";
    cin >> reportFile;
    reportFile += ".txt";
    cout << "Enter report start date (mm dd yyyy): ";
    cin >> sMonth >> sDay >> sYear;
    cout << "Enter report end date (mm dd yyyy): ";
    cin >> eMonth >> eDay >> eYear;

    fin.open(ticketFile); //open the input file
    if (!fin.is_open()){
        cerr << "Unable to open " << ticketFile << endl;
        return 1;
    }
    fout.open(reportFile); //open the output file
    if (!fout.is_open()){
        cerr << "Unable to open " << reportFile << endl;
        return 1;
    }

    string citationNumber;
    int m, d, y;
    int clockedSpeed;
    int speedLimit;
    char roadType;
    double fine;
    while (fin >> citationNumber >> m >> d >> y >> clockedSpeed >> speedLimit >> roadType){ //iterate through the input file while data can be obtained
        if (y >= sYear && y <= eYear){ //makes sure only data within the range of starting and ending years is sent to the output file
            if (y == sYear){ 
                if (m == sMonth){ //if the year is equal to the start year and the month is equal to the start month
                    if (d >= sDay){ //then the day must be equal to or greater than the start day
                        switch (roadType){
                            case 'i':
                                fine = (clockedSpeed - speedLimit) * INTERSTATE_MULTIPLIER;
                                break;
                            case 'h':
                                fine = (clockedSpeed - speedLimit) * HIGHWAY_MULTIPLIER;
                                break;
                            case 'r':
                                fine = (clockedSpeed - speedLimit) * RESIDENTIAL_MULTIPLIER;
                                break;
                            default:
                                fine = (clockedSpeed - speedLimit) * DEFAULT_MULTIPLIER;
                                break;
                        }
                    fout << setfill('0');
                    fout << setw(2) << d << "-" << THREE_LETTER_MONTHS[m - 1] << "-" << y << " " << setfill(' ') << left << setw(10) << citationNumber << " $" << right << setw(9) << fixed << setprecision(2) << fine << endl;
                    }
                }
                if (m > sMonth){ //if the year is equal to the starting year and the month is greater than the starting month then the day does not matter
                    switch (roadType){
                            case 'i':
                                fine = (clockedSpeed - speedLimit) * INTERSTATE_MULTIPLIER;
                                break;
                            case 'h':
                                fine = (clockedSpeed - speedLimit) * HIGHWAY_MULTIPLIER;
                                break;
                            case 'r':
                                fine = (clockedSpeed - speedLimit) * RESIDENTIAL_MULTIPLIER;
                                break;
                            default:
                                fine = (clockedSpeed - speedLimit) * DEFAULT_MULTIPLIER;
                                break;
                    }
                    fout << setfill('0');
                    fout << setw(2) << d << "-" << THREE_LETTER_MONTHS[m - 1] << "-" << y << " " << setfill(' ') << left << setw(10) << citationNumber << " $" << right << setw(9) << fixed << setprecision(2) << fine << endl;
                }
            }
            if (y > sYear && y < eYear){ //if the year is between the starting and ending years but not equal to them then the month and day dont matter
                switch (roadType){
                            case 'i':
                                fine = (clockedSpeed - speedLimit) * INTERSTATE_MULTIPLIER;
                                break;
                            case 'h':
                                fine = (clockedSpeed - speedLimit) * HIGHWAY_MULTIPLIER;
                                break;
                            case 'r':
                                fine = (clockedSpeed - speedLimit) * RESIDENTIAL_MULTIPLIER;
                                break;
                            default:
                                fine = (clockedSpeed - speedLimit) * DEFAULT_MULTIPLIER;
                                break;
                    }
                    fout << setfill('0');
                    fout << setw(2) << d << "-" << THREE_LETTER_MONTHS[m - 1] << "-" << y << " " << setfill(' ') << left << setw(10) << citationNumber << " $" << right << setw(9) << fixed << setprecision(2) << fine << endl;
            }
            if (y == eYear){
                if (m < eMonth){ //if the year is equal to the ending year and the month is less than the ending month then the day does not matter
                    switch (roadType){
                            case 'i':
                                fine = (clockedSpeed - speedLimit) * INTERSTATE_MULTIPLIER;
                                break;
                            case 'h':
                                fine = (clockedSpeed - speedLimit) * HIGHWAY_MULTIPLIER;
                                break;
                            case 'r':
                                fine = (clockedSpeed - speedLimit) * RESIDENTIAL_MULTIPLIER;
                                break;
                            default:
                                fine = (clockedSpeed - speedLimit) * DEFAULT_MULTIPLIER;
                                break;
                    }
                    fout << setfill('0');
                    fout << setw(2) << d << "-" << THREE_LETTER_MONTHS[m - 1] << "-" << y << " " << setfill(' ') << left << setw(10) << citationNumber << " $" << right << setw(9) << fixed << setprecision(2) << fine << endl;
                }
                if (m == eMonth){ //if the year is equal to the ending year and the month is equal to the ending month
                    if (d <= eDay){ //then the day must be less than or equal to the ending day
                        switch (roadType){
                            case 'i':
                                fine = (clockedSpeed - speedLimit) * INTERSTATE_MULTIPLIER;
                                break;
                            case 'h':
                                fine = (clockedSpeed - speedLimit) * HIGHWAY_MULTIPLIER;
                                break;
                            case 'r':
                                fine = (clockedSpeed - speedLimit) * RESIDENTIAL_MULTIPLIER;
                                break;
                            default:
                                fine = (clockedSpeed - speedLimit) * DEFAULT_MULTIPLIER;
                                break;
                        }
                    fout << setfill('0');
                    fout << setw(2) << d << "-" << THREE_LETTER_MONTHS[m - 1] << "-" << y << " " << setfill(' ') << left << setw(10) << citationNumber << " $" << right << setw(9) << fixed << setprecision(2) << fine << endl;
                    }
                }
            }
        }
    }
    fin.close(); //close input file
    fout.close(); //close output file
}