#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getLine (char *prmpt, char *buff, size_t sz) {
    int ch, extra;

    // Get line with buffer overrun protection.
    if (prmpt != NULL) {
        printf ("%s", prmpt);
        fflush (stdout);
    }
    if (fgets (buff, sz, stdin) == NULL)
        return NO_INPUT;

    // If it was too long, there'll be no newline. In that case, we flush
    // to end of line so that excess doesn't affect the next call.
    if (buff[strlen(buff)-1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? TOO_LONG : OK;
    }

    // Otherwise remove newline and give string back to caller.
    buff[strlen(buff)-1] = '\0';
    return OK;
}

char* get_user_line(char* sentence_to_display, char* dest){
  char buf[BUFSIZ];
  char *p;

  printf (sentence_to_display, sizeof(buf));

  if (fgets(buf, sizeof(buf), stdin) != NULL)
  {

    /*
     *  Now test for, and remove that newline character
     */
    if ((p = strchr(buf, '\n')) != NULL)
      *p = '\0';
    strncpy(dest, buf, 100);

  }


}

bool is_float(const char *s, float *dest) {
  if (s == NULL) {
    return false;
  }
  char *endptr;
  *dest = (float) strtod(s, &endptr);
  if (s == endptr) {
    return false; // no conversion;
  }
  // Look at trailing text
  while (isspace((unsigned char ) *endptr)){
    endptr++;
  }
  return *endptr == '\0';
}
bool is_integer(int* result){
int num;
char term;

if(scanf("%d%c", &num, &term) != 2 || term != '\n')
    return false;
else
    *result = num;
    return true;
}

void print_portfolio_recap(int goog_unit, int amzn_unit, int fb_unit, int aapl_unit, int msft_unit,float cash_available, int day){

    float goog_value, amzn_value, fb_value, aapl_value, msft_value=0;
    is_float(getValue(day-1,5,"GOOG"),&goog_value);
    is_float(getValue(day-1,5,"AMZN"),&amzn_value);
    is_float(getValue(day-1,5,"FB"),&fb_value);
    is_float(getValue(day-1,5,"AAPL"),&aapl_value);
    is_float(getValue(day-1,5,"MSFT"),&msft_value);

    printf("*********Titres disponibles*********\n");
    printf("**************GOOG******************\n");
    printf("******** cours de la veille : %.2f $ ****\n",goog_value);
    printf("**************AMZN******************\n");
    printf("******** cours de la veille : %.2f $ ****\n",amzn_value);
    printf("**************FB******************\n");
    printf("******** cours de la veille : %.2f $ ****\n",fb_value);
    printf("**************AAPL******************\n");
    printf("******** cours de la veille : %.2f $ ****\n",aapl_value);
    printf("**************MSFT******************\n");
    printf("******** cours de la veille : %.2f $ ****\n",msft_value);

    printf("*********Quantité en portefeuille********\n");
    printf("**************GOOG : %d\n",goog_unit);
    printf("**************AMZN : %d\n",amzn_unit);
    printf("**************FB   : %d\n",fb_unit);
    printf("**************AAPL : %d\n",aapl_unit);
    printf("**************MSFT : %d\n",msft_unit);
    printf("*****************************************\n");

    printf("******valeur total du portefeuille*******\n");
    float portfolio_value = 0;
    compute_portfolio_value(goog_unit,amzn_unit, fb_unit, aapl_unit, msft_unit, &portfolio_value,day);
    float total_value = portfolio_value + cash_available;
    printf("le portefeuille vaut : %.2f avec valeur action = %.2f et en cash %.2f\n",total_value,portfolio_value,cash_available );





//    getValue(5,1,company);


}

/*void total_portfolio_value(int day){
    int resultat = goog_unit*getValue(day+1,5,"GOOG"));
}
*/
void ask_investment_decisions(char* company,int* new_stock_units, int* total_stock_units, float* cash_available, int day){
    float puchase_value = 0;
    float company_value = 0;
    is_float(getValue(day-1,5,company),&company_value);

    float test =-1;


    printf("Pour %s : \n", company);
    while(test<0){
        while(!is_integer(new_stock_units)){
            printf("non valid amount");
        }
        puchase_value = *new_stock_units * company_value;
        test = *cash_available - puchase_value;
        if(test<0){
            printf("vous ne pouvez pas acheter autant de stock, pas assez d'argent \n");
        }
        else{
            *cash_available-=puchase_value;
        }
    }

    printf("vous avez acheté : %d de %s  \n",*new_stock_units,company );

    puchase_value = *new_stock_units * company_value;


    printf("prix HA = : %d * %.2f = %.2f   \n",*new_stock_units,company_value,puchase_value );

    *total_stock_units += *new_stock_units;
    printf("vous possédez donc en tout  : %d de %s  \n",*total_stock_units,company );
    printf("il vous reste %.2f $ \n ",*cash_available );
}

void compute_portfolio_value(int goog_unit, int amzn_unit, int fb_unit, int aapl_unit, int msft_unit, float* portfolio_value, int day){
    float goog_value,  amzn_value,  fb_value,  aapl_value,  msft_value=0;
    is_float(getValue(day-1,5,"GOOG"),&goog_value);
    is_float(getValue(day-1,5,"AMZN"),&amzn_value);
    is_float(getValue(day-1,5,"FB"),&fb_value);
    is_float(getValue(day-1,5,"AAPL"),&aapl_value);
    is_float(getValue(day-1,5,"MSFT"),&msft_value);

    *portfolio_value = goog_unit*goog_value + amzn_unit*amzn_value + fb_unit*fb_value + aapl_unit*aapl_value   + msft_unit*msft_value;
}

void addToScoreboard(float final_total_value, char* user_name)
    {
        FILE *scoreboardFile = fopen("scoreboard.txt", "a");
        fprintf(scoreboardFile, "Name: %s \nCash Money: %.2f\n\n\n", user_name, final_total_value);
        fclose(scoreboardFile);

    }


