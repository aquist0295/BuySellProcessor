#include <iostream>
#include <fstream>
#include "stockProcessor.cpp"

using namespace std;

int main(){
ifstream file("../../Downloads/EtradePythonClient/etrade_python_client/tickerInfo.txt");

string str = "";
string ticker = "";
string curr_price = "";

while(getline(file, str)){
    
    for(int x = 0; x < str.size(); x++){
        if(isalpha(str[x])){
            ticker += str[x];
        }
        else{
            curr_price += str[x];
        }
    }
}

double Market_Price = stod(curr_price);

StockProcessor processor1(ticker, Market_Price);

processor1.setBuyPrice(50.0, 100.0);

return 0;}