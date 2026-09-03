/*
    Title: Graphmatrix.h
    Author: Evan Moore
    Date: 12/6/2021
    Purpose: GraphMatrix header file
                                    */
#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include <iostream>
using namespace std;

class GraphMatrix{
                private:
                        int** vertexMatrix;
                        int numVertices;
                        int numEdges;
                public:
                        GraphMatrix(int nv){
                            numVertices = nv;
                            vertexMatrix = new int*[numVertices];
                            for (int i = 0; i < numVertices; i++){
                                vertexMatrix[i] = new int[numVertices];
                            }
                            for (int i = 0; i < numVertices; i++){
                                for (int k = 0; k < numVertices; k++){
                                    vertexMatrix[i][k] = 0;
                                }
                            }
                        }
                        ~GraphMatrix(){
                            delete[] vertexMatrix;
                        }
                        void addEdge(int vertex1, int vertex2){
                            vertexMatrix[vertex1][vertex2] = 1;
                            numEdges += 1;
                        }
                        void printGraph(){
                            for (int i = 0; i < numVertices; i++){
                                for (int k = 0; k < numVertices; k++){
                                    cout << vertexMatrix[i][k] << " ";
                                }
                                cout << endl;
                            }
                        }
                        bool isThereAnEdge(int row, int column){
                            if (vertexMatrix[row][column] == 1){
                                return true;
                            }
                            else{
                                return false;
                            }
                        }

};
#endif