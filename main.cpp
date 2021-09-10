#include <iostream>
#include "Menu.h" //menu header file

using namespace std;

int main()
{
    Menu* menu=new Menu(); //a pointer of type menu
    menu->menuLoop(); //menu pointer pointing to the function menu loop
    return 0;
}

