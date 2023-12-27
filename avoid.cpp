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
void box(int sensors[]);
// main function
int main() {
    int sensors[4];// array of four distance sensors
    string labels[4];// array of labels for each sensor
    int dir;// indicates which direction to go next
    srand( time( 0 ));// initialize the random number generator
    labels[0] = "north";// initialize the sensor labels
    labels[1] = "west";
    labels[2] = "south";
    labels[3] = "east";
    for ( int i=0; i<5; i++ ) { // simulate 5 moves by the robot
        getSensors( sensors );// get values for all the sensors
        printSensors( sensors, labels ); // print out the sensor values
        dir = furthest( sensors ); // find the direction that is furthest from an obstacle
        cout << "moving " << labels[dir] << endl; // ``go''
        box(sensors);
    }
} // end of main()
void getSensors(int sensors[]){
    do{
        sensors[0]=senseDistance();
        sensors[2]=senseDistance();
    }while((sensors[0]+sensors[2])!=100);//get north and south sensor readigs 
    do{
        sensors[1]=senseDistance();//get east and west readings 
        sensors[3]=senseDistance();
    }while((sensors[1]+sensors[3])!=100);
}
void printSensors(int sensors[],string labels[]){
    for(int i=0;i<4;i++){
        cout<<labels[i]<<" Sensor Reading : "<<sensors[i]<<endl;//output sensor readings
    }
}
int furthest(int sensor[]){//unction to select furthest sensor 
    int far=0;
    far=(sensor[1]>sensor[far]?1:far);
    far=(sensor[2]>sensor[far]?2:far);
    far=(sensor[3]>sensor[far]?3:far);
    return far;
}
int senseDistance(){//function to randomly generate sensor reading btw 0 to 100
    return rand()%101;
}

void box( int sensors[]){
    for(int k=0;k<26;k++){//loop for dsiplaying top line
        cout<<"--";
    }
    cout<<endl;
    for(int i=0;i<25;i++){
        cout<<"|";//print start barrier
        for(int j=0;j<50;j++){
        cout<<(i==sensors[0]/4&&j==sensors[1]/2?'*':char(32));
        }
        cout<<"|\n";//print end barrier
    }
    for(int k=0;k<26;k++){//loop for dsiplaying bbottom line
        cout<<"--";
    }
    cout<<endl;
}
