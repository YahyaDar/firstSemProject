#include <stdlib.h>
#include <sys/time.h>
#include <iostream>
#include <string>
using namespace std;
// function prototypes
int senseDistance();
void getSensors( int sensors[] );
void printSensors( int sensors[], string labels[] );
int furthest( int sensors[] );
// main function
int main() {
    int sensors[4];// array of four distance sensors
    string labels[4];// array of labels for each sensor
    int dir;// indicates which direction to go next
    srand( time( NULL ));// initialize the random number generator
    labels[0] = "north";// initialize the sensor labels
    labels[1] = "west";
    labels[2] = "south";
    labels[3] = "east";
    for ( int i=0; i<5; i++ ) { // simulate 5 moves by the robot
        getSensors( sensors );// get values for all the sensors
        printSensors( sensors, labels ); // print out the sensor values
        dir = furthest( sensors ); // find the direction that is furthest from an obstacle
        cout << "moving " << labels[dir] << endl; // ``go''
    }
} // end of main()
void getSensors(int sensors[]){
    for(int k=0;k<4;k++){
        sensor[k]=senseDistance(k);
    }
}
void printSensors(int sensors[],string labels[]){
    for(int i=0;i<4;i++){
        cout<<labels[i]<<" Sensor Reading : "<<sensors[i]<<endl;
    }
}
int furthest(int sensor[]){
    int far=0;
    far=(sensor[1]>sensor[far]?1:far);
    far=(sensor[2]>sensor[far]?2:far);
    far=(sensor[3]>sensor[far]?3:far);
    return far;
}
