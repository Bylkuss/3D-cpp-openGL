#include <iostream>
#include <memory>



class CBase
{
public:
    CBase()  { std::cout << "B"; }
    ~CBase() { std::cout << "b"; }
};
 
class CComposed
{
public:
    CComposed()  { std::cout << "C"; }
    ~CComposed() { std::cout << "c"; }
};
 
class CDerived : public CBase
{
public:
    CDerived()  { std::cout << "D"; }
    ~CDerived() { std::cout << "d"; }
 
private:
    CComposed m_composed;
};
  
int main()
{
    auto pBase    = new CBase;
    auto pDerived = std::make_unique< CDerived >();
    const CComposed composed1;
    static const CComposed composed2;
}