//
//  main.cpp
//  motor
//
//  Created by LALIT DAHIYA on 5/18/16.
//  Copyright © 2016 LALIT DAHIYA. All rights reserved.
//

#include<iostream>
#include<cmath>
#include <cstdlib>
#include<pthread.h>
using namespace std;

#define pi 3.142857

float voltage(float i , float j){
    if (i<60.0){
        return i*j;
    }
    else return 60.0*j;
}

float torque(float i , float j){
    if (j>1800.0){
        return i/j;
    }
    else return i/1800.0;
}

float power(float i , float j){
    if (j<1800.0){
        return i*j;
    }
    else return i*1800.0;
}

void demo(float f, float r,float rhp){
    float v; float hp;float rpm;float t;float rt;
    rt = rhp/1800.0;
    rpm = 30.0*f;
    v = voltage(f,r);
    hp = power(rt,rpm);
    t = torque(rhp,rpm);
    cout<<"Motor rpm is : "<<rpm<<endl;
    cout<<"Motor voltage is : "<<v<<endl;
    cout<<"Motor power is : "<<hp<<endl;
    cout<<"Motor torque is : "<<t<<endl;
}


float printWaveform(float f,float t){
    return sin(2*pi*f*t);
}


int main(){
    float f; float r; float rhp;
    cout<<"Enter rated power of motor "<<endl;
    cin>>rhp;
    cout<<"Enter motor frequency"<<endl;
    cin>>f;
    cout<<"Enter voltage-frequency ratio"<<endl;
    cin>>r;
    demo(f, r, rhp);
    float t = 0.0;
    while(t<10.0){
        cout<<t<<" : "<<printWaveform(f,t)<<endl;
        t = t+1;
    }
    return 0;
}
