#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_

#include <iostream>
#include "../../enums/Enums.hpp"
#include "../../../utils/Class.hpp"

namespace ItemType{
    const int IHeal = 1, IPokeball = 2, ICT = 3;
}
class Item{
public:
    static Item* itemsLst[200];
	Item(std::string nom, bool usable, bool usableInFight, bool givable, int categorie, int id);
	static  Item* getItem (std::string const& name);
	static  Item* getItem (int id);
	static int searchItem (Item *toSearch);
	bool operator==(Item const& b) const;
	std::string getNom() const {return nom;}
	bool isUsable() const {return usable;}
	bool isGivable() const {return givable;}
	int getCategorie () const{return categorie;}
	bool isUsableInFight() const{return usableInFight;}
	int getID() const {return id;}
	static int getItemNumber(){return sizeof(itemsLst);}
	virtual int getItemTypeID() const{return itemTypeID;}


private:
    int itemTypeID = 0;
    std::string nom;
    bool usable;
    bool givable;
    int categorie;
    bool usableInFight;
    int id;

};

void initItems();

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_ */