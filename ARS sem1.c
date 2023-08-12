#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


struct Flights{
	char FlightNo[10];
	char FlightName[20];
	char From[20];
	char Destination[20];
	char Departure[10];
	char Arrival[10];
	char Price[10];
};
struct Flights F[50];

struct Passenger{
	int PassengerID;
	char Name[50];
	int Seats;	
};
struct Passenger P[200];

void filereadFlights()
{
	char *token;
	FILE *fptr = NULL;
	fptr = fopen("Flights.txt", "r");
	char buffer [400];
	int i = 0;
	
	if (fptr == NULL)
	{
		printf("Error \n");
	}
	rewind(fptr);
	while(fgets(buffer, 400, fptr) != NULL)
	{
		
		token = strtok(buffer, ",");
		strcpy(F[i].FlightNo, token);
		token = strtok(NULL, ",");
		strcpy(F[i].FlightName, token);
		token = strtok(NULL, ",");
		strcpy(F[i].From, token);
		token = strtok(NULL, ",");
		strcpy(F[i].Destination, token);
		token = strtok(NULL, ",");
		strcpy(F[i].Arrival, token);
		token = strtok(NULL, ",");
		strcpy(F[i].Departure, token);
		token = strtok(NULL, ",");
		strcpy(F[i].Price, token);
		
		++i;
	}
	fclose(fptr);
	fptr = NULL;
}

int FlightNoSearch(char num[10]){
	int k, res;
	filereadFlights();
	
	for (k =0; k < 50; k++){
		res = strcmp(num,F[k].FlightNo);
		if(res == 0){
			return k;
		}
	}
	return -1;
}

void filewriteFlights(){
	int j;
	
	FILE *fptr;
		fptr = fopen("Flights.txt","w");
		if (fptr == NULL){
			printf("File cannot be opened!");
		}
	rewind(fptr);
	for(j = 0; j < 50; j++){
		if(F[j].FlightNo != NULL){
			fprintf(fptr,"%s,%s,%s,%s,%s,%s,%s\n", F[j].FlightNo, F[j].FlightName, F[j].From, F[j].Destination, F[j].Departure, F[j].Arrival, F[j].Price);
		}
		else if(F[j].FlightNo == NULL){
			break;
		}
	}
	fclose(fptr);
}

void AddFlight(){
	char choice = 'y';
	int j = 0;
	
	filereadFlights();
	while (choice =='y' || choice == 'Y'){
		system("cls");
		fflush(stdin);
		printf("\n\nEnter Flight No# : ");
		gets(F[j].FlightNo);
		printf("Enter Flight Name: ");
		gets(F[j].FlightName);
		printf("Enter Departure Location: ");
		gets(F[j].From);
		printf("Enter Destination: ");
		gets(F[j].Destination);
		printf("Enter Departure Time: ");
		gets(F[j].Departure);
		printf("Enter Arrival Time: ");
		gets(F[j].Arrival);
		printf("Enter Seat Price: ");
		gets(F[j].Price);
		fflush(stdin);
		
		printf("Do you want to add another Flight? (y/n): ");
		choice = getche();
		j++;
	}
	filewriteFlights();
}

void EditFlight(){
	char choice = 'y';
	char num[10];
	int f;

	filereadFlights();
	while (choice =='y'){
		system("cls");
		fflush(stdin);
		printf("Enter Flight No: ");
		gets(num);
		
		f = FlightNoSearch(num);
		if (f==-1){
			printf("No Flight exists for with No: %s",num);
		}
		else{
			printf("Flight No#: %s\nFlight Name: %s\nDeparture Location: %s\nDestination: %s\nDeparture Time: %s\nArrival Time: %s\nSeat Price %s\n",F[f].FlightNo, F[f].FlightName, F[f].From, F[f].Destination, F[f].Departure, F[f].Arrival, F[f].Price);
			fflush(stdin);
			printf("\n\nEnter Flight No# : ");
			gets(F[f].FlightNo);
			printf("Enter Flight Name: ");
			gets(F[f].FlightName);	
			printf("Enter Departure Location: ");
			gets(F[f].From);
			printf("Enter Destination: ");
			gets(F[f].Destination);
			printf("Enter Departure Time: ");
			gets(F[f].Departure);
			printf("Enter Arrival Time: ");
			gets(F[f].Arrival);
			printf("Enter Seat Price: ");
			gets(F[f].Price);
			fflush(stdin);
			//fprintf(fptr,"%s,%s,%s,%s,%s,%s,%s\n", F[f].FlightNo, F[f].FlightName, F[f].From, F[f].Destination, F[f].Departure, F[f].Arrival, F[f].Price);
			// file write function	
			printf("Do you want to edit another Flight? (y/n): ");
			choice = getche();
		}
	}
	filewriteFlights();
}

/*void DeleteFlight(){
1- take input of the Column ID you want to Delete 
2- run a loop from that input to the end of structure using a temp to replace those values with the next one
so that the array remains intact and can be properly used.
}*/

int ArrivalDeparture(){
	char id[10], choice = 'y';
	int f;
//	int flag=0, result, i=0;
	
//	FILE *fptr;
//		fptr = fopen("Flights.txt","r");
//		if (fptr == NULL){
//			printf("File cannot be opened!");
//		}
	while (choice == 'y'){
		system("cls");
		printf("\nEnter Flight No.");
		scanf("%s",id);
		
		f = FlightNoSearch(id);
		if (f == -1){
			printf("No Flight exists for with No: %s",id);
			return 0;
		}
		else{
			printf("Enter Departure Time: ");
			gets(F[f].Departure);
			printf("Enter Arrival Time: ");
			gets(F[f].Arrival);
		
			printf("Do you want to edit another Flight? (y/n): ");
			choice = getche();
		}
	}
	
//	while (fread(&F,sizeof(F),1,fptr)>0 && flag==0){
//		result = strcmp(F[i].FlightNo,temp);
//		
//		if (result == 0){
//			flag=1;
//			printf("Record is found");
//			printf("%s \t %s \t %s",F[i].Arrival,F[i].Departure,F[i].Price);
//		}
//	}
//	fclose(fptr);
	return 0;
}

int FlightDetails(){
	int choice, temp;
	int pin = 9078;
	
	system("cls");
	
	printf("Enter Pin Code for Authorization: ");
	scanf("%d",&temp);
	
	system("cls");
	
	if (temp != pin){
		printf("\nYou are not Authorized to change Flight Details.");
		return 0;
	}
	while (choice != 5){
			
		printf("*****************************************************************");
		printf("*****************************************************************\n\t\t\tWelcome To the Airline Rservation Program\n*****************************************************************");
		printf("*****************************************************************\n");
		printf("\n\n1. Add New Flight\n2. Edit Flight Record\n3. Delete Flight\n4. Flight Arrival and Departure\n5. Back to Main Menu\nYour Choice: ");
		scanf("%d",&choice);		
		switch(choice){
			case 1:
				AddFlight();
				break;
			case 2:
				EditFlight();
				break;
//			case 3:
//				DeleteFlight();
//				break;
			case 4:
				ArrivalDeparture();
				break;
			case 5:
				return 0;
		}
	}
	
	return 0;
}

/*void ReserveSeat(){
1- same as AddFlight()
2- make new folder
3- Comma separated file(new function filereadPassenger())
4- take inputs, store and then add to file.
}*/

void FlightSchedule(){
	char id[10];
	char choice = 'y';
	int f;
		
	filereadFlights();
	
	while(choice == 'y'){
		system("cls");
		
		printf("Enter Flight No: ");
		gets(id);
		
		f = FlightNoSearch(id);
		printf("FlightNo: %s\nFlight Name: %s\nFlight Departure location: %s\nFlight Destination: %s\nFlight Departure: %s\nFlight Arrival: %s\nSeat Price : Rs%s", F[f].FlightNo, F[f].FlightName, F[f].From, F[f].Destination, F[f].Departure, F[f].Arrival, F[f].Price);
		
		printf("Do you want to check another Flight Schedule? (y/n): ");
		choice = getche();
	}
	
	
}

/*void PassengerRecords(){
	call filereadPassenger()
	take passenger ID as input and compare with array
	display every match.
}*/

int main(){
	int choice = 0;
	
	while(choice != 5){
		system("cls");
		printf("*****************************************************************");
		printf("*****************************************************************\n\t\t\tWelcome To the Airline Rservation Program\n*****************************************************************");
		printf("*****************************************************************\n");
		printf("\n1. Reserve Seat\n2. Flights Schedule\n3. Passenger Records\n4. Flight Details\n5. Quit\nYour Choice: ");
		scanf("%d",&choice);
		
		switch(choice){
//			case 1:
//				ReserveSeat();
//				break;
			case 2:
				FlightSchedule();
				break;
//			case 3:
//				PassengerRecords();
//				break;
			case 4:
				FlightDetails();
				break;
			case 5:
				exit(1);
		}
		printf("\n\n");
	}
	exit(1);
}