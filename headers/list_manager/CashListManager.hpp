#ifndef CASHLISTMANAGER_HPP
#define CASHLISTMANAGER_HPP

#include "../cash/Cash.hpp"
#include "../collision_detector/CollisionDetector.hpp"
#include "../filereader/FileReader.hpp"

struct CashList
{
    Cash cash;
    CashList *next;
};
typedef CashList* pCashList;

class CashListManager
{
    private:
    
        pCashList cashlist;
        int qty;
    
    public:

        CashListManager();

        void addcash();
        void placeallcash();
        void placefixedqty(int q);
        pCashList findcash(int y, int x);
        void removecash(int y, int x);
        void displaycash();
        void deleteallcash();

        int getqty();
};

#endif