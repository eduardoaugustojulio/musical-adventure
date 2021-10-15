#include <iostream>

#include "Trade.hpp" 

int main(const int argc, const char **argv){

    std::vector<Trade> trades;

    int tradeCount;
    std::string referenceDate;

    std::cout << "Enter the reference date: ";
    std::cin >> referenceDate;

    std::cout << "Enter the number of trades: ";
    std::cin >> tradeCount;

    for(auto i = 0; i < tradeCount; i++){
        double amount;
        std::string sector, date;
        std::cin >> amount >> sector >> date;
        Trade aTrade(amount, sector, date);
        trades.push_back(aTrade);
    }

    for(auto trade : trades){
       std::cout << trade.categorizeRisk(referenceDate) << std::endl;
    }

    return 0;
}
