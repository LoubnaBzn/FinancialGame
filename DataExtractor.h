#ifndef DATAEXTRACTOR_H_INCLUDED
#define DATAEXTRACTOR_H_INCLUDED

void callDataScript(char* start_date, char* end_date, char* stock);
const char* getfield(char* line, int num);
char* getValue(int day, int field_number, char* company_name );
void getAllStocksPrices();



#endif // FINANCIALOBJECTS_H_INCLUDED
