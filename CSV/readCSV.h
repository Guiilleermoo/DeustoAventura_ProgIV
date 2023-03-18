#ifndef CSV_READCSV_H_
#define CSV_READCSV_H_

int GetTotalLineCount(FILE* fp);              // Calcula el número total de filas en el archivo csv
int GetTotalColCount(FILE * fp);              // Calcula el número total de columnas en el archivo csv (basado en el número de columnas en la primera fila)
int AssignSpaceForData(int inumdata);         // Asignación dinámica de espacio de memoria a datos a través del puntero * giCsvData
void FreeCsvData();                           // Liberar memoria dinámica de datos
int ReadCsvData(char* csvFilePath);           // Leer los datos en Csv (el tipo de datos predeterminado en este ejemplo es int)
void  ShowCsvData();                           // Muestra los datos csv leídos a través de la consola

#endif /* CSV_READCSV_H_ */
