
//  Product Registration Tool
//



#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

void SaveState();
void CurrentTime();
void cIgnore();
void CreateNewList();
void PostListCreation();
void MainMenu();
void CreateNewProduct();
void PostProdCreation();
void GoBack();
void UpdateProductStock();
void PostProdUpdate();
void ViewProductList();
void BackToViewList();



// Initializations and definitions

const string LTITLE = "List: ";
const string TITLE = "Title: ";
const string CAT = "Category: ";
const string INFO = "Description: ";
const string LINFO = "List Description: ";
const string PRICE = "Price: $";
const string PRODPRICE = "Production Price: $";
const string NEWPRICE = "New price: $";
const string PROFIT = "Profit: $";
const string STOCK = "Stock: ";
const string BUYALL = "Price for all products in stock: $";

const time_t NOW = time(0);

int NumberSold = 0;
int NewPrice = 0;
int NewPPrice = 0; 
int Profit = 0;

const int NewProdSize = 10;
const int NewListSize = 2;



/* Save program state

void SaveState()
{
	ofstream file("save.sav");	
	
	file >> ProdSlot;
	file >> Title; 
	file >> Category;
	file >> PInfo;
	file >> Price;
	file >> PPrice;
	file >> Stock;
   	file >> TotalCost;
   	
	
}; */


void cIgnore()
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};


// Product List Class

struct NewList{
	
	string LTitle = "Untitled list .. ";
	string ListDescription = "Write list description here: ";
	
} List[NewListSize];


// Product Class

struct NewProduct{
   
	string Title = "Untitled .. "; 
	string Category = "Uncategorized .. ";
	string PInfo = "Write product info here: ";
	int Price;
	int PPrice;
	int Stock;
   	int TotalCost() {return Price*Stock;}
 	Product();
    
} Prod[NewProdSize];


// Create a new product list

void CreateNewList()
{
	system("CLS");
	cIgnore();
	
	cout << "_______________________\n";
	cout << "CREATE NEW PRODUCT LIST" << endl << endl;
	cout << "1 - List_1 - " << List[0].LTitle << endl;
	cout << "2 - List_2 - " << List[1].LTitle << endl << endl;
	cout << "3 - Return to Main Menu" << endl << endl;
	

	int NewListChoice = 0;
	cout << "Choose a list: ";
	cin >> NewListChoice;

	if (NewListChoice == 1)
	{
	system("CLS");
	cIgnore();
	
	cout << "LIST CREATION\n" << endl;
	
	cout << "List Name: ";
	cout << List[0].LTitle;
	getline(cin, List[0].LTitle);
	
	cout << "List Description: ";
	cout << List[0].ListDescription;
	getline(cin, List[0].ListDescription);
	
	
	cout << "_____________________\n";
	cout << "YOUR NEW PRODUCT LIST: \n" << endl;
	cout << LTITLE << List[0].LTitle << endl;
	cout << LINFO << List[0].ListDescription << endl << endl;
	
	
	PostListCreation();
}

	
	if (NewListChoice == 2)
	{
	system("CLS");
	cIgnore();
	
	cout << "LIST CREATION\n" << endl;
	
	cout << "List Name: ";
	cout << List[1].LTitle;
	getline(cin, List[1].LTitle);
	
	cout << "List Description: ";
	cout << List[1].ListDescription;
	getline(cin, List[1].ListDescription);
	
	
	cout << "_____________________\n";
	cout << "YOUR NEW PRODUCT LIST: \n" << endl;
	cout << LTITLE << List[1].LTitle << endl;
	cout << LINFO << List[1].ListDescription << endl << endl;
	
	
	PostListCreation();
}

	else if(NewListChoice == 3)
	MainMenu();
	
};



// Do after having created a product list

void PostListCreation()
{
	int PostListCreate = 0;
    cout << "1 - Create or modify another list\n";
    cout << "2 - Return to Main Menu\n" << endl;
    cout << "Do more or return to Main Menu? ";
    cin >> PostListCreate;
    
    if (PostListCreate == 1)
    {
    	CreateNewList();
	}
	
	else if (PostListCreate == 2)
	{
		MainMenu();
	}
};



// Create a new product

void CreateNewProduct()
{

	system("CLS");
	cIgnore();
    cout << "__________________" << endl;
    cout << "CREATE NEW PRODUCT" << endl << endl;	
	
	// Limited product slots (ONLY in early program vrs.). Pick one of 5 slots
	int ProdSlot = 0;
	
	cout << "Available Product Slots in the list \"" << List[0].LTitle << "\"" << endl << endl;
	cout << "1 - Product_1 - " << Prod[0].Title << endl;
	cout << "2 - Product_2 - " << Prod[1].Title << endl;
	cout << "3 - Product_3 - " << Prod[2].Title << endl;
	cout << "4 - Product_4 - " << Prod[3].Title << endl;
	cout << "5 - Product_5 - " << Prod[4].Title << endl << endl;
	
	cout << "6 - Return to Main Menu" << endl << endl;
	
	cout << "Which one would you like to create / modify? ";
	cin >> ProdSlot;
	
	cout << endl << endl;

	
	if (ProdSlot == 1)
	{
		system("CLS");
		cout << "PRODUCT CREATION" << endl << endl;
		cout << "Fill in the necessary product registration fields: " << endl << endl;
		cin.ignore();
		cout << TITLE << Prod[0].Title;
		getline(cin, Prod[0].Title);	
		cout << CAT << Prod[0].Category;
		getline(cin, Prod[0].Category);
		cout << INFO << Prod[0].PInfo;
		getline(cin, Prod[0].PInfo);
		cout << PRICE << Prod[0].Price;
		cin >> Prod[0].Price;
		cout << PRODPRICE << Prod[0].PPrice;
		cin >> Prod[0].PPrice;
		cout << STOCK << Prod[0].Stock;
		cin >> Prod[0].Stock;
		cout << endl << endl;

		cout << "_________________\n";
		cout << "YOUR NEW PRODUCT: \n" << endl;
		cout << TITLE << Prod[0].Title << endl;
		cout << CAT << Prod[0].Category << endl << endl;
		cout << INFO << Prod[0].PInfo << endl << endl;
		cout << PRICE << Prod[0].Price << endl;
		cout << PRODPRICE << Prod[0].PPrice << endl;
		cout << STOCK << Prod[0].Stock << endl;
		cout << "Price for all \"" << Prod[0].Title << "\" in stock: " << Prod[0].TotalCost() << endl << endl;
		
		PostProdCreation();
			
	}
	
	
	if (ProdSlot == 2)
	{
		system("CLS");
		cout << "PRODUCT CREATION" << endl << endl;
		cout << "Fill in the necessary product registration fields: " << endl << endl;
		cin.ignore();
		cout << TITLE << Prod[1].Title;
		getline(cin, Prod[1].Title);
		cout << CAT << Prod[1].Category;
		getline(cin, Prod[1].Category);
		cout << INFO << Prod[1].PInfo;
		getline(cin, Prod[1].PInfo);
		cout << PRICE << Prod[1].Price;
		cin >> Prod[1].Price;
		cout << PRODPRICE << Prod[1].PPrice;
		cin >> Prod[1].PPrice;
		cout << STOCK << Prod[1].Stock;
		cin >> Prod[1].Stock;
		cout << endl << endl << endl;
		cin.ignore();
		
		
		cout << "_________________\n";
		cout << "YOUR NEW PRODUCT: \n" << endl;
		cout << TITLE << Prod[1].Title << endl;
		cout << CAT << Prod[1].Category << endl << endl;
		cout << INFO << Prod[1].PInfo << endl << endl;
		cout << PRICE << Prod[1].Price << endl;
		cout << PRODPRICE << Prod[1].PPrice << endl;
		cout << STOCK << Prod[1].Stock << endl;
		cout << "Price for all \"" << Prod[1].Title << "\" in stock: " << Prod[1].TotalCost() << endl << endl;
		
		
		PostProdCreation();

	}
	
	
		if (ProdSlot == 3)
	{
		system("CLS");
		cout << "PRODUCT CREATION" << endl << endl;
		cout << "Fill in the necessary product registration fields: " << endl << endl;
		cin.ignore();
		cout << TITLE << Prod[2].Title;
		getline(cin, Prod[2].Title);
		cout << CAT << Prod[2].Category;
		getline(cin, Prod[2].Category);
		cout << INFO << Prod[2].PInfo;
		getline(cin, Prod[2].PInfo);
		cout << PRICE << Prod[2].Price;
		cin >> Prod[2].Price;
		cout << PRODPRICE << Prod[2].PPrice;
		cin >> Prod[2].PPrice;
		cout << STOCK << Prod[2].Stock;
		cin >> Prod[2].Stock;
		cout << endl << endl << endl;
		cin.ignore();
		
		
		cout << "_________________\n";
		cout << "YOUR NEW PRODUCT: \n" << endl;
		cout << CAT << Prod[2].Category << endl << endl;
		cout << INFO << Prod[2].PInfo << endl << endl;
		cout << PRICE << Prod[2].Price << endl;
		cout << PRODPRICE << Prod[2].PPrice << endl;
		cout << STOCK << Prod[2].Stock << endl;
		cout << "Price for all \"" << Prod[2].Title << "\" in stock: " << Prod[2].TotalCost() << endl << endl;
		
		
		PostProdCreation();
		
	}


		if (ProdSlot == 4)
	{
		system("CLS");
		cout << "PRODUCT CREATION" << endl << endl;
		cout << "Fill in the necessary product registration fields: " << endl << endl;
		cin.ignore();
		cout << TITLE << Prod[3].Title;
		getline(cin, Prod[3].Title);
		cout << CAT << Prod[3].Category;
		getline(cin, Prod[3].Category);
		cout << INFO << Prod[3].PInfo;
		getline(cin, Prod[3].PInfo);
		cout << PRICE << Prod[3].Price;
		cin >> Prod[3].Price;
		cout << PRODPRICE << Prod[3].PPrice;
		cin >> Prod[3].PPrice;
		cout << STOCK << Prod[3].Stock;
		cin >> Prod[3].Stock;
		cout << endl << endl << endl;
		cin.ignore();
		
		
		cout << "_________________\n";
		cout << "YOUR NEW PRODUCT: \n" << endl;
		cout << TITLE << Prod[3].Title << endl;
		cout << CAT << Prod[3].Category << endl << endl;
		cout << INFO << Prod[3].PInfo << endl << endl;
		cout << PRICE << Prod[3].Price << endl;
		cout << PRODPRICE << Prod[3].PPrice << endl;
		cout << STOCK << Prod[3].Stock << endl;
		cout << "Price for all \"" << Prod[3].Title << "\" in stock: " << Prod[3].TotalCost() << endl << endl;
		
		
		PostProdCreation();

	}


		if (ProdSlot == 5)
	{
		system("CLS");
		cout << "PRODUCT CREATION" << endl << endl;
		cout << "Fill in the necessary product registration fields: " << endl << endl;
		cin.ignore();
		cout << TITLE << Prod[4].Title;
		getline(cin, Prod[4].Title);
		cout << CAT << Prod[4].Category;
		getline(cin, Prod[4].Category);
		cout << INFO << Prod[4].PInfo;
		getline(cin, Prod[4].PInfo);
		cout << PRICE << Prod[4].Price;
		cin >> Prod[4].Price;
		cout << PRODPRICE << Prod[4].PPrice;
		cin >> Prod[4].PPrice;
		cout << STOCK << Prod[4].Stock;
		cin >> Prod[4].Stock;
		cout << endl << endl << endl;
		cin.ignore();
		
		
		cout << "_________________\n";
		cout << "YOUR NEW PRODUCT: \n" << endl;
		cout << TITLE << Prod[4].Title << endl;
		cout << CAT << Prod[4].Category << endl << endl;
		cout << INFO << Prod[4].PInfo << endl << endl;
		cout << PRICE << Prod[4].Price << endl;
		cout << PRODPRICE << Prod[4].PPrice << endl;
		cout << STOCK << Prod[4].Stock << endl;
		cout << "Price for all \"" << Prod[4].Title << "\" in stock: " << Prod[4].TotalCost() << endl << endl;
		
		
		PostProdCreation();
	}


	else if (ProdSlot == 6)
	{
		MainMenu();
	}
	
};



void PostProdCreation()
{
	// After product creation, create a new one or go back to main menu?
		cout << endl;
		cout << "1 - Create or modify another product" << endl;
		cout << "2 - Return to Main Menu" << endl << endl;
		
		int PostProdChoice = 0;
		cout << "Choose what to do next: ";
		cin >> PostProdChoice;
		
		
		if (PostProdChoice == 1)
		{
			CreateNewProduct();
		}
		else if (PostProdChoice == 2)
		{
			MainMenu();
		}
};



// Register number of sold or acquired items in stock

void UpdateProductStock()
{

	system("CLS");

	cout << "____________________" << endl;
	cout << "UPDATE PRODUCT STOCK" << endl << endl;
	
	cout << "1 - " << Prod[0].Title << endl;
	cout << "2 - " << Prod[1].Title << endl;
	cout << "3 - " << Prod[2].Title << endl;
	cout << "4 - " << Prod[3].Title << endl;
	cout << "5 - " << Prod[4].Title << endl << endl;
	cout << "6 - Return to Main Menu" << endl << endl;
	
	cout << "Choose product to update: ";
	
	int UpdateProduct = 0;
	cin >> UpdateProduct;
	
	
	// Update Product_1 stock
	
	if (UpdateProduct == 1)
	{
	system("CLS");
	cout << "UPDATING - \"" << Prod[0].Title << "\"" << endl << endl;
	
	// Stock update
	cout << "\"" << Prod[0].Title << "\" in " << STOCK << Prod[0].Stock << endl;
    cout << endl;
    cout << "Number of \"" << Prod[0].Title << "\" sold: " << NumberSold;
    cin >> NumberSold;
    cout << endl;
    
    // Price update
	
	cout << PRICE << Prod[0].Price << " - " << NEWPRICE << NewPrice;
	cin >> NewPrice;
	
	// Production Price update
    cout << PRODPRICE << Prod[0].PPrice << " - " << NEWPRICE << NewPPrice;
	cin >> NewPPrice;


    // Update overview
    cout << endl << endl << endl;
	cout << " -- PRODUCT " << Prod[0].Title << endl << endl;
    
	Prod[0].Stock = Prod[0].Stock-NumberSold;
   	cout << "\"" << Prod[0].Title << "\" in " << STOCK << Prod[0].Stock << endl << endl;
   	
	Prod[0].Price = NewPrice; 
	cout << PRICE << Prod[0].Price << endl << endl;
	
	Prod[0].PPrice = NewPPrice;
	cout << PRODPRICE << Prod[0].PPrice << endl << endl;
	

	PostProdUpdate();
    
	    
	}
	
	
	
	// Update Product_2 stock
	
	if (UpdateProduct == 2)
	{
	system("CLS");
	cout << "\"" << Prod[1].Title << "\" in " << STOCK << Prod[1].Stock << endl;
    cout << endl;
    cout << "Number of \"" << Prod[1].Title << "\" sold: " << NumberSold;
    cin >> NumberSold;
    cout << endl;

    Prod[1].Stock = Prod[1].Stock-NumberSold;

    cout << "\"" << Prod[1].Title << "\" in " << STOCK << Prod[1].Stock << " (updated)" << endl;
    cout << endl;
    cout << endl;
    
    PostProdUpdate();
    
}

	// Update Product_3 stock
	
	if (UpdateProduct == 3)
	{
	system("CLS");
	cout << "\"" << Prod[2].Title << "\" in " << STOCK << Prod[2].Stock << endl;
    cout << endl;
    cout << "Number of \"" << Prod[2].Title << "\" sold: " << NumberSold;
    cin >> NumberSold;
    cout << endl;

    Prod[2].Stock = Prod[2].Stock-NumberSold;

    cout << "\"" << Prod[2].Title << "\" in " << STOCK << Prod[2].Stock << " (updated)" << endl;
    cout << endl;
    cout << endl;
    
  	PostProdUpdate();
    
}


	// Update Product_4 stock
	
	if (UpdateProduct == 4)
	{
	system("CLS");
	cout << "\"" << Prod[3].Title << "\" in " << STOCK << Prod[3].Stock << endl;
    cout << endl;
    cout << "Number of \"" << Prod[3].Title << "\" sold: " << NumberSold;
    cin >> NumberSold;
    cout << endl;

    Prod[3].Stock = Prod[3].Stock-NumberSold;

    cout << "\"" << Prod[3].Title << "\" in " << STOCK << Prod[3].Stock << " (updated)" << endl;
    cout << endl;
    cout << endl;
    
    PostProdUpdate();
    
}


	// Update Product_5 stock
	
	if (UpdateProduct == 5)
	{
	system("CLS");
	cout << "\"" << Prod[4].Title << "\" in " << STOCK << Prod[4].Stock << endl;
    cout << endl;
    cout << "Number of \"" << Prod[4].Title << "\" sold: " << NumberSold;
    cin >> NumberSold;
    cout << endl;

    Prod[4].Stock = Prod[4].Stock-NumberSold;

    cout << "\"" << Prod[4].Title << "\" in " << STOCK << Prod[4].Stock << " (updated)" << endl;
    cout << endl;
    cout << endl;
    
    PostProdUpdate();
    
}

    // Return to Main Menu
    
    else if (UpdateProduct == 6)
    {
    	MainMenu();
	}
   
	cout << endl;
   
};



void PostProdUpdate()
{
	int PostProdUpdate = 0;
    cout << "1 - Update more products\n";
    cout << "2 - Return to Main Menu\n" << endl;
    cout << "Update more or return to Main Menu? ";
    cin >> PostProdUpdate;
    
    if (PostProdUpdate == 1)
    {
    	UpdateProductStock();
	}
	
	else if (PostProdUpdate == 2)
	{
		MainMenu();
	}
    
};



// Display the current product list

void ViewProductList()
{  
	system("CLS");

	cout << "____________" << endl;
	cout << "PRODUCT LIST" << endl << endl;
	
	cout << "Product Slots in \"" << List[0].LTitle << "\"" << endl << endl;
	
	cout << "1 - " << Prod[0].Title << " [" << Prod[0].Stock << "], " << Prod[0].Category << endl;
	cout << "2 - " << Prod[1].Title << " [" << Prod[1].Stock << "], " << Prod[1].Category << endl;	
	cout << "3 - " << Prod[2].Title << " [" << Prod[2].Stock << "], " << Prod[2].Category << endl;
	cout << "4 - " << Prod[3].Title << " [" << Prod[3].Stock << "], " << Prod[3].Category << endl;
	cout << "5 - " << Prod[4].Title << " [" << Prod[4].Stock << "], " << Prod[4].Category << endl << endl;
	
	cout << "Price for all " << (Prod[0].Stock+Prod[1].Stock+Prod[2].Stock+Prod[3].Stock+Prod[4].Stock) << 
	" products in the \"" << List[0].LTitle << "\" stock: $" << (Prod[0].TotalCost()+Prod[1].TotalCost()) << endl << endl;
	
	cout << "________________________" << endl;
	
	cout << "Product Slots in \"" << List[1].LTitle << "\"" << endl << endl;

	cout << "6 - " << Prod[5].Title << " [" << Prod[5].Stock << "], " << Prod[5].Category << endl;
	cout << "7 - " << Prod[6].Title << " [" << Prod[6].Stock << "], " << Prod[6].Category << endl;	
	cout << "8 - " << Prod[7].Title << " [" << Prod[7].Stock << "], " << Prod[7].Category << endl;
	cout << "9 - " << Prod[8].Title << " [" << Prod[8].Stock << "], " << Prod[8].Category << endl;
	cout << "10 - " << Prod[9].Title << " [" << Prod[9].Stock << "], " << Prod[9].Category << endl << endl;	
	
	cout << "Price for all " << (Prod[5].Stock+Prod[6].Stock+Prod[7].Stock+Prod[8].Stock+Prod[9].Stock) << 
	" products in the \"" << List[1].LTitle << "\" stock: $" << (Prod[5].TotalCost()+Prod[6].TotalCost()) << endl << endl;
	
	
	cout << "11 - Return to Main Menu\n" << endl;
	
	int ProdSelect = 0;
	cout << "For more detailed info, select a product: ";
	cin >> ProdSelect;
	
	/* SELECTION OF PRODUCT DETAILS */	
	
	if (ProdSelect == 1)
	{
	// Display Product_1
	
	system("CLS");
	
	cout << "PRODUCT DETAILS -- " << Prod[0].Title << endl << endl;
	
	cout << INFO << Prod[0].PInfo << endl << endl;
	cout << CAT << Prod[0].Category << endl;
	cout << PRICE << Prod[0].Price << endl;
	cout << PRODPRICE << Prod[0].PPrice << endl;
	cout << STOCK << Prod[0].Stock << endl << endl;
	
	BackToViewList();
}


	if (ProdSelect == 2)
	{
	// Display Product_2
	system("CLS");
	
	cout << "PRODUCT DETAILS -- " << Prod[1].Title << endl << endl;
	
	cout << INFO << Prod[1].PInfo << endl << endl;
	cout << CAT << Prod[1].Category << endl;
	cout << PRICE << Prod[1].Price << endl;
	cout << PRODPRICE << Prod[1].PPrice << endl;
	cout << STOCK << Prod[1].Stock << endl << endl;
	
	BackToViewList();
	
}

	if (ProdSelect == 3)
	{	
	// Display Product_3
	system("CLS");

	cout << "PRODUCT DETAILS -- " << Prod[2].Title << endl << endl;

	cout << INFO << Prod[2].PInfo << endl << endl;
	cout << CAT << Prod[2].Category << endl;
	cout << PRICE << Prod[2].Price << endl;
	cout << PRODPRICE << Prod[2].PPrice << endl;
	cout << STOCK << Prod[2].Stock << endl << endl;
	
	BackToViewList();
}
	
	
	if (ProdSelect == 4)
	{	
	// Display Product_4
	system("CLS");
	
	cout << "PRODUCT DETAILS -- " << Prod[3].Title << endl << endl;

	cout << INFO << Prod[3].PInfo << endl << endl;	
	cout << CAT << Prod[3].Category << endl;
	cout << PRICE << Prod[3].Price << endl;
	cout << PRODPRICE << Prod[3].PPrice << endl;
	cout << STOCK << Prod[3].Stock << endl << endl;
	
	BackToViewList();
}

	
	if (ProdSelect == 5)
	{
	// Display Product_5
	system("CLS");
	
	cout << "PRODUCT DETAILS -- " << Prod[4].Title << endl << endl;

	cout << INFO << Prod[4].PInfo << endl << endl;	
	cout << CAT << Prod[4].Category << endl;
	cout << PRICE << Prod[4].Price << endl;
	cout << PRODPRICE << Prod[4].PPrice << endl;
	cout << STOCK << Prod[4].Stock << endl << endl;
	
	BackToViewList();
}
	
	
	
	// Back to Main Menu
	else if (ProdSelect == 11)
	{
		MainMenu();
	}
	
	
	cout << endl;

}; 


void BackToViewList()
{
	int BackToViewList = 0;
	cout << "1 - Product List Overview" << endl;
	cout << "2 - Main Menu" << endl << endl;
	
	cout << "View product list, or return to Main Menu? ";
	cin >> BackToViewList;
	
	
	
	if (BackToViewList == 1)
	{
	ViewProductList();
	}
	
	else if (BackToViewList == 2)
	{
		MainMenu();
	}
};



// Output Software Name + Current Time

void CurrentTime()
{
    cout << "_____________________________" << endl;
    cout << "| PRODUCT REGISTRATION TOOL |" << endl;
    cout << "   " << asctime(localtime(&NOW)) << " " << endl;
};



// Whudduya wanna do, hombré - view list, new prod, or update prod?

void MainMenu()
{
	system("CLS");
	CurrentTime();
    cout << endl;
	cout << "-->> MAIN MENU <<--" << endl << endl << endl;
	cout << "1 - Create New Product List\n" << endl;
    cout << "2 - Create New Product\n" << endl;
    cout << "3 - Update Product Stock\n" << endl;
    cout << "4 - View Lists and Products\n" << endl << endl;


    cout << "To select an option, type its number and press \"Enter\": ";
   	int MainMenuChoice = 0;
    cin >> MainMenuChoice;

 	if (MainMenuChoice == 1)
    CreateNewList();
    
    if (MainMenuChoice == 2)
    CreateNewProduct();

    if (MainMenuChoice == 3)
    UpdateProductStock();
    
    if (MainMenuChoice == 4)
	ViewProductList();
    
    
 

};



void GoBack()
{
	cout << endl << endl;
	cout << "-- Back to main menu? [y] -- Or exit the program? [n]: ";

    string GoBack;
    cin >> GoBack;

    if(GoBack == "y" || GoBack == "Y")
	{
		MainMenu();
		cout << endl << endl;
	}
	else(GoBack == "" || GoBack == "");
	
	cout << endl << endl;
};



int main()
{
    MainMenu();


    return 0;    
}
