#include <iostream>

using namespace std;

struct Product
{
    string name;
    float price;
    Product* next = nullptr;
};
struct Section
{
    string name;
    Product *product = nullptr;
    Section* next = nullptr;
};
struct Store
{
    string name;
    string owner;
    Section *section = nullptr;
    Store *next = nullptr;
};
struct City
{
    string name;
    public:int shops;
    Store *store = nullptr;
    City* next = nullptr;
    City* prev = nullptr;
};

class StoreManagement{

    City *head = nullptr;
    City *tail = nullptr;

    //Function to find city using name
    public:City* search_city(string key){
        City *p = head;

        while (p != nullptr && p->name != key){
            p = p->next;
        }
        return p;
    }//search ends here

    //Function to find store using name
    public:Store* search_store(City* c_p, string key){
        if(!c_p){
            return nullptr;
        }
        Store *p = c_p->store;

        while (p != nullptr && p->name != key){
            p = p->next;
        }
        return p;
    }//search ends here

    //Function to find section using name
    public:Section* search_section(Store *s_p, string key){
        if(!s_p){
            return nullptr;
        }
        Section *p = s_p->section;

        while (p != nullptr && p->name != key){
            p = p->next;
        }
        return p;
    }//search ends here

    public:void add_city(City *curr){
        if (head == nullptr)
        {
            head = tail = curr;
        }
        else
        {
            tail->next = curr;
            curr->prev = tail;
            tail = curr;
        }
    }

    public:void add_store(string city_name, Store *curr){

        City *city = search_city(city_name);
        if(!city){
            cout<<"City not found";
            return;
        }
        if (city->store == nullptr)
        {
            city->store = curr;
        }
        else
        {
            Store* store_p = city->store;

            while (store_p->next != nullptr){
                store_p = store_p->next;
            }
            store_p->next = curr;
        }

        city->shops+=1;
    }

    public:void add_section(string city_name, string store_name, Section *curr){

        City *city = search_city(city_name);
        Store* store = search_store(city, store_name);

        if(!city || !store){
            cout<<"City or Store not found";
            return;
        }


        if (store->section == nullptr)
        {
            store->section = curr;
        }
        else
        {
            Section* section_p = store->section;

            while (section_p->next != nullptr){
                section_p = section_p->next;
            }
            section_p->next = curr;
        }
    }

    public:void add_product(string city_name, string store_name, string section_name, Product *curr){

        City *city = search_city(city_name);
        Store* store = search_store(city, store_name);
        Section* section = search_section(store, section_name);

        if(!city || !store || !section){
            cout<<"Error........";
            return;
        }

        if (section->product == nullptr)
        {
            section->product = curr;
        }
        else
        {
            Product* product_p = section->product;

            while (product_p->next != nullptr){
                product_p = product_p->next;
            }
            product_p->next = curr;
        }
    }

    public:void remove_product(string city_name, string store_name, string section_name, string product_name){

        City *city = search_city(city_name);
        Store* store = search_store(city, store_name);
        Section* section = search_section(store, section_name);

        if (section->product->name == product_name){
            section->product = section->product->next;
        }

        else{
            Product* product_p = section->product;

            while (product_p->next->name != product_name && product_p!=nullptr){
                product_p = product_p->next;
            }

            if(product_p){
                product_p->next = product_p->next->next;
            }
        }

    }

    public:void display_product(Product* p){
        cout<<"Name: "<<p->name<<"\n";
        cout<<"Price: "<<p->price;
        cout<<"\n\n";
        return;
    }

    public:void display_from_section(string city_name, string store_name, string section_name){
        City *city = search_city(city_name);
        Store* store = search_store(city, store_name);
        Section* section = search_section(store, section_name);

        if(!section){
            cout<<"Error.....";
            return;
        }
        Product* p = section->product;
        cout<<"\nPrducts in Section: "<<section->name<<"\n";

        while (p!=nullptr){
            display_product(p);
            p=p->next;
        }
    }

    public:void display_for_store(string city_name, string store_name){
        City *city = search_city(city_name);
        Store* store = search_store(city, store_name);

        Section* section_p = store->section;

        while (section_p!=nullptr)
        {
            Product* p = section_p->product;
            cout<<"\nPrducts in Section: "<<section_p->name<<"\n";

            while (p!=nullptr){
                display_product(p);
                p = p->next;
            }

            section_p = section_p->next;
        }
        
    }

};

int main(){
    int check = -1;

    StoreManagement* system = new StoreManagement;

    while(check !=0){
    cout << "\n1- Add City\n2- Add Store\n3- Add Section\n4- Add Product\n5- Products(Section)\n6- Products(Store)\n7- Remove Product\n0- Exit\n";
    cin >> check;
    if(check==1){
        City* curr = new City;
        string name;
        cout<<"Enter name of City: ";
        cin>>curr->name;

        system->add_city(curr);
    }

    else if(check==2){
        Store* curr = new Store;
        string city_name;
        cout<<"Enter name of City: ";
        cin>>city_name;
        cout<<"Enter name of Store: ";
        cin>>curr->name;
        cout<<"Enter name of Owner: ";
        cin>>curr->owner;

        system->add_store(city_name, curr);
    }

    else if(check==3){
        Section* curr = new Section;
        string city_name, store_name;
        cout<<"Enter name of City: ";
        cin>>city_name;
        cout<<"Enter name of Store: ";
        cin>>store_name;
        cout<<"Enter name of Section: ";
        cin>>curr->name;

        system->add_section(city_name, store_name, curr);
    }

    else if(check==4){
        Product* curr = new Product;
        string city_name, store_name, section_name;
        cout<<"Enter name of City: ";
        cin>>city_name;
        cout<<"Enter name of Store: ";
        cin>>store_name;
        cout<<"Enter name of Section: ";
        cin>>section_name;
        cout<<"Enter name of Product: ";
        cin>>curr->name;
        cout<<"Enter Price of Product: ";
        cin>>curr->price;

        system->add_product(city_name, store_name, section_name, curr);
    }

    else if(check==5){
        string city_name, store_name, section_name;
        cout<<"Enter name of City: ";
        cin>>city_name;
        cout<<"Enter name of Store: ";
        cin>>store_name;
        cout<<"Enter name of Section: ";
        cin>>section_name;

        system->display_from_section(city_name, store_name, section_name);
    }

    else if(check==6){
        string city_name, store_name, section_name;
        cout<<"Enter name of City: ";
        cin>>city_name;
        cout<<"Enter name of Store: ";
        cin>>store_name;

        system->display_for_store(city_name, store_name);
    }

    else if(check==7){
        string city_name, store_name, section_name, product_name;
        cout<<"Enter name of City: ";
        cin>>city_name;
        cout<<"Enter name of Store: ";
        cin>>store_name;
        cout<<"Enter name of Section: ";
        cin>>section_name;
        cout<<"Enter name of Product: ";
        cin>>product_name;

        system->remove_product(city_name, store_name, section_name, product_name);
    }

    else if(check ==0){
        cout<<"Thanks..........";
        break;
    }

    else{
        cout<<"\nInvalid Input\n";
    }


}

}



