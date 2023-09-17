#include<iostream>
#include<fstream>//for filehandling  opertaion
using namespace std;

class shopping{
private:
   int pcode;
   float price;
   float dis;
   string pname;

   public:
     void menu();
     void administrator();
     void buyer();
     void add();
     void edit();
     void rem();
     void list();
     void recept();
};

void shopping::menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t_______________________________________\n ";
    cout<<"\t\t\t\t                                        \n";
     cout<<"\t\t\t\t         supermarket Main Menu          \n";
     cout<<"\t\t\t\t_______________________________________\n ";
     cout<<"\t\t\t\t                                        \n";


     cout<<"\t\t\t\t|( 1)Administrator   |\n";
     cout<<"\t\t\t\t|                    |\n";
     cout<<"\t\t\t\t|( 2)Buyer           |\n";
     cout<<"\t\t\t\t|                    |\n";
     cout<<"\t\t\t\t|( 3)Exit            |\n";
     cout<<"\t\t\t\t|                    |\n";
     cout<<"\n\t\t\t please select!";
     cin>>choice;

     switch(choice){
        case 1:
            cout<<"\t\t\t please Login  \n";
            cout<<"\t\t\t Enter Email   \n";
            cin>>email;
            cout<<"\t\t\t password      \n";
            cin>>password;

            if(email=="jackworth@email.com" && password=="jack@123"){
                administrator();
            }
            else{
                cout<<"invalid email/password";
            }
            break;
     

     case 2:
       {
        buyer();
       }
    case 3:
    {
        exit(0);
    }
    default:
       {
        cout<<"please select from the given option";
       }
 }
 goto m;//jumping back to the menu;
    
}

void shopping:: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t administrator menu";
    cout<<"\n\t\t\t|____1) Add the product________|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|____2) Modiofy the product____|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|____3) Delete the product_____|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|____4) Back to the main menu__|";
    
    cout<<"\n\n\t Please enter your choice";
    cin>>choice;

    switch(choice){
        case 1:
          add();
          break;
        case 2:
          edit();
          break;
        case 3:
          rem();
          break;
        case 4:
          menu();
          break;
        
        defult :
           cout<<"invalid choice!";
    }
goto m;

}

void shopping:: buyer(){
    m:
    int choice;
    cout<<"\t\t\t    Buyer       \n";
    cout<<"\t\t\t________________\n";
    cout<<"                      \n";
    cout<<"\t\t\t 1) Buy product \n";
    cout<<"                      \n";
    cout<<"\t\t\t 2) GO Back     \n";
    cout<<"\t\t\t Enter your choice :";

    cin>>choice;
    switch(choice){
       case 1:
          recept();
          break;
        case 2:
          menu();

        default :
          cout<<"invalid choice";
    }
    goto m;
}

void shopping:: add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n Name of the product";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    

    if(token==1)
      goto m;
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
}
    cout<<"\n\n\t\t Record inserted ! ";
}

void shopping::edit(){
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nFile doesnt exist! ";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t Product of new  code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t Record edited";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry !";
        }
    }
}
void shopping::rem(){
   fstream data,data1;
   int pkey;
   int token=0;
   cout<<"\n\n\t Delete product";
   cout<<"\n\n\t Product code :";
   cin>>pkey;
   data.open("database.txt",ios::in);
   if(!data){
    cout<<"File doesnt exist";

   }

   else{
    data1.open("database1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;

    while(!data.eof()){
        if(pcode==pkey){
            cout<<"\n\n\t product deleted succesfully";
            token++;
        }
        else{
            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        }
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt","database.txt");
    
    if(token==0){
        cout<<"\n\n Record not be found";
    }
   }
}

void shopping::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_____________________________________________________________________________\n";
    cout<<"prono\t\tname\t\tprice\n";
     cout<<"\n\n|____________________________________________________________________________\n";
     data>>pcode>>pname>>price>>dis;

     while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;

     }
     data.close();

}

void shopping :: recept(){
    
    fstream data;

    int arrc[100];
    int arrq[100];
    char ch;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t recept";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n empty database";

    }
    else{
        data.close();

        list();
        cout<<"\n_________________________________________________\n";
        cout<<"\n|                                                |\n";
        cout<<"\n|         please place the order                 |\n";
        cout<<"\n|________________________________________________|\n";

         do{
            m:
            cout<<"\n\nEnter the product code: ";
            cin>>arrc[c];
            cout<<"\n\nenter the product quantity:";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                  cout<<"\n\n duplicate product code.please try again!";
                  goto m;
                }
            }
            c++;
            cout<<"\n\n do you want to buy anither product ? if yes then press y else no";
            cin>>ch;
         }
         while(ch=='y');

         cout<<"\n\n\t\t\t__________________________recept_____________________________\n";
         cout<<"\nproduct no\t product name\t product quantity\tprice\tamount\tamount with discount\n";

         for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<"\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
         }
        data.close();

    }
    cout<<"\n\n_______________________________________________________________";
    cout<<"\n total amount: "<<total;

}
int main(){
    shopping s;
    s.menu();
}
