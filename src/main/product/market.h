#ifndef MARKET
#define MARKET

#include <iostream>
#include <string>

//�г���
class Market
{
public:
	virtual void sellPrice(int n) = 0;
};

//�г���proxy Patternʵ�֣�����ΪSingleton
class RealMarket : public Market
{
public:
	static RealMarket* Instance()
	{
		return myMarket;
	}
	void sellPrice(int n)
	{
		std::cout << "��Ʒ�г��۸�Ϊ "<<price[n-1] << std::endl;
	}
private:
	RealMarket()
	{
		for (int i = 0; i < 4; ++i)
			price[i] = 100 * (i + 1);
	}
	RealMarket(const RealMarket&) { }

	RealMarket& operator=(const RealMarket&) { }

private:
	static RealMarket* myMarket;
	int price[4];
};

//����Ψһ�г���ΪSingleton Pattern
RealMarket* RealMarket::myMarket = new RealMarket();

//������
class ProxyBuyer : public Market 
{
public:
	void sellPrice(int n) 
	{
		RealMarket* market = RealMarket::Instance();
		market->sellPrice(n);
	}
	ProxyBuyer() {};
private:
	
};
#endif 

