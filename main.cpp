#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int NUM_PROCESS;

struct Process{
    int processId;
    int arrivalTime;
    int lifeTime;
    int numOfPiece;
    int* sizeOfMemChunk;
    
    Process(int Id, int arrivalTime, int lifeTime, int numOfPiece, int* sizeOfMemChunk):processId(Id),arrivalTime(lifeTime),lifeTime(lifeTime),numOfPiece(numOfPiece), sizeOfMemChunk(sizeOfMemChunk){}
    
    void print(){
        cout << "ID: " << processId << endl
            << arrivalTime << " " << lifeTime << endl
        << numOfPiece;
        for(int i=0; i<numOfPiece; i++){
            cout << " " << sizeOfMemChunk[i];
        }
        cout << endl;
    }
};

Process* fileReader(){
    fstream fin;
    fin.open("in1.txt", fstream::in);
    fin >> NUM_PROCESS;
    cout << NUM_PROCESS << endl;
    Process* Processes[NUM_PROCESS];
    int processId;
    int arrivalTime;
    int lifeTime;
    int numOfPiece;
    for(int i=0; i<NUM_PROCESS; i++){
        fin >> processId >> arrivalTime >> lifeTime >> numOfPiece;
        int* sizeOfMemChunk = new int [numOfPiece];
        for(int j = 0; j < numOfPiece; j++){
            fin >> sizeOfMemChunk[j];
        }
        Processes[i] = new Process(processId, arrivalTime, lifeTime, numOfPiece, sizeOfMemChunk);
        Processes[i]->print();
    }
    return Processes[0];
}

int main(){
    Process* Processes;
    Processes = fileReader();
    
    
    return 0;
    
}