#pragma once
#include <iostream>
#include <string>
#include <vector>

class MenuItem {
	std::string name;
	std::string description;
	bool vegetarian;
	double price;
    
	public:
    MenuItem(std::string name, 
	                std::string description, 
	                bool vegetarian, 
	                double price) 
	{
		this->name = name;
		this->description = description;
		this->vegetarian = vegetarian;
		this->price = price;
	}
  
	std::string getName() {
		return name;
	}
  
	std::string getDescription() {
		return description;
	}
  
	double getPrice() {
		return price;
	}
  
	bool isVegetarian() {
		return vegetarian;
	}
	operator std::string() {
		return (name + ", $" + std::to_string(price) + description + "\n" );
	}
};

class Iterator
{
    public:
        virtual bool hasNext() = 0;
        virtual MenuItem* next() = 0; 
        virtual ~Iterator(){}
};

class PancaIterator: public Iterator
{
    int pos = 0;
    std::vector<MenuItem*> item;

    public:
        PancaIterator(std::vector<MenuItem*> i):item(i) {}

        MenuItem* next()
        {
            MenuItem* menu = item[pos];
            pos++;
            return menu;
        }

        bool hasNext()
        {
            if(pos < this->item.size())
                return true;
            return false;
        }
};

class PancakeHouseMenu
{
	std::vector<MenuItem*> menuItems;
 
	public:
    PancakeHouseMenu() {
		
		addItem("K&B's Pancake Breakfast", 
			"Pancakes with scrambled eggs, and toast", 
			true,
			2.99);
 
		addItem("Regular Pancake Breakfast", 
			"Pancakes with fried eggs, sausage", 
			false,
			2.99);
 
		addItem("Blueberry Pancakes",
			"Pancakes made with fresh blueberries",
			true,
			3.49);
 
		addItem("Waffles",
			"Waffles, with your choice of blueberries or strawberries",
			true,
			3.59);
	}

    ~PancakeHouseMenu()
    {
        for(auto i : this->menuItems)
            delete i;
    }

	void addItem(std::string name, std::string description,
	                    bool vegetarian, double price)
	{
		MenuItem* menuItem = new MenuItem(name, description, vegetarian, price);
		menuItems.push_back(menuItem);
	}
 
	
    std::vector<MenuItem*> getMenuItems() {
		return menuItems;
	}
	
    Iterator* createIterator() {
		return new PancaIterator(this->menuItems);
	}

	operator std::string() {
		return "Objectville Pancake House Menu";
	}
};

class Waitress
{
    PancakeHouseMenu* pamenu;
    Iterator *ite;
    public:
        Waitress(PancakeHouseMenu* p):pamenu(p) {
            ite = this->pamenu->createIterator();
        }
        ~Waitress()
        {
            delete this->ite;
            delete this->pamenu;
        }
        void printMenu()
        {
            while (ite->hasNext())
            {
                std::cout << std::string(*(ite->next()));
            }
        }
        
};




/******************************************************/
// class base
// {
//     public:
//         void func()
//         {
//             this->print();
//         }
//         virtual ~base(){}
//     protected:
//         virtual void print() = 0;
// };

// class child: public base
// {
//     public:
//         child(){}
//     private:
//         void print()
//         {
//             std::cout << "child";
//         }
// };