#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	
	
	int menuOption;
	string movieTitle[100];
	string movieGenre[100];
	
	int movieYear[100];
	int movieNumber[100];
	
	int n = 0;
	
	cout << " MOVIE MANAGEMENT SYSTEM " << endl;
	cout << endl;
	do {
		cout << "1. Input" << endl;
		cout << "2. Output" << endl;
		cout << "3. Search" << endl;
		cout << "4. Delete" << endl;
		cout << "5. Update" << endl;
		cout << "6. Sort name A->Z" << endl;
		cout << "7. Sort name Z->A" << endl;
		cout << "8. Exit" << endl;
		cout << "8. Input your choice: ";
		cin>> menuOption;
		
		switch (menuOption){
			
			case 1:  
				       cout << " ==== CREATE MOVIE INFO === " << endl;
				       cout << "Input movie number: "; cin >> movieNumber[n];
				       cout << "Input movie title: "; cin.clear();cin.ignore();getline(cin,movieTitle[n]);
				       cout << "Input movie genre: "; cin >> movieGenre[n];
				       cout << "Input movie year: "; cin >> movieYear[n];
				       n++;
				       
				break;
			
			case 2: {
						cout << " ==== OUTPUT MOVIE INFO === " << endl;
						for (int i = 0; i < n; i++){
							cout << setw (20) << movieNumber[i];
							cout << setw (20) << movieTitle[i];
							cout << setw (20) << movieGenre[i];
							cout << setw (20) << movieYear[i] << endl;
						}
						
				
				break;
			}
			case 3: 
						cout << " ==== SEARCH MOVIE INFO === " << endl;
				
				break;
			
			case 4: 
						cout << " ==== DELETE MOVIE INFO === " << endl;
				
				break;
			
			case 5: 
						cout << " ==== UPDATE MOVIE INFO === " << endl;
				
				break;
			
			case 6: 
						cout << " ==== SORT MOVIE NAME A->Z === " << endl;
				
				break;
			
			case 7: 
						cout << " ==== SORT MOVIE NAME Z->A === " << endl;
				
				break;
			
			case 8: 
				
				exit(0);		
			
} 
  }
	while(menuOption != 8);
	
	return 0;
	

}

