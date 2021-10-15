#include <iostream>
#include <string>

#include <boost/date_time/gregorian/gregorian.hpp>


class RiskCategories {
public:
    inline static const std::string DEFAULTED = "DEFAULTED";
    inline static const std::string MEDIUMRISK = "MEDIUMRISK";
    inline static const std::string HIGHRISK = "HIGHRISK";
};

class Trade {
public:
    Trade(double amount, std::string sector, std::string date){
        value = amount;
        clientSector = sector;
        nextPaymentDate = boost::gregorian::date(boost::gregorian::from_us_string(date));
    }
    
    std::string categorizeRisk(std::string date){
        std::string retVal;
        boost::gregorian::date referenceDate(boost::gregorian::from_us_string(date));
        boost::gregorian::days deadLine = referenceDate - nextPaymentDate;  
        
        if(deadLine.days() > unpaidDays){
            retVal = RiskCategories::DEFAULTED;    
        }else if(value > maxAmount and clientSector == publicSector){
            retVal = RiskCategories::MEDIUMRISK;
        }else if(value > maxAmount and clientSector == privateSector){
            retVal = RiskCategories::HIGHRISK;
        }
        return retVal;
    }

    double value;
    std::string clientSector;
    boost::gregorian::date nextPaymentDate;
    RiskCategories risk; 

    const int unpaidDays = 30;
    const double maxAmount = 1000000;
    const std::string publicSector = "Public";
    const std::string privateSector = "Private";
};
