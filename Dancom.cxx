#include<iostream>
#include<string> 
#include<ctime>
#include<fstream>
#include<sstream>
#include<vector>
#include<conio.h>
#include<filesystem>
#include<cstdlib>
#include<iomanip>
#include<random>
#include <sqlite3.h>
#include <curl/curl.h>
#include <openssl/sha.h>
#include<stdio.h>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <ctype.h>
#include <stdexcept>
#include <sqlite3.h> // SQLite C++ Connector

using namespace std;

class Account {
private:
    double balance;
    int  loan_amount;
    bool hasLoan;
    

public:
    Account() : balance(500), loan_amount(0), hasLoan(false) {}
int rate;

void Sendmoney(int ammount )
{ 
    if (hasLoan && ammount <= loan_amount)
    {
        loan_amount -= ammount;
    }
    else if (hasLoan && ammount > loan_amount)
    {
        loan_amount-=ammount;        
    }
    else if (!hasLoan && ammount <= balance)
    {
        balance -= ammount;
    }
    else if (!hasLoan && ammount > balance)
    {
        balance -= ammount;
    }
}
   void withedraw ( int ammount)
   {
    if (ammount <= balance)
    { 
    balance -= ammount;
    }    
   }
   
   void airtime(int ammount)
   {
      if (ammount < balance)
      {
           balance-=ammount;
      }
   }
    void deposit(unsigned int Deposit) {
        balance += Deposit;

        if (hasLoan && Deposit >= loan_amount) {
            balance += Deposit;
            balance -= loan_amount+ rate;                  
            hasLoan = false;
            
           
        } else if (hasLoan && Deposit < loan_amount) {
            balance += Deposit;
            loan_amount -= balance;
            std::cout << "Partial loan repayment made! Remaining loan amount: " << loan_amount << std::endl;
        } else {
            std::cout << "Amount deposited: " << Deposit << ". Current balance: " << balance << std::endl;
        }
    }

    void takeLoan(int ammount) {
        if (!hasLoan) {
            balance+=loan_amount;
            balance += ammount;
            hasLoan = true;
            std::cout << "Loan of " << loan_amount << " taken! Current balance: " << balance << std::endl;
        } else {
            std::cout << "You already have an active loan!" << std::endl;
        }
    }
};
std::string salt;
std::string hashed_password;
int i;
// Callback function for SQLite queries
static int callback(void* data, int argc, char** argv, char** azColName) {
    std::cout << "";
    for (int i = 0; i < argc; i++) {
        std::cout  << (argv[i] ? argv[i] : "NULL") << " ";
    }
    if ( argc > 0) 
    {
        return i;
    } 
    else 
    
    {
        std::cout << "User not registered in our system." << std::endl;
 return 0; 
   }
    
}


void setcolor( unsigned char color )
{
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}
// Function to create a new admin account
void createAdminAccount() {
    string username, password;
     bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_digit = false;
    cout << "Create a new admin account:" << endl;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;
      for (char c : password) {
        if (isupper(c)) {
            has_uppercase = true;
        }
        else if (islower(c)) {
            has_lowercase = true;
        }
        else if (isdigit(c)) {
            has_digit = true;
        }
    }

    if (has_uppercase && has_lowercase && has_digit)
     {
        }
    else { system("color C");
        cout << "Password must contain at least:" ;
   setcolor(0x02);      
cout<<" An UPERCASE LETTER"; 
setcolor(0x03);      
 cout<<",lowercase letter ";
 setcolor(0x0C);       
 cout<<"and";
 setcolor(0x06);     
 cout<<" 1 digit." << endl;
  return  createAdminAccount();
   }

    // Save the admin's username and password to a file
    ofstream adminFile("Dancomadmin.txt");
    adminFile << username << " " << password;
    adminFile.close();

    cout << "Admin account created successfully." << endl;
}

// Function to authenticate the admin
bool authenticateAdmin() {
    string inputUsername, inputPassword;
    cout << "Enter your username: ";
    cin >> inputUsername;
    cout << "Enter your password: ";
    cin >> inputPassword;

    // Read the saved admin credentials from the file
    ifstream adminFile("Dancomadmin.txt");
    string savedUsername, savedPassword;
    adminFile >> savedUsername >> savedPassword;
    adminFile.close();

    // Check if the entered credentials match the saved credentials
    if (inputUsername == savedUsername && inputPassword == savedPassword) {
        cout << "Authentication successful. Access granted!" << endl;
        return true;
    } else {
        cout << "Authentication failed. Access denied." << endl;
        return authenticateAdmin();
    }
}

void showMenu( )
{
	cout<<"******DANCOM******"<<endl;
	cout<<"0. Register"<<endl;
	cout<<"1. Send money"<<endl;
	cout<<"2. Withedraw cash"<<endl;
	cout<<"3. Buy airtime"<<endl;
	cout<<"4. loans and savings"<<endl;
	cout<<"5. lipa na dancom"<<endl;
	cout<<"6. my account"<<endl;
	cout<<"7. Deposit"<<endl;
	cout<<"8. LIPA EMPLOYEE "<<endl;	
	cout<<"9. Exit"<<endl;
	cout<<"DIVERSE AGENCY NETWORK COMMUNICATION "<<endl;	cout<<"Building Solutions Through Technology(INVENT,INNOVATE,INSPIRE)"<<endl;
} 
void show(string arr[2]){
    for(int x=0;x<2;x++){
 std::cout<<arr[x]<<endl;}
    }
    // Function to generate a fingerprint
std::string generateFingerprint()
{
    // TODO: Implement fingerprint generation algorithm
    return "FINGERPRINT";
}

// Function to save the fingerprint as a password
void saveFingerprint(const std::string& fingerprint)
{
    // TODO: Save the fingerprint to a file or database
}

// Function to check the availability of the fingerprint password
bool checkFingerprint(const std::string& fingerprint)
{
    // TODO: Check the fingerprint against the saved password
    return true;
}

int main( )
{srand(time(0));
   Account userAccount; 
 
//send_money,withdraw_cash,buy_airtime,loans_and_savings,lipa_na_Dancom,my_account,show_menu
int option;int option2,option3,option4,option5,option6,option7,option8,option9,option10,option11,option12,option13,option14,option15;int choice;
 string agentnumber,businessnumber;string phonenumber;string lipa[3]; 
int p=1; double balance=500;unsigned int  Deposit; string  tillnumber; int userpin=0000; int bonus;int transaction_fee;int airtime=0; int ammount; string decision[2];  int g=1;  string password; string employee_no; float hour,hours,extra_hours,extra_hours_month;  float ammount_per_hour,ammount_per_hours,ammount_per_month; int reporting_days_month,reporting_days_week;float ammount_per_week; int extra_hour_ammount; int index;time_t now=time(0);
char*dt=ctime(&now); string username;double Daccount=0,saveaccount=0;int month; int rate; ofstream f; string arr[2];string airtime_option[2]; string deposit_bank[2];int m=1; int i=1; int d=1; string send_bank[6];string loan[5];  int s=1; int k=1; int loan_interest;int loan_ammount;   
  int ID;   srand(time(0));
int len=10; char valid[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 char rand_array[250];
 const int l = 36;      std::string first_name, second_name, last_name;
  int id_number;
  std::string pasword;const int MAX_ATTEMPTS = 3;std::string enteredPin; std::string pin;   int attempts;
 string fingerprint =" generateFingerprint()";  string employeefirst_name, employeesecond_name, employeelast_name;
  string employeeid_number; 
  sqlite3 *db;	
    char *zErrMsg = 0;
    int rc;  sqlite3_stmt *res;
      bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_digit = false;
      char* errMsg = 0;
    string   BFirstName,BSecondName,location,sublocation,FirstName,SecondName,LastName,IdNo,AgentCode,AgentId,BsNo,AcNo,storenumber;int q,r;     char* kErrMsg = nullptr;string Agentcode,Agentid; string department,employeetype,paypoint,costcenter,staffbranch,companybank,email,staffacno,paygrade,hoursday,daysweek,daysmonth,payepin,itaxemployee;string KraPin,BankNo,BpermitNo;
      // Get the current time
  time_t t = time(nullptr);
  tm* timePtr = localtime(&t);  
 char choose; 

    cout << "Welcome to DANCOM Admin Login Program" << endl;

    // Check if admin account already exists
    ifstream adminFile("Dancomadmin.txt");
    if (adminFile.good()) {
        authenticateAdmin();
        
    } else {
        adminFile.close();
        createAdminAccount();
    }

  setcolor( 0x07 );
    system("color a");     
do{ 
showMenu( );
cout<<"option:";
cin>>option;
switch (option)
{ case 0: cout<<"Registration"<<endl;
if(option==0)
cout<<"1.Register user"<<endl;
cout<<"2.Register As an Agent"<<endl;
cout<<"3.Register Business"<<endl;
cout<<"Enter option"<<endl;
cin>>option2;
switch (option2)
{
    case 1:cout<<"Register user"<<endl;
    if (option2==1)
{
    rc = sqlite3_open("DANCOM.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } else 
    {
        cout << "Opened database successfully" << endl;
    }

    /* Create SQL statement */
    string sql = "CREATE TABLE DANCOM("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "ID_NUMBER  INT    NOT NULL," \
                 "FIRST_NAME           VARCHAR(255)    NOT NULL," \
                 "SECOND_NAME            VARCHAR(255)   NOT NULL," \
                 "LAST_NAME            VARCHAR(255)   NOT NULL," \
                 "PHONE_NUMBER   STRING NOT   NULL       ," \
                   "Registration_time  TIMESTAMP     ," \
                 "PIN            INT  NOT  NULL                     );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } else {
    cout << "Table created successfully" << endl;
    }

    string first_name, second_name, last_name, id_number, phone_number ;

    cout << "Enter ID number: ";
    cin >> id_number;
     if  ( id_number.length( )>=8)
     {
       
          } 
          else
            {
                system("color C");
        std::cout << "wrong id number" << std::endl;
return -1;    }  

{
  std::string phone_number = "07";  // First two digits are 07
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 9);  // Generate random numbers from 0 to 9

  // Generate the remaining 8 digits of the phone number
  for (int i = 0; i < 8; i++) {
    phone_number += std::to_string(dis(gen));
  }

  std::cout << "your phone number is:" << phone_number << std::endl;
}
  {
    std::cout << "Please create a four-digit PIN for your number: ";
    std::cin >> pin;
    if (pin.length() != 4)
    {
        std::cout << "ERROR: PIN must be four digits. Please try again: ";
        std::cin >> pin;
   } 
    std::cout << "Your PIN has been set." << std::endl;
;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      
        std::cout << "Please enter your PIN: ";
        std::cin >> enteredPin;
   }
system("color a");
    cout << "Enter first name: ";
    cin >> first_name;

    cout << "Enter second name: ";
    cin >> second_name;

    cout << "Enter last name: ";
    cin >> last_name;

  cout<<"Enter the phone number generated"<<endl;
  cin>>phone_number;

   if  ( phone_number.length( )==10)
     {
       
          }
           else 
           {system("color C");
        std::cout << "wrong phone number" << std::endl;
return -1;  
  } system("color a");


        /* Create SQL statement */
    sql = "INSERT INTO DANCOM (ID_NUMBER,FIRST_NAME,SECOND_NAME,LAST_NAME,PHONE_NUMBER,Registration_time,PIN) "  \
          "VALUES (" + id_number + ", '" + first_name + "', '" + second_name + "', '" + last_name + "', '" + phone_number+ "',  '" + ctime(&now) + "'," + pin + "); ";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ) {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } else {
    cout << "Records created successfully" << endl;
    }

  }


        if (pin == pin)
        {
            cout<<"\n"<<endl;
        system("color b");
            std::cout << "WELCOME TO DANCOM"  <<endl;
            
  	sqlite3_prepare_v2(db, "SELECT * FROM DANCOM", -1, &res, NULL);
	printf("Database contents:\n");
	int rc = sqlite3_step(res);
	while (rc != SQLITE_DONE)
	{
		printf("%s\n", sqlite3_column_text(res, 0));
		printf("%s\n", sqlite3_column_text(res, 4));
		
		rc = sqlite3_step(res);
	}
	sqlite3_finalize(res);
	sqlite3_close(db);
	
}          
        
        else
      { system("color c"); 
            std::cout << "Incorrect PIN. You have " << (MAX_ATTEMPTS - attempts) << " remaining." << std::endl;       
    std::cout << "You have exceeded the maximum number of attempts. Access denied." << std::endl;          
   }}
     system("color a");  
break;  
case 2: cout<<"Register As an Agent"<<endl;
if (option2==2)
{
    rc = sqlite3_open("AGENTS.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } else 
    {
        cout << "Opened database successfully" << endl;
    }

    /* Create SQL statement */
    string sql = "CREATE TABLE AGENTS("  \
      "id INTEGER  AUTOINCREMENT," \
                 "FIRSTB_NAME           VARCHAR(255)    NOT NULL," \
                 "SECONDB_NAME            VARCHAR(255)   NOT NULL," \
                 "LOCATION           VARCHAR(255)   NOT NULL," \
                 "SUB_LOCATION           VARCHAR(255)   NOT NULL," \
                 "FIRST_NAME           VARCHAR(255)    NOT NULL," \
                 "SECOND_NAME           VARCHAR(255)    NOT NULL," \
                 "LAST_NAME           VARCHAR(255)    NOT NULL," \
                 "PHONE_NUMBER   STRING NOT   NULL       ," \
                 "ID_NUMBER  INT    NOT NULL," \
                   "Registration_time  TIMESTAMP     ," \
                    "Agentcode  INT    NOT NULL," \
                 "AgentId          INT  PRIMARY KEY NOT  NULL                     );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } else {
    cout << "Table created successfully" << endl;
    }
cout<<"Enter first Name of the Agent business"<<endl;
cin>>BFirstName;
cout<<"Enter Second Name of the Agent business"<<endl;
cin>>BSecondName;
cout<<"Enter the location"<<endl;
cin>>location;
cout<<"Enter the sub location"<<endl;
cin>>sublocation;
cout<<"Enter Your First Name "<<endl;
cin>>FirstName;
cout<<"Enter Second Name "<<endl;
cin>>SecondName;
cout<<"Enter last Name "<<endl;
cin>>LastName;
cout<<"Enter Phonenumber"<<endl;
cin>>phonenumber;
if (phonenumber .length( )==10)
{
     }else 
{system("color c");
    cout<<"number should have 10 characters"<<endl;
return -1;
}
cout<<"Enter id number"<<endl;
cin>>IdNo;
if (IdNo .length( )==8)
{
     }else 
{system("color c");
    cout<<"wrong Id number "<<endl;
return -1;
}

// Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number with 6 characters
    int randomNumber = 0;
    for (int r= 0; r < 6; ++r) {
        randomNumber = (randomNumber * 10) + (std::rand() % 10);
    }
     
    cout<<"Your Agent code is:";
    system("color c");
    cout<<randomNumber<<endl;
    
    int randNumber = 0;
    for (int q= 0; q < 6; ++q) {
        randNumber = (randNumber * 10) + (std::rand() % 10);
    }
     system("color a");
    cout<<"your Agent identification number is:";
    system("color c");
    cout<<randNumber<<endl;
    system("color a");
    cout<<"Enter The Agent Code"<<endl;
    cin>>Agentcode;
    cout<<"Enter The Agent identification number"<<endl;
    cin>>Agentid;
      /* Create SQL statement */
    sql = "INSERT INTO AGENTS (FIRSTB_NAME,SECONDB_NAME,LOCATION,SUB_LOCATION,FIRST_NAME,SECOND_NAME,LAST_NAME,PHONE_NUMBER,ID_NUMBER,Registration_time,Agentcode,Agentid) "  \
          "VALUES ( '" + BFirstName + "', '" + BSecondName + "', '" + location+ "', '" + sublocation+ "','" + FirstName+ "','" + SecondName+ "','" + LastName+ "','" + phonenumber+ "', " + IdNo + " ,'" + ctime(&now) + "'," + Agentcode + "," + Agentid + "); ";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ) {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } else {
    cout << "Records created successfully" << endl;
    }}
    break;
    case 3:cout<<"Dancom Business Till"<<endl;
     if (option2==3)
     
    cout<<"Till number is available for the following businesses"<<endl;
    cout<<"1. Individual "<<endl;
    cout<<"2. Sole Propriatorship"<<endl;
    cout<<"3.Limited Liability Company (LLC) "<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1:
    if (choice==1)
    {
    rc = sqlite3_open("individualbs.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } else 
    {
        cout << "Opened database successfully" << endl;
    }
     /* Create SQL statement */
    string sql = "CREATE TABLE individual("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "ID_NUMBER  INT    NOT NULL," \
                 "EMAIL          VARCHAR(255)    NOT NULL," \
                 "KRA_PIN           STRING  NOT NULL," \
                 "BANK_CT_NO           STRING   NOT NULL," \                
                 "FIRSTB_NAME   STRING NOT   NULL       ," \
                 "SECONDB_NAME  STRING NOT   NULL       ," \
                  "PHONE_NUMBER   STRING NOT   NULL       ," \
                 "TILL_NO   STRING NOT   NULL       ," \
                 "STORE_NO   STRING NOT   NULL       ," \
                 "Registration_time  TIMESTAMP     ," \
                 "PIN            INT  NOT  NULL                     );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } else {
    cout << "Table created successfully" << endl;
    }
     string phonenumber,pin,id_number,email,KraPin,BankNo,tillnumber,storenumber;
    cout<<"Enter Id Number"<<endl;
    cin>>id_number;
   
    cout<<"Enter the business Email/phonenumber"<<endl;  
     cin>>email;
     
    cout<<"Enter KRA pin"<<endl;
    cin>>KraPin;
    
    cout<<"Enter your bank certificate registration number"<<endl;
    cin>>BankNo;
        
cout<<"Enter the first name of the business"<<endl;
cin>>BFirstName;
cout<<"Enter the second name of the business"<<endl;
cin>>BSecondName;

 cout<<"Enter your phone number"<<endl; 
     cin>>phonenumber;
     if (phonenumber .length( )==10)
{
     }else 
{system("color c");
    cout<<"number should have 10 characters"<<endl;
return -1;
}

// Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number with 6 characters
    int randomNumber = 0;
    for (int r= 0; r < 6; ++r) {
        randomNumber = (randomNumber * 10) + (std::rand() % 10);
    }
     
    cout<<"Your Till Number  is:";
    system("color c");
    cout<<randomNumber<<endl;
    system("color a");
    int randNumber = 0;
    for (int q= 0; q < 4; ++q) {
        randNumber = (randNumber * 10) + (std::rand() % 10);
    }
     cout<<"your Store number is:"; 
     system("color c");
     cout<<randNumber<<endl;
     
      int randaNumber = 0;
    for (int q= 0; q < 4; ++q) {
        randaNumber = (randaNumber * 10) + (std::rand() % 10);
    }
    system("color a");
     cout<<"your PIN number is:";
     system("color c");
     cout <<randaNumber<<endl;
     system("color a");
     cout<<"Enter the Till number generated"<<endl;
     cin>>tillnumber;
     cout<<"Enter the store number generated"<<endl;
     cin>>storenumber;
     cout<<"Enter the Pin generated"<<endl;
     std::cin>>pin;
       if (pin.length( )==4)
{
     }else 
{system("color c");
    cout<<"wrong pin,try again later!"<<endl;
return -1;
}
                   

    /* Create SQL statement */
    sql = "INSERT INTO individual (ID_NUMBER,EMAIL,KRA_PIN,BANK_CT_NO,FIRSTB_NAME,SECONDB_NAME,PHONE_NUMBER,TILL_NO,STORE_NO,Registration_time,PIN) "  \
          "VALUES (" + id_number + ", '" + email + "', '" + KraPin + "', '" + BankNo + "',  '" + BFirstName + "', '" + BSecondName + "', '" + phonenumber + "','" + tillnumber + "',  '" + storenumber + "', '" + ctime(&now) + "', "+ pin + "); ";
          

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ) {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } else {
    cout << "Records created successfully" << endl;
    }
   
     cout<<"Change pin to activate Till number"<<endl;
      rc = sqlite3_open("individualbs.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return 1;
    }

    // Create the pins table if it doesn't exist
    string createTableSQL = "CREATE TABLE IF NOT EXISTS individual (id INTEGER PRIMARY KEY, pin TEXT);";
    rc = sqlite3_exec(db, createTableSQL.c_str(), callback, nullptr, &kErrMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << kErrMsg << endl;
        sqlite3_free(kErrMsg);
        sqlite3_close(db);
        return 1;
    }

    // Prompt the user for the old and new PIN
    string PIN, newPin;
    cout << "Enter your old PIN: ";
    cin >> PIN;
cout<<"Enter the till  number"<<endl;
cin>>tillnumber;
    // Verify the old PIN by checking the database
    string verifyPinSQL = "SELECT PIN FROM individual WHERE TILL_NO = '" + tillnumber + "';";    
    char** result;
    int numRows, numCols;
    rc = sqlite3_get_table(db, verifyPinSQL.c_str(), &result, &numRows, &numCols, &kErrMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << kErrMsg << endl;
        sqlite3_free(kErrMsg);
        sqlite3_free_table(result);
        sqlite3_close(db);
        return 1;
    }

    if (numRows == 0 || result[numCols] != PIN) {system("color c");
        cout << "Incorrect PIN. PIN change failed." << endl;
        sqlite3_free_table(result);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_free_table(result);

    cout << "Enter your new PIN: ";
    cin >> newPin;

    // Update the PIN in the database
    string updatePinSQL = "UPDATE individual  SET PIN = '" + newPin + "' WHERE  TILL_NO = '" + tillnumber + "';";    
    rc = sqlite3_exec(db, updatePinSQL.c_str(), callback, nullptr, &kErrMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << kErrMsg << endl;
        sqlite3_free(kErrMsg);
        sqlite3_close(db);
        return 1;
    }
system("color a");
    cout << "PIN changed successfully." << endl;
cout<<"Till Number activated successfully,and ready for use"<<endl;
    sqlite3_close(db);
return 0;
    }
        break;  
    void showMenu();
    case 2:
    if (choice==2)
    {
    rc = sqlite3_open("Solepropriatorship.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } else 
    {
        cout << "Opened database successfully" << endl;
    }
     /* Create SQL statement */
    string sql ="CREATE TABLE propriatorship("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "ID_NUMBER  INT    NOT NULL," \
                "PHONE_NUMBER   STRING NOT   NULL       ," \
                 "FIRSTB_NUMBER         VARCHAR(255)    NOT NULL," \
                  "SECONDB_NUMBER         VARCHAR(255)    NOT NULL," \
                   "EMAIL          VARCHAR(255)    NOT NULL," \
                    "BP_NUMBER   STRING NOT   NULL       ," \
                 "KRA_PIN           VARCHAR(255)   NOT NULL," \
                 "BANK_CT_NO           VARCHAR(255)   NOT NULL," \
                 "Registration_time  TIMESTAMP     ," \
                  "TILL_NO   STRING NOT   NULL       ," \
                   "STORE_NO   STRING NOT   NULL       ," \
                 "PIN            INT  NOT  NULL                     );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } else {
    cout << "Table created successfully" << endl;
    }
    cout<<"Enter your id number"<<endl;
    cin>>id_number;
         
    cout<<"Enter your phone number"<<endl;   cin>>phonenumber;

    cout<<"Enter the first name of the business" <<endl;
        cin>>BFirstName;
           
        cout<<"Enter the second name of the business" <<endl;
        cin>>BSecondName;
            
   cout<<"Enter the business Email/phonenumber"<<endl;  
     cin>>email;
           
    cout<<"Enter your Business Permit Number"<<endl;
    cin>>BpermitNo;
    
cout<<"Enter KRA pin"<<endl;
    cin>>KraPin;
                                  
    cout<<"Enter your bank certificate registration number"<<endl;
    cin>>BankNo;
    
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number with 6 characters
    int randemNumber = 0;
    for (int r= 0; r < 6; ++r) {
        randemNumber = (randemNumber * 10) + (std::rand() % 10);
    }
     
    cout<<"Your Till Number  is:";
    system("color c");
    cout<<randemNumber<<endl;
    system("color a");
    int randupNumber = 0;
    for (int q= 0; q < 4; ++q) {
        randupNumber = (randupNumber * 10) + (std::rand() % 10);
    }
     cout<<"your Store number is:"; 
     system("color c");
     cout<<randupNumber<<endl;
     
      int randiNumber = 0;
    for (int q= 0; q < 4; ++q) {
        randiNumber = (randiNumber * 10) + (std::rand() % 10);
    }system("color a");
     cout<<"your PIN number is:";
     system("color c");
     cout <<randiNumber<<endl;
     system("color a");
     cout<<"Enter the Till number generated"<<endl;
     cin>>tillnumber;
     cout<<"Enter the store number generated"<<endl;
     cin>>storenumber;
     cout<<"Enter the Pin generated"<<endl;
     std::cin>>pin;
       if (pin.length( )==4)
{
     }else 
{system("color c");
    cout<<"wrong pin,try again later!"<<endl;
return -1;
}

 
   cout<<"Change pin to activate Till number"<<endl;
      rc = sqlite3_open("propriatorship.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return 1;
    }

    // Create the pins table if it doesn't exist
    string createTableSQL = "CREATE TABLE IF NOT EXISTS propriatorship (id INTEGER PRIMARY KEY, pin TEXT);";
    rc = sqlite3_exec(db, createTableSQL.c_str(), callback, nullptr, &kErrMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << kErrMsg << endl;
        sqlite3_free(kErrMsg);
        sqlite3_close(db);
        return 1;
    }

    // Prompt the user for the old and new PIN
    string PIN, newPin;
    cout << "Enter your old PIN: ";
    cin >> PIN;
cout<<"Enter the till  number"<<endl;
cin>>tillnumber;
    // Verify the old PIN by checking the database
    string verifyPinSQL = "SELECT PIN FROM propriatorship WHERE TILL_NO = '" + tillnumber + "';";    
    char** result;
    int numRows, numCols;
    rc = sqlite3_get_table(db, verifyPinSQL.c_str(), &result, &numRows, &numCols, &kErrMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << kErrMsg << endl;
        sqlite3_free(kErrMsg);
        sqlite3_free_table(result);
        sqlite3_close(db);
        return 1;
    }

    if (numRows == 0 || result[numCols] != PIN) {system("color c");
        cout << "Incorrect PIN. PIN change failed." << endl;
        sqlite3_free_table(result);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_free_table(result);

    cout << "Enter your new PIN: ";
    cin >> newPin;

    // Update the PIN in the database
    string updatePinSQL = "UPDATE individual  SET PIN = '" + newPin + "' WHERE  TILL_NO = '" + tillnumber + "';";    
    rc = sqlite3_exec(db, updatePinSQL.c_str(), callback, nullptr, &kErrMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << kErrMsg << endl;
        sqlite3_free(kErrMsg);
        sqlite3_close(db);
        return 1;
    }
system("color a");
    cout << "PIN changed successfully." << endl;
cout<<"Till Number activated successfully,and ready for use"<<endl;
    sqlite3_close(db);
return 0;

    }
break;
    void showMenu();    
  case 3:
    if (choice==3)
    {
    cout<<"Enter your id number"<<endl;
    cin>>id_number;
     cout<<"Enter KRA pin"<<endl;
    cin>>KraPin;
    cout<<"Produce a CR12 valid for 90days"<<endl;
     cout<<"Produce a CERTIFICATE OF INCORPORATION RECEIPT with ANNUAL RETURNS"<<endl;
   cout<<"Enter your bank certificate registration number"<<endl;
    cin>>BankNo;
    cout<<"Produce a filled stamped or sealed RESOLUTION letter signed by Director of LLC"<<endl;
   cout<<"Enter the business Email/phonenumber"<<endl;  
     cin>>email; 
  }     
   break;
    }
break;
}

  break; 
   void showMenu();
case 1:cout<<"send money:"<<endl;
if (option==1)
{
         
    string phonenumber; int ammount; 
cout<<"enter phone number"<<endl;
cin>>phonenumber;
if (phonenumber .length( )==10)
{
     }else 
{system("color c");
    cout<<"number should have 10 characters"<<endl;
    return -1;
}
system("color a");
cout<<"enter amount"<<endl;
std::cin>>ammount;
userAccount.Sendmoney(ammount);
if ( ammount <=500)
transaction_fee=0;
if (ammount>500 && ammount <= 600)
transaction_fee=6;
if (ammount>600 && ammount <=700)
transaction_fee=7;
if (ammount>700 && ammount <=800)
transaction_fee=8;
if (ammount >800 && ammount <=900)
transaction_fee=9;
if (ammount>900 && ammount <=1000)
transaction_fee=10;
if (ammount>1000 && ammount <=2000)
transaction_fee=12;
if (ammount>2000 && ammount <= 3000)
transaction_fee=13;
if (ammount>3000 && ammount <= 4000)
transaction_fee=14;
if (ammount>4000 && ammount <= 5000)
transaction_fee=15;
if (ammount>5000 && ammount<=6000)
transaction_fee=18;
if (ammount>6000 && ammount<=7000)
transaction_fee=20;
if (ammount>7000 && ammount<=8000)
transaction_fee=21;
if (ammount>8000 && ammount<=9000)
transaction_fee=22;
if (ammount>9000 && ammount<=10000)
transaction_fee=25;
if (ammount>10000 && ammount<=12000)
transaction_fee=28;
if (ammount>12000 && ammount<=14000)
transaction_fee=30;
if (ammount>14000 && ammount<=16000)
transaction_fee=32;
if (ammount>16000 && ammount<=20000)
transaction_fee=35;
if (ammount>20000 && ammount<=25000)
transaction_fee=40;
if (ammount>25000 && ammount<=30000)
transaction_fee=50;
if (ammount>30000 && ammount<=35000)
transaction_fee=55;
if (ammount>35000 && ammount<=40000)
transaction_fee=60;
if (ammount>40000 && ammount<=45000)
transaction_fee=65;
if (ammount>45000 && ammount<=50000)
transaction_fee=70;
if (ammount>50000 && ammount<=55000)
transaction_fee=75;
if (ammount>55000 && ammount<=60000)
transaction_fee=80;
if (ammount>60000 && ammount<=65000)
transaction_fee=85;
if (ammount>65000 && ammount<=70000)
transaction_fee=90;
if (ammount>70000 && ammount<=75000)
transaction_fee=95;
if (ammount>75000 && ammount<=80000)
transaction_fee=100;
if (ammount>80000 && ammount<=85000)
transaction_fee=105;
if (ammount>85000 && ammount<=90000)
transaction_fee=110;
if (ammount>90000 && ammount<=95000)
transaction_fee=115;
if (ammount>95000 && ammount<=100000)
transaction_fee=120;

std::cout<<"enter pin"<<endl;
for ( userpin=0; userpin<1; userpin++)
std::cin>>userpin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{ system("color c");
cout<<"wrong pin try again!"<<endl;

    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      system("color a");
        std::cout << "Please enter your PIN: ";
        std::cin >> userpin;
}}
         
    if (ammount< balance )
{
      balance-=ammount + transaction_fee;
          
     for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    } 
     // Open the database connection
    int rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
// SQL statement to retrieve receivers information
  system("color c");
  string selectQuery = "SELECT FIRST_NAME, LAST_NAME,PHONE_NUMBER  FROM DANCOM WHERE PHONE_NUMBER = '" + phonenumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    } int choice20;
    system("color a");
cout<< "will receive ksh:";
system("color c");
cout<<ammount;
system("color a");
cout<<",a transaction fee of ksh:";
system("color c");
cout<<transaction_fee;
system("color a");
cout<<" will be charged"<<endl;
cout<<"Do you wish to proceed with the transaction?"<<endl;
cout<<"1.Yes"<<endl;
cout<<"2.No"<<endl;
cin>> choice20;
switch (choice20)
{
    case 1:
    {
         // Open SQLite database
    int rc = sqlite3_open("TRANSACTIONS.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened transaction database successfully!" << std::endl;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS SendMoney ("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Phonenumber STRING," 
                                   "Amount  INT NOT NULL," 
                                   "Balance REAL,"                                                 "transaction_time TIMESTAMP        );";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Send Money Table created successfully!" << std::endl;
    }
    }
    break;
    case 2:
    if (choice20==2)
    {system("color c");
        cout<<"You have successfully canceled the transaction "<<endl;
        return 0;
    }
    break;
}system("color a");
   // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO SendMoney (Phonenumber, Amount, Balance, transaction_time) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    sqlite3_bind_text(stmt, 1, phonenumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, ammount);
    sqlite3_bind_double(stmt, 3, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }
    sqlite3_close(db);
    
     rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have send:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<ammount;
setcolor(0x02);
cout<<" to ";
setcolor( 0x0C );
  selectQuery = "SELECT FIRST_NAME, LAST_NAME,PHONE_NUMBER  FROM DANCOM WHERE PHONE_NUMBER = '" + phonenumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
    
setcolor(0x02);
cout<<"on:"<<dt;
cout<<"your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
setcolor(0x02);
cout<<",a Transaction fee of:";
cout << "\033[4;31m";
setcolor(0x0C);
cout<<"ksh"<<transaction_fee;
setcolor(0x02);
cout<<" has been charged,";
  cout<<"The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh5000000"<<endl;
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
      
}
else
{system("color c");
int sum,choose1;int loan_amount=ammount-balance; float interest = (loan_amount) / (100);
cout<<"insufficient funds to transfer :ksh"<< ammount <<" transaction fee of :ksh"<<transaction_fee<< " is required"<<endl;
cout<<"your dancom balance is :Ksh"<<balance<<endl;
setcolor( 0x02 );
cout<<"would you like to SUM UP the remaining amount?"<<endl;
cout<<"1. YES"<<endl;
cout<<"2. NO"<<endl;
cin>>choose1;
switch (choose1)
{ 
case 1:
if (choose1==1)
sum=(balance + ammount ) - (balance + transaction_fee);
loan_amount = ammount-balance ;
balance-=balance;
{
    // Open the database connection
    int rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
// SQL statement to retrieve transaction history
cout<<"You are SUMMING UP ksh:";
setcolor(0x0C);
cout<<loan_amount;
setcolor(0x02);
cout<< " to";
   setcolor( 0x0C );
  string selectQuery = "SELECT FIRST_NAME, LAST_NAME,PHONE_NUMBER  FROM DANCOM WHERE PHONE_NUMBER = '" + phonenumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    } int choose3;
    setcolor(0x02);
cout<<"on:";
setcolor(0x0C);
cout<<dt;
setcolor(0x02);
cout<<" a Transaction fee of ksh:";
setcolor(0x0C);
cout<<transaction_fee;
setcolor(0x02);
cout<<" and an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged."<<endl;
cout<<"Do you wish to proceed with the transaction?" <<endl;
cout<<"1.Yes"<<endl;
cout<<"2.No"<<endl;
cin>>choose3;
switch (choose3)
{
    case 1:
    if (choose3==1)
    { 
    userAccount.takeLoan(loan_amount);
    // Open SQLite database
    int rc = sqlite3_open("SUM_UP.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened transaction database successfully!" << std::endl;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS Sum_Up_SendMoney ("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Phonenumber STRING," 
                                   "Amount  INT NOT NULL," 
                                   "Balance REAL,"                                                 "transaction_time TIMESTAMP        );";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Sum Up Send Money Table created successfully!" << std::endl;
    }
       
    }
    break;
    case 2:
    if (choose3==2)
  { 
   cout<<"You have successfully canceled the transaction"<<endl;
return 0;
  }
    break;
   void showMenu();
}// Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Sum_Up_SendMoney (Phonenumber, Amount, Balance, transaction_time) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    sqlite3_bind_text(stmt, 1, phonenumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, loan_amount);
    sqlite3_bind_double(stmt, 3, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);

 // Open the database connection
    rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have send:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<sum;
setcolor(0x02);
cout<<" to";
setcolor( 0x0C );
  selectQuery = "SELECT FIRST_NAME, LAST_NAME,PHONE_NUMBER  FROM DANCOM WHERE PHONE_NUMBER = '" + phonenumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
    
setcolor(0x02);
cout<<"on:"<<dt;
cout<<"The amount is to  be paid before ";
setcolor( 0x0C );
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
setcolor( 0x02 );
cout<<"your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
setcolor(0x02);
cout<<" Your Dancom SUM UP amount is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<loan_amount;
setcolor(0x02);
cout<<" an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged and";
cout<<" a Transaction fee of:";
cout << "\033[4;31m";
setcolor(0x0C);
cout<<"ksh"<<transaction_fee;
setcolor(0x02);
cout<<" has been charged,";
  cout<<"The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh5000000";
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
}
    break;
    case 2:
    if (choose1==2)
 {  
  break;   
 } 
}
break;
}    }
system("color a");
break;
void showMenu( );
case 2:cout<<"withedraw cash:"<<endl;
if (option==2)
cout<<"1.from Agent"<<endl;
cout<<"2.from ATM"<<endl;
std::cout<<"enter option!"<<endl;
std::cin>>option3;
switch (option3)
{
    case 1:cout<<"from Agent"<<endl;
if (option3==1)
{
   
std::cout<<"enter agent number"<<endl;
std::cin>>Agentcode;
if (Agentcode .length( )==6)
{
     }else 
{system("color c");
    cout<<"wrong agentnumber, agentnumber should have 6 characters "<<endl;
return -1;
}
std::cout<<"enter amount you wish to withedraw"<<endl;
std::cin>>ammount;
if (ammount > 50 && ammount <=100)
transaction_fee=2;
if (ammount>100 && ammount <= 500)
transaction_fee=6;
if (ammount>500 && ammount <=700)
transaction_fee=7;
if (ammount>700 && ammount <=800)
transaction_fee=8;
if (ammount >800 && ammount <=900)
transaction_fee=9;
if (ammount>900 && ammount <=1000)
transaction_fee=10;
if (ammount>1000 && ammount <=2000)
transaction_fee=20;
if (ammount>2000 &&ammount <= 3000)
transaction_fee=30;
if (ammount>3000 && ammount <= 4000)
transaction_fee=40;
if (ammount>4000 && ammount <= 5000)
transaction_fee=50;
if (ammount>5000 && ammount <=6000)
transaction_fee=60;
if (ammount>6000 && ammount<=7000)
transaction_fee=70;
if (ammount>7000 && ammount<=8000)
transaction_fee=80;
if (ammount>8000 && ammount<=9000)
transaction_fee=90;
if (ammount>9000 && ammount<=10000)
transaction_fee=100;
if (ammount>10000 && ammount<=12000)
transaction_fee=110;
if (ammount>12000 && ammount<=14000)
transaction_fee=120;
if (ammount>14000 && ammount<=16000)
transaction_fee=130;
if (ammount>16000 && ammount<=20000)
transaction_fee=135;
if (ammount>20000 && ammount<=25000)
transaction_fee=140;
if (ammount>25000 && ammount<=30000)
transaction_fee=145;
if (ammount>30000 && ammount<=35000)
transaction_fee=150;
if (ammount>35000 && ammount<=40000)
transaction_fee=155;
if (ammount>40000 && ammount<=45000)
transaction_fee=160;
if (ammount>45000 && ammount<=50000)
transaction_fee=165;
if (ammount>50000 && ammount<=55000)
transaction_fee=170;
if (ammount>55000 && ammount<=60000)
transaction_fee=175;
if (ammount>60000 && ammount<=65000)
transaction_fee=180;
if (ammount>65000 && ammount<=70000)
transaction_fee=185;
if (ammount>70000 && ammount<=75000)
transaction_fee=190;
if (ammount>75000 && ammount<=80000)
transaction_fee=195;
if (ammount>80000 && ammount<=85000)
transaction_fee=200;
if (ammount>85000 && ammount<=90000)
transaction_fee=205;
if (ammount>90000 && ammount<=95000)
transaction_fee=210;
if (ammount>95000 && ammount<=100000)
transaction_fee=215;
if (ammount>100000 && ammount<=105000)
transaction_fee=300;
if (ammount>105000 && ammount<=110000)
transaction_fee=305;
if (ammount >110000 && ammount <=115000)
transaction_fee=310;
if (ammount>115000 && ammount <=120000)
transaction_fee=315;
if (ammount>120000 && ammount <=125000)
transaction_fee=320;
if (ammount>125000 && ammount <=130000)
transaction_fee=325;
if (ammount>130000 && ammount <=135000)
transaction_fee=330;
if (ammount>135000 && ammount <=140000)
transaction_fee=335;
if (ammount>140000 && ammount <=145000)
transaction_fee=340;
if (ammount>145000 && ammount <=150000)
transaction_fee=345;
if (ammount>150000 && ammount <=155000)
transaction_fee=350;
if (ammount>155000 && ammount <=160000)
transaction_fee=355;
if (ammount>160000 && ammount <=165000)
transaction_fee=360;
if (ammount>165000 && ammount <=170000)
transaction_fee=365;
if (ammount>170000 && ammount <=175000)
transaction_fee=370;
if (ammount>175000 && ammount <=180000)
transaction_fee=375;
if (ammount>180000 && ammount <=185000)
transaction_fee=380;
if (ammount>185000 && ammount <=190000)
transaction_fee=385;
if (ammount>190000 && ammount <=195000)
transaction_fee=390;
if (ammount>195000 && ammount <=200000)
transaction_fee=400;
if (ammount>20000 && ammount <=210000)
transaction_fee=420;
if (ammount>210000 && ammount <=220000)
transaction_fee=440;
if (ammount>220000 && ammount <=230000)
transaction_fee=460;
if (ammount>230000 && ammount <=2400000)
transaction_fee=480;
if (ammount>240000 && ammount <=250000)
transaction_fee=500;
if (ammount>250000 && ammount <=260000)
transaction_fee=520;
if (ammount>260000 && ammount <=270000)
transaction_fee=540;
if (ammount>270000 && ammount <=280000)
transaction_fee=560;
if (ammount>280000 && ammount <=290000)
transaction_fee=580;
if (ammount>290000 && ammount <=300000)
transaction_fee=600;
if (ammount>300000 && ammount <=310000)
transaction_fee=620;
if (ammount>310000 && ammount <=320000)
transaction_fee=640;
if (ammount>330000 && ammount <=340000)
transaction_fee=660;
if (ammount>340000 && ammount <=350000)
transaction_fee=680;
if (ammount>350000 && ammount <=360000)
transaction_fee=700;
if (ammount>360000 && ammount <=370000)
transaction_fee=720;
if (ammount>370000 && ammount <=380000)
transaction_fee=740;
if (ammount>380000 && ammount <=390000)
transaction_fee=760;
if (ammount>390000 && ammount <=400000)
transaction_fee=780;
if (ammount>400000 && ammount <=410000)
transaction_fee=800;
if (ammount>410000 && ammount <=420000)
transaction_fee=820;
if (ammount>420000 && ammount <=430000)
transaction_fee=840;
if (ammount>430000 && ammount <=440000)
transaction_fee=860;
if (ammount>440000 && ammount <=450000)
transaction_fee=880;
if (ammount>450000 && ammount <=460000)
transaction_fee=900;
if (ammount>460000 && ammount <=470000)
transaction_fee=920;
if (ammount>470000 && ammount <=480000)
transaction_fee=940;
if (ammount>480000 && ammount <=490000)
transaction_fee=960;
if (ammount>490000 && ammount <=500000)
transaction_fee=980;
if (ammount>500000 && ammount <=510000)
transaction_fee=1000;
std::cout<<"enter pin"<<endl;
cin>>userpin;
if(userpin>999 && userpin<=9999)
{ 
} else 
{ system("color c");
cout<<"wrong pin try again!"<<endl;
return -1;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      system("color a");
        std::cout << "Please enter your PIN: ";
        std::cin >>userpin;

}}
if (userpin>999 && userpin <=9999 && ammount>500000)
cout<<"The maximum amount you can withedraw is:Ksh500000"<<endl;
if(userpin>999 && userpin<=9999 && ammount<balance)

for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }       
}

 if (ammount<balance && ammount<=5000000)
{   
  // Open the database connection
    int rc = sqlite3_open("AGENTS.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
 cout<<"You are withedrawing Ksh:"<<ammount<<" from ";
 string selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME,location,sub_location,AgentId FROM AGENTS WHERE Agentcode= '" + Agentcode + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    } int choice21;
setcolor( 0x02 );
  cout<<"A transaction fee of Ksh:"<<transaction_fee<<" will be charged."<<endl;
  cout<<"Do you wish to continue with the transaction?"<<endl;
  cout<<"1.Yes"<<endl;
  cout<<"2.No"<<endl;
  cin>>choice21;
  switch (choice21)
  { 
      case 1:
      if (choice21==1)
      {
          // Open SQLite database
    int rc = sqlite3_open("TRANSACTIONS.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened database successfully!" << std::endl;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS Withedrawals ("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Agentnumber STRING," 
                                   "Ammount  INT NOT NULL," 
                                   "Balance REAL,"                                                 "transaction_time TIMESTAMP        );";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table created successfully!" << std::endl;
    }
          
      }
    break;
    case 2:
    if(choice21==2)  
    {
        cout<<"You have successfully cancelled the Transaction"<<endl;
        return 0;
    }
    break;
  }
  balance-=transaction_fee + ammount;
   // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Withedrawals(Agentnumber, Ammount, Balance, transaction_time) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    sqlite3_bind_text(stmt, 1, Agentcode.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, ammount);
    sqlite3_bind_double(stmt, 3, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }
    sqlite3_close(db);
    
      // Open the database connection
     rc = sqlite3_open("AGENTS.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }    
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have withedrawn:";
setcolor( 0x0C);
cout << "\033[4;31m";
cout<<"ksh"<<ammount;
setcolor( 0x02);
cout<<" from";
setcolor( 0x0C );
  // SQL statement to retrieve transaction history
    
     selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME,location,sub_location,AgentId FROM AGENTS WHERE Agentcode= '" + Agentcode + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
setcolor( 0x02 );
cout<< " on "<< dt;
cout <<",a Transaction fee of:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<transaction_fee;
setcolor( 0x02);
cout<<" has been charged";
cout<<",your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
setcolor(0x02);
  cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh 5000000"<<endl;
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
} 
else
{system("color c");
int sum,choose2;float loan_amount=ammount- balance; float interest= (loan_amount)/(100);
cout<<" insufficient amount in your DANCOM account"<<endl;
cout<<"your Dancom balance is Ksh:";
setcolor( 0x02 );
cout<<balance;
setcolor( 0x0C);
cout<<",a Transaction fee of Ksh:"; 
setcolor( 0x02);
cout<<transaction_fee;
setcolor( 0x0C);
cout<<" is required."<<endl;
setcolor( 0x02 );
cout<<"would you like to SUM UP the remaining amount?"<<endl;
cout<<"1. YES"<<endl;
cout<<"2. NO"<<endl;
cin>>choose2;
switch (choose2)
{ 
case 1:
if (choose2==1)
sum=(balance + ammount ) - (balance + transaction_fee);
loan_amount = ammount-balance ;
balance-=balance;
{   
  // Open the database connection
    int rc = sqlite3_open("AGENTS.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
 cout<<"You are SUMMING UP ksh:";
setcolor(0x0C);
cout<<loan_amount;
setcolor(0x02);
cout<< " to ";
   setcolor( 0x0C );
     // SQL statement to retrieve transaction history
    
    string selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME,location,sub_location,AgentId FROM AGENTS WHERE Agentcode= '" + Agentcode + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
  int choose4;
    setcolor(0x02);
cout<<"for your withedrawal as on:";
setcolor(0x0C);
cout<<dt;
setcolor(0x02);
cout<<" a Transaction fee of ksh:";
setcolor(0x0C);
cout<<transaction_fee;
setcolor(0x02);
cout<<" and an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged."<<endl;
cout<<"Do you wish to proceed with the transaction?" <<endl;
cout<<"1.Yes"<<endl;
cout<<"2.No"<<endl;
cin>>choose4;
switch (choose4)
{
    case 1:
    if (choose4==1)
    { 
       // Open SQLite database
    int rc = sqlite3_open("SUM_UP.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened database successfully!" << std::endl;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS Sum_Up_Withedrawals ("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Agentnumber STRING," 
                                   "Amount  INT NOT NULL," 
                                   "Balance REAL,"                                                 "transaction_time TIMESTAMP        );";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table created successfully!" << std::endl;
    }
    }
    break;
    case 2:
    if (choose4==2)
  { 
   cout<<"You have successfully canceled the transaction"<<endl;
return 0;
  }
    break;
   void showMenu();
}
 balance-=balance;
  // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Sum_Up_Withedrawals(Agentnumber, Amount, Balance, transaction_time) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    sqlite3_bind_text(stmt, 1, Agentcode.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2,loan_amount);
    sqlite3_bind_double(stmt, 3, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);
    
 // Open the database connection
     rc = sqlite3_open("AGENTS.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have withedrawn:";
setcolor( 0x0C);
cout << "\033[4;31m";
cout<<"ksh"<<sum;
setcolor( 0x02);
cout<<" from ";
setcolor( 0x0C );
  // SQL statement to retrieve transaction history
    
     selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME,location,sub_location,AgentId FROM AGENTS WHERE Agentcode= '" + Agentcode + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
setcolor( 0x02 );
cout<< "on "<< dt;
cout<<"The amount is to  be paid before ";
setcolor( 0x0C );
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
setcolor( 0x02 );
cout<<"Your Dancom SUM UP amount is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<loan_amount;
setcolor(0x02);
cout <<",a Transaction fee of:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<transaction_fee;
setcolor( 0x02);
cout<<" has been charged";
cout<<" and an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged";
cout<<",your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
setcolor(0x02);
  cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh 5000000"<<endl;
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
} 
    break;
    case 2:
    if (choose2==2)
 {  
  break;   
 } 
}
break;

}
  break;
  void showMenu();
  system("color a");
  case 2:cout<<"From ATM"<<endl;
if (option3==2)
{
    // Open the database connection
    int rc = sqlite3_open("AGENTS.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
std::cout<<"enter agent number"<<endl;
std::cin>>Agentcode;
std::cout<<"enter amount"<<endl;
std::cin>>ammount;
if (ammount > 50 && ammount <=100)
transaction_fee=2;
if (ammount>100 && ammount <= 500)
transaction_fee=6;
if (ammount>500 && ammount <=700)
transaction_fee=7;
if (ammount>700 && ammount <=800)
transaction_fee=8;
if (ammount >800 && ammount <=900)
transaction_fee=9;
if (ammount>900 && ammount <=1000)
transaction_fee=10;
if (ammount>1000 && ammount <=2000)
transaction_fee=20;
if (ammount>2000 &&ammount <= 3000)
transaction_fee=30;
if (ammount>3000 && ammount <= 4000)
transaction_fee=40;
if (ammount>4000 && ammount <= 5000)
transaction_fee=50;
if (ammount>5000 && ammount <=6000)
transaction_fee=60;
if (ammount>6000 && ammount<=7000)
transaction_fee=70;
if (ammount>7000 && ammount<=8000)
transaction_fee=80;
if (ammount>8000 && ammount<=9000)
transaction_fee=90;
if (ammount>9000 && ammount<=10000)
transaction_fee=100;
if (ammount>10000 && ammount<=12000)
transaction_fee=110;
if (ammount>12000 && ammount<=14000)
transaction_fee=120;
if (ammount>14000 && ammount<=16000)
transaction_fee=130;
if (ammount>16000 && ammount<=20000)
transaction_fee=135;
if (ammount>20000 && ammount<=25000)
transaction_fee=140;
if (ammount>25000 && ammount<=30000)
transaction_fee=145;
if (ammount>30000 && ammount<=35000)
transaction_fee=150;
if (ammount>35000 && ammount<=40000)
transaction_fee=155;
if (ammount>40000 && ammount<=45000)
transaction_fee=160;
if (ammount>45000 && ammount<=50000)
transaction_fee=165;
if (ammount>50000 && ammount<=55000)
transaction_fee=170;
if (ammount>55000 && ammount<=60000)
transaction_fee=175;
if (ammount>60000 && ammount<=65000)
transaction_fee=180;
if (ammount>65000 && ammount<=70000)
transaction_fee=185;
if (ammount>70000 && ammount<=75000)
transaction_fee=190;
if (ammount>75000 && ammount<=80000)
transaction_fee=195;
if (ammount>80000 && ammount<=85000)
transaction_fee=200;
if (ammount>85000 && ammount<=90000)
transaction_fee=205;
if (ammount>90000 && ammount<=95000)
transaction_fee=210;
if (ammount>95000 && ammount<=100000)
transaction_fee=215;
if (ammount>100000 && ammount<=105000)
transaction_fee=300;
if (ammount>105000 && ammount<=110000)
transaction_fee=305;
if (ammount >110000 && ammount <=115000)
transaction_fee=310;
if (ammount>115000 && ammount <=120000)
transaction_fee=315;
if (ammount>120000 && ammount <=125000)
transaction_fee=320;
if (ammount>125000 && ammount <=130000)
transaction_fee=325;
if (ammount>130000 && ammount <=135000)
transaction_fee=330;
if (ammount>135000 && ammount <=140000)
transaction_fee=335;
if (ammount>140000 && ammount <=145000)
transaction_fee=340;
if (ammount>145000 && ammount <=150000)
transaction_fee=345;
if (ammount>150000 && ammount <=155000)
transaction_fee=350;
if (ammount>155000 && ammount <=160000)
transaction_fee=355;
if (ammount>160000 && ammount <=165000)
transaction_fee=360;
if (ammount>165000 && ammount <=170000)
transaction_fee=365;
if (ammount>170000 && ammount <=175000)
transaction_fee=370;
if (ammount>175000 && ammount <=180000)
transaction_fee=375;
if (ammount>180000 && ammount <=185000)
transaction_fee=380;
if (ammount>185000 && ammount <=190000)
transaction_fee=385;
if (ammount>190000 && ammount <=195000)
transaction_fee=390;
if (ammount>195000 && ammount <=200000)
transaction_fee=400;
if (ammount>20000 && ammount <=210000)
transaction_fee=420;
if (ammount>210000 && ammount <=220000)
transaction_fee=440;
if (ammount>220000 && ammount <=230000)
transaction_fee=460;
if (ammount>230000 && ammount <=2400000)
transaction_fee=480;
if (ammount>240000 && ammount <=250000)
transaction_fee=500;
if (ammount>250000 && ammount <=260000)
transaction_fee=520;
if (ammount>260000 && ammount <=270000)
transaction_fee=540;
if (ammount>270000 && ammount <=280000)
transaction_fee=560;
if (ammount>280000 && ammount <=290000)
transaction_fee=580;
if (ammount>290000 && ammount <=300000)
transaction_fee=600;
if (ammount>300000 && ammount <=310000)
transaction_fee=620;
if (ammount>310000 && ammount <=320000)
transaction_fee=640;
if (ammount>330000 && ammount <=340000)
transaction_fee=660;
if (ammount>340000 && ammount <=350000)
transaction_fee=680;
if (ammount>350000 && ammount <=360000)
transaction_fee=700;
if (ammount>360000 && ammount <=370000)
transaction_fee=720;
if (ammount>370000 && ammount <=380000)
transaction_fee=740;
if (ammount>380000 && ammount <=390000)
transaction_fee=760;
if (ammount>390000 && ammount <=400000)
transaction_fee=780;
if (ammount>400000 && ammount <=410000)
transaction_fee=800;
if (ammount>410000 && ammount <=420000)
transaction_fee=820;
if (ammount>420000 && ammount <=430000)
transaction_fee=840;
if (ammount>430000 && ammount <=440000)
transaction_fee=860;
if (ammount>440000 && ammount <=450000)
transaction_fee=880;
if (ammount>450000 && ammount <=460000)
transaction_fee=900;
if (ammount>460000 && ammount <=470000)
transaction_fee=920;
if (ammount>470000 && ammount <=480000)
transaction_fee=940;
if (ammount>480000 && ammount <=490000)
transaction_fee=960;
if (ammount>490000 && ammount <=500000)
transaction_fee=980;
if (ammount>500000 && ammount <=510000)
transaction_fee=1000;
std::cout<<"enter pin"<<endl;
std::cin>>userpin;
if(userpin>999 && userpin <=9999) 
{ 
} else 
{system("color c");
     cout<<"wrong pin try again!"<<endl;
return -1;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      system("color a");
        std::cout << "Please enter your PIN: ";
        std::cin >> userpin;
}}
  if (ammount<balance)
{    cout<<"You are withedrawing Ksh:"<<ammount<<" from ";
 string selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME,location,sub_location,AgentId FROM AGENTS WHERE Agentcode= '" + Agentcode + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    } int choice22;
setcolor( 0x02 );
  cout<<"A transaction fee of Ksh:"<<transaction_fee<<" will be charged."<<endl;
  cout<<"Do you wish to continue with the transaction?"<<endl;
  cout<<"1.Yes"<<endl;
  cout<<"2.No"<<endl;
  cin>>choice22;
  switch (choice22)
  { 
      case 1:
      {
          
      }
    break;
    case 2:
    if(choice22==2)  
    {
        cout<<"You have successfully cancelled the Transaction"<<endl;
        return 0;
    }
    break;
  }
 balance-=transaction_fee + ammount; 
setcolor( 0x0C );
cout << "\033[4;31m"; 
std::cout<<rand_array; 
setcolor( 0x02);
cout<<" confirmed you have withedrawn:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<ammount;
setcolor( 0x02 );
cout<<" from ";
setcolor( 0x0C );
  // SQL statement to retrieve transaction history
    
     selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME,location,sub_location,AgentId FROM AGENTS WHERE Agentcode= '" + Agentcode + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
setcolor( 0x02 );
cout<< " on "<<dt;
cout<<",a Transaction fee of:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<< transaction_fee;
setcolor( 0x02 );
cout<<" has been charged";
cout<<",your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
setcolor(0x02);
 cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<" Ksh5000000"<<endl;
     cout << "\033[0m" << endl;
}
else
{ int choose5,sum,total= ammount-balance; float interest = (total)/(100);
    system("color c");
std::cout<<"insuficient funds in your dancom account"<<endl;
cout<<"your dancom balance is Ksh";
setcolor( 0x02 );
cout <<balance;
setcolor( 0x0C );
cout<<" on ";
setcolor( 0x02 );
cout<< dt <<endl;
setcolor( 0x0C );
cout<<"A Transaction fee of :Ksh";
setcolor( 0x02 );
cout<< transaction_fee;
setcolor( 0x0C );
cout<<" is required"<<endl;
setcolor( 0x02 );
cout<<"would you like to SUM UP the remaining amount?"<<endl;
cout<<"1. YES"<<endl;
cout<<"2. NO"<<endl;
cin>>choose5;
switch (choose5)
{ 
case 1:
if (choose5==1)
sum=(balance + ammount ) - (balance + transaction_fee);
total = ammount-balance ;

{   
  // Open the database connection
    int rc = sqlite3_open("AGENTS.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }cout<<"You are SUMMING UP ksh:";
setcolor(0x0C);
cout<<total;
setcolor(0x02);
cout<< " to ";
   setcolor( 0x0C );
     // SQL statement to retrieve transaction history
    
    string selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME,location,sub_location,AgentId FROM AGENTS WHERE Agentcode= '" + Agentcode + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
  int choose6;
    setcolor(0x02);
cout<<"for your withedrawal as on:";
setcolor(0x0C);
cout<<dt;
setcolor(0x02);
cout<<" a Transaction fee of ksh:";
setcolor(0x0C);
cout<<transaction_fee;
setcolor(0x02);
cout<<" and an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged."<<endl;
cout<<"Do you wish to proceed with the transaction?" <<endl;
cout<<"1.Yes"<<endl;
cout<<"2.No"<<endl;
cin>>choose6;
switch (choose6)
{
    case 1:
    if (choose6==1)
    { 
    
    }
    break;
    case 2:
    if (choose6==2)
  { 
   cout<<"You have successfully canceled the transaction"<<endl;
return 0;
  }
    break;
   
}
 balance-=balance;
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have withedrawn:";
setcolor( 0x0C);
cout << "\033[4;31m";
cout<<"ksh"<<sum;
setcolor( 0x02);
cout<<" from ";
setcolor( 0x0C );
  // SQL statement to retrieve transaction history
    
     selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME,location,sub_location,AgentId FROM AGENTS WHERE Agentcode= '" + Agentcode + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
setcolor( 0x02 );
cout<< "on "<< dt;
cout<<"The amount is to  be paid before ";
setcolor( 0x0C );
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
setcolor( 0x02 );
cout<<"Your Dancom SUM UP amount is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<total;
setcolor(0x02);
cout<<" an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" wil be charged and";
cout <<" a Transaction fee of:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<transaction_fee;
setcolor( 0x02);
cout<<" has been charged";
cout<<",your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
setcolor(0x02);
  cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh 5000000"<<endl;
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
} 
    break;
    case 2:
    if (choose5==2)
 {  
  break;   
 } 
}
break;
}
}
}
system("color a");
break;
void showMenu( );
case 3:cout<<"buy airtime:"<<endl;
if (option==3)
cout<<"1.Buy for this number"<<endl;
cout<<"2.Buy for other number "<<endl;
cout<<"Enter option"<<endl;
cin>>option4;
switch(option4)
{
case 1:cout<<"Buy for this number"<<endl;
if (option4==1)
{
    rc = sqlite3_open("TRANSACTIONS.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
  /* Create SQL statement */
    string sql = "CREATE TABLE Airtime("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
                 "BONUS  INT   NOT NULL," \
                 "BALANCE  REAL NOT NULL," \
                 "PHONENUMBER   STRING     ," \
                   "Time_Bought    TIMESTAMP                          );";

    

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }

cout<<"enter amount you wish to spend"<<endl;
cin>>ammount;

cout<<"enter pin"<<endl;
cin>>userpin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{ system("color c");
cout<<"wrong pin try again!"<<endl;
return -1;
}
{    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   
      system("color a");
        std::cout << "Please enter your PIN: ";
        std::cin >> userpin;
}}

 if (ammount==100)
bonus=1;
if (ammount>100 && ammount<=200)
bonus=2;
if (ammount>200 && ammount <=300)
bonus=3;
if (ammount>300 && ammount <=400)
bonus=4;
if (ammount>400 && ammount<=500)
bonus=5;
if (ammount>500 &&ammount <=600)
bonus=6;
if (ammount>600 && ammount <=700)
bonus=7;
if (ammount>700 &&ammount <=800)
bonus=8;
if (ammount>800 &&ammount <=900)
bonus=9;
if (ammount>900 && ammount<=1000)
bonus=10;
if (ammount>1000 && ammount<=2000 )
bonus=30;
if (ammount>2000 && ammount <=3000)
bonus=40;
if (ammount>3000 && ammount<=4000)
bonus=45;
if (ammount>4000 && ammount <=5000)
bonus=50;
if (ammount>5000 &&ammount<=6000  )
bonus=55;
if (ammount>6000 && ammount<=7000)
bonus=60;
if (ammount>7000 && ammount <= 8000)
bonus=65;
if (ammount>8000 && ammount <= 9000)
bonus=70;
if (ammount>9000 && ammount <= 10000)
bonus=85;
if (ammount>10000)
bonus=100;
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
    
    if (ammount<=balance)
{
     
    balance-=ammount;
airtime+=ammount + bonus;
    // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Airtime (AMOUNT,BONUS,BALANCE,PHONENUMBER, Time_Bought ) VALUES (?, ?, ?, ?,CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, ammount);
    sqlite3_bind_int(stmt, 2, bonus);
    sqlite3_bind_double(stmt, 3, balance);
    sqlite3_bind_text(stmt, 4, phonenumber.c_str(), -1, SQLITE_STATIC);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);
setcolor( 0x0C );
cout << "\033[4;31m";
cout<< rand_array ;
setcolor( 0x02 );
cout <<" confirmed you have bought:";
setcolor( 0x0C );
cout << "\033[4;31m";
 cout<<"ksh"<<ammount;
 setcolor( 0x02);
 cout<<" worth of airtime on,"<<dt;        
std::cout<<"your dancom airtime bonus is :";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<bonus;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<" your total dancom airtime is:";setcolor( 0x0C );
cout << "\033[4;31m";
cout<<airtime;
cout << "\033[0m";
cout<<" your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
cout << "\033[0m";
setcolor(0x02);
cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh5000000";
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
}       
else
{system("color c");
cout<<"insufficient funds to buy airtime";
cout<<" your DANCOM balance is:ksh";
setcolor( 0x02 );
cout<<balance;
setcolor( 0x0C );
cout<<",as on ";
setcolor( 0x02 );
cout<<dt<<endl;

}
break;
void showMenu();
system("color a");
case 2:cout<<"Buy for another number"<<endl;
if (option4==2)
rc = sqlite3_open("TRANSACTIONS.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
  /* Create SQL statement */
    string sql = "CREATE TABLE  Airtime_otheruser("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
                 "BONUS  INT NOT NULL," \
                 "BALANCE  REAL NOT NULL," \
                 "PHONENUMBER   STRING     ," \
                   "Time_Bought    TIMESTAMP                          );";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }
cout<<"Enter the number"<<endl;
cin>>phonenumber;
cout<<"enter amount you wish to spend"<<endl;
cin>>ammount;
cout<<"enter pin"<<endl;
cin>>userpin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{ system("color c");
cout<<"wrong pin try again!"<<endl;
return -1;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      system("color a");
        std::cout << "Please enter your PIN: ";
        std::cin >> userpin;
}}
if (ammount==100)
bonus=1;
if (ammount>100 && ammount<=200)
bonus=2;
if (ammount>200 && ammount <=300)
bonus=3;
if (ammount>300 && ammount <=400)
bonus=4;
if (ammount>400 && ammount<=500)
bonus=5;
if (ammount>500 &&ammount <=600)
bonus=6;
if (ammount>600 && ammount <=700)
bonus=7;
if (ammount>700 &&ammount <=800)
bonus=8;
if (ammount>800 &&ammount <=900)
bonus=9;
if (ammount>900 && ammount<=1000)
bonus=10;
if (ammount>1000 && ammount<=2000 )
bonus=30;
if (ammount>2000 && ammount <=3000)
bonus=40;
if (ammount>3000 && ammount<=4000)
bonus=45;
if (ammount>4000 && ammount <=5000)
bonus=50;
if (ammount>5000 &&ammount<=6000  )
bonus=55;
if (ammount>6000 && ammount<=7000)
bonus=60;
if (ammount>7000 && ammount <= 8000)
bonus=65;
if (ammount>8000 && ammount <= 9000)
bonus=70;
if (ammount>9000 && ammount <= 10000)
bonus=85;
if (ammount>10000)
bonus=100;
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
if (ammount<=balance)
{
    balance-=ammount;
    airtime+=ammount + bonus;
       // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Airtime_otheruser (AMOUNT,BONUS,BALANCE,PHONENUMBER, Time_Bought ) VALUES (?, ?, ?, ?,CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, ammount);
    sqlite3_bind_int(stmt, 2, bonus);
    sqlite3_bind_double(stmt, 3, balance);
    sqlite3_bind_text(stmt, 4, phonenumber.c_str(), -1, SQLITE_STATIC);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);
    // Open the database connection
    int rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<rand_array;
setcolor( 0x02);
cout<<" confirmed you have bought:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh";
cout<<ammount;
setcolor( 0x02 );
cout<<" worth of airtime to:";
setcolor( 0x0C );
// SQL statement to retrieve transaction history
    
    string selectQuery = "SELECT FIRST_NAME,LAST_NAME, PHONE_NUMBER FROM DANCOM WHERE  PHONE_NUMBER = '" + phonenumber+ "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
setcolor( 0x02 );
cout<<" on "<< dt ;
std::cout<<" your dancom airtime bonus is :";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<bonus;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<",your total dancom airtime is:"; setcolor( 0x0C );
cout << "\033[4;31m";
cout<<airtime;
cout << "\033[0m";
setcolor( 0x02 );
cout<<",your Dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<balance;
cout << "\033[0m";
setcolor(0x02);
  cout<<" The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh5000000";
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
    }
else 
{system("color c");
airtime+=ammount + bonus;
int choose7; float total = ammount-balance;int sum; float interest = (total)/(100);
    cout<<"insufficient funds to buy airtime"<<endl;
cout<<"your DANCOM balance is :ksh "<<balance<<endl;
setcolor(0x02);
cout<<"would you like to SUM UP the remaining amount?"<<endl;
cout<<"1. YES"<<endl;
cout<<"2. NO"<<endl;
cin>>choose7;
switch (choose7)
{ 
case 1:
if (choose7==1)

total = ammount-balance ;

{   
  // Open the database connection
    int rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
   cout<<"You are SUMMING UP ksh:";
setcolor(0x0C);
cout<<total;
setcolor(0x02);
cout<< " to ";
   setcolor( 0x0C );
     
// SQL statement to retrieve transaction history
    
    string selectQuery = "SELECT FIRST_NAME,LAST_NAME, PHONE_NUMBER FROM DANCOM WHERE  PHONE_NUMBER = '" + phonenumber+ "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }    
   
  int choose8;
    setcolor(0x02);
cout<<"for airtime on:";
setcolor(0x0C);
cout<<dt;
setcolor(0x02);
cout<<" an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<"will be charged"<<endl;
cout<<"Do you wish to proceed with the transaction?" <<endl;
cout<<"1.Yes"<<endl;
cout<<"2.No"<<endl;
cin>>choose8;
switch (choose8)
{
    case 1:
    if (choose8==1)
    { 
       rc = sqlite3_open("SUM_UP.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
  /* Create SQL statement */
    string sql = "CREATE TABLE Sum_Up_Airtime_otheruser("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
        "LOAN  INT    NOT NULL," \
                 "BONUS  INT   NOT NULL," \
                 "BALANCE  REAL NOT NULL," \
                 "PHONENUMBER   STRING     ," \
                   "Time_Bought    TIMESTAMP                          );";

    

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }

    
    }
    break;
    case 2:
    if (choose8==2)
  { 
   cout<<"You have successfully canceled the transaction"<<endl;
return 0;
  }
    break;
   void showMenu();
}
 balance-=balance;
  // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Sum_Up_Airtime_otheruser (AMOUNT,LOAN,BONUS,BALANCE,PHONENUMBER, Time_Bought ) VALUES (?, ?,?, ?, ?,CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, ammount);
    sqlite3_bind_int(stmt, 2, total);
    sqlite3_bind_int(stmt, 3, bonus);
    sqlite3_bind_double(stmt, 4, balance);
    sqlite3_bind_text(stmt, 5, phonenumber.c_str(), -1, SQLITE_STATIC);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);
   // Open the database connection
    rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have bought:";
setcolor( 0x0C);
cout << "\033[4;31m";
cout<<"ksh"<<ammount;
setcolor( 0x02);
cout<<" worth of airtime to";
setcolor( 0x0C );
   // SQL statement to retrieve transaction history
    
    selectQuery = "SELECT FIRST_NAME,LAST_NAME, PHONE_NUMBER FROM DANCOM WHERE  PHONE_NUMBER = '" + phonenumber+ "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    } 
setcolor( 0x02 );
cout<< "on "<< dt;
cout<<"The amount is to  be paid before ";
setcolor( 0x0C );
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
setcolor( 0x02 );
cout<<"Your Dancom SUM UP amount is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<total;
setcolor(0x02);
cout<<" an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged"<<endl;
cout<<",your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
setcolor(0x02);
  cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh 5000000"<<endl;
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
} 
    break;
    case 2:
    if (choose7==2)
 {  
  break;   
 } 
}
break;
}
break;
}
system("color a");
break;
void showMenu( );
case 4:cout<<"loans and savings:"<<endl;
if (option==4)
cout<<"1.D.bank"<<endl;
cout<<"2.Equity-dancom"<<endl;
std::cout<<"Enter option"<<endl;
cin>>option5;
switch (option5)
{  
  case 1:cout<<"D.bank"<<endl;
  if (option5==1)
cout<<  "1.send to D.bank"<<endl;
cout<<"2.withedraw from D.bank"<<endl;
cout<<"3.lock savings"<<endl;
cout<<"4.get a loan"<<endl;
cout<<"5.check balance"<<endl;
cout<<"Enter option"<<endl;
cin>>option6;
switch(option6)
{
case 1:cout<<"Send To D-bank"<<endl;
if (option6==1)
{
int rc = sqlite3_open("D-BANK.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
    
  /* Create SQL statement */
    string sql = "CREATE TABLE  Dbank_Deposits("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
        "BALANCE  REAL NOT NULL," \
        "PHONENUMBER   STRING     ," \
         "TIME   TIMESTAMP                          );";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }
std::cout<<"Enter amount"<<endl;
std::cin>>ammount;
std::cout<<"Enter pin"<<endl;
std::cin>>userpin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{ cout<<"wrong pin try again!"<<endl;
return -1;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      
        std::cout << "Please enter your PIN: ";
        std::cin >> userpin;
}}

for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
    if( ammount<=balance)
{balance-=ammount;
Daccount+=ammount;
// Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Dbank_Deposits (AMOUNT,BALANCE,PHONENUMBER, TIME ) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, ammount);
    sqlite3_bind_double(stmt, 2, Daccount);
    sqlite3_bind_text(stmt, 3, phonenumber.c_str(), -1, SQLITE_STATIC);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02);
cout<<" confirmed:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<ammount;
setcolor( 0x02 );
cout<<" has been send to your D.bank on,"<<dt;
std::cout<<",your outstanding Dancom balance as on "<<dt<<" is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<balance;
setcolor( 0x02);
cout<<" and D-bank balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<< Daccount ;
cout << "\033[0m";
setcolor(0x02);
  cout<<" The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh5000000";
     cout << "\033[0m" << endl;
}
else 
{system("color c");
cout<<"insufficient amount in your Dancom account";
std::cout<<",your outstanding Dancom balance as on "<<dt<<" is:"<<"Ksh"<<balance<<endl;
} }
break;
void showMenu();
system("color a");
case 2:cout<< "Withedraw From D.bank"<<endl;
if (option6==2)
{
    int rc = sqlite3_open("D-BANK.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
    
  /* Create SQL statement */
    string sql = "CREATE TABLE  Dbank_withedrawals("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
        "BALANCE  REAL NOT NULL," \
        "PHONENUMBER   STRING     ," \
         "TIME   TIMESTAMP                          );";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }
std::cout<<"Enter amount"<<endl;
std::cin>>ammount;

std::cout<<"Enter pin"<<endl;
std::cin>>pin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{ cout<<"wrong pin try again!"<<endl;
return -1;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      
        std::cout << "Please enter your PIN: ";
        std::cin >>userpin;
}}

for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
    if (ammount<=Daccount)
{Daccount-=ammount;
balance+=ammount;
// Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Dbank_Withedrawals(AMOUNT,BALANCE,PHONENUMBER, TIME ) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, ammount);
    sqlite3_bind_double(stmt, 2, Daccount);
    sqlite3_bind_text(stmt, 3, phonenumber.c_str(), -1, SQLITE_STATIC);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have withedrawn:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<ammount;
setcolor( 0x02 );
cout<<" from your D.bank account on,"<<dt<<" and has been sent to your Dancom account"<<endl;
std::cout<<"your new D.bank account balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<< Daccount;
setcolor( 0x02 );
std::cout<<" your outstanding Dancom ballance as on "<<dt<<" is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<balance;
setcolor(0x02);
  cout<<" The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh5000000";
     cout << "\033[0m" << endl;
}
else
{system("color c");
cout<<"insufficient amount in your D.Bank account";
std::cout<<" your outstanding D.bank balance as on "<<dt<<" is: Ksh "<<Daccount<<endl;
} }
break;
void showMenu();
system("color a");
case 3:cout<<"3.lock savings"<<endl;
if (option6==3)
{
     int rc = sqlite3_open("D-BANK.db", &db);
    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
    
  /* Create SQL statement */
    string sql = "CREATE TABLE  Lock_savings("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
        "BALANCE  REAL NOT NULL," \
        "PERIOD   INT NOT NULL    ," \
         "TIME   TIMESTAMP                          );";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }
std::cout<<"How many months would you like to lock your savings"<<endl;
std::cin>>month;
std::cout<<"how much would you like to save?"<<endl;
std::cin>>ammount;
std::cout <<"Enter pin "<<endl;
std::cin>>userpin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{ system("color c");
cout<<"wrong pin try again!"<<endl;
return -1;

    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      system("color a");
        std::cout << "Please enter your PIN: ";
        std::cin >> userpin;
}
}
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
    if (ammount<=balance)
{
    balance-=ammount;
saveaccount+=ammount;
// Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Lock_savings(AMOUNT,BALANCE,PERIOD, TIME ) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, ammount);
    sqlite3_bind_double(stmt, 2, saveaccount);
    sqlite3_bind_int(stmt, 3,month);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02);
cout <<" confirmed:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<ammount;
setcolor( 0x02 );
cout <<" has been send to your lock savings account your new savings account  balance is";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<saveaccount;
setcolor( 0x02);
cout<<" and DANCOM balance is:";
setcolor(0x0C);
cout << "\033[4;31m";
cout<<"Ksh"<<balance;
setcolor(0x02);
  cout<<" The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh5000000";
     cout << "\033[0m" << endl;
}
else 
{system("color c");
    std::cout<<"insufficient amount in your DANCOM account  to transfer:"<<"Ksh "<< ammount<<" in your lock savings account your DANCOM balance is:Ksh"<< balance<<endl;
    }}
    break;
    void showMenu();
system("color a");
case 4:cout<<"Get a loan"<<endl;
if (option6==4 )
setcolor( 0x0C );
cout<<"1.1000"<<endl;
cout<<"2.5000" <<endl;
cout<<"3.10000"<<endl;
cout<<"4.20000"<<endl;
cout<<"5.50000"<<endl;
setcolor( 0x02 );
cout<<"Enter option"<<endl;
cin>>option7;
 userAccount.takeLoan(loan_ammount);
  balance+=loan_ammount;
switch (option7)
{
    case 1:
    if (option7==1)
    {
      loan_ammount=1000;
    rate =((loan_ammount)/(100));
  balance+=loan_ammount;
loan_interest=loan_ammount+rate;
     int rc = sqlite3_open("LOANS.db", &db);
    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
    
  /* Create SQL statement */
    string sql = "CREATE TABLE  Debtors("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
        "INTEREST  REAL NOT NULL," \
        "RATE   INT NOT NULL    ," \
         "TIME   TIMESTAMP                          );";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }
   
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
  
   // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Debtors(AMOUNT,INTEREST,RATE, TIME ) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, loan_ammount);
    sqlite3_bind_double(stmt, 2, loan_interest);
    sqlite3_bind_int(stmt, 3,rate);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02);
cout<<" confirmed you have received"; 
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<loan_ammount;
cout << "\033[0m";
setcolor( 0x02);
cout<<" from D.bank on "<<dt<<",The interest rate is";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<rate;
cout << "\033[0";
setcolor( 0x02 );
std::cout<<" your new DANCOM balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<balance;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<" The amount is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<< loan_interest;
 cout << "\033[0m";
setcolor( 0x02 );
cout<< " to be paid before," ;
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
 cout << "\033[0m" <<endl;
    }
    break;
    void showMenu();
    case 2:
    loan_ammount=5000;
    rate =((loan_ammount)/(100));
     balance+=loan_ammount;
loan_interest=loan_ammount+rate;
    if (option7==2)
    {
   int rc = sqlite3_open("LOANS.db", &db);
    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
    
  /* Create SQL statement */
    string sql = "CREATE TABLE  Debtors("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
        "INTEREST  REAL NOT NULL," \
        "RATE   INT NOT NULL    ," \
         "TIME   TIMESTAMP                          );";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
// Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Debtors(AMOUNT,INTEREST,RATE, TIME ) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, loan_ammount);
    sqlite3_bind_double(stmt, 2, loan_interest);
    sqlite3_bind_int(stmt, 3,rate);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }
     
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02);
cout<<" confirmed you have received"; 
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<loan_ammount;
cout << "\033[0m";
setcolor( 0x02);
cout<<" from D.bank on "<<dt<<",The interest rate is";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<rate;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<" your new DANCOM balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<balance;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<" The Total amount to be paid is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<< loan_interest;
cout << "\033[0m";
setcolor( 0x02 );
cout<< " to be paid before," ;
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
 cout << "\033[0m" << endl;
    }
    break;    
    void showMenu();
    case 3:
    loan_ammount=10000;
    rate =((loan_ammount)/(100));
     balance+=loan_ammount;
loan_interest=loan_ammount+rate;
    if (option7==3)   
    {
     int rc = sqlite3_open("LOANS.db", &db);
    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
    
  /* Create SQL statement */
    string sql = "CREATE TABLE  Debtors("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
        "INTEREST  REAL NOT NULL," \
        "RATE   INT NOT NULL    ," \
         "TIME   TIMESTAMP                          );";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }
setcolor( 0x02);
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
  
// Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Debtors(AMOUNT,INTEREST,RATE, TIME ) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, loan_ammount);
    sqlite3_bind_double(stmt, 2, loan_interest);
    sqlite3_bind_int(stmt, 3,rate);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }
   
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02);
cout<<" confirmed you have received"; 
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<loan_ammount;
cout << "\033[0m";
setcolor( 0x02);
cout<<" from D.bank on "<<dt<<",The interest rate is";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<rate;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<" your new DANCOM balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<balance;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<" The Total amount to be paid is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<< loan_interest;
cout << "\033[0m";
setcolor( 0x02 );
cout<< " to be paid before," ;
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
 cout << "\033[0m" << endl;
    }
    break;
    void showMenu();
    case 4:
    loan_ammount=20000;
    rate =((loan_ammount)/(100));
     balance+=loan_ammount;
loan_interest=loan_ammount+rate;
    if (option7==4)
    {
         int rc = sqlite3_open("LOANS.db", &db);
    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
    
  /* Create SQL statement */
    string sql = "CREATE TABLE  Debtors("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
        "INTEREST  REAL NOT NULL," \
        "RATE   INT NOT NULL    ," \
         "TIME   TIMESTAMP                          );";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
  
   // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Debtors(AMOUNT,INTEREST,RATE, TIME ) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, loan_ammount);
    sqlite3_bind_double(stmt, 2, loan_interest);
    sqlite3_bind_int(stmt, 3,rate);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02);
cout<<" confirmed you have received"; 
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<loan_ammount;
cout << "\033[0m";
setcolor( 0x02);
cout<<" from D.bank on "<<dt<<",The interest rate is";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<rate;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<" your new DANCOM balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<balance;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<" The Total amount to be paid is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<< loan_interest;
cout << "\033[0m";
setcolor( 0x02 );
cout<< " to be paid  before," ;
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
 cout << "\033[0m" << endl;
    }
    break;
    void showMenu();
    case 5:
    loan_ammount=50000;
    rate =((loan_ammount)/(100));
     balance+=loan_ammount;
loan_interest=loan_ammount+rate;
    if (option7==5)
  {
       int rc = sqlite3_open("LOANS.db", &db);
    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } 
    else 
    {
        cout << "Opened database successfully" << endl;
    }
    
  /* Create SQL statement */
    string sql = "CREATE TABLE  Debtors("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
        "AMOUNT INT    NOT NULL," \
        "INTEREST  REAL NOT NULL," \
        "RATE   INT NOT NULL    ," \
         "TIME   TIMESTAMP                          );";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else
     {
    cout << "Table created successfully" << endl;
    }
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
  
   // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Debtors(AMOUNT,INTEREST,RATE, TIME ) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    
    sqlite3_bind_int(stmt, 1, loan_ammount);
    sqlite3_bind_double(stmt, 2, loan_interest);
    sqlite3_bind_int(stmt, 3,rate);
    
    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
cout << "\033[0m";
setcolor( 0x02);
cout<<" confirmed you have received"; 
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<loan_ammount;
cout << "\033[0m";
setcolor( 0x02);
cout<<" from D.bank on "<<dt<<",The interest rate is";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":Ksh"<<rate;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<"your new DANCOM balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<balance;
cout << "\033[0m";
setcolor( 0x02 );
std::cout<<" The Total amount to be paid is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<< loan_interest;
cout << "\033[0m";
setcolor( 0x02 );
cout<< " to be paid before," ;
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
setcolor( 0x02 );
 cout << "\033[0m" <<endl;
 break;
} }
break;
void showMenu();
case 5:cout<<"5.check balance"<<endl;
if (option6==5)
cout<<"Enter pin"<<endl;
cin>>userpin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{ cout<<"wrong pin try again!"<<endl;
return -1;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      
        std::cout << "Please enter your PIN: ";
        std::cin >> userpin;
}}
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
 
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<rand_array;
setcolor( 0x02);
cout<<" confirmed your D-bank account balance is:ksh"<<Daccount<<" as on "<<dt;

  cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh5000000";
     cout << "\033[0m" << endl;
break;
}
break;
void showMenu( );
case 2:cout<<"Equity-D.bank"<<endl;
if (option5==2)
break;
}
system("color a");
break;
void showMenu( );
case 5:cout<<"lipa na dancom"<<endl;
if(option==5)
cout<<"1.pay bill"<<endl;
cout<<"2.buy goods and services"<<endl;
cout<<"3.pochi la biashara"<<endl;
cout<<"Enter option"<<endl;
cin>>option8;
switch (option8)
{ 
case 1:
if (option8==1)   
{
// Open SQLite database
    int rc = sqlite3_open("TRANSACTIONS.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened transaction database successfully!" << std::endl;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS Paybill("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Bs_No  INT NOT NULL," 
                                   "Till_Number  INT NOT NULL,"
                                   "Amount  INT NOT NULL," 
                                   "Balance REAL,"                                                 "Time TIMESTAMP        );";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Pay Bill  Table created successfully!" << std::endl;
    }
                 
cout<<"enter business number"<<endl;
cin>>businessnumber;
if (businessnumber .length( )==6)
{
     }else 
{system("color c");
    cout<<"wrong businessnumber, businessnumber should have 6 characters"<<endl;
return -1;
}
cout<<"Enter till number"<<endl;
cin>>phonenumber;
if (phonenumber .length( )==10)
{
     }else 
{system("color c");
    cout<<"wrong tillnumber, pay bill tillnumber  should have 10 characters"<<endl;
return -1;
}
cout<<"enter amount "<<endl;
cin>>ammount;

cout<<"enter pin"<<endl;
cin>>userpin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{ cout<<"wrong pin try again!"<<endl;
return -1;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      
        std::cout << "Please enter your PIN: ";
        std::cin >> userpin;
}}
if (ammount > 50 && ammount <=100)
transaction_fee=2;
if (ammount>100 && ammount <= 500)
transaction_fee=6;
if (ammount>500 && ammount <=700)
transaction_fee=7;
if (ammount>700 && ammount <=800)
transaction_fee=8;
if (ammount >800 && ammount <=900)
transaction_fee=9;
if (ammount>900 && ammount <=1000)
transaction_fee=10;
if (ammount>1000 && ammount <=2000)
transaction_fee=20;
if (ammount>2000 &&ammount <= 3000)
transaction_fee=30;
if (ammount>3000 && ammount <= 4000)
transaction_fee=40;
if (ammount>4000 && ammount <= 5000)
transaction_fee=50;
if (ammount>5000 && ammount <=6000)
transaction_fee=60;
if (ammount>6000 && ammount<=7000)
transaction_fee=70;
if (ammount>7000 && ammount<=8000)
transaction_fee=80;
if (ammount>8000 && ammount<=9000)
transaction_fee=90;
if (ammount>9000 && ammount<=10000)
transaction_fee=100;
if (ammount>10000 && ammount<=12000)
transaction_fee=110;
if (ammount>12000 && ammount<=14000)
transaction_fee=120;
if (ammount>14000 && ammount<=16000)
transaction_fee=130;
if (ammount>16000 && ammount<=20000)
transaction_fee=135;
if (ammount>20000 && ammount<=25000)
transaction_fee=140;
if (ammount>25000 && ammount<=30000)
transaction_fee=145;
if (ammount>30000 && ammount<=35000)
transaction_fee=150;
if (ammount>35000 && ammount<=40000)
transaction_fee=155;
if (ammount>40000 && ammount<=45000)
transaction_fee=160;
if (ammount>45000 && ammount<=50000)
transaction_fee=165;
if (ammount>50000 && ammount<=55000)
transaction_fee=170;
if (ammount>55000 && ammount<=60000)
transaction_fee=175;
if (ammount>60000 && ammount<=65000)
transaction_fee=180;
if (ammount>65000 && ammount<=70000)
transaction_fee=185;
if (ammount>70000 && ammount<=75000)
transaction_fee=190;
if (ammount>75000 && ammount<=80000)
transaction_fee=195;
if (ammount>80000 && ammount<=85000)
transaction_fee=200;
if (ammount>85000 && ammount<=90000)
transaction_fee=205;
if (ammount>90000 && ammount<=95000)
transaction_fee=210;
if (ammount>95000 && ammount<=100000)
transaction_fee=215;
if (ammount>100000 && ammount<=105000)
transaction_fee=220;
if (ammount>105000 && ammount<=110000)
transaction_fee=225;
if (ammount>110000 && ammount<=115000)
transaction_fee=230;
if (ammount>115000 && ammount<=120000)
transaction_fee=235;
if (ammount>120000 && ammount<=125000)
transaction_fee=240;
if (ammount>125000 && ammount<=130000)
transaction_fee=250;
if (ammount>130000 && ammount<=135000)
transaction_fee=255;
if (ammount>135000 && ammount<=140000)
transaction_fee=260;
if (ammount>140000 && ammount<=145000)
transaction_fee=265;
if (ammount>145000 && ammount<=150000)
transaction_fee=270;
if (ammount>150000 && ammount<=155000)
transaction_fee=280;
if (ammount>155000 && ammount<=160000)
transaction_fee=285;
if (ammount>160000 && ammount<=165000)
transaction_fee=290;
if (ammount>165000 && ammount<=170000)
transaction_fee=300;
if (ammount>170000 && ammount<=175000)
transaction_fee=310;
if (ammount>175000 && ammount<=180000)
transaction_fee=315;
if (ammount>180000 && ammount<=185000)
transaction_fee=325;
if (ammount>185000 && ammount<=190000)
transaction_fee=330; 
if (ammount>190000 && ammount<=195000)
transaction_fee=340;
if (ammount>195000 && ammount<=200000)
transaction_fee=345;
if (ammount>200000 && ammount<=205000)
transaction_fee=355;
if (ammount>205000 && ammount<=210000)
transaction_fee=360;  
  
    if (ammount <= balance) 
{
   balance-=ammount + transaction_fee;

      for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
   // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Paybill(Bs_No,Till_Number, Amount, Balance, Time) VALUES (?,?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
   sqlite3_bind_text(stmt, 1,businessnumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, phonenumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, ammount);
    sqlite3_bind_double(stmt, 4, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);
    
      // Open the individual business database connection
    rc = sqlite3_open("individualbs.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
   
     string selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME FROM individual WHERE PHONE_NUMBER= '" + phonenumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }int choice23;
                 
setcolor( 0x02 );
cout<<"will receive Ksh:"<<ammount<<",a Transaction fee of ksh:"<<transaction_fee<<" will be charged"<<endl;
cout<<"Do you wish to proceed with the transaction?"<<endl;
cout<<"1.Yes"<<endl;
cout<<"2.No"<<endl;
cin>>choice23;
switch(choice23)
{
    case 1:
    {
        
    }
    break;
    case 2:
    if (choice23==2)
    {
        cout<<"You have successfully canceled the transaction"<<endl;
    }
    
}
        
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<rand_array;
setcolor( 0x02);
cout<<" confirmed you have paid:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<< "ksh"<<ammount ;
setcolor( 0x02);
cout<<" to ";
setcolor( 0x0C );
// SQL statement to retrieve business owners information 
    selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME FROM individual WHERE PHONE_NUMBER= '" + phonenumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
                 
setcolor( 0x02 );
cout<< " on "<< dt;
setcolor( 0x02 );
cout<<" your new Dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<balance;
cout << "\033[0m";
setcolor( 0x02 );
cout<<" The Transaction fee is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<< transaction_fee;
setcolor(0x02);
cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" While  the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh5000000";
    cout << "\033[0m" << endl; 
}
else
{system("color c");
int choose14,sum; float total= ammount- balance; float interest = (total)/(100); 
cout<<"insufficient amount to purchase goods";
cout<<" your dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<" ksh"<<balance;
setcolor(0x02);
cout<< " on "<< dt ;
cout<<" A transaction fee of:";
    setcolor(0x0C);
    cout << "\033[4;31m";
      cout<<  "ksh"<< transaction_fee;
       cout << "\033[0m" ;
      setcolor(0x02);
      cout<<" is required"<<endl;
      setcolor( 0x02 );
cout<<"would you like to SUM UP the remaining amount?"<<endl;
cout<<"1. YES"<<endl;
cout<<"2. NO"<<endl;
cin>>choose14;
switch (choose14)
{ 
case 1:
if (choose14==1)
sum=(balance + ammount ) - (balance + transaction_fee);
total = ammount-balance ;

{   
  // Open the database connection
    int rc = sqlite3_open("individualbs.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }cout<<"You are SUMMING UP ksh:";
setcolor(0x0C);
cout<<total;
setcolor(0x02);
cout<< " to ";
   setcolor( 0x0C );
     // SQL statement to retrieve transaction history
     string selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME FROM individual WHERE TILL_NO= '" + tillnumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
   
  int choose15;
    setcolor(0x02);
cout<<"for pay bill as on:";
setcolor(0x0C);
cout<<dt;
setcolor(0x02);
cout<<" a Transaction fee of ksh:";
setcolor(0x0C);
cout<<transaction_fee;
setcolor(0x02);
cout<<" and an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged."<<endl;
cout<<"Do you wish to proceed with the transaction?" <<endl;
cout<<"1.Yes"<<endl;
cout<<"2.No"<<endl;
cin>>choose15;
switch (choose15)
{
    case 1:
    if (choose15==1)
    { 
    // Open SQLite database
    int rc = sqlite3_open("SUM_UP.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened Sum Up database successfully!" << std::endl;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS Sum_Up_Paybill("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Bs_No  INT NOT NULL," 
                                   "Till_Number  INT NOT NULL,"
                                   "Amount  INT NOT NULL,"
                                   "Loan  INT NOT NULL,"  
                                   "Balance REAL,"                                                 "Time TIMESTAMP        );";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Pay Bill  Table created successfully!" << std::endl;
    }
                 
    
    }
    break;
    case 2:
    if (choose15==2)
  { 
   cout<<"You have successfully canceled the transaction"<<endl;
return 0;
  }
    break;
   
}
 balance-=balance;
   // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Sum_Up_Paybill(Bs_No,Till_Number, Amount,Loan,Balance, Time) VALUES (?,?, ?, ?,?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
   sqlite3_bind_text(stmt, 1,businessnumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, phonenumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, ammount);
    sqlite3_bind_int(stmt, 4,total );
    sqlite3_bind_double(stmt, 5, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);
    
      // Open the individual business database connection
    rc = sqlite3_open("individualbs.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have paid:";
setcolor( 0x0C);
cout << "\033[4;31m";
cout<<"ksh"<<sum;
setcolor( 0x02);
cout<<" to ";
setcolor( 0x0C );
  // SQL statement to retrieve transaction history
selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME FROM individual WHERE TILL_NO= '" + tillnumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
     
setcolor( 0x02 );
cout<< "on "<< dt;
cout<<"The amount is to  be paid before ";
setcolor( 0x0C );
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
setcolor( 0x02 );
cout<<"Your Dancom SUM UP amount is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<total;
setcolor(0x02);
cout <<",a Transaction fee of:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<transaction_fee;
setcolor( 0x02);
cout<<" has been charged";
cout<<" and an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged"<<endl;
cout<<",your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
setcolor(0x02);
  cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh 5000000"<<endl;
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
} 
    break;
    case 2:
    if (choose14==2)
 {  
  break;   
 } 
}
break;
}}
break;
void showMenu();
system("color a");
case 2:
if (option8==2)
{
 // Open SQLite database
    int rc = sqlite3_open("TRANSACTIONS.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened transaction database successfully!" << std::endl;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS Buy_Goods("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Till_Number  INT NOT NULL,"
                                   "Amount  INT NOT NULL," 
                                   "Balance REAL,"                                                 "Time TIMESTAMP        );";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Buy Goods Table created successfully!" << std::endl;
    }
 
cout<<"enter till number"<<endl;
cin>>tillnumber;
if (tillnumber .length( )==6)
{
     }else 
{system("color c");
    cout<<"wrong tillnumber, tillnumber  should have 6 characters"<<endl;
return -1;
}
cout<<"Enter amount "<<endl;
cin>>ammount;
if (ammount > 50 && ammount <=100)
transaction_fee=2;
if (ammount>100 && ammount <= 500)
transaction_fee=6;
if (ammount>500 && ammount <=700)
transaction_fee=7;
if (ammount>700 && ammount <=800)
transaction_fee=8;
if (ammount >800 && ammount <=900)
transaction_fee=9;
if (ammount>900 && ammount <=1000)
transaction_fee=10;
if (ammount>1000 && ammount <=2000)
transaction_fee=20;
if (ammount>2000 &&ammount <= 3000)
transaction_fee=30;
if (ammount>3000 && ammount <= 4000)
transaction_fee=40;
if (ammount>4000 && ammount <= 5000)
transaction_fee=50;
if (ammount>5000 && ammount <=6000)
transaction_fee=60;
if (ammount>6000 && ammount<=7000)
transaction_fee=70;
if (ammount>7000 && ammount<=8000)
transaction_fee=80;
if (ammount>8000 && ammount<=9000)
transaction_fee=90;
if (ammount>9000 && ammount<=10000)
transaction_fee=100;
if (ammount>10000 && ammount<=12000)
transaction_fee=110;
if (ammount>12000 && ammount<=14000)
transaction_fee=120;
if (ammount>14000 && ammount<=16000)
transaction_fee=130;
if (ammount>16000 && ammount<=20000)
transaction_fee=135;
if (ammount>20000 && ammount<=25000)
transaction_fee=140;
if (ammount>25000 && ammount<=30000)
transaction_fee=145;
if (ammount>30000 && ammount<=35000)
transaction_fee=150;
if (ammount>35000 && ammount<=40000)
transaction_fee=155;
if (ammount>40000 && ammount<=45000)
transaction_fee=160;
if (ammount>45000 && ammount<=50000)
transaction_fee=165;
if (ammount>50000 && ammount<=55000)
transaction_fee=170;
if (ammount>55000 && ammount<=60000)
transaction_fee=175;
if (ammount>60000 && ammount<=65000)
transaction_fee=180;
if (ammount>65000 && ammount<=70000)
transaction_fee=185;
if (ammount>70000 && ammount<=75000)
transaction_fee=190;
if (ammount>75000 && ammount<=80000)
transaction_fee=195;
if (ammount>80000 && ammount<=85000)
transaction_fee=200;
if (ammount>85000 && ammount<=90000)
transaction_fee=205;
if (ammount>90000 && ammount<=95000)
transaction_fee=210;
if (ammount>95000 && ammount<=100000)
transaction_fee=215;
if (ammount>100000 && ammount<=105000)
transaction_fee=220;
if (ammount>105000 && ammount<=110000)
transaction_fee=225;
if (ammount>110000 && ammount<=115000)
transaction_fee=230;
if (ammount>115000 && ammount<=120000)
transaction_fee=235;
if (ammount>120000 && ammount<=125000)
transaction_fee=240;
if (ammount>125000 && ammount<=130000)
transaction_fee=250;
if (ammount>130000 && ammount<=135000)
transaction_fee=255;
if (ammount>135000 && ammount<=140000)
transaction_fee=260;
if (ammount>140000 && ammount<=145000)
transaction_fee=265;
if (ammount>145000 && ammount<=150000)
transaction_fee=270;
if (ammount>150000 && ammount<=155000)
transaction_fee=280;
if (ammount>155000 && ammount<=160000)
transaction_fee=285;
if (ammount>160000 && ammount<=165000)
transaction_fee=290;
if (ammount>165000 && ammount<=170000)
transaction_fee=300;
if (ammount>170000 && ammount<=175000)
transaction_fee=310;
if (ammount>175000 && ammount<=180000)
transaction_fee=315;
if (ammount>180000 && ammount<=185000)
transaction_fee=325;
if (ammount>185000 && ammount<=190000)
transaction_fee=330; 
if (ammount>190000 && ammount<=195000)
transaction_fee=340;
if (ammount>195000 && ammount<=200000)
transaction_fee=345;
if (ammount>200000 && ammount<=205000)
transaction_fee=355;
if (ammount>205000 && ammount<=210000)
transaction_fee=360;  
cout<<"enter pin"<<endl;
cin>>userpin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{system("color c");
     cout<<"wrong pin try again!"<<endl;
return -1;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      system("color a");
        std::cout << "Please enter your PIN: ";
        std::cin >> enteredPin;
}}

    if (userpin>999 && userpin<=9999 && ammount<balance)
{
    balance-=ammount + transaction_fee;
    for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
      // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Buy_Goods(Till_Number, Amount, Balance, Time) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
   sqlite3_bind_text(stmt, 1,tillnumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, ammount);
    sqlite3_bind_double(stmt, 3, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);

// Open the database connection
    rc = sqlite3_open("individualbs.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
   string selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME FROM individual WHERE TILL_NO= '" + tillnumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }int choice24;
    cout<<"will receive amount Ksh:"<<ammount<< ",a transaction of Ksh:"<<transaction_fee<<" will be charged"<<endl;
    cout<<"Do you wish to continue with the transaction?"<<endl;
    cout<<"1.Yes"<<endl;
    cout<<"2.No"<<endl;
    cin>>choice24;
    switch(choice24)
    {
        case 1:
        {
            
        }
        break;
        case 2:
        {
            cout<<"You have successfully cancelled the transaction"<<endl;
            return 0;
        }
        break;
    }
   
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<rand_array;
setcolor( 0x02);
cout<<" confirmed you have paid:"; 
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<< ammount ;
setcolor( 0x02);
cout<<" to ";
setcolor( 0x0C );
// SQL statement to retrieve transaction history
    
    selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME FROM individual WHERE TILL_NO= '" + tillnumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }

setcolor( 0x02 );
cout<< " on "<< dt ;
cout<<" your new Dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<balance;
setcolor(0x02);
cout<<" A Trasaction fee of ";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<":ksh"<< transaction_fee;
setcolor(0x02);
cout<<" has been charged";
cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" while the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<" Ksh5000000";
     cout << "\033[0m" << endl;
}
else
{system("color c");
int choose9; int sum; float total= ammount-balance; float interest= (total)/(100);
cout<<"insufficient amount to purchase goods";
cout<<"your dancom balance is :"<<balance<< " on "<< dt <<endl;
cout<<"A Trasaction fee of :ksh"<< transaction_fee<<" is required"<<endl;

setcolor( 0x02 );
cout<<"would you like to SUM UP the remaining amount?"<<endl;
cout<<"1. YES"<<endl;
cout<<"2. NO"<<endl;
cin>>choose9;
switch (choose9)
{ 
case 1:
if (choose9==1)
sum=(balance + ammount ) - (balance + transaction_fee);
total = ammount-balance ;

{   
  // Open the database connection
    int rc = sqlite3_open("individualbs.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }cout<<"You are SUMMING UP ksh:";
setcolor(0x0C);
cout<<sum;
setcolor(0x02);
cout<< " to ";
   setcolor( 0x0C );
     // SQL statement to retrieve transaction history
     string selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME FROM individual WHERE TILL_NO= '" + tillnumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
   
  int choose10;
    setcolor(0x02);
cout<<"to buy goods as on:";
setcolor(0x0C);
cout<<dt;
setcolor(0x02);
cout<<" a Transaction fee of ksh:";
setcolor(0x0C);
cout<<transaction_fee;
setcolor(0x02);
cout<<" and an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged."<<endl;
cout<<"Do you wish to proceed with the transaction?" <<endl;
cout<<"1.Yes"<<endl;
cout<<"2.No"<<endl;
cin>>choose10;
switch (choose10)
{
    case 1:
    if (choose10==1)
    { 
     // Open SQLite database
    int rc = sqlite3_open("SUM_UP.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened Sum Up database successfully!" << std::endl;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS Sum_Up_Buy_Goods("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Till_Number  INT NOT NULL,"
                                   "Amount  INT NOT NULL,"
                                   "Loan  INT NOT NULL,"  
                                   "Balance REAL,"                                                 "Time TIMESTAMP        );";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Buy Goods Table created successfully!" << std::endl;
    }
 
    }
    break;
    case 2:
    if (choose10==2)
  { 
   cout<<"You have successfully canceled the transaction"<<endl;
return 0;
  }
    break;
   
}
 balance-=balance;
  // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Sum_Up_Buy_Goods(Till_Number, Amount, Loan,Balance, Time) VALUES (?, ?, ?,?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
   sqlite3_bind_text(stmt, 1,tillnumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, ammount);
    sqlite3_bind_int(stmt, 3, total);
    sqlite3_bind_double(stmt, 4, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);

// Open the database connection
    rc = sqlite3_open("individualbs.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have bought goods worth:";
setcolor( 0x0C);
cout << "\033[4;31m";
cout<<"ksh"<<sum;
setcolor( 0x02);
cout<<" from ";
setcolor( 0x0C );
  // SQL statement to retrieve transaction history
selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME FROM individual WHERE TILL_NO= '" + tillnumber + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
     
setcolor( 0x02 );
cout<< "on "<< dt;
cout<<"The amount is to  be paid before ";
setcolor( 0x0C );
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
setcolor( 0x02 );
cout<<"Your Dancom SUM UP amount is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<total;
setcolor(0x02);
cout <<",a Transaction fee of:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<transaction_fee;
setcolor( 0x02);
cout<<" has been charged";
cout<<" and an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged";
cout<<",your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
setcolor(0x02);
  cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh 5000000"<<endl;
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
} 
    break;
    case 2:
    if (choose9==2)
 {  
  break;   
 } 
}
break;
} }
break;
void showMenu( );
case 3:cout<<"Pochi la Biashara"<<endl;
if (option8==3)
{
     // Open SQLite database
    int rc = sqlite3_open("TRANSACTIONS.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened transaction database successfully!" << std::endl;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS Pochi("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Phone_number  INT NOT NULL,"
                                   "Amount  INT NOT NULL," 
                                   "Balance REAL,"                                                 "Time TIMESTAMP        );";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Pochi La Biashara Table created successfully!" << std::endl;
    }
cout<<"Enter phone number"<<endl;
cin>>phonenumber;
if (phonenumber .length( )==10)
{
     }else 
{system("color c");
    cout<<"number should have 10 characters"<<endl;
return -1;
}
cout<<"Enter Amount"<<endl;
cin>>ammount;
if (ammount > 50 && ammount <=100)
transaction_fee=2;
if (ammount>100 && ammount <= 500)
transaction_fee=6;
if (ammount>500 && ammount <=700)
transaction_fee=7;
if (ammount>700 && ammount <=800)
transaction_fee=8;
if (ammount >800 && ammount <=900)
transaction_fee=9;
if (ammount>900 && ammount <=1000)
transaction_fee=10;
if (ammount>1000 && ammount <=2000)
transaction_fee=20;
if (ammount>2000 &&ammount <= 3000)
transaction_fee=30;
if (ammount>3000 && ammount <= 4000)
transaction_fee=40;
if (ammount>4000 && ammount <= 5000)
transaction_fee=50;
if (ammount>5000 && ammount <=6000)
transaction_fee=60;
if (ammount>6000 && ammount<=7000)
transaction_fee=70;
if (ammount>7000 && ammount<=8000)
transaction_fee=80;
if (ammount>8000 && ammount<=9000)
transaction_fee=90;
if (ammount>9000 && ammount<=10000)
transaction_fee=100;
if (ammount>10000 && ammount<=12000)
transaction_fee=110;
if (ammount>12000 && ammount<=14000)
transaction_fee=120;
if (ammount>14000 && ammount<=16000)
transaction_fee=130;
if (ammount>16000 && ammount<=20000)
transaction_fee=135;
if (ammount>20000 && ammount<=25000)
transaction_fee=140;
if (ammount>25000 && ammount<=30000)
transaction_fee=145;
if (ammount>30000 && ammount<=35000)
transaction_fee=150;
if (ammount>35000 && ammount<=40000)
transaction_fee=155;
if (ammount>40000 && ammount<=45000)
transaction_fee=160;
if (ammount>45000 && ammount<=50000)
transaction_fee=165;
if (ammount>50000 && ammount<=55000)
transaction_fee=170;
if (ammount>55000 && ammount<=60000)
transaction_fee=175;
if (ammount>60000 && ammount<=65000)
transaction_fee=180;
if (ammount>65000 && ammount<=70000)
transaction_fee=185;
if (ammount>70000 && ammount<=75000)
transaction_fee=190;
if (ammount>75000 && ammount<=80000)
transaction_fee=195;
if (ammount>80000 && ammount<=85000)
transaction_fee=200;
if (ammount>85000 && ammount<=90000)
transaction_fee=205;
if (ammount>90000 && ammount<=95000)
transaction_fee=210;
if (ammount>95000 && ammount<=100000)
transaction_fee=215;
if (ammount>100000 && ammount<=105000)
transaction_fee=300;
if (ammount>105000 && ammount<=110000)
transaction_fee=305;
if (ammount >110000 && ammount <=115000)
transaction_fee=310;
if (ammount>115000 && ammount <=120000)
transaction_fee=315;
if (ammount>120000 && ammount <=125000)
transaction_fee=320;
if (ammount>125000 && ammount <=130000)
transaction_fee=325;
if (ammount>130000 && ammount <=135000)
transaction_fee=330;
if (ammount>135000 && ammount <=140000)
transaction_fee=335;
if (ammount>140000 && ammount <=145000)
transaction_fee=340;
if (ammount>145000 && ammount <=150000)
transaction_fee=345;
if (ammount>150000 && ammount <=155000)
transaction_fee=350;
if (ammount>155000 && ammount <=160000)
transaction_fee=355;
if (ammount>160000 && ammount <=165000)
transaction_fee=360;
if (ammount>165000 && ammount <=170000)
transaction_fee=365;
if (ammount>170000 && ammount <=175000)
transaction_fee=370;
if (ammount>175000 && ammount <=180000)
transaction_fee=375;
if (ammount>180000 && ammount <=185000)
transaction_fee=380;
if (ammount>185000 && ammount <=190000)
transaction_fee=385;
if (ammount>190000 && ammount <=195000)
transaction_fee=390;
if (ammount>195000 && ammount <=200000)
transaction_fee=400;
if (ammount>20000 && ammount <=210000)
transaction_fee=420;
if (ammount>210000 && ammount <=220000)
transaction_fee=440;
if (ammount>220000 && ammount <=230000)
transaction_fee=460;
if (ammount>230000 && ammount <=2400000)
transaction_fee=480;
if (ammount>240000 && ammount <=250000)
transaction_fee=500;
if (ammount>250000 && ammount <=260000)
transaction_fee=520;
if (ammount>260000 && ammount <=270000)
transaction_fee=540;
if (ammount>270000 && ammount <=280000)
transaction_fee=560;
if (ammount>280000 && ammount <=290000)
transaction_fee=580;
if (ammount>290000 && ammount <=300000)
transaction_fee=600;
if (ammount>300000 && ammount <=310000)
transaction_fee=620;
if (ammount>310000 && ammount <=320000)
transaction_fee=640;
if (ammount>330000 && ammount <=340000)
transaction_fee=660;
if (ammount>340000 && ammount <=350000)
transaction_fee=680;
if (ammount>350000 && ammount <=360000)
transaction_fee=700;
if (ammount>360000 && ammount <=370000)
transaction_fee=720;
if (ammount>370000 && ammount <=380000)
transaction_fee=740;
if (ammount>380000 && ammount <=390000)
transaction_fee=760;
if (ammount>390000 && ammount <=400000)
transaction_fee=780;
if (ammount>400000 && ammount <=410000)
transaction_fee=800;
if (ammount>410000 && ammount <=420000)
transaction_fee=820;
if (ammount>420000 && ammount <=430000)
transaction_fee=840;
if (ammount>430000 && ammount <=440000)
transaction_fee=860;
if (ammount>440000 && ammount <=450000)
transaction_fee=880;
if (ammount>450000 && ammount <=460000)
transaction_fee=900;
if (ammount>460000 && ammount <=470000)
transaction_fee=920;
if (ammount>470000 && ammount <=480000)
transaction_fee=940;
if (ammount>480000 && ammount <=490000)
transaction_fee=960;
if (ammount>490000 && ammount <=500000)
transaction_fee=980;
if (ammount>500000 && ammount <=510000)
transaction_fee=1000;
cout<<"Enter Pin"<<endl;
cin>>userpin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{system("color c");
     cout<<"wrong pin try again!"<<endl;
return -1;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      system("color a");
        std::cout << "Please enter your PIN: ";
        std::cin >> enteredPin;
}}


if (ammount<balance)
{
    balance-=ammount + transaction_fee;
   
    for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
    
        // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Pochi (Phone_number, Amount, Balance, Time) VALUES (?, ?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
   sqlite3_bind_text(stmt, 1,phonenumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, ammount);
    sqlite3_bind_double(stmt, 3, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);

    // Open the database connection
    int rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    
    string selectQuery = "SELECT FIRST_NAME,LAST_NAME, PHONE_NUMBER FROM DANCOM WHERE  PHONE_NUMBER = '" + phonenumber+ "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
int choice25;                              
setcolor( 0x02 );
cout<<"will receive Ksh:"<<ammount<<",a transaction fee of Ksh:"<<transaction_fee<<" will be charged"<<endl;
cout<<"Do you wish to continue with the transaction?"<<endl;
cout<<"1.Yes"<<endl;
cout<<"2.No"<<endl;
cin>>choice25;
switch (choice25)
{
    case 1:
    {
        
    }
    break;
    case 2:
    if (choice25==2);
{
         cout<<"You have successfully cancelled the transaction" <<endl;                                                                            
}                                                                   
    }
    
    setcolor( 0x0C );
    cout << "\033[4;31m";
cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have send Ksh:";
setcolor( 0x0C );
cout<<ammount;
setcolor( 0x02 );
cout<<" to ";
setcolor( 0x0C );
      
// SQL statement to retrieve transaction history
    
    selectQuery = "SELECT FIRST_NAME,LAST_NAME, PHONE_NUMBER FROM DANCOM WHERE  PHONE_NUMBER = '" + phonenumber+ "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
setcolor( 0x02 );
cout<<" New Dancom balance is Ksh:";
setcolor( 0x0C );
cout<<balance;
setcolor( 0x02 );
cout<<" The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
   cout<<" while the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<" Ksh5000000";
     cout << "\033[0m" << endl;
}else 
{ system("color c");
int choose11,sum; float total= ammount-balance;float interest=(total)/(100);
cout<<"insufficient amount in your Dancom account"<<endl;
cout<<"your dancom balance is Ksh";
setcolor( 0x02 );
cout <<balance;
setcolor( 0x0C );
cout<<" on ";
setcolor( 0x02 );
cout<< dt <<endl;
setcolor( 0x0C );
cout<<"A Transaction fee of :Ksh";
setcolor( 0x02 );
cout<< transaction_fee;
setcolor( 0x0C );
cout<<" is required"<<endl;
setcolor( 0x02 );
cout<<"would you like to SUM UP the remaining amount?"<<endl;
cout<<"1. YES"<<endl;
cout<<"2. NO"<<endl;
cin>>choose11;
switch (choose11)
{ 
case 1:
if (choose11==1)
sum=(balance + ammount ) - (balance + transaction_fee);
total = ammount-balance ;

{   
  // Open the database connection
    int rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }cout<<"You are SUMMING UP ksh:";
setcolor(0x0C);
cout<<total;
setcolor(0x02);
cout<< " to ";
   setcolor( 0x0C );
     // SQL statement to retrieve transaction history
     string selectQuery = "SELECT FIRST_NAME,LAST_NAME, PHONE_NUMBER FROM DANCOM WHERE  PHONE_NUMBER = '" + phonenumber+ "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
    
  int choose12;
    setcolor(0x02);
cout<<"for pochi la biashara as on:";
setcolor(0x0C);
cout<<dt;
setcolor(0x02);
cout<<" a Transaction fee of ksh:";
setcolor(0x0C);
cout<<transaction_fee;
setcolor(0x02);
cout<<" and an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged."<<endl;
cout<<"Do you wish to proceed with the transaction?" <<endl;
cout<<"1.Yes"<<endl;
cout<<"2.No"<<endl;
cin>>choose12;
switch (choose12)
{
    case 1:
    if (choose12==1)
    { 
     // Open SQLite database
    int rc = sqlite3_open("SUM_UP.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened transaction database successfully!" << std::endl;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS Sum_Up_Pochi("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Phone_number  INT NOT NULL,"
                                   "Amount  INT NOT NULL,"
                                    "Loan  INT NOT NULL," 
                                   "Balance REAL,"                                                 "Time TIMESTAMP        );";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Pochi La Biashara Table created successfully!" << std::endl;
    }
    
    }
    break;
    case 2:
    if (choose12==2)
  { 
   cout<<"You have successfully canceled the transaction"<<endl;
return 0;
  }
    break;
   
}
 balance-=balance;
  // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Sum_Up_Pochi (Phone_number, Amount,Loan,Balance, Time) VALUES (?, ?,?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
   sqlite3_bind_text(stmt, 1,phonenumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, ammount);
    sqlite3_bind_int(stmt, 3, total);
    sqlite3_bind_double(stmt, 4, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);

    // Open the database connection
     rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    
setcolor( 0x0C );
cout << "\033[4;31m";
std::cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have send:";
setcolor( 0x0C);
cout << "\033[4;31m";
cout<<"ksh"<<sum;
setcolor( 0x02);
cout<<" to ";
setcolor( 0x0C );
  // SQL statement to retrieve transaction history
     selectQuery = "SELECT FIRST_NAME,LAST_NAME, PHONE_NUMBER FROM DANCOM WHERE  PHONE_NUMBER = '" + phonenumber+ "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
     
setcolor( 0x02 );
cout<< "on "<< dt;
cout<<"The amount is to  be paid before ";
setcolor( 0x0C );
std::cout << timePtr->tm_mday << "/";     
  std::cout << timePtr->tm_mon + 2<< "/";
   std::cout << timePtr->tm_year + 1900 << 
std::endl;
setcolor( 0x02 );
cout<<"Your Dancom SUM UP amount is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<total;
setcolor(0x02);
cout <<",a Transaction fee of:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<transaction_fee;
setcolor( 0x02);
cout<<" has been charged";
cout<<" and an interest of ksh:";
setcolor(0x0C);
cout<<interest;
setcolor(0x02);
cout<<" will be charged";
cout<<",your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh";
cout<<balance;
setcolor(0x02);
  cout<<",The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
    cout<<" And the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<"Ksh 5000000"<<endl;
     cout << "\033[0m" << endl;
 // Close the database connection
    sqlite3_close(db);
} 
    break;
    case 2:
    if (choose11==2)
 {  
  break;   
 } 
}

break;
}}}
system("color a");
break;
void showMenu( );
case 6:cout<<"my account:"<<endl;
if (option==6)
cout<<"1. Ministatement"<<endl;
cout<<"2. Check Balance"<<endl;
cout<<"3. Change Pin"<<endl;
cout<<"4. Change Language"<<endl;
cout<<"5. Update Customer Menu"<<endl;
cout<<"6. Customize Phonenumber"<<endl;
cout<<"Enter option"<<endl;
cin>>option9;
switch (option9)
{
    case 1: cout<<"ministatement"<<endl;
    if (option9==1)
    cout<<"Enter pin"<<endl;
    cin>>userpin;
    
    cout<<"Your statement will be provided shortly "<<endl;
    // get users transaction history from the database.
    
        // Open the database connection
   { int rc = sqlite3_open("TRANSACTIONS.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    
    // SQL statement to retrieve transaction history
    const char* sql = "SELECT * FROM SendMoney";
    
    // Execute the SQL statement
    rc = sqlite3_exec(db, sql, callback, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }
    
    // Close the database connection
    sqlite3_close(db);
    
    
}
    
    break;
    void showMenu( );
    case 2: cout<<"check balance"<<endl;
    if (option9==2)
cout<<"enter pin"<<endl;
cin>>userpin;
if(userpin>999 && userpin <=9999)
{ 
} else 
{ system("color c");
cout<<"wrong pin try again!"<<endl;
return -1;
    // Login
    for (int attempts = 1; attempts <= MAX_ATTEMPTS; ++attempts)
   {
      
        std::cout << "Please enter your PIN: ";
        std::cin >> userpin;
}}
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }setcolor( 0x0C );
    cout << "\033[4;31m";
cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed your dancom balance was:" ;
setcolor( 0x0C);
cout << "\033[4;31m";
cout<<"ksh"<< balance ;
setcolor( 0x02 );
cout<< " on "<< dt ;
cout<<" The lowest amount you can deposit is:";
setcolor(0x0C); 
cout << "\033[4;31m"; 
cout<<"ksh50";
setcolor(0x02);  
 cout<<" while the highest amount you can deposit is:";
 setcolor(0x0C);  
 cout << "\033[4;31m";   
cout<<"Ksh5000000";
 cout << "\033[0m" << endl;
system("color a");
break;
void showMenu();
case 3:cout<<"Change Pin"<<endl;
if (option9==3)
{ rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return 1;
    }

    // Create the pins table if it doesn't exist
    string createTableSQL = "CREATE TABLE IF NOT EXISTS DANCOM (id INTEGER PRIMARY KEY, pin TEXT);";
    rc = sqlite3_exec(db, createTableSQL.c_str(), callback, nullptr, &kErrMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << kErrMsg << endl;
        sqlite3_free(kErrMsg);
        sqlite3_close(db);
        return 1;
    }

    // Prompt the user for the old and new PIN
    string PIN, newPin;
      
    cout << "Enter your old PIN: ";
    cin >> PIN;
cout<<"Enter the phone number"<<endl;
cin>>phonenumber;
    // Verify the old PIN by checking the database
    string verifyPinSQL = "SELECT PIN FROM DANCOM WHERE PHONE_NUMBER = '" + phonenumber + "';";    
    char** result;
    int numRows, numCols;
    rc = sqlite3_get_table(db, verifyPinSQL.c_str(), &result, &numRows, &numCols, &kErrMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << kErrMsg << endl;
        sqlite3_free(kErrMsg);
        sqlite3_free_table(result);
        sqlite3_close(db);
        return 1;
    }

    if (numRows == 0 || result[numCols] != PIN) {
        cout << "Incorrect PIN. PIN change failed." << endl;
        sqlite3_free_table(result);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_free_table(result);

    cout << "Enter your new PIN: ";
    cin >> newPin;

    // Update the PIN in the database
    string updatePinSQL = "UPDATE DANCOM SET PIN = '" + newPin + "' WHERE  PHONE_NUMBER = '" + phonenumber + "';";    
    rc = sqlite3_exec(db, updatePinSQL.c_str(), callback, nullptr, &kErrMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << kErrMsg << endl;
        sqlite3_free(kErrMsg);
        sqlite3_close(db);
        return 1;
    }

    cout << "PIN changed successfully." << endl;

    sqlite3_close(db);
return 0;
}
break;
void showMenu();
case 4:cout<<"Change Language"<<endl;
if (option9==4)
cout<<"1. English"<<endl;
cout<<"2. Kiswahili"<<endl;
cout<<"Enter option"<<endl;
cin>>option10;
switch (option10)
{
    case 1:cout<<"English"<<endl;
    if (option10==1)
    cout<<"Thankyou for choosing English as your prefered language, changes will take a minute,Thankyou."<<endl;    
void showMenu( );
break;
 case 2: cout<<"Kiswahili"<<endl;
 if (option10==2)
 cout<<"Asante sana kwa kuichagua lugha ya kiswahili kama lugha utakayoitumia,mabadiliko yatatekelezwa hivi punde,Shukran"<<endl;
 // generate a program that converts language
 break;
}
break;
void showMenu();
case 5:cout<<"update customer Menu"<<endl;
if (option9==5)
//generate a program to add updates on the menu
break;
void showMenu();
case 6:cout<<"Customize Phonenumber"<<endl;
if (option9==6)
   { rc = sqlite3_open("DANCOM.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return 1;
    }

    // Create the pins table if it doesn't exist
    string createTableSQL = "CREATE TABLE IF NOT EXISTS DANCOM (id INTEGER PRIMARY KEY, pin TEXT);";
    rc = sqlite3_exec(db, createTableSQL.c_str(), callback, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Prompt the user for the old and new Phone number
    string phonenumber, newPhonenumber;
   cout<<"Enter first name: ";
    cin>> first_name;
    cout<<"Enter second name: ";
    cin>>second_name;
    cout<<"Enter last name: ";
    cin>>last_name;
      cout << "Enter your old Phone number: ";
    cin >> phonenumber;
    

    // Verify the old Phone number by checking the database
    string verifyPinSQL = "SELECT PHONE_NUMBER,FIRST_NAME,SECOND_NAME,LAST_NAME  FROM DANCOM WHERE PHONE_NUMBER = '" +phonenumber + "';";    
    char** result;
    int numRows, numCols;
    rc = sqlite3_get_table(db, verifyPinSQL.c_str(), &result, &numRows, &numCols, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_free_table(result);
        sqlite3_close(db);
        return 1;
    }

    if (numRows == 0 || result[numCols] != phonenumber) {
        cout << "Incorrect Phone number. Phone number change failed." << endl;
        sqlite3_free_table(result);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_free_table(result);

    cout << "Enter your new Phone number: ";
    cin >> newPhonenumber;

    // Update the phone number in the database
    string updatePinSQL = "UPDATE DANCOM SET PHONE_NUMBER = '" + newPhonenumber+ "' WHERE PHONE_NUMBER = '" + phonenumber + "';";    
    rc = sqlite3_exec(db, updatePinSQL.c_str(), callback, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    cout << "Phone number changed successfully." << endl;

    sqlite3_close(db);

    return 0;
}

break;
}
break;
void showMenu( );
case 7: cout<<"Deposit"<<endl;
if(option==7)
{
    int rc = sqlite3_open("TRANSACTIONS.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened transaction database successfully!" << std::endl;
    }

    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS Deposits ("
                                   "id INTEGER PRIMARY KEY AUTOINCREMENT," 
                                   "Agent_number STRING," 
                                   "Amount  INT NOT NULL,"
                                   "Phone_number STRING," 
                                   "Id_passport  INT NOT NULL," 
                                   "Balance REAL," 
                                   "Time TIMESTAMP);";
    rc = sqlite3_exec(db, createTableQuery, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    } else {
        std::cout << "Deposit  Table created successfully!" << std::endl;
    }
std::cout<<"enter agent number"<<endl;
std::cin>>Agentcode;
if (Agentcode .length( )==6)
{
     }else 
{system("color c");
    cout<<"wrong agentnumber, agentnumber should have 6 characters "<<endl;
return -1;
}
 
 cout<<"how much ammount would you like to deposit"<<endl;
cin>>Deposit;
userAccount.deposit(Deposit);
cout<<"Enter your phone number"<<endl;
cin>>phonenumber;
if (phonenumber .length( )==10)
{
     }else 
{system("color c");
    cout<<"number should have 10 characters"<<endl;
return -1;
}
cout<<"Enter your ID number"<<endl;
cin>>ID;
    
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }
    if(Deposit>=50 && Deposit<=5000000)
  { 
   balance+=Deposit;
   // Begin transaction
    rc = sqlite3_exec(db, "BEGIN TRANSACTION;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }

    // Prepare the INSERT statement
    sqlite3_stmt *stmt;
    const char* insertDataQuery = "INSERT INTO Deposits(Agent_number,Amount,Phone_number, Id_passport, Balance, Time) VALUES (?, ?,?,?, ?, CURRENT_TIMESTAMP);";
    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }

    // Bind values to the prepared statement
    sqlite3_bind_text(stmt, 1,Agentcode.c_str(), -1, SQLITE_STATIC);
     sqlite3_bind_int(stmt, 2, Deposit);
   sqlite3_bind_text(stmt, 3,phonenumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, ID);
    sqlite3_bind_double(stmt, 5, balance);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }

    // Finalize and close
    sqlite3_finalize(stmt);

    // Commit transaction
    rc = sqlite3_exec(db, "COMMIT;", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Transaction committed successfully!" << std::endl;
    }

    sqlite3_close(db);
    
    // Open the database connection
    int rc = sqlite3_open("AGENTS.db", &db);
    if (rc) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } 
  setcolor( 0x0C );
  cout << "\033[4;31m";
cout<<rand_array;
setcolor( 0x02 );
cout<<" confirmed you have deposited:";
setcolor( 0x0C );
cout << "\033[4;31m";
  cout<<"ksh"<< Deposit;
  cout << "\033[0m"<<endl;
  setcolor( 0x02 );
  cout<<" to ";
  setcolor(0x0C);
   // SQL statement to retrieve transaction history
    
    string selectQuery = "SELECT FIRSTB_NAME,SECONDB_NAME, LOCATION,SUB_LOCATION FROM AGENTS WHERE Agentcode= '" + Agentcode + "';";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
  setcolor( 0x02 );
cout<<"your new Dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<balance;
setcolor( 0x02);
cout<<" on "<<dt ;
cout<<" Thank you " <<phonenumber<<" for using Dancom";
cout<<" The lowest amount you can deposit is:";
  setcolor(0x0C);  
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor(0x02);  
 cout<<" while The highest amount you can deposit is:";
    setcolor(0x0C);  
    cout << "\033[4;31m";
  cout<<"Ksh5000000";
   cout << "\033[0m" << endl;
    }
else 
{
    system("color c");
    cout<<"failed the lowest amount you can deposit is ksh50"<<endl;
cout<<"The highest amount you can deposit is Ksh5000000"<<endl;
cout<<"Thank you "<<phonenumber<<" for using Dancom"<<endl;
}}
system("color a");
break;
void showMenu( );
case 8: cout<<"LIPA EMPLOYEE"<<endl;
  cout << "Main Menu:" << endl;
        cout << "1. Log in as admin" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choose;

        switch (choose)
         {
            case '1':
                
 if (choose == '1' )                                                                                                
 authenticateAdmin();                                     
 if  (authenticateAdmin() == true )            
   cout<<"1. Employee Registration"<<endl;
cout<<"2. Weekly Wages"<<endl;
cout<<"3. Monthly Wages"<<endl;
cout<<"Enter option"<<endl;
cin>>option11;
switch (option11)
{
    case 1:
    if (option11==1)
    {
int rc;
sqlite3* db;
    // Create a database
    rc = sqlite3_open("Admindatabase.db", &db);
    if (rc) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS DANCOMADMIN("
                                   "Username TEXT PRIMARY KEY NOT NULL,"
                                   "Password TEXT NOT NULL);";
    char* errMsg;
    rc = sqlite3_exec(db, createTableQuery, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK)
     {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }
    else 
    { 
      std::cout<<"Table created successfully"<<endl;        
    }
    
cout<<"Enter user name"<<std::endl;
cin>>username;
cout<<"Enter password"<<std::endl;
cin>>password;
for (char c : password) {
        if (isupper(c)) {
            has_uppercase = true;
        }
        else if (islower(c)) {
            has_lowercase = true;
        }
        else if (isdigit(c)) {
            has_digit = true;
        }
    }

    if (has_uppercase && has_lowercase && has_digit) 
    {
  
      }
    else {setcolor(0x0C);  
        cout << "Password must contain at least:" ;
   setcolor(0x02);      
cout<<" one UPERCASE LETTER ,"; 
setcolor(0x03);      
 cout<<", one lowercase letter ";
 setcolor(0x0C);       
 cout<<"and";
 setcolor(0x06);     
 cout<<" 1 digit." << endl;
 return 0;
   }  
   // Insert username and password into the table
    std::string insertQuery = "INSERT INTO DANCOMADMIN(Username, Password) VALUES ('" + username + "', '" + password + "');";
    rc = sqlite3_exec(db, insertQuery.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting data into table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }
else
{
    std::cout << "Username and password saved successfully." << std::endl;

}
    
{
    cout<<"\n"<<endl;
system("color b");
    std::cout << "WELCOME TO DANCOM FINGERPRINT CENTER !" << std::endl;

    // Generate a new fingerprint
    std::string fingerprint = generateFingerprint();

    // Save the fingerprint as the password
    saveFingerprint(fingerprint);

    std::cout << "Fingerprint is required for employee registration." << std::endl;

    std::cout << "Enter employees fingerprint : ";
    std::string input;
    std::cin >> input;

    // Check the availability of the fingerprint password
    if (checkFingerprint(input))
    {
        std::cout << "Fingerprint accepted!" << std::endl;
    }
    else
    {setcolor(0x0C);
        std::cout << "Fingerprint denied!. Try again." << std::endl;
    }   
}

rc = sqlite3_open("EMPLOYEE.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } else 
    {
        cout << "Opened database successfully" << endl;
    }
/* Create SQL statement */
    string sql = "CREATE TABLE IF NOT EXISTS EMPLOYEE("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
                 "FIRST_NAME           VARCHAR(255)    NOT NULL," \
                 "SECOND_NAME            VARCHAR(255)   NOT NULL," \
                 "LAST_NAME            VARCHAR(255)   NOT NULL," \
                 "DEPARTMENT            VARCHAR(255)   NOT NULL," \
                 "EMPLOYEE_TYPE           VARCHAR(255)   NOT NULL," \
                 "PAY_POINT           VARCHAR(255)   NOT NULL," \
                 "COST_CENTER           VARCHAR(255)   NOT NULL," \
                 "POSITION          VARCHAR(255)   NOT NULL," \
                   "STAFF_BRANCH         VARCHAR(255)   NOT NULL," \
                     "COMPANY_BANK         VARCHAR(255)   NOT NULL," \
                       "EMAIL         VARCHAR(255)   NOT NULL," \
                         "AC_NO         VARCHAR(255)   NOT NULL," \
                           "P_GRADE         VARCHAR(255)   NOT NULL," \
                             "HOURS_DAY         VARCHAR(255)   NOT NULL," \
                               "DAYS_WEEK        VARCHAR(255)   NOT NULL," \
                                 "DAYS_MONTH        VARCHAR(255)   NOT NULL," \
                                   "PAYE_PIN         VARCHAR(255)   NOT NULL," \
                                     "ITAX_EMPLOYEE         VARCHAR(255)   NOT NULL," \
                   "ID_NUMBER  STRING   NOT NULL," \
                 "PHONENUMBER   STRING NOT   NULL       ," \
                   "Registration_time  TIMESTAMP     ," \
                 "Work_Code          STRING  NOT  NULL                );";

    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else 
    {
    cout << "Table created successfully" << endl;
    }
    string employeefirst_name,employeesecond_name,employeelast_name,phonenumber,employeeid_number,employee_no;string position;
setcolor(0x02);
  cout<<"PERMANENT EMPLOYEE REGISTRATION CENTER"<<endl;

 cout << "Enter employee first name: "<<endl;
  cin >> employeefirst_name;

  cout << "Enter employee second name: "<<endl;
  cin >> employeesecond_name;

  cout << "Enter employee last name: "<<endl;
  cin >> employeelast_name;
  
  cout << "Enter Department: "<<endl;
  cin >> department;
  
  cout << "Enter employee type: "<<endl;
  cin >> employeetype;
  
  cout << "Enter pay point: "<<endl;
  cin >> paypoint;
  
  cout << "Enter cost center: "<<endl;
  cin >> costcenter;
  
 cout << "Enter employee position: "<<endl;
  cin >> position;
  
   cout << "Enter employee staff branch: "<<endl;
  cin >> staffbranch;
  
   cout << "Enter employee company bank: "<<endl;
  cin >> companybank;
  
   cout << "Enter employee email: "<<endl;
  cin >> email;
  
   cout << "Enter employee account number: "<<endl;
  cin >> staffacno;
  
   cout << "Enter employee pay grade: "<<endl;
  cin >> paygrade;
  
   cout << "Enter number of working hours a day: "<<endl;
  cin >> hoursday;
  
   cout << "Enter number of working days a week: "<<endl;
  cin >> daysweek;
  
   cout << "Enter nuber of working days a month: "<<endl;
  cin >> daysmonth;
  
   cout << "Enter employees PAYE pin: "<<endl;
  cin >> payepin;
  
   cout << "Enter itax type of employee: "<<endl;
  cin >> itaxemployee;
  
  cout << "Enter employee ID number: "<<endl;
  cin >> employeeid_number;
  
 cout << "Enter employee phone number: "<<endl;
  cin >>phonenumber;
  
  for(int w=0; w<1; w++)
  setcolor( 0x0C );
 cout<<rand( );
setcolor( 0x02);
//sends the employee his/her work code
  cout<<" Is your work code"<<endl;
  std::cout << "Employee information:" ;
  setcolor( 0x0C );
  cout<< first_name ;
  cout<< " " << employeesecond_name << " " << employeelast_name << std::endl;
  setcolor( 0x02 );
  std::cout << "Employee ID number is: " ;
  setcolor( 0x0C );
  cout<< employeeid_number << std::endl;
  cout<<"\n"<<endl;
  setcolor( 0x02);
cout<<"Enter employee work code"<<endl;
cin>>employee_no;
if (employee_no .length( )==10)
{
     } 
     else 
{
    system("color c");
    cout<<"wrong employee work code, work code should be the one generated and send to the employee via Sms,if employee has not received the code,please repeat the procedure. "<<endl;
return -1;
}

     /* Create SQL statement */
    sql = "INSERT INTO EMPLOYEE (FIRST_NAME,SECOND_NAME,LAST_NAME,DEPARTMENT,EMPLOYEE_TYPE,PAY_POINT,COST_CENTER,POSITION,STAFF_BRANCH,COMPANY_BANK,EMAIL,AC_NO,P_GRADE,HOURS_DAY,DAYS_WEEK,DAYS_MONTH,PAYE_PIN,ITAX_EMPLOYEE,ID_NUMBER,PHONENUMBER,Registration_time,Work_Code) "  \
          "VALUES ('"+employeefirst_name+  "', '"  + employeesecond_name + "', '"+ employeelast_name + "','"+ department + "','"+ employeetype + "','"+ paypoint + "','"+ costcenter + "','"+ position+ "', '"+ staffbranch + "','"+ companybank + "','"+ email + "','"+ staffacno + "','"+ paygrade + "','"+ hoursday + "','"+ daysweek + "','"+ daysmonth + "','"+ payepin + "','"+ itaxemployee + "','"+ employeeid_number+   "', '" +phonenumber + "',  '" + ctime(&now) + "',"+ employee_no+ "); ";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ) {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else 
    {
    cout << "Records created successfully" << endl;
    }
    }
    break; 
    void showMenu();
    case 2:cout<<"EMPLOYEES WEEKLY INFORMATION"<<endl;
    if (option11==2)
    {
           {
           rc = sqlite3_open("Casual_labourers.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } else 
    {
        cout << "Opened database successfully" << endl;
    }
    
         /* Create SQL statement */
string sql = "CREATE TABLE IF NOT EXISTS CASUAL("  \
      "id INTEGER  PRIMARY KEY AUTOINCREMENT," \
                 "FIRST_NAME        VARCHAR(255)    NOT NULL," \
                 "SECOND_NAME          VARCHAR(255)   NOT NULL," \
                 "LAST_NAME       VARCHAR(255)   NOT NULL," \
                 "PHONE      VARCHAR(255)   NOT NULL," \
                  "ID_NO    VARCHAR(255)   NOT NULL," \
                 "WORKING_HOURS      VARCHAR(255)  NOT NULL," \
                 "AMOUNT_HOUR        VARCHAR(255)   NOT NULL," \
                 "REPORTING_DAYS         VARCHAR(255)   NOT NULL," \
                 "EXTRA_HOURS         VARCHAR(255)  NOT NULL," \
                 "AC_NUMBER   STRING NOT   NULL       ," \
                 "Registration_time  TIMESTAMP           );";

    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else 
    {
    cout << "Table created successfully" << endl;
    } 
        
 cout << "Enter employee first name: "<<endl;
  cin >> employeefirst_name;

  cout << "Enter employee second name: "<<endl;
  cin >> employeesecond_name;

  cout << "Enter employee last name: "<<endl;
  cin >> employeelast_name;
cout<<"Enter employees phonenumber"<<endl;
cin>>phonenumber;   
if (phonenumber.length( )==10)
{
     }else 
{system("color c");
    cout<<"wrong phone number, phone number should have 10 characters "<<endl;
return -1;
}

cout<<"Enter employees id number"<<endl;
cin>>employeeid_number;       
if (employeeid_number .length( )==8)
{
     }else 
{system("color c");
    cout<<"wrong id number, id number should have 8 characters "<<endl;
return -1;
}
     
cout<<"Enter employees working hours"<<endl;
cin>>hours;
cout<<"enter ammount paid per hour"<<endl;
cin>>ammount_per_hour;
cout<<"Enter number of days the employee reported to work a week"<<endl;
cin>>reporting_days_week;
cout<<"Enter extra hours the employee did a week "<<endl;
cin>>extra_hours;
cout<<"Enter employees A/C number"<<endl;
cin>>staffacno;
if(staffacno.length( )==11)
{
     }else 
{system("color c");
    cout<<"wrong account number, account number should have 11 characters "<<endl;
return -1;
}


/* Create SQL statement */
    sql = "INSERT INTO CASUAL (FIRST_NAME,SECOND_NAME,LAST_NAME,PHONE,ID_NO,WORKING_HOURS,AMOUNT_HOUR,REPORTING_DAYS,EXTRA_HOURS,AC_NUMBER ,Registration_time) "  \
          "VALUES ('"+employeefirst_name+  "', '"  + employeesecond_name + "', '"+ employeelast_name + "','"+ phonenumber +"','"+ employeeid_number  + "','"+ std::to_string(hours)+ "','"+std::to_string(ammount_per_hour)  + "','"+ std::to_string(reporting_days_week) + "', '"+ std::to_string(extra_hours) + "','" + staffacno +"','"+ ctime(&now) + "'); ";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ) {
    cout << "SQL error: " << zErrMsg << endl;
    sqlite3_free(zErrMsg);
    } 
    else 
    {
    cout << "Records created successfully" << endl;
    sqlite3_close(db);
    }}
if (extra_hours==1)
extra_hour_ammount=500;
if (extra_hours==2)
extra_hour_ammount=1000;
if (extra_hours==3)
extra_hour_ammount=1500;
if (extra_hours==4)
extra_hour_ammount=2000;
if (extra_hours==5)
extra_hour_ammount=2500;
if (extra_hours==6)
extra_hour_ammount=3000;
ammount_per_week=((hours*ammount_per_hour*reporting_days_week )+ (extra_hour_ammount));
if (ammount<balance)
{
      rc = sqlite3_open("Casual_labourers.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } else 
    {
        cout << "Opened database successfully" << endl;
    }
cout<<"The ammount to be paid to ";
setcolor( 0x0C );
// SQL statement to retrieve transaction history
    
    string selectQuery = "SELECT FIRST_NAME,SECOND_NAME,LAST_NAME  FROM CASUAL WHERE  id = 1;";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        
        return rc;
    }}
setcolor( 0x02 );
cout<<" this week is :";
setcolor( 0x0C );
cout<<"ksh"<< ammount_per_week;
setcolor( 0x02 );
cout<< " on " << dt <<endl;
cout<<"would you like to pay the employee?"<<endl;
cout<<"1.YES"<<endl;
cout<<"2.NO"<<endl;
cout<<"Enter 1 to proceed or Enter 2 to cancel"<<endl;
cin>>option13;
    switch (option13)
{
    case 1:
if ( balance>ammount_per_week )
{balance-=ammount_per_week;
for (int i = 0; i < len; ++i )
    {
        rand_array[i] = valid[rand() % l];    
    }setcolor( 0x0C );
    cout << "\033[4;31m";
cout<<rand_array;
setcolor( 0x02);
cout<<" confirmed";
setcolor( 0x0C );
cout << "\033[4;31m";
// SQL statement to retrieve transaction history
    
    string selectQuery = "SELECT FIRST_NAME,SECOND_NAME,LAST_NAME  FROM CASUAL WHERE  id = 1;";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        
        return rc;
    }
setcolor( 0x02);
cout<<" has been paid a weekly salary of:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"ksh"<<ammount_per_week;
setcolor( 0x02 );
cout<<" on "<< dt<<endl;
cout<<"your new dancom balance is:";
setcolor( 0x0C );
cout << "\033[4;31m";
cout<<"Ksh"<<balance<<endl;
cout << "\033[0m"<<endl;
setcolor( 0x02);
cout<<"The lowest amount you can deposit is:";
  setcolor(0x0C);  
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor(0x02);  
 cout<<" while The highest amount you can deposit is:";
    setcolor(0x0C);  
    cout << "\033[4;31m";
  cout<<"Ksh5000000"<<endl;
   cout << "\033[0m" << endl;
} 
else
{system("color c");
cout<<"insuficient ammount to pay employee"<<endl;
cout<<"DANCOM outstanding balance is Ksh:"<<balance<< " on "<< dt <<endl;
}
break;
void showMenu();
case 2:
if(option13==2)
{
    cout<<"You have succesfully canceled the payment  "<<endl;
 return 0;
}
break;
void showMenu();
}
 break;
void showMenu(); 
case 3:
cout<<"1.Employees Monthly information"<<endl;  
if (option11==3)
 {
rc = sqlite3_open("EMPLOYEE.db", &db);

    if( rc ) {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return(0);
    } else 
    {
        cout << "Opened database successfully" << endl;
    }
    cout<<"Confirmed  ";
    setcolor( 0x0C );
      
// SQL statement to retrieve transaction history
    
    string selectQuery = "SELECT FIRST_NAME,SECOND_NAME,LAST_NAME  FROM EMPLOYEE WHERE  id = 1;";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        
        return rc;
    }
setcolor( 0x02 );
cout<<" has been paid a monthly salary of ksh";
 setcolor( 0x0C );
      
// SQL statement to retrieve transaction history
    
     selectQuery = "SELECT  P_GRADE FROM EMPLOYEE WHERE  id=1;";
    rc = sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, &errMsg);
    if (ammount<balance)
    { 
    
    }
    else 
{
    cout<<"insufficient funds in your Dancom account"<<endl;
}
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return rc;
    }
setcolor( 0x02 );
cout<<"New Dancom balance is Ksh:";
setcolor( 0x0C );
cout<<balance<<endl;
setcolor( 0x02 );
cout<<"The lowest amount you can deposit is:";
  setcolor( 0x0C );
  cout << "\033[4;31m";
  cout<<"ksh50";
  setcolor( 0x02);
   cout<<" while the highest amount you can deposit is:";
    setcolor(0x0C);
    cout << "\033[4;31m";
    cout<<" Ksh5000000"<<endl;
     cout << "\033[0m" << endl;
}
else 
{ system("color c");
cout<<"insufficient amount in your Dancom account"<<endl;
}
   }  
break;
}
 break;
            case '2':
                cout << "Thankyou for using Dancom!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;        
   } 
}}while (option!=9);
system("pause>0");
};

