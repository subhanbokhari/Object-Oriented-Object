#include <iostream>
using namespace std;

class total_items : public Starters, public Food_items, public Beverages, public Dessert
{
    public:
};

class Starters : public Soup
{
    int onion_rings;
    Soup s1;
    int chick_strips;
    int fish_tenders;
    int starters_total;

    public:
    Starters(Soup s1,int onion_rings=0, int chick_strips=0, int fish_tenders=0,int starters_total=0)
    {
        this-> onion_rings = onion_rings;
        this-> s1 = s1;
        this-> chick_strips = chick_strips;
        this-> fish_tenders = fish_tenders;
    }
    string add_item (int add)
    {
        if (add==1)
        {
            onion_rings = onion_rings + 1;

        }
        if (add==2)
        {
            int option; int bowls;
            cout << "Please Input Type: " << endl << "1-Chicken Corn" << endl << "2-Hot n Sour" << endl << "3-Chef_special" << endl << "4-Crackers" << endl;
            cin >> option;
            cout << "How many bowls?" << endl;
            cin >> bowls;
            s1.add_soup(bowls,option);
        }
        if (add==3)
        {
            chick_strips = chick_strips + 1;
        }
        if (add==4)
        {
            fish_tenders = fish_tenders + 1;
        }                        
    }
    void starter_bill ()
    {
        if (onion_rings > 0)
        {
            starters_total+= onion_rings*10;
        }
        if (s1.get_num() > 0 )
        {
            starters_total+= s1.get_price();
        }
        if (chick_strips > 0)
        {
            starters_total+= chick_strips*15;
        }
        if (fish_tenders > 0)
        {
            starters_total+= fish_tenders * 17;
        }

    }
};
class Soup
{
    int num;
    int price;
    int type;
    int chick_corn;
    int hotnsour;
    int chef_special;
    int crackers;

    public:
    Soup (int num = 1, int price=0, int type=0, int chick_corn=1, int hotnsour=0, int chefs_special=0, int crackers=0 )
    {
        this->num=num;
        this->type=0;
        this->chick_corn=chick_corn;
        this->hotnsour=hotnsour;
        this->chef_special=chef_special;
        this->crackers=crackers;
    }
    void add_soup(int num,int type)
    {
        if (type==1)
        {
            chick_corn = chick_corn +1;
            price += chick_corn*12;
        }
        if (type==2)
        {
            hotnsour = hotnsour +1;
            price += hotnsour*13;
        }
        if (type==3)
        {
            chef_special = chef_special + 1;
            price += chef_special*16;
        }
        if (type==4)
        {
            crackers = crackers + 1;
            price += crackers*10;
        }
    }
    void price_calc()
    {
        price += chick_corn*12;
        price += hotnsour*13;
        price += chef_special*16;
        price += crackers*10;
    }
    int get_price()
    {
        return this->price;
    } 
    int get_num()
    {
        return num;
    }
};


class Food_items : public Steak, public Burger, public Wrap
{
 int food_total; 
 Steak steak;
 Burger burger;
 int alfredo_pasta;
 int lasagne;
 Wrap wrap;
};

class Steak 
{
 int num2;
 bool rare;
 bool medium_rare;
 bool medium;
 bool medium_well;
 bool well;
 int mashed_potatos;
 int steamed_rice;

 public:
 Steak(int num2=1,bool rare=1, bool medium_rare=0, bool medium=0, bool medium_well=0, bool well=0, int mashed_potatos=1, int steamed_rice=0)
 {
    num2=num2+1;
    this->rare=rare;
    this->medium_rare=medium_rare;
    this->medium=medium;
    this->medium_well=medium_well;
    this->well=well;
    this->mashed_potatos=mashed_potatos;
    this->steamed_rice=steamed_rice;
 }
};


class Burger 
{
 int num1;
 int burger_price;
 int letuce;
 string patty;
 bool mayo;
 int tomato;
 bool cheese;
 int extra_vegs;

 public:
 void burger_type (int num1 = 1, int burger_price = 0, int letuce = 0, string patty = "beef", bool mayo = 0, int tomato = 0, int cheese = 0, int extra_vegs = 0)
 {
    this->num1 = num1;
    this->letuce = letuce;
    this->patty = patty;
    this->mayo = mayo;
    this->tomato = tomato;
    this->cheese = cheese;
    this->extra_vegs = extra_vegs;
 }
 void add_burger (int letuce, string patty, bool mayo, int tomato, int cheese, int extra_vegs) 
 {
    Burger *b = new Burger;
    b->num1=num1 + 1;
    b->letuce=letuce;
    b->patty=patty;
    b->mayo=mayo;
    b->tomato=tomato;
    b->cheese=cheese;
    b->extra_vegs=extra_vegs;
 }
 int buger_calc()
 {
    if (letuce > 0)
    {
        burger_price+=1;
    }
    if (patty == "chicken")
    {
        burger_price+=5;
    }
    else
    {
        burger_price+=8;
    }
    if (mayo==1)
    {
        burger_price+= 1;
    }
    if (tomato > 0)
    {
        burger_price+=1;
    }
    if (cheese==1)
    {
        burger_price+=1;
    }
    if (extra_vegs > 0)
    {
        burger_price+=2;
    }
 }
};

class Wrap 
{
 public:
 Wrap(int num3=0,int letuce=0, string patty="Null", int mayo=0, int tomato=0, int cheese=0, int extra_vegs=0)
 {
    this-> num3 = num3;
    this->letuce = letuce;
    this->patty = patty;
    this->mayo = mayo;
    this->tomato= tomato;
    this->cheese= cheese;
    this->extra_vegs= extra_vegs;
 }
 int num3;
 int letuce;
 string patty;
 int mayo;
 int tomato;
 int cheese;
 int extra_vegs;
};



class Beverages : public Cola
{
    public:
    Beverages(Cola cola, int mint_margrita=0, int pineapple_blast=0, int oreo_shake=0, int lassi=0, string type="Null", int numd=0 )
    {
        this->numd= numd;
        this-> cola=cola;
        this->mint_margrita= mint_margrita;
        this->pineapple_blast= pineapple_blast;
        this->oreo_shake= oreo_shake;
        this->type= type;
        this->Lassi= lassi;
    }
    int numd;
    Cola cola;
    int Lassi;
    int mint_margrita;
    int pineapple_blast;
    int oreo_shake;
    string type;
    float price;
    void calc_bev()
    {
        if(numd==1 || numd==2||numd==3 ||numd==4 ||numd==5 ||numd==6 ||numd==7 ||numd==8)
        {
            price+=3;
        }
        if(numd==9 || numd==10)
        {
            price+= 6;
        }
        if(numd==11)
        {
            price+=8;
        }
    }
};
class Cola 
{
    public:
    Cola(int pepsi=0, int marinda=0, int coke=0,int sprite=0, int fanta=0, int sevenup=0, int mountain_dew=0,int pakola=0)
    {
        this->pepsi= pepsi;
        this->marinda= marinda;
        this->sprite= sprite;
        this->coke= coke;
        this->fanta=fanta;
        this->sevenup= sevenup;
        this-> mountain_dew= mountain_dew;
        this->pakola= pakola;
    }
    int pepsi;
    int marinda;
    int sprite;
    int coke;
    int fanta;
    int sevenup;
    int mountain_dew;
    int pakola;
};


class Dessert : public Ml, public Ic, public Ps
{
    public:
    Ml molten_lava;
    Ic icecream;
    Ps Pakistni_sweet;
};
class Ml
{
    public:
    int num4;
    Ic icecream;
    int extra_choc;
};
class Ic
{
    public:
    int num5;
    int choc;
    int van;
    int fruity;
    int mango;
    int strawb;
    int pista;
};
class Ps
{
    public:
    int barfi;
    int ladu;
    int gulab_jamun;
    int rasgulla;
};



int main()
{
    cout << "Assalam-u-Alaikum" << endl << "Welcome to Subhan's cafe!" << endl << "How can we help you today?" << endl;
    cout << "Menu :" << endl;


 return 0;
}