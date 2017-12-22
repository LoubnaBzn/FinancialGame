#ifndef INTERFACE_FUNCTIONS_H_INCLUDED
#define INTERFACE_FUNCTIONS_H_INCLUDED

#include <stdbool.h>

int getLine (char *prmpt, char *buff, size_t sz);
bool is_float(const char *s, float *dest);
void ask_investment_decisions(char* company,int* new_stock_units, int* total_stock_units, float* cash_available, int day);
char* get_user_line(char* sentence_to_display, char* dest);
void print_portfolio_recap(int goog_unit, int amzn_unit, int fb_unit, int aapl_unit, int msft_unit,float cash_available, int day);
void compute_portfolio_value(int goog_unit, int amzn_unit, int fb_unit, int aapl_unit, int msft_unit, float* portfolio_value, int day);
void addToScoreboard(float final_total_value, char* user_name);

#endif // INTERFACE_FUNCTIONS_H_INCLUDED
