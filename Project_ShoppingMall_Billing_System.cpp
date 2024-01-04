#include<iostream>
#include<fstream>
#include <Windows.h>

using namespace std;

class mall
{
public:
	void mainscreen()
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t     _____________________________  \t\t\t\n";
		 cout << "\t\t\t\t\t    |                             | \t\t\t\n";
	    cout << "\t\t\t\t\t    | 	       MAIN MENU          | \t\t\t\n";
	    cout << "\t\t\t\t\t    |_____________________________| \t\t\t\n\n\n";
		cout << "1) Administrator\t\t\t\n\n\n";
		cout << "2) Buyer\t\t\t\n\n\n";
	    cout << "3) Exit\t\t\t\n\n\n";
	    cout << "Please select 1-3: \n\n\n";
	}	 
};

class Admin : public mall
{
	int prod_code;
	string prod_name;
	float prod_price;
	float prod_discount;


public:
	void choice()
	{
	int choice;
	//system("cls");
	a:
	cout << "\n\n\t\t\t\t\t -----------------------------------------\t\t\t\t\t\n";
	cout << "\t\t\t\t\t|                                         |\t\t\t\t\t\n";
	cout << "\t\t\t\t\t|             ADMINISTRATOR MENU          |\t\t\t\t\t\n";
	cout << "\t\t\t\t\t|                                         |\t\t\t\t\t\n";
	cout << "\t\t\t\t\t -----------------------------------------\t\t\t\t\t\n";
	cout << "1) Add the product\t\t\t\n\n\n";
	cout << "2) Edit the product\t\t\t\n\n\n";
    cout << "3) Delete the product\t\t\t\n\n\n";
    cout << "4) Back to main menu\t\t\t\n\n\n";
    cout << "Please select your choice: ";
    cin >> choice;
    system("cls");
     switch (choice) 
    {
      case 1:
        add();
        break;
      case 2:
        edit();
        break;
      case 3:
        del();
        break;
	//  default :
	//  	cout << "Please Enter Valid Choice!\n";
		goto a;
		break;
    }
		
	}

    
    
    void add()
	{
		
		fstream file;
		int pi;
		string pn;
		float pp,pd;
		int dup = 0;
		d:
		dup = 0;
		cout << "\t\t\t ADD NEW PRODUCT \t\t\t\n";
		cout << "Enter the product ID: ";
		cin  >> prod_code;
		cout << "\nEnter the product name: ";
		cin  >> prod_name;
		cout << "\nEnter the product price: ";
		cin  >> prod_price;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			goto d;
		}
		cout << "\nEnter the product discount: ";
		cin  >> prod_discount;
		
		file.open("malldata.txt", ios::in);
		
		if(!file)
		{
			file.open("malldata.txt",ios::app|ios::out);
			file<<prod_code<<" "<<prod_name<<" "<<prod_price<<" "<<prod_discount << "\n";
			file.close();
		}
		else
		{
			file>>pi>>pn>>pp>>pd;
			
			while(!file.eof())
			{
				if(prod_code == pi)
				{
				  dup = 1;	
				}
			  file>>pi>>pn>>pp>>pd;
			}
			file.close();
			
			if(dup==1)
			{
				cout << "\nProduct id already exists\n\n";
				goto d;
			}
			else
			{
				file.open("malldata.txt",ios::app|ios::out);
			    file<<prod_code<<" "<<prod_name<<" "<<prod_price<<" "<<prod_discount << "\n";
			    file.close();
			}
		}
		system("cls");
		cout << "\n\n YOUR RECORD IS BEING INSERTED!\n";
		Sleep(3000);
	}
	
	void edit()
	{
		fstream file,file2;
		int pi;
		string pn;
		float pp,pd;
		int dup = 0;
		int prod_key;
		cout << "\t\t\t EDIT THE PRODUCT \t\t\t\n";
		L:
		cout << "Enter the Product Code: ";
		cin  >> prod_key;
		
		file.open("malldata.txt", ios::in);
		
		if(!file)
		{
			cout << "\nFile doesn't exist ";
		}
		else
		{
			file2.open("malldata2.txt", ios::out);
			
			file>>pi>>pn>>pp>>pd;
			
			while(!file.eof())
			{
				if (prod_key == pi)
				{
					
					cout << "\nEnter the product name: ";
					cin  >> pn;
					cout << "\nEnter the product price: ";
					cin  >> pp;
					cout << "\nEnter the product discount: ";
					cin  >> pd;
					file2 << prod_key << " " << pn << " " << pp << " " << pd << "\n";
					cout << "\t\t\n RECORD EDITED\t\t\n";
					dup++;
				}
				else
				{
					file2<<pi<<" "<<pn<<" "<<pp<<" "<<pd<<"\n";
				}
				file>>pi>>pn>>pp>>pd;
			}
			file.close();
			file2.close();
			
			remove("malldata.txt");
			rename("malldata2.txt","malldata.txt");
			
			if (dup==0)
			{
				cout << "\n Record Not Found \n\n";
				goto L;
			}
		}
		    Sleep(3000);

	}
	
	void del()
	{
		fstream file,file2;
		int dup = 0;
		int prod_key;
		
		cout << "\t\t\t DELETE THE PRODUCT \t\t\t\n";
		cout << "Enter the Product Code: ";
		cin  >> prod_key;
		
		file.open("malldata.txt", ios::in);
		
		if(!file)
		{
			cout << "\nFile doesn't exist ";
		}
		else
		{
			file2.open("malldata2.txt",ios::out);
			
			file>>prod_code>>prod_name>>prod_price>>prod_discount;
			
			while(!file.eof())
			{
				if (prod_key == prod_code)
				{
					cout << "\t\t\n PRODUCT IS BEING DELETED \t\t\n";
					dup++;
				}
				else
				{
					file2<<prod_code<<" "<<prod_name<<" "<<prod_price<<" "<<prod_discount<<"\n";
				}
				file>>prod_code>>prod_name>>prod_price>>prod_discount;
			}
			file.close();
			file2.close();
			
			remove("malldata.txt");
			rename("malldata2.txt","malldata.txt");
			
			if (dup==0)
			{
				cout << "\n Record Not Found ";
			}
		}
		Sleep(3000);
	}
	
};

class Buyer : public mall
{
	int prod_code;
	string prod_name;
	int prod_price;
	int prod_discount;
	int choice;
public:
	void list()
	{
		
		fstream file;
		file.open("malldata.txt", ios::in);
		if(file.is_open())
	  {
		
		cout << "\n\n----------------------------------------------------------------------------\n";
		cout << "Product Number\t\tName\t\tPrice\t\tDiscount\n";
		cout << "\n\n----------------------------------------------------------------------------\n";
		file >> prod_code >> prod_name >> prod_price >> prod_discount;
		while(!file.eof())
		{
			cout << prod_code << "\t\t\t" << prod_name << "\t\t" << prod_price << "\t\t" << prod_discount << " %"<<'\n';
			file >> prod_code >> prod_name >> prod_price >> prod_discount;
		}
	  }
	  else
	  {
	  	cout << "\nCouldn't Find the File!\n";
	  }   
		file.close();
	}
	
	void receipt()
	{
		fstream file;
		
		int c=0;
		int arrcode[200];
		int arrquantity[200];
		char choice;
		float prod_amount = 0;
		float prod_discount = 0;
		float prod_total = 0;
		
		cout << "\t\t\n RECEIPT \t\t\n";
		file.open("malldata.txt", ios::in);
		if(!file)
		{
			cout << "\n\nEMPTY";
		}
		
		else 
		{
			file.close();
		
			cout<< "\t\t--------------------------------------\n";
			cout<< "\t\t          Place the order!            \n";
			cout<< "\t\t--------------------------------------\n";
			
			do
			{
				h:
				cout << "\t\t\n Enter product code: ";
				cin >> arrcode[c];
				cout << "\t\t\n Enter product quantity: ";
				cin >> arrquantity[c];
				for(int i=0; i<c ; i++)
				{
					if(arrcode[c]==arrcode[i])
					{
						cout << "\n\n Duplicate code of Product. Try Again!";
						goto h;
					}
				}
				c++;
				cout<<"\n\nDo you want to buy another product? Press y for 'Yes' and n for 'No' : ";
				cin>> choice;
				
			}
			while(choice== 'y' || choice== 'Y');
			system("cls");
			cout<< "\t\t\t\n\n------------------ RECEIPT ---------------------- \n\n";
			cout<<"\nProduct Number\tProduct Name\tProduct Quantity\tProduct Price\tProduct Amount\tAmount with discount\n";
			for(int i=0;i<c;i++)
			{
				file.open("malldata.txt", ios::in);
				file >> prod_code >> prod_name >> prod_price >> prod_discount;
				
				while(!file.eof())
				{
					if(prod_code==arrcode[i])
					{
						prod_amount = prod_price*arrquantity[i];
						prod_discount = prod_amount - (prod_amount*(prod_discount/100));
						prod_total+= prod_discount;
						cout << "\n"<<prod_code<<"   \t\t"<<prod_name<<"\t\t  "<<arrquantity[i]<<"\t\t\t  "<<prod_price<<"\t\t  "<<prod_amount<<"\t\t  "<<prod_discount;
					}
					file >> prod_code >> prod_name >> prod_price >> prod_discount;
				}
				file.close();
			}
		}
		cout << "\n\n-----------------------------------------\n";
		cout << "Total Amount: " << prod_total;
		Sleep(5000);
	}
};
int main(){
	char input;
	mall m1;
	Admin ad;
	Buyer b1;
	cout << "\n\n\t\t\t\t\t -----------------------------------------\t\t\t\t\t\n";
	cout << "\t\t\t\t\t|                                         |\t\t\t\t\t\n";
	cout << "\t\t\t\t\t| 	   WELCOME TO  SHOPPING MALL      |\t\t\t\t\t\n";
	cout << "\t\t\t\t\t|                                         |\t\t\t\t\t\n";
	cout << "\t\t\t\t\t -----------------------------------------\t\t\t\t\t\n";
	Sleep(3000);
	do
	{
		m1.mainscreen();
		cin >> input;
		system("cls");
		//cout << "\n";
		if(input == '1')
		{
			ad.choice();
			//break;
		}
		else if(input == '2')
		{
			b1.list();
			
			cout<<"\n\n-----------------\n\n";
			b1.receipt();
			//break;
		}
		
		else if(input == '3')
		{
			exit(0);
		}
		else
		{
			cout << "Please Enter Valid Choice!\n";
		}
	}while (input!='3');
	

	return 0;
}

