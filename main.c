#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct dataStruct {
    int length;
    double* values;
    double meanValue;
    double StandDev;
};

typedef struct dataStruct DATA;

DATA storagingData;

void printStartProgram() {
    printf("Insert the values for mean and standard deviation calculation\n");
}

void quitWarning() {
    printf("If you want to stop inserting values, press q\n");
}

void receiveData(int* insertionConcluded, DATA* dataStruct) {
    char scanned[10];
    int len = 0;

    dataStruct->values = (double*)malloc(100 * sizeof(double));

    while (!(*insertionConcluded)) {
        printStartProgram();
        quitWarning();

        scanf("%s", &scanned);

        if (strcmp(scanned, "q") == 0) {
            *insertionConcluded = 1;
        } else {
            double insertedValue = atoi(scanned);
            dataStruct->values[len] = insertedValue;
            len++;
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
    double variance = 0.0;
    double standDev;
    double mean = dataStruct->meanValue;

    for (int idx = 0; idx < dataStruct->length; idx++) {
        variance += pow((dataStruct->values[idx]-mean), 2);
    }

    variance = variance / dataStruct->length;

    standDev = sqrt(variance);
    dataStruct->StandDev = standDev;
}

void generateReport(DATA* dataStruct) {
    printf("****************************************\n");
    printf("The data inserted generates this resutls\n");

    printf("Mean value: %f\n", dataStruct->meanValue);
    printf("Standard deviation: %f\n", dataStruct->StandDev);

}

int main () {
    // variables iniatilization
    int insertionConcluded = 0;

    // register the number of data is to be inserted
    receiveData(&insertionConcluded, &storagingData);

    // calculates the mean and the standard deviation
    meanCalculator(&storagingData);
    StandDevCalculator(&storagingData);

    // prints the report of the data inserted
    generateReport(&storagingData);
    free(storagingData.values);

    return 0;
}