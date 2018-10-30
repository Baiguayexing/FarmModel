//
// Created by Ǳˮ�� on 2018/10/28.
//
#include <iostream>
#include "../main/plants/Wheat.h"
#include "../main/plants/Cotton.h"
#include "../main/plants/PlantsField.h"
#include "../main/visitor/ConcreteVisitor.h"
using namespace std;

/**
 * Test program for plants
 * @return
 */
int main(void){
    Wheat wheat(3);
    wheat.setMature(true);
    cout<<wheat.isMature()<<endl;
    wheat.harvest();
    Cotton cotton(1);
    cotton.setMature(true);
    cout<<cotton.isMature()<<endl;
    cotton.harvest();
    cotton.doAction(1);

    PlantsField  field;//��������
    //field.add(&wheat);//push
    //field.add(&cotton);
    field.add(1);
    field.add(2);
    field.print();//����

    IVisitor *staffa = new StaffA();
    IVisitor *staffb = new StaffB();
    cotton.Accept(staffa);
    cotton.Accept(staffb);

    return 0;
}