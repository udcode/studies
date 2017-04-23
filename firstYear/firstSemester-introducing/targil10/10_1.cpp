//yudi noiman
//id: 301759692
//this code manage a store.
//main functions of the store: add items, sold, order find price and print the items list

#include <iostream>
#include <cstring>
using namespace std;

struct Item{
    int id;
    char name[20];
    int amount;
    int minAmount;
    float price;
};
/**
 * @brief addItem Add item to the store.
 *      update amount if item id exist and the name is the same.
 *      if the name is not the same print error.
 * @param store Pointer to the store list.
 * @param maxItems Max number of item that the store can contain.
 * @param numItems The num of the item that in the store. [by ref]
 */
void addItem(Item * store,int  maxItems,int &numItems);
/**
 * @brief findPrice Find the price an item that user set.
 *       an error whould be printed if the id is not in the list.
 * @param store Pointer to the store list.
 * @param numItems The num of the item that in the store.
 */
void findPrice(Item * store,int numItems);
/**
 * @brief sold Sell item by number of amount that the user give.
 * @param store Pointer to the store list.
 * @param numItems The num of the item that in the store.
 */
void sold(Item * store,int  numItems);
/**
 * @brief order Do order for the items that their amount is short from the minimum amount
 *      and print order details.
 * @param store Pointer to the store list.
 * @param numItems The num of the item that in the store.
 * @note  I ASSUMED THAT AMOUNT CANT BE NEGATIVE
 */
void order(Item * store,int numItems);
/**
 * @brief print Print the list of the items
 * @param store Pointer to the store list.
 * @param numItems The num of the item that in the store.
 */
void print(Item * store,int numItems);
/**
 * @brief findItem Find the item by id.
 * @param store Pointer to the store list.
 * @param numItems The num of the item that in the store.
 * @param id The id to look for.
 * @return the index of the item in the list or -1 if not found.
 */
int findItem(Item * store,int  numItems,int id);


int main(){
    Item * store;
    int maxItems;
    int numItems=0;
    int choice;
    //get the maximum items
    cout << "enter max number of items: "<<endl;
    cin >> maxItems;
    store = new Item[maxItems];

    do{//loop for choice
        cout << "enter 0-5:\n";
        cin >> choice;

        switch (choice){
        case 0:	break;//get out
        case 1://add item
            addItem(store, maxItems, numItems);
            break;
        case 2://find price
            findPrice(store, numItems);
            break;
        case 3://sold
            sold(store, numItems);
            break;
        case 4://order
            order(store, numItems);
            break;
        case 5://print
            print(store, numItems);
            break;
        default : 	cout << "ERROR" << endl;
        }
    } while (choice != 0);
    //free the memory
    delete [] store;

    return 0;
}
void addItem(Item * store,int  maxItems,int &numItems){
    //get the new item from the user
    Item newItem;
    cout<<"enter code:"<<endl;
    cin>>newItem.id;
    cout<<"enter name:"<<endl;
    cin.ignore();
    cin.getline(newItem.name,20);
    cout<<"enter amount:"<<endl;
    cin>>newItem.amount;
    cout<<"enter minimum amount:"<<endl;
    cin>>newItem.minAmount;
    cout<<"enter price:"<<endl;
    cin>>newItem.price;

    //check if the id is in the list
    int foundIndex = findItem(store,numItems,newItem.id);
    if(foundIndex<0){//no such item yet
        if(numItems<maxItems){//insert
            store[numItems].id=newItem.id;
            strcpy(store[numItems].name,newItem.name);
            store[numItems].amount=newItem.amount;
            store[numItems].minAmount=newItem.minAmount;
            store[numItems].price=newItem.price;
            ++numItems;
        }else{//no space for more items
            cout<<"ERROR"<<endl;
        }
    }else{//list has such id
        //check if their names are the same
        if(strcmp(store[foundIndex].name,newItem.name)==0){//update
            store[foundIndex].amount+=newItem.amount;
        }else{//no match
            cout<<"ERROR"<<endl;
        }
    }
}

int findItem(Item * store, int  numItems, int id){
    for(int i=0;i<numItems;++i){//move over the array
        if(store[i].id==id){//ther is such id in the list
            return i;
        }
    }
    return -1;
}
void findPrice(Item * store,int numItems){
    int code;
    //get the id from the user
    cout<<"enter code:"<<endl;
    cin>>code;
    //check if the id is in the list
   int foundIndex= findItem(store,numItems,code);
   if(foundIndex>=0){//found
       //print the price
       cout<<"price: "<<store[foundIndex].price<<endl;
   }else{//not found
       cout<<"ERROR"<<endl;
   }
}
void sold(Item * store,int  numItems){
    int code,amount,indexFound;
    //get the id and the amount to sold from the user
    cout<<"enter code:"<<endl;
    cin>>code;
    cout<<"enter amount:"<<endl;
    cin>>amount;

    //check if the id is in the list
    indexFound= findItem(store,numItems,code);
    if(indexFound>=0){//found
        //update the amount
        store[indexFound].amount-=amount;
        //I ASSUMED THAT AMOUNT CANT BE NEGATIVE
        if(store[indexFound].amount<0){
            store[indexFound].amount=0;
        }
    }else{//not found
        cout<<"ERROR"<<endl;
    }
}
void order(Item * store,int numItems){
    int itemsToOrder;
    //move over the list and update when the amount is smaller then the minimum amount
    for(int i =0;i<numItems;++i){
        if(store[i].amount<store[i].minAmount){//need to update
            //number items to order
            itemsToOrder=(store[i].minAmount+5)-store[i].amount;
            //print details
            cout<<"item name: "<<store[i].name<<endl;
            cout<<"code: "<<store[i].id<<endl;
            cout<<"amount to order: "<<itemsToOrder<<endl;
            //update
            store[i].amount+=itemsToOrder;
        }
    }
}
void print(Item * store,int numItems){
    //move over the array and print everything
    for(int i=0;i<numItems;++i){
        cout<<"name: "<<store[i].name<<endl;
        cout<<"code: "<<store[i].id<<endl;
        cout<<"amount: "<<store[i].amount<<endl;
        cout<<"minimum amount: "<<store[i].minAmount<<endl;
        cout<<"price: "<<store[i].price<<endl;
        cout<<endl;
    }
}
/*
 * enter max number of items:
2
enter 0-5:
1
enter code:
100
enter name:
arr
enter amount:
100
enter minimum amount:
20
enter price:
12.3
enter 0-5:
1
enter code:
102
enter name:
crt
enter amount:
15
enter minimum amount:
2
enter price:
5.6
enter 0-5:
2
enter code:
102
price: 5.6
enter 0-5:
3
enter code:
100
enter amount:
50
enter 0-5:
4
enter 0-5:
5
name: arr
code: 100
amount: 50
minimum amount: 20
price: 12.3

name: crt
code: 102
amount: 15
minimum amount: 2
price: 5.6

enter 0-5:
0
*/

