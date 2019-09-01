#ifndef TICKETMACHINE_H
#define TICKETMACHINE_H
//·ÀÖ¹ÖØÐÂÉùÃ÷

class TicketMachine
{
    public:
        TicketMachine();
        virtual ~TicketMachine();
        void showPrompt();
        void insertMoney(int money);
        void showBalance();
        void printTicket();
        void showTotal();
    protected:

    private:
        const int PRICE;
        int balance;
        int total;

};

#endif // TICKETMACHINE_H
