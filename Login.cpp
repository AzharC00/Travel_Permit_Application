/********************************************************
*	TME2413(G01) OBJECT ORIENTED SOFTWARE DEVELOPEMENT  *
*	GROUP PROJECT (40%)                      			*
*********************************************************/

#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include "CancelSuccess.h"

using namespace std;
void login();
void registr();
void User(string user, string role);
void Traveler(string user, string role);
void AirportOfficer(string user, string role);
void JettyCheckPointOfficer(string user, string role);
void PoliceStationOfficer(string user, string role);
void DisasterControlOfficer(string user, string role);
void TravelPermitApplication(string user, string role);
void Covid19SelfAssessment(string user, string role, int application_id);
void Cancellation(string user, string role);
void ConCancel(string user, string role);
void CancelSuccess(string user, string role);
void Notification(string user, string role);
void Logout();
void ViewPermitApplication();
void approve_application();
void reject_application();
void back();

main()
{
	int choice;
	cout<<"*********** INTERSTATE TRAVEL PERMIT APPLICATION SYSTEM **********\n";
	cout<<"1.Login\n";
	cout<<"2.Register\n";
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			login();
			break;
		}
		case 2:
		{
			registr();
			break;
		}
		default:
		{
			cout<<"Sorry, wrong choice selected\n";
			main();
		}
	}
}

void registr()
{
	
/************************************************************************
*	NAME:				ALBERT ANAK ALIAM  								*
*	MATRICES NUMBER:   	72080											*
*	PURPOSE:			New user (Traveler only) can register account   *
*************************************************************************/

	string name, identity_card_number, telephone_number, home_address, office_address, email_address, username, password;
	string role = "Traveler";
	
	system("cls");
	cout<<"*********** REGISTER **********\n";
	
	cin.ignore();
	cout<<"Please keyin your name: ";
	getline(cin,name);
//	std::replace(name.begin(), name.end(), ' ', '_');
	
	cin.ignore();
	cout<<"Please keyin your identity card number:\t";
	getline(cin,identity_card_number);
	
	cin.ignore();
	cout<<"Please keyin your telephone number:\t";
	getline(cin,telephone_number);
	
	cin.ignore();
	cout<<"Please keyin your home address:\t";
	getline(cin,home_address);
	
	cin.ignore();
	cout<<"Please keyin your office address:\t";
	getline(cin,office_address);
	
	cin.ignore();
	cout<<"Please keyin your email address:\t";
	getline(cin,email_address);
	
	cin.ignore();
	cout<<"Please keyin your username:\t";
	getline(cin,username);
	
	cin.ignore();
	cout<<"Please keyin your password:\t";
	getline(cin,password);
	
	ofstream reg("Database/register_user_list.txt", ios::app);
	reg<<name<<' '<<identity_card_number<<' '<<telephone_number<<' '<<home_address<<' '<<office_address<<' '<<email_address<<' '<<username<<' '<<password<<endl;
	
	ofstream exist("Database/exist_user_list.txt", ios::app);
	exist<<name<<' '<<password<<' '<<' '<<role<<endl;
	
	cout<<"*********** Register Successfully ***********";
	
	system("cls");
	main();
}

void login()
{
/************************************************************************
*	NAME:				NGIAM JOHN TZE  								*
*	MATRICES NUMBER:   	72815											*
*	PURPOSE:			Exist user (Traveler, Disaster Control Officer,	*
*						Airport Officer, Jetty Officer, Police Officer)	*
*						can login.   									*
*************************************************************************/
	int authenticate_user = 0;
	string user,pass,u,p,role;
	system("cls");
	cout<<" *********** LOGIN **********\n";
	cout<<"Enter the username :";
	cin>>user;
	cout<<"Enter the password :";
	cin>>pass;
	
	ifstream input("Database/exist_user_list.txt");
	
	while(input>>u>>p>>role)
	{
		if(u == user && p == pass)
		{
				system("cls");
				cout<<"Log In Success!!!";
				cout<<"Hello "<<user<<".\nWe're glad that you're here\n";
				cout<<"Press any button continue...";
				cin.get();
				cin.get();
				
				User(u,role);
		}
	}
	input.close();
	
}

void User(string user, string role)
{	
/************************************************************************
*	ACTOR:				NGIAM JOHN TZE  								*
*	MATRICES NUMBER:   	72815											*
*	PURPOSE:			User class work as parent, which mean Traveler,	*
*						Disaster Control Officer, Airport Officer,		*
*						Jetty Officer, Police Officer classes will		*
*						reused attribute and method from User class		*
*************************************************************************/
	if (role == "Traveler")
	{
		Traveler(user, role);
	}
	else if (role == "AirportOfficer")
	{
		AirportOfficer(user, role);
	}
	else if (role == "JettyCheckPointOfficer")
	{
		JettyCheckPointOfficer(user, role);
	}
	else if (role == "PoliceStationOfficer")
	{
		PoliceStationOfficer(user, role);
	}
	else if (role == "DisasterControlOfficer")
	{
		DisasterControlOfficer(user, role);
	}
	else
	{
		cout<<"Error: No role get";
		main();
	}
	
}

void Traveler(string user, string role)
{
/********************************************
*	ACTOR:				NGIAM JOHN TZE  	*
*	MATRICES NUMBER:   	72815				*
*	PURPOSE:			Traveler Class		*
*********************************************/
	int choice;
	system("cls");
	cout<<"*********** TRAVELER **********\n";
	cout<<"1.Apply New Permit\n";
	cout<<"2.Cancel Applied Permit\n";
	cout<<"3.New Notification\n";
	cout<<"4.Logout\n";
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			TravelPermitApplication(user, role);
			break;
		}
		case 2:
		{
			Cancellation(user, role);
			break;
		}
		case 3:
		{
			Notification(user, role);
			break;
		}
		case 4:
		{
			Logout();
			break;
		}
		default:
		{
			cout<<"Sorry, wrong choice selected\n";
			Traveler(user, role);
		}
	}
}

void AirportOfficer(string user, string role)
{
/********************************************
*	ACTOR:				NGIAM JOHN TZE  	*
*	MATRICES NUMBER:   	72815				*
*	PURPOSE:			AirportOfficer Class*
*********************************************/
	int choice;
	system("cls");
	cout<<"*********** AIRPORT OFFICER **********\n";
	cout<<"1.New Notification\n";
	cout<<"2.Logout\n";
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			Notification(user, role);
			break;
		}
		case 2:
		{
			Logout();
			break;
		}
		default:
		{
			cout<<"Sorry, wrong choice selected\n";
			AirportOfficer(user, role);
		}
	}
}

void JettyCheckPointOfficer(string user, string role)
{
/************************************************************
*	ACTOR:				NGIAM JOHN TZE  					*
*	MATRICES NUMBER:   	72815								*
*	PURPOSE:			JettyCheckPointOfficer Class		*
*************************************************************/
	int choice;
	system("cls");
	cout<<"*********** JETTY CHECK POINT OFFICER **********\n";
	cout<<"1.New Notification\n";
	cout<<"2.Logout\n";
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			Notification(user, role);
			break;
		}
		case 2:
		{
			Logout();
			break;
		}
		default:
		{
			cout<<"Sorry, wrong choice selected\n";
			Traveler(user, role);
		}
	}
}

void PoliceStationOfficer(string user, string role)
{
/********************************************************
*	ACTOR:				NGIAM JOHN TZE  				*
*	MATRICES NUMBER:   	72815							*
*	PURPOSE:			PoliceStationOfficer Class		*
*********************************************************/
	int choice;
	system("cls");
	cout<<"*********** POLICE STATION OFFICER **********\n";
	cout<<"1.New Notification\n";
	cout<<"2.Logout\n";
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			Notification(user, role);
			break;
		}
		case 2:
		{
			Logout();
			break;
		}
		default:
		{
			cout<<"Sorry, wrong choice selected\n";
			Traveler(user, role);
		}
	}
}

void DisasterControlOfficer(string user, string role)
{
/************************************************************
*	ACTOR:				NGIAM JOHN TZE  					*
*	MATRICES NUMBER:   	72815								*
*	PURPOSE:			DisasterControlOfficer Class		*
*************************************************************/
	int choice;
	system("cls");
	cout<<"*********** DISASTER CONTROL OFFICER **********\n";
	cout<<"1.View Permit Application\n";
	cout<<"2.Logout\n";
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			ViewPermitApplication();
			break;
		}
		case 2:
		{
			Logout();
			break;
		}
		default:
		{
			cout<<"Sorry, wrong choice selected\n";
			Traveler(user, role);
		}
	}
}

void TravelPermitApplication(string user, string role)
{
/************************************************************
*	ACTOR:				NUR FATIN FAREEDA BINTI ROSLAN  	*
*	MATRICES NUMBER:   	57228								*
*	PURPOSE:			Use to apply new travel permit		*
*						application and save to a file.		*
*************************************************************/
	string travel_purpose, start_destination, end_destination, transportation_mode, date_of_travel, travel_history, covid19_test_result;
	string application_status = "PENDING";
	
	srand((unsigned) time(0));
	int application_id = rand();
	
	system("cls");
	
	cout<<"*********** TRAVEL PERMIT APPLICATION **********\n";
	cout<<"Please enter your,";
	
	cout<<"Travel purpose:\t";
	cin>>travel_purpose;
	
	cout<<"Start destination:\t";
	cin>>start_destination;
	
	cout<<"End destination:\t";
	cin>>end_destination;
	
	cout<<"Transportation mode:\t";
	cin>>transportation_mode;
	
	cout<<"Date of travel:\t";
	cin>>date_of_travel;
	
	cout<<"Travel History:\t";
	cin>>travel_history;
	
	cout<<"Covid19 Test Result(Positive/Negative):\t";
	cin>>covid19_test_result;
	
	ofstream permit("Database/travel_permit_application.txt", ios::app);
	
		if (!permit.is_open())
	{
		cout << "Error: Could not open/find the file.";
	}
	
	permit<<application_id<<user<<' '<<travel_purpose<<' '<<start_destination<<' '<<end_destination<<' '<<transportation_mode<<' '<<date_of_travel<<' '<<travel_history<<' '<<covid19_test_result<<' '<<application_status<<' '<<role<<endl;
	system("cls");
	cout<<"Travel Permit Application Success Apply";	
	Covid19SelfAssessment(user, role, application_id);
}

void Covid19SelfAssessment(string user, string role, int application_id)
{
/************************************************************
*	ACTOR:				NGIAM JOHN TZE					  	*
*	MATRICES NUMBER:   	72815								*
*	PURPOSE:			After apply new permit, must keyin	* 
*						user's covid19 self assessment.		*
*************************************************************/
	string self_assessment_answer_1, self_assessment_answer_2, self_assessment_answer_3;
	system("cls");
	cout << "*********** COVID-19 SELF-ASSESSMENT **********\n";
	cout << "1. Is the applicant experiencing any of the following:\n";
	cout << "- severe difficulty breathing (e.g., struggling for each breath, speaking in single words),\n";
	cout << "- severe chest pain,\n";
	cout << "- having a very hard time waking up,\n"; 
	cout << "- feeling confused,\n";
	cout << "- lost consciousness,\n";
	cout << "- shortness of breath at rest,\n";
	cout << "- inability to lie down because of difficulty breathing,\n";
	cout << "- chronic health conditions that you are having difficulty managing because of your current respiratory illness,\n";
	cout << "- fever,\n";
	cout << "- new onset of cough or worsening of chronic cough,\n";
	cout << "- new or worsening shortness of breath,\n";
	cout << "- new or worsening difficulty breathing,\n";
	cout << "- sore throat,\n";
	cout << "- runny nose,\n";
	cout << "- chills,\n";
	cout << "- painful swallowing,\n";
	cout << "- stuffy nose,\n";
	cout << "- headache,\n";
	cout << "- muscle or joint ache,\n";
	cout << "- feeling unwell,\n";
	cout << "- fatigue or severe exhaustion,\n";
	cout << "- nausea,\n";
	cout << "- vomiting,\n";
	cout << "- diarrhea or unexplained loss of appetite,\n";
	cout << "- loss of sense of smell or taste,\n";
	cout << "- conjunctivitis (pink eye)\n";
	cout << "Yes or No? If yes please specify.\n";
	cin >> self_assessment_answer_1;
	cout << "2. Have you been in close contact with a confirmed case of COVID-19?\n";
	cout << "Yes or No? If yes please specify.\n";
	cin >> self_assessment_answer_2;
	cout << "3. The past 14 days, did you return from travel to red zone/high risk areas?\n";
	cout << "Yes or No? If yes please specify.\n";
	cin >> self_assessment_answer_3;
	
	//open covid_19_self_assessment.txt for save self assessment report
	ofstream assessment("Database/covid_19_self_assessment.txt", ios::app);
	
	//check the covid_19_self_assessment.txt is exist
	if (!assessment.is_open())
	{
		cout << "Error: Could not open/find the file.";
//		Traveler(user, role);
	}
	
	//save the self assessment report
	assessment << application_id << ' ' << self_assessment_answer_1 << ' ' << self_assessment_answer_2 << ' ' << self_assessment_answer_3 << endl;
	system("cls");
	cout << "Your self-assessment success recorded.\n";
	assessment.close();
	
	Traveler(user, role);	
}

void Cancellation(string user, string role)
{
/************************************************************
*	ACTOR:				MATHIAS SAM ANAK FRANCIS		 	*
*	MATRICES NUMBER:   	70337								*
*	PURPOSE:			User can use to cancel the 			*
*						application.						*
*************************************************************/
	string application_id, travel_purpose, start_destination, end_destination, transportation_mode, date_of_travel, travel_history, covid19_test_result, application_status, u,r;
	system("cls");
	ifstream cancellation("C:/OOSD_Project/Database/travel_permit_application.txt");
	
	cout << "******************************************* CANCELLATION ****************************************\n";
	
	while(cancellation>>application_id>>u>>travel_purpose>>start_destination>>end_destination>>transportation_mode>>date_of_travel>>travel_history>>covid19_test_result>>application_status>>r)
	{
		if (user == u)
		{
			if (application_status == "PENDING")
			{
				cout << "|\t" << application_id << "\t|\t" << travel_purpose << "\t|\t" << start_destination << "\t|\t" << end_destination <<endl;
			}
			else
			{
				cout << "No older application.";
			}
		}
	}
	ConCancel(user, role);
}

void ConCancel(string user, string role)
{
	string cancel, application_id, travel_purpose, start_destination, end_destination, transportation_mode, date_of_travel, travel_history, covid19_test_result, application_status, u,r;
	system("cls");
	ifstream cancellation("C:/OOSD_Project/Database/travel_permit_application.txt");
	
	ofstream temp("C:/OOSD_Project/Database/temp.txt");
	
	cout << "Which you want cancel?" << endl;
	cin >> cancel;

	while(cancellation>>application_id>>u>>travel_purpose>>start_destination>>end_destination>>transportation_mode>>date_of_travel>>travel_history>>covid19_test_result>>application_status>>r)
	{
		if(cancel.compare(start_destination))
		{
			temp << application_id<<' '<<u<<' '<<travel_purpose<<' '<<start_destination<<' '<<end_destination<<' '<<transportation_mode<<' '<<date_of_travel<<' '<<travel_history<<' '<<covid19_test_result<<' '<<application_status<<endl;
		}
		else
		{
			application_status = "CANCEL";
			temp << application_id<<' '<<u<<' '<<travel_purpose<<' '<<start_destination<<' '<<end_destination<<' '<<transportation_mode<<' '<<date_of_travel<<' '<<travel_history<<' '<<covid19_test_result<<' '<<application_status<<endl;
			cout << "Cancel Successfully!";
			application_status = "";
		}
	}
	CancelSuccess(user, role);
}

void Logout()
{
	system("cls");
	main();
}

void Notification(string user, string role)
{
/****************************************************************
*	ACTOR:				NGIAM JOHN TZE						 	*
*	MATRICES NUMBER:   	72815									*
*	PURPOSE:			User (Traveler, Disaster Control 		*
*						Officer, Airport Officer, Jetty 		*
*						Officer, Police Officer) will received	*
*						notification.							*
*****************************************************************/
	string application_id, travel_purpose, start_destination, end_destination, transportation_mode, date_of_travel, travel_history, covid19_test_result, application_status, u,r;
	system("cls");
	ifstream notification_message("Database/travel_permit_application.txt");
	
	cout << "***************************************** NOTIFICATION **************************************\n";
	
	while(notification_message>>application_id>>u>>travel_purpose>>start_destination>>end_destination>>transportation_mode>>date_of_travel>>travel_history>>covid19_test_result>>application_status>>r)
	{
		if (user == u && role == r)
		{
			if (application_status == "PENDING")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Your travel application "<< application_id << " is pending." << "\t|" << endl;
			}
			else if (application_status == "APPROVED")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Your travel application "<< application_id << " is approved." << "\t|" << endl;
			}
			else if (application_status == "REJECTED")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Your travel application "<< application_id << " is rejected." << "\t|" << endl;
			}
			else if (application_status == "CANCEL")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Your travel application "<< application_id << " is cancelled." << "\t|" << endl;
			}
		}
		else if (role == "AirportOfficer")
		{
			if(application_status == "APPROVED")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Travel application "<< application_id << " is approved." << "\t|" << endl;
			}
			else if (application_status == "REJECTED")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Travel application "<< application_id << " is rejected." << "\t|" << endl;
			}
			else if (application_status == "CANCEL")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Travel application "<< application_id << " is cancelled." << "\t|" << endl;
			}
		}
		else if (role == "JettyCheckPointOfficer")
		{
			if(application_status == "APPROVED")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Travel application "<< application_id << " is approved." << "\t|" << endl;
			}
			else if (application_status == "REJECTED")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Travel application "<< application_id << " is rejected." << "\t|" << endl;
			}
			else if (application_status == "CANCEL")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Travel application "<< application_id << " is cancelled." << "\t|" << endl;
			}
		}
		else if (role == "PoliceStationOfficer")
		{
			if(application_status == "APPROVED")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Travel application "<< application_id << " is approved." << "\t|" << endl;
			}
			else if (application_status == "REJECTED")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Travel application "<< application_id << " is rejected." << "\t|" << endl;
			}
			else if (application_status == "CANCEL")
			{
				cout << "|\t" << u << "\t|\t" << r << "\t|\t" << "Travel application "<< application_id << " is cancelled." << "\t|" << endl;
			}
		}
	}
	
	cout << "*********************************************************************************************\n";
	cout<<"Press any button continue...";
	cin.get();
	cin.get();
	User(user,role);
}

void ViewPermitApplication()
{
/****************************************************************
*	ACTOR:				AZHAR CHONG							 	*
*	MATRICES NUMBER:   	69186									*
*	PURPOSE:			Disaster control officer will evaluate 	*
*						the application from here, and either 	*
*						approve or reject the application.		*
*****************************************************************/
	int choice;
	string application_id, u, travel_purpose, start_destination, end_destination, transportation_mode, date_of_travel, travel_history, covid19_test_result, self_assessment_answer_1, application_status, r;
	system("cls");
	ifstream permit("C:/OOSD_Project/Database/travel_permit_application.txt");
	
	cout << "******************************************* TRAVELER PERMIT APPLICATION ****************************************\n";
	
	while(permit>>application_id>>u>>travel_purpose>>start_destination>>end_destination>>transportation_mode>>date_of_travel>>travel_history>>covid19_test_result>>application_status>>r)
	{
		if(application_status == "PENDING")
		{
			cout << "Application ID: " << application_id << endl;
			cout << "Travel Purpose :" << travel_purpose << endl;
			cout << "Start Destination :" << start_destination << endl;
			cout << "End Destination :" << end_destination << endl;
			cout << "Transportation Mode :" << transportation_mode << endl;
			cout << "Date of Travel :" << date_of_travel << endl;
			cout << "Travel History :" << travel_history << endl;
			cout << "Covid19 Test Result :" << covid19_test_result << endl << endl;
		}
	}
	
	cout<<"1.Approve Application\n";
	cout<<"2.Reject Application\n";
	cout<<"3.Logout\n";
	cout<<"Enter your choice: ";
	cin >> choice;
	switch(choice)
	{
		case 1:
		{
			approve_application();
			break;
		}
		case 2:
		{
			reject_application();
			break;
		}
		case 3:
		{
			Logout();
			break;
		}
		default:
		{
			cout<<"Sorry, wrong choice selected\n";
			main();
		}
	}
}

void approve_application()
{
	string approve, application_id, user, travel_purpose, start_destination, end_destination, transportation_mode, date_of_travel, travel_history, covid19_test_result, application_status;
	
	cout << "Keyin Application ID to approve: ";
	cin >> approve;
	
	ifstream approval("C:/OOSD_Project/Database/travel_permit_application.txt");
	
	ofstream temp("C:/OOSD_Project/Database/temp.txt");
	
	while(approval>>application_id>>user>>travel_purpose>>start_destination>>end_destination>>transportation_mode>>date_of_travel>>travel_history>>covid19_test_result>>application_status)
	{
		if(approve.compare(application_id))
		{
			temp<<application_id<<user<<travel_purpose<<start_destination<<end_destination<<transportation_mode<<date_of_travel<<travel_history<<covid19_test_result<<application_status;
		}
		else
		{
			application_status = "APPROVED";
			temp<<application_id<<' '<<user<<' '<<travel_purpose<<' '<<start_destination<<' '<<end_destination<<' '<<transportation_mode<<' '<<date_of_travel<<' '<<travel_history<<' '<<covid19_test_result<<' '<<application_status;
			application_status = "";
			cout << "Application ID: " << approve << "has approved.";
		}
	}
	approval.close();
	temp.close();
	
	remove("C:/OOSD_Project/Database/travel_permit_application.txt");
	rename("C:/OOSD_Project/Database/temp.txt","travel_permit_application.txt");
}

void reject_application()
{
	string reject, application_id, user, travel_purpose, start_destination, end_destination, transportation_mode, date_of_travel, travel_history, covid19_test_result, application_status;
	
	cout << "Keyin Application ID to reject: ";
	cin >> reject;
	
	ifstream rejects("C:/OOSD_Project/Database/travel_permit_application.txt");
	
	ofstream temp("C:/OOSD_Project/Database/temp.txt");
	
	while(rejects>>application_id>>user>>travel_purpose>>start_destination>>end_destination>>transportation_mode>>date_of_travel>>travel_history>>covid19_test_result>>application_status)
	{
		if(reject.compare(application_id))
		{
			temp<<application_id<<user<<travel_purpose<<start_destination<<end_destination<<transportation_mode<<date_of_travel<<travel_history<<covid19_test_result<<application_status;
		}
		else
		{
			application_status = "REJECTED";
			temp<<application_id<<' '<<user<<' '<<travel_purpose<<' '<<start_destination<<' '<<end_destination<<' '<<transportation_mode<<' '<<date_of_travel<<' '<<travel_history<<' '<<covid19_test_result<<' '<<application_status;
			application_status = "";
			cout << "Application ID: " << reject << "has rejected.";
		}
	}
	rejects.close();
	temp.close();
	
	remove("C:/OOSD_Project/Database/travel_permit_application.txt");
	rename("C:/OOSD_Project/Database/temp.txt","travel_permit_application.txt");
}
