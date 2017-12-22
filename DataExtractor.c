#include<stdio.h>




void callDataScript(char* stock,char* start_date, char* end_date){

    char command[100];
    sprintf(command, "/home/simonsays/scrapYahoo.sh %s %s %s",stock, start_date,end_date );
    printf("%s\n", command);
    system(command);
//./scrapYahoo.sh AAPL  20160101 20170101
}

void getAllStocksPrices(){

    char companies[5][100];

    strcpy(companies[0],"GOOG");
    strcpy(companies[1],"AMZN");
    strcpy(companies[2],"FB");
    strcpy(companies[3],"AAPL");
    strcpy(companies[4],"MSFT");
    const char* start_date = "20171101";
    const char* end_date = "20171201";

    for (int i =0; i<5;i++){
            callDataScript(companies[i], start_date,end_date);
    }
}

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");tok && *tok;tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

char* getValue(int day, int field_number, char* company_name ){
    char* base_path = "/home/simonsays/Cfiles/financeProject/financialGame/";
    char path[200];
    day++;
    strcpy(path, base_path);
    strcat(path, company_name);
    strcat(path,".csv");

    FILE* stream = fopen(path, "r");

    char field_value[100];
    char line[1024];
    int i =0;
    while (fgets(line, 1024, stream))
    {
        i++;
        char* tmp = strdup(line);
        if(i==day){
            return getfield(tmp, field_number);

        }
    }
}


