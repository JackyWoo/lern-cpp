//
// Created by wujianchao5 on 2020/11/13.
//

#include <iostream>
#include "Stock.h"

void Stock::acquire(const std::string & company, long n, double pr){
    if(n<0){
        std::cout<<"Number of share can not be negative!" << std::endl;
        shares = 0;
    }
    this->company = company;
    this->shares = n;
    this->shareVal = pr;

    setTotal();
}

/**
 * const修饰的方法将不能修改class
 */
void Stock::show() const {
//    company = "1";
    std::cout<<company<<"-"<<totalVal<<std::endl;
}

const std::string &Stock::getCompany() const {
    return company;
}

void Stock::setCompany(const std::string &company) {
    Stock::company = company;
}

long Stock::getShares() const {
    return shares;
}

void Stock::setShares(long shares) {
    Stock::shares = shares;
}

double Stock::getShareVal() const {
    return shareVal;
}

void Stock::setShareVal(double shareVal) {
    Stock::shareVal = shareVal;
}

double Stock::getTotalVal() const {
    return totalVal;
}

void Stock::setTotalVal(double totalVal) {
    Stock::totalVal = totalVal;
}

Stock::Stock(const std::string &company, long shares, double shareVal, double totalVal) : company(company),
                                                                                          shares(shares),
                                                                                          shareVal(shareVal),
                                                                                          totalVal(totalVal) {
    std::cout<<"construct stock object with 3 args" << std::endl;
}

Stock::~Stock() {
    std::cout<<"destroy stock object" << std::endl;
}

Stock::Stock() {
    std::cout<<"construct stock object with no args" << std::endl;
}

Stock::Stock(const std::string &company) : company(company) {
    std::cout<<"construct stock object with 1 args" << std::endl;
}

