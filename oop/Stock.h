//
// Created by wujianchao5 on 2020/11/13.
//

#ifndef LEARN_CPP_STOCK_H
#define LEARN_CPP_STOCK_H

#include <string>

class Stock {
private:
    std::string company;
    long shares;
    double shareVal;
    double totalVal;

    //定义在class定义中的函数都为inline函数
    void setTotal(){
        totalVal = shares * shareVal;
    }

public:
    Stock();

    Stock(const std::string &company);

    Stock(const std::string &company, long shares, double shareVal, double totalVal);

    virtual ~Stock();

    void acquire(const std::string & company, long shares, double shareVal);
    void sell(long num, double price);
    void buy(long num, double price);
    void show() const;

    const std::string &getCompany() const;

    void setCompany(const std::string &company);

    long getShares() const;

    void setShares(long shares);

    double getShareVal() const;

    void setShareVal(double shareVal);

    double getTotalVal() const;

    void setTotalVal(double totalVal);
};


#endif //LEARN_CPP_STOCK_H
