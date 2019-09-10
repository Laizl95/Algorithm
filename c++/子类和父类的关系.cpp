#include<bits/stdc++.h>

using namespace std;

class Employee{
public:
    Employee(const std::string& name,const std::string& ssn);
    const std::string& get_name() const;
    void print(std::ostream& out) const;
    void print(std::ostream& out,const std::string& msg) const;
protected:
    std::string m_name;
    std::string m_ssn;
};

int main(){

return 0;
}
