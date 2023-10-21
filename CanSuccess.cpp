#include <string>
#include<iostream>
#include "CancelSuccess.h"

using namespace std;

void CancelSuccess(std::string user, std::string role)
{	
	char filename[] = "C:/OOSD_Project/Database/travel_permit_application.txt";
	
	/*	Deletes the file if exists */
	if (remove(filename) != 0)
		perror("File deletion failed");
	else
		cout << "File deleted successfully";
		
	char tempfile[] = "C:/OOSD_Project/Databasetemp.txt";
	
	
	if (rename(tempfile, filename) != 0)
	{
		cout << "Error";
	}
	else
	{
		cout << "Success rename";
	}
		
	cout << "*************************************************************************************************\n";
}
