#include<stdio.h>
#include "interface_functions.h"
#include "DataExtractor.h"

#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2




int main()
{
    char user_name[100];
    char temp_input[100];
    float amount_invested;
    get_user_line("Quel est votre nom? ",user_name);
    printf ("votre nom est %s \n",user_name );

    while(!is_float(temp_input,&amount_invested)){
        get_user_line("De combien d'argent disposez vous pour investir ? ",temp_input);


    }
    is_float(temp_input,&amount_invested);
    printf ("Vous disposez de %.2f \n",amount_invested );


    printf ("Nous allons maintenant commencer le jeu\n");

    int goog_unit=0, amzn_unit=0,  fb_unit=0,  aapl_unit=0,  msft_unit =0;
    int goog_pucharse, amzn_purchase, fb_puchase, msft_purchase = 0;
//    int google_price, amzn_price, fb_price, msft_price = 0;

    int i =2; //i = premier jour du mois
    float cash_available;
    cash_available = amount_invested;
    while(i<24){
        int day_goog_unit=0, day_amzn_unit=0,  day_fb_unit=0,  day_aapl_unit=0,  day_msft_unit =0;
        char* current_day = getValue(i,1,"AAPL");


        float goog_value, amzn_value, fb_value, aapl_value, msft_value=0;
        is_float(getValue(i,5,"GOOG"),&goog_value);
        is_float(getValue(i,5,"AMZN"),&amzn_value);
        is_float(getValue(i,5,"FB"),&fb_value);
        is_float(getValue(i,5,"AAPL"),&aapl_value);
        is_float(getValue(i,5,"MSFT"),&msft_value);
        printf ("apple: %.2f \n", aapl_value);

//        google_price = getValue(i, )
        printf ("Nous somme aujourd'hui le : %s , jour de trading n° %d \n", current_day, i-1);

        print_portfolio_recap(goog_unit,amzn_unit,  fb_unit,  aapl_unit,  msft_unit,cash_available,i);

        i++;

        printf ("Veuillez indiquer vos décisions d'investissement pour ce jour : \n");

        ask_investment_decisions("GOOG",&day_goog_unit,&goog_unit,&cash_available,i);
        ask_investment_decisions("AMZN",&day_amzn_unit,&amzn_unit,&cash_available,i);
        ask_investment_decisions("FB",&day_fb_unit,&fb_unit,&cash_available,i);
        ask_investment_decisions("AAPL",&day_aapl_unit,&aapl_unit,&cash_available,i);
        ask_investment_decisions("MSFT",&day_msft_unit,&msft_unit,&cash_available,i);
        i+=50;
        if(i>20){
            float portfolio_value = 0;
            float total_value =0;
            compute_portfolio_value(goog_unit,amzn_unit, fb_unit, aapl_unit, msft_unit, &portfolio_value,23);


            total_value = portfolio_value + cash_available;
            printf("final value = %.2f\n", total_value);
            printf("votre p&l est de  = %.2f\n", total_value-amount_invested);
            addToScoreboard(total_value-amount_invested,user_name);


        }


    }










    return 0;
}

