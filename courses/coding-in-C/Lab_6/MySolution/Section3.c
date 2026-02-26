#include <stdio.h>
#define N 3000

typedef struct {
float time;
double probability;
} SensorData;

typedef struct Sensor {
int sensor_ID;
double threshold;
SensorData data[N];
int object_detection[N];
} Sensor;

int binary_detection_signal_1(Sensor* ptrS) {
    ptrS->sensor_ID=1;
    ptrS->threshold=0.8;
    FILE* p1 = fopen("sensor1.txt", "r");

    if(p1==NULL) {return 1;}
    for(int i=0; i < N; i++){
        if(fscanf(p1, " %f %lf", &ptrS->data[i].time, &ptrS->data[i].probability)!=2) {break;}
        else {
            if(ptrS->data[i].probability >= ptrS->threshold) {
            ptrS->object_detection[i]=1;
            }   else if(ptrS->data[i].probability < ptrS->threshold) {
                ptrS->object_detection[i]=0;
                }    
        } 
    }
    fclose(p1);
    return 1;
}


int binary_detection_signal_2(Sensor* ptrS) {
    ptrS->sensor_ID=2;
    ptrS->threshold=0.7;
    FILE* p2= fopen("sensor2.txt", "r");

    if(p2==NULL) {return 1;}
    for(int i=0; i < N; i++){
        if(fscanf(p2, " %f %lf", &ptrS->data[i].time, &ptrS->data[i].probability)!=2) {break;} 
        else{
            if(ptrS->data[i].probability >= ptrS->threshold) {
                ptrS->object_detection[i]=1;
            }   else if(ptrS->data[i].probability < ptrS->threshold) {
                ptrS->object_detection[i]=0;
                }
        }   
    }
fclose(p2);
return 1;  
}

int set_time(Sensor* ptrS) {
int state=0;

    for(int i=0; i<N;i++) {
        if(ptrS->object_detection[i]==1 && state==0) {
        state=1;
        printf("Start: %f\n", ptrS->data[i].time);
        }
            
        else if(ptrS->object_detection[i]==0 && state==1) {
            printf("Ende: %f\n", ptrS->data[i-1].time);
            state=0;
        }
    }
    if(state==1) {
        printf("Ende: %f\n", ptrS->data[N-1].time);
    }
    return 1;
}

void Fusion(const Sensor* s1, const Sensor* s2) {
    Sensor fused;
    fused.sensor_ID = 3;
    fused.threshold = 0.0;

    for (int i = 0; i < N; i++) {
        fused.data[i] = s1->data[i]; // Zeit übernehmen
        if(s1->object_detection[i] == 1 && s2->object_detection[i] == 1) {
            fused.object_detection[i] =1;
        } else {
                fused.object_detection[i]=0;
            }
    }
}

int main() {
Sensor s1;
Sensor s2;
    binary_detection_signal_1(&s1);
    binary_detection_signal_2(&s2);

    printf("Sensor 1: \n");
    set_time(&s1);

    printf("\n\nSensor 2: \n");
    set_time(&s2);

    printf("\n\nFusion (beide Sensoren):\n");
    Fusion(&s1, &s2);
    set_time(&s1); 
}