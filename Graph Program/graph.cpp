/*
    Title: graph.cpp
    Author: Evan Moore
    Date: 12/6/2021
    Purpose: main file for program 4
                                    */
#include "Stack.h"
#include "Graphmatrix.h"
#include "Graphlist.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream infile;
    string fileName;
    cout << "Enter the filename of the file that contains the graph information:  ";
    cin >> fileName;
    infile.open(fileName, ios::in);
    if(infile.is_open()){
        string data;
        getline (infile, data);
        int vertices = stoi(data);
        GraphList adjList(vertices);
        GraphMatrix adjMatrix(vertices);
        Stack<int> stack;
        string vertex;
        while (getline (infile, data)){
            stringstream ss(data);
            getline (ss, vertex, ' ');
            int source = stoi(vertex);
            getline (ss, vertex, ' ');
            int destination = stoi(vertex);
            adjList.addEdge(source, destination);
            adjMatrix.addEdge(source, destination);
            stack.push(destination);
        }
        cout << "\n\n";
        cout << "Adjacency Matrix: \n";
        adjMatrix.printGraph();
        cout << "\n\n";
        cout << "Adjacency List: \n";
        adjList.printGraph();
        cout << "Now traversing & printing vertices with DFS\n";
        while (!stack.isEmpty()){
            int current;
            stack.pop(current);
            cout << current << " ";
        }
    }
    else{
        cout << "The File could not be opened";
    }
    return 0;
}