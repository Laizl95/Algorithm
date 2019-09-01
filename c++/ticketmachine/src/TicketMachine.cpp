#include "TicketMachine.h"
#include <iostream>
using namespace std;



TicketMachine::TicketMachine():PRICE(0)
{
    //ctor
    balance=0;
}

TicketMachine::~TicketMachine()
{
    //dtor
}

void TicketMachine::showPrompt(){
    cout<<"some thing";
}

void TicketMachine::insertMoney(int money){
    balance+=money;
}

void TicketMachine::showBalance(){
    cout<<balance;
}


