#include <iostream>
#include "stockProcessor.cpp"

using namespace std;


int main(){
StockProcessor p("aapl", 120.90);

p.setBuyPrice(130, 100);
p.setSellPrice(120, 100);

return 0;}