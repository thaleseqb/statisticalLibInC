#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct dataStruct {
    int length;
    int* values;
    double meanValue;
    double StandDev;
};

typedef struct dataStruct DATA;

DATA storagingData;

void printStartProgram() {
    printf("Insert the values for mean and standard deviation calculation\n");
}

void quitWarning() {
    printf("If you want to stop inserting values, press any word key\n");
}

void receiveData(int* insertionConcluded, DATA* dataStruct) {
    int insertedValue;
    int len = 0;

    while (!insertionConcluded) {
        printStartProgram();
        quitQuestion();

        scanf("%d", &insertedValue);

        len++;

        if (!isdigit(insertedValue)) {
            *insertionConcluded = 1;
        } else {
            dataStruct->values[len] = insertedValue;
        }
    }

    dataStruct->length = len;
}

void meanCalculator(DATA* dataStruct) {
    double mean;

    for (int idx = 0; idx < dataStruct->length; idx++) {
        mean += dataStruct->values[idx];
    }

    mean = mean / dataStruct->length;

    dataStruct->meanValue = mean;
}

void StandDevCalculator(DATA* dataStruct) {
    double variance;
    double standDev;
    double mean = dataStruct->meanValue;

    for (int idx = 0; idx < dataStruct->length; idx++) {
        variance += pow((dataStruct->values[idx]-mean), 2);
    }

    int nMinusOne = (dataStruct->length) - 1;
    variance = variance / nMinusOne;

    standDev = sqrt(variance);
    dataStruct->StandDev = standDev;
}

void generateReport(DATA* dataStruct) {
    printf("****************************************\n");
    printf("The data inserted generates this resutls\n");

    printf("Mean value: %f", dataStruct->meanValue);
    printf("Standard deviation: %f", dataStruct->StandDev);

}

int main () {
    // variables iniatilization
    int insertionConcluded = 0;

    // register the number of data is to be inserted
    receiveData(insertionConcluded, &storagingData);

    // calculates the mean and the standard deviation
    meanCalculator(&storagingData);
    StandDevCalculator(&storagingData);

    // prints the report of the data inserted
    generateReport(&storagingData);

}