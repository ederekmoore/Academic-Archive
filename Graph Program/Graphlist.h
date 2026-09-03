/*
    Title: Graphlist.h
    Author: Evan Moore
    Date: 12/6/2021
    Purpose: Graphlist header file
                                    */
#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <iostream>
using namespace std;

class GraphList{

                private:
                        struct ListNode{
                            int vertex;
                            ListNode *next;
                        };
                        
                        ListNode **headArray;

                        int numVertices;

                        int  numEdges;

                public:
                        GraphList (int vertices){
                            numVertices = vertices;
                            headArray = new ListNode *[numVertices];
                            for (int i = 0; i < numVertices; i++){
                                headArray[i] = nullptr;
                            }
                        }
                        ~GraphList(){
                            for (int i = 0; i < numVertices; i++){
                                ListNode *ptr = headArray[i];
                                ListNode *t = nullptr;

                                while (ptr != nullptr){
                                    t = ptr;
                                    ptr = ptr -> next;
                                    delete t;
                                }
                            }
                            delete[] headArray;
                        }
                        void addEdge(int source, int destination){
                            ListNode* newNode = getAdjListNode(destination, headArray[source]);
                            headArray[source] = newNode;
                            newNode = getAdjListNode(source, headArray[destination]);
                            headArray[destination] = newNode;
                        }
                        ListNode* getAdjListNode(int dest, ListNode* head){
                            ListNode *newNode = new ListNode;
                            newNode->vertex = dest;
                            newNode->next = head;
                            return newNode;
                        }
                        void printGraph(){
                            for (int i = 0; i < numVertices; i++){
                                ListNode *ptr = headArray [i];
                                cout << i << "--->";
                                while (ptr != nullptr){
                                    cout << ptr->vertex << "--->";
                                    ptr = ptr->next;
                                }
                                cout << "NULL";
                                cout << "\n";
                            }
                        }
};
#endif