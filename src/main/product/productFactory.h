#ifndef PRODUCT_FACTORY
#define PRODUCT_FACTORY

#include <iostream>
#include <string>
#include "trademark.h"
#include "market.h"

//��Ʒ����
class Product
{
public:
	Product() 
	{
		m_price = 0;
		tradeMark = NULL;
		m_buyer = new ProxyBuyer();
	}
	virtual void SellProduct() = 0;
	virtual void CreatProduct() = 0;

protected:
	int m_price;
	trademarkFlyweight* tradeMark;
	ProxyBuyer* m_buyer;
};

//4����Ʒ��ʵ��
class Product1 : public Product
{
public:
	Product1(FlyweightFactory* factory)
	{
		tradeMark = creatTrademark(factory, 1);
		m_price = 100;
		std::cout << "��Ʒ1������" << std::endl;
	}
	int getPrice() { return m_price; }
	virtual void SellProduct() { m_buyer->sellPrice(1); }
	virtual void CreatProduct() { std::cout << "������Ʒ" << m_price / 100 << std::endl; }
};

class Product2 : public Product
{
public:
	Product2(FlyweightFactory* factory)
	{
		tradeMark = creatTrademark(factory, 2);
		m_price = 200;
		std::cout << "��Ʒ2������" << std::endl;
	}
	int getPrice() { return m_price; }
	virtual void SellProduct() { m_buyer->sellPrice(2); }
	virtual void CreatProduct() { std::cout << "������Ʒ" << m_price / 100 << std::endl; }

};

class Product3 : public Product
{
public:
	Product3(FlyweightFactory* factory)
	{
		tradeMark = creatTrademark(factory, 3);
		m_price = 300;
		std::cout << "��Ʒ3������" << std::endl;
	}
	int getPrice() { return m_price; }
	virtual void SellProduct() { m_buyer->sellPrice(3); }
	virtual void CreatProduct() { std::cout << "������Ʒ" << m_price / 100 << std::endl; }

};

class Product4 : public Product
{
public:
	Product4(FlyweightFactory* factory)
	{
		tradeMark = creatTrademark(factory, 4);
		m_price = 400;
		std::cout << "��Ʒ4������" << std::endl;
	}
	int getPrice() { return m_price; }
	virtual void SellProduct() { m_buyer->sellPrice(4); }
	virtual void CreatProduct() { std::cout << "������Ʒ" << m_price / 100 << std::endl; }
};

//��Ʒ���� factory pattern
class ProductFactory
{
public:
	ProductFactory()
	{
		m_flyweightFactroy = new FlyweightFactory();
	}
	Product* productGoods(int n)
	{
		switch (n)
		{
		case 1:
			return new Product1(this->m_flyweightFactroy);
			break;
		case 2:
			return new Product2(this->m_flyweightFactroy);
			break;
		case 3:
			return new Product3(this->m_flyweightFactroy);
			break;
		case 4:
			return new Product4(this->m_flyweightFactroy);
			break;
		default:
			std::cout << "������1-4" << std::endl;
			break;
		}
	}
private:
	FlyweightFactory* m_flyweightFactroy;
};

#endif 