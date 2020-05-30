//
// Created by 45184 on 2020/4/30.
//

#ifndef COMPREHENSIVE_EXAMPLE_ACCOUNT_H
#define COMPREHENSIVE_EXAMPLE_ACCOUNT_H

#include "Date.h"
#include "Accumulator.h"
#include <string>
#include <map>
#include "AccountRecord.h"

using namespace std;
class AccountRecord;
// ���������洢��Ŀ�Ķ���ӳ������
typedef multimap<Date, AccountRecord> RecordMap;
class Account { // �����˻���
private:
    string id; // �˺�
    double balance; // ���
    static double total; // �����˻����ܽ��
    static RecordMap recordMap;
//    double rate; // ������
//    Date lastDate;  // �ϴα������ʱ��
//    double accumulation; // �����ۼ�֮��
//    // ��¼һ���ˣ�date Ϊ���ڣ�amount Ϊ��desc Ϊ˵��
//    void record(const Date &date, double amount, const string &desc);
//    // ���������Ϣ
//    void error(const string &msg) const;
//    // ��õ�ָ������Ϊֹ�Ĵ����İ����ۻ�ֵ
//    double accumulate(const Date &date) const{ return accumulation + balance * date.distance(lastDate);}
protected:
    // ����������õĹ��캯��
    Account(const string &id, const Date &date);

    // ����һ���ˣ�date ���ڣ�amount ��desc ˵��
    void record(const Date &date, double amount, const string &desc);

    // ���������Ϣ
    void error(const string &msg) const;

public:
    static void query(const Date &begin, const Date &end);

    const string &getId() const { return id; }

    double getBalance() const { return balance; }

    static double getTotal() { return total; }

    // �����ֽ�date ���ڣ�amount ��desc ˵��
    virtual void deposit(const Date &date, double amount, const string &desc) = 0;

    // ȡ���ֽ�date ���ڣ�amount ��desc ˵��
    virtual void withdraw(const Date &date, double amount, const string &desc) = 0;

    // ������Ϣ��ÿ�½���һ�Σ�date ��������
    virtual void settle(const Date &date) = 0;

    // ��ʾ�˻���Ϣ
    virtual void show() const;
};


#endif //COMPREHENSIVE_EXAMPLE_ACCOUNT_H
