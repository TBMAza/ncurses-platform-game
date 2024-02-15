#include "../../headers/list_manager/CashListManager.hpp"

CashListManager::CashListManager()
{
    this->cashlist = NULL;
    this->qty = 0;
};

/*******************************<CASH LIST MANAGEMENT>*********************************/
void CashListManager::addcash()
{
    pCashList newcash = new CashList;
    
    bool position_assigned = false;
    while(!position_assigned)
    {
        int random_y = RandomGenerator::generate(FLOATING_BLOCK_LVL3-1, MAX_PLAYABLE_Y);
        int random_x = RandomGenerator::generate(PLAYER_INIT_POS_X+1, MAX_PLAYABLE_X);

        if(CollisionDetector::below(random_y, random_x) == FLOOR && CollisionDetector::retrieve(random_y, random_x) == NULLCHR && this->findcash(random_y, random_x) == NULL)
        {
            (newcash->cash).setposition(random_y, random_x);
            position_assigned = true;
        }
    }

    newcash->next = this->cashlist;
    this->cashlist = newcash;
};

void CashListManager::placeallcash()
{
    this->qty = 8;

    for(int i = 0; i < this->qty; i++)
    {
        this->addcash();
    }
};

pCashList CashListManager::findcash(int y, int x)
{
    pCashList current = this->cashlist;

    bool found = false;
    while(!found && current != NULL)
    {
        if( (current->cash).getpos_y() == y && (current->cash).getpos_x() == x )
        {
            found = true;
        }
        else
        {
            current = current->next;
        }
    }

    return current;
};

void CashListManager::removecash(int y, int x)
{
    pCashList todelete = this->findcash(y, x);
    pCashList current = this->cashlist;

    bool removed = false;
    while(!removed)
    {
        if(this->cashlist == todelete)
        {
            this->cashlist = (this->cashlist)->next;
            delete todelete;
            todelete = NULL;
            removed = true;
            (this->qty)--;
        }
        else if(current->next == todelete)
        {
            current->next = todelete->next;
            delete todelete;
            todelete = NULL;
            removed = true;
            (this->qty)--;
        }
        else
        {
            current = current->next;
        }
    }
};

void CashListManager::displaycash()
{
    pCashList current = this->cashlist;

    while(current != NULL)
    {
        attron(COLOR_PAIR(GREEN));
        mvaddch((current->cash).getpos_y(), (current->cash).getpos_x(), (current->cash).getaspect());
        attroff(COLOR_PAIR(GREEN));

        current = current->next;
    }
};

void CashListManager::deleteallcash()
{
    pCashList current = this->cashlist;
    pCashList nextnode = NULL;

    while(current != NULL)
    {
        nextnode = current->next;
        delete current;
        current = nextnode;
    }

    this->cashlist = NULL;
    this->qty = 0;
};

int CashListManager::getqty()
{
    return this->qty;
};

void CashListManager::placefixedqty(int q)
{
    this->qty = q;
    for(int i = 0; i < q; i++)
    {
        this->addcash();
    }
}
/*******************************<\CASH LIST MANAGEMENT>*********************************/