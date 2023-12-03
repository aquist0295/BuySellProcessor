#include <iostream>
#include <map>
#include <utility>
#include "../buysellExecution/stockProcessor.h"
#include "Queuingbuy_sell.h"

using namespace std;

QueueMech :: QueueMech(){
 cout<<"checking queue for eligible orders that can be executed now."<<endl;
}


pair<string,float> QueueMech :: UpdateBuyQueue(){
    if(buyQueue.empty()){
        return {};
    }

    //loop through buy queue and compare real time price to requested buy price if the ticker exist
    for(auto m : p.Buy_Order_queue){
        string ticker = m.first;
        //float marketPrice = ;
       // if(m.second.first == marketPrice){
            //call buy function in Processor program
        //}
    }

}

pair<string,float> QueueMech :: UpdateSellQueue(){

}