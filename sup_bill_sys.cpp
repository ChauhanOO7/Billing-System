#include<bits/stdc++.h>
using namespace std;

class product
{
    public:
        string pro_no,name;
        float price,discount;
        product(string no,string name,float price,float dis)
        {
            this->pro_no=no;
            this->name=name;
            this->price=price;
            this->discount=dis;
        }
};

class admin
{
    public:
        void add_product(string,string,float,float);
        void update_product(string);
        void delete_product(string);
        void display_all();
};

void admin::add_product(string no,string ne,float pr,float dis)
{
    product p=product(no,ne,pr,dis);
    fstream out;
    out.open("details_pro.txt",ios::app);
    out<<setw(8)<<p.pro_no<<setw(36)<<p.name<<setw(28)<<p.price<<setw(29)<<p.discount<<endl;
    out.close();
}

void admin:: delete_product(string no)
{
    fstream in,out;
    in.open("details_pro.txt",ios::in);
    out.open("det.txt",ios::app);
    string store="",line="";
    while(getline(in,line))
    {
        if(line.find(no)==string::npos)
        {
            out<<line<<endl;
        }
    }
    in.close();
    out.close();
   
    remove("details_pro.txt");
    rename("det.txt","details_pro.txt");

    cout<<"Product Deleted Successfully..."<<endl;

}

void admin:: update_product(string no)
{
    fstream in,out;
    in.open("details_pro.txt",ios::in);
    out.open("det.txt",ios::out);
    string line="";
    while(getline(in,line))
    {
        if(line.find(no)!=string::npos)
        {
            string ne,pn;
            float pr,dis;
            cout<<endl;
            cout<<"Enter the product Number :";
            cin>>pn;
            cin.ignore();
            cout<<"Enter the Name of the product :";
            getline(cin,ne);
            cout<<"Enter the Price of the Product :";
            cin>>pr;
            cout<<"Enter the Discount of the product :";
            cin>>dis;
            out<<setw(8)<<pn<<setw(36)<<ne<<setw(28)<<pr<<setw(29)<<dis<<endl;
            cout<<"Product Successfully Added..."<<endl;
        }
        else
        {
            out<<line<<endl;
        }
    }

    in.close();
    out.close();
    remove("details_pro.txt");
    rename("det.txt","details_pro.txt");

}
void admin:: display_all()
{
    ifstream in;
    in.open("details_pro.txt",ios::in);
    string line="";
    while(getline(in,line))
    {
        cout<<line<<endl;
    }

    in.close();
}

class buyer
{
    public:
        void Buy_product(string,int);
        void make_bill(float);
        void delete_curr_bill();
};

void buyer::Buy_product(string se,int i)
{
    int counter=i;
    string line="";
    fstream out,in;
    in.open("details_pro.txt",ios::in);
    if(counter==0)
    {
        out.open("buyer.txt",ios::out);
        out<<"Product Number"<<setw(30)<<" Name "<<setw(30)<<"Price"<<setw(30)<<"Discount"<<endl;
        out.close();
    }
    out.open("buyer.txt",ios::app);
    while(getline(in,line))
    {
        if(line.find(se)!=string::npos)
        {
            out<<line<<endl;
        }
    }
    in.close();
    out.close();

}

void buyer:: make_bill(float total_amount)
{
    ifstream in;
    in.open("buyer.txt");
    string line="";
    while(getline(in,line))
    {
        cout<<line<<endl;
    }
    cout<<endl;
    cout<<setw(100)<<"Total Amount :"<<total_amount<<endl;

    in.close();
}

void buyer:: delete_curr_bill()
{
    ofstream out;
    out.open("buyer.txt",ios::out);
    out.close();
    
}

int main()
{
    admin ad;
    buyer by;
    int choice,to_menu=0,i=0;
    float pr,dis,total_amount=0;
    string ne,pn,admin_id="",pass="";

    do
    {
        cout<<"----------------------------------Supermarket Billing System---------------------------------------------"<<endl<<endl;
        cout<<"                                    1. Adminstration"<<endl;
        cout<<"                                    2. Buyer"<<endl;
        cout<<"                                    3. Exit"<<endl;

        cout<<"Enter your choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<endl;
                cout<<"Admin Id :";
                cin>>admin_id;
                cin.ignore();
                cout<<"Password :";
                getline(cin,pass);
                cout<<endl;
                if(admin_id!="supermarket111@gmail.com" || pass!="invoicesystem")
                {
                    cout<<"Invalid details..."<<endl;
                    break;
                }
                do
                {
                    cout<<"---------------------------------------Adminstraion---------------------------------------------"<<endl<<endl;
                    cout<<"                                    1. Add Product"<<endl;
                    cout<<"                                    2. Update Product"<<endl;
                    cout<<"                                    3. Delete Product"<<endl;
                    cout<<"                                    4. Display Available Products"<<endl;
                    cout<<"                                    5. Exit to Menu"<<endl;

                    cout<<"Enter your choice :";
                    cin>>choice;

                    switch(choice)
                    {
                        case 1:
                                cout<<"Enter the product Number :";
                                cin>>pn;
                                cin.ignore();
                                cout<<"Enter the Name of the product :";
                                getline(cin,ne);
                                cout<<"Enter the Price of the Product :";
                                cin>>pr;
                                cout<<"Enter the Discount of the product :";
                                cin>>dis;
                                ad.add_product(pn,ne,pr,dis);
                                break;

                        case 2:
                            {
                                string no;
                                cout<<"Enter the product no you want to update :";
                                cin>>no;
                                ad.update_product(no);
                                break;
                            }
                        case 3:
                            {
                                ad.display_all();
                                cout<<endl;
                                string no;
                                cout<<"Enter the product no you want to delete :";
                                cin>>no;
                                ad.delete_product(no);
                                break;
                            }
                        
                        case 4:
                                ad.display_all();
                                cout<<endl;
                                break;
                        case 5:
                                to_menu++;
                                break;
                        default:
                                cout<<"Invalid Choice..."<<endl;
                    }

                    if(to_menu>0)
                    {
                        to_menu=0;
                        break;
                    }
                    
                }while(1);
                
                break;

            case 2:
                do
                {
                    cout<<"-------------------------------------------Buyer---------------------------------------------"<<endl<<endl;
                    cout<<"                                    1. Buy Product"<<endl;
                    cout<<"                                    2. Make Bill"<<endl;
                    cout<<"                                    3. Exit to Menu"<<endl;

                    cout<<"Enter the choice :";
                    cin>>choice;

                    switch(choice)
                    {
                        case 1:
                            {
                                string se;
                                float pr,dis;
                                cout<<endl;
                                ad.display_all();
                                cout<<endl;
                                cout<<"Product number :";
                                cin>>se;
                                cout<<"Price of the Product :";
                                cin>>pr;
                                cout<<"Discount on the Product :";
                                cin>>dis;
                                by.Buy_product(se,i);
                                total_amount+=(pr-((dis/100)*pr));
                                i++;
                                cout<<endl;
                            }
                            
                            break;
                        case 2:
                            by.make_bill(total_amount);
                            by.delete_curr_bill();
                            total_amount=0;
                            i=0;
                            break;
                        case 3:
                            to_menu++;
                            break;
                        default:
                            cout<<"Invalid choice..."<<endl;
                        
                    }
                    if(to_menu>0)
                    {
                        to_menu=0;
                        break;
                    }
                }while(1);

                break;
            
            case 3:
                exit(0);

            default:
                cout<<"Invalid Choice"<<endl;

        }

    }while(1);

    return 0;
}