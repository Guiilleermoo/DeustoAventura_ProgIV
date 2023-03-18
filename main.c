#include "CSV/readCSV.h"

    int main(void)
    {
    char *filename="";
    ReadCsvData(filename);           // Leer datos csv
    ShowCsvData();                   // Muestra los datos csv leídos a través de la consola
    FreeCsvData();                   // Libera la memoria dinámica
    return 1;
    }
