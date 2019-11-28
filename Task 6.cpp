#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int clear_database(vector<char> *entries) {
	char input_char = '\0';
	

	std::printf("Are you shure you want to delete all entries in the database?(y/n)\n");
	cin >> input_char;
	if (input_char == 'y') {
		std::printf("Entries deleted\n");
		(*entries).clear();
		(*entries).push_back('\0');
		return 0;
	}
	else if (input_char == 'n') {
		std::printf("Deletion aborted\n");
		return 0;
	}
	else
		return 1;
	
}

int insert_entries(vector<char>* entries) {
	bool loop = true;
	int size = 0;
	int count = 0;
	int count_2 = 0;
	int count_3 = 0;
	char input_char[50];
	while (loop == true) {
		std::printf("Please write an entry to be added or write Q or q to go back to menu selection\n");
		scanf_s("%s", input_char, _countof(input_char));

		//Looking for Q and q and break the loop (I am unfamiliar with the break command, I prefer using bools for loops
		if ((input_char[0] == 'Q' || input_char[0] == 'q') && input_char[1] == '\0')
			loop = false;

		//Alocating memory and storeing values
		else {
			count = count_2 = count_3 = size = 0;

			//Checking size of input variable and allocate memory
			while (input_char[size] != '\0') {
				size++;
			}
			count_2 = (*entries).size();
			(*entries).resize(size + count_2 + 1);

			count_3 = count_2 + size;
			count = 0;

			//Entering entry
			while (count_2 < count_3) {
				(*entries)[count_2] = input_char[count];
				count++;
				count_2++;
			}
			(*entries)[count_2] = '\0';
		}
	}
	std::printf("You have stopped inputing entries, please select a new option\n");
	return 0;
}

int search_entries(const vector<char>* entries) {
	int count = 0;
	int count_2 = 0;
	int count_3 = 0;
	int size = 0;
	char input_char[50];
	//Get search term
	std::printf("Please enter one or several characters to search the Database for\n");
	scanf_s("%s", input_char, _countof(input_char));
	while (input_char[size] != '\0')
		size++;

	//Search loop
	while (count < (*entries).size()) {
		while ((*entries)[count + count_2] == input_char[count_2]) {
			//if-statement true when all chars of input equate to somewhere in entries
			if (count_2 == size - 1) {
				count_2 = count_3 = count;
				//Finds start of entry
				while ((*entries)[count_2] != '\0')
					count_2--;
				//Finds end of entries
				while ((*entries)[count_3] != '\0')
					count_3++;
				count_2++;
				while (count_2 < count_3) {
					std::printf("%c", (*entries)[count_2]);
					count_2++;
				}
				count_2 = 0;
				std::printf("\n");
			}
			count_2++;
		}
		count++;
		count_2 = count_3 = 0;
	}
	return 0;
}

int delete_entries(vector<char>* entries) {
	int size = 0;
	int count = 0;
	int count_2 = 0;
	int count_3 = 0;
	int count_4 = 0;
	char input_char[50];
	std::printf("Please enter the name of an entry to delete\nThis will delete all entries with this exact name\n");

	//Get search term for deletion
	scanf_s("%s", input_char, _countof(input_char));
	while (input_char[size] != '\0')
		size++;
	while (count < (*entries).size()) {
		//Finds first character
		if ((*entries)[count] == input_char[0]) {
			count--;
			if ((*entries)[count] == '\0') {
				count_2 = count + 1;
				//Checks the rest of the characters
				while (count_3 < size && (*entries)[count_2] == input_char[count_3]) {
					count_2++;
					count_3++;
					//Checks that the lenghts match up 
					if ((*entries)[count_2] == '\0' && count_3 == size) {
						count_2 = count + 1;
						count_3 = count + size + 1;
						//entries.push_back('\0');
						//Moves characters forwards
						while ((*entries).size() > count_3) {
							entries[count_2] = entries[count_3];
							count_2++;
							count_3++;
						}
						//Removes unnececary memory
						count_2 = size;
						while (count_2 > 0) {
							(*entries).pop_back();
							count_2--;
						}
						count_4++;
					}
				}
			}
			count++;
		}
		count++;
		count_2 = count_3 = 0;
	}
	std::printf("%i entrie(s) deleted\n", count_4);
	return 0;
}

int print_database(const vector<char>* entries) {
	int count = 1;
	while (count < (*entries).size()) {
		if ((*entries)[count] == '\0') {
			std::printf("\n");
		}
		else {
			std::printf("%c", (*entries)[count]);
		}
		count++;
	}
	return 0;
}

int save_database(const vector<char>* entries) {
	ofstream file;
	char filename[50];
	int count = 1;
	printf("Enter a name for the file that the database will be saved to.\n(remember to include .txt)\n");
	cin >> filename;
	file.open(filename);
	while (count < (*entries).size()) {
		if ((*entries)[count] == '\0') {
			file << '\n';
		}
		else {
			file << (*entries)[count];
		}
		count++;
	}
	file.close();
	return 0;
}

int load_database(vector<char>* entries) {

	char filename[50], temp;
	int count = 0;

	printf("Enter a name for the file that the database will be loaded from\n(remember to include .txt)\n");
	cin >> filename;
	fstream file(filename, fstream::in);
	if (file.is_open()) {
		while (file >> noskipws >> temp) {
			if (temp == '\n') {
				(*entries).push_back('\0');
			}
			else {
				(*entries).push_back(temp);
			}
		}
		return 0;
	}
	else {
		printf("The file couldn't be opened, make shure that you spelled the name correctly\n");
		return 1;
	}
}

int main() {
	vector<char> entries(1, '\0');
	
	char input_char[50];
	int input_int = 0;
	int return_value;
	bool loop = true;

	std::printf("+--------+\n|  MENU  |\n+--------+\n\n");
	std::printf("1:Clear Database\n2:Insert Entry\n3:Search Entry\n4:Delete Entry\n5:Print Database\n6:Save Database\n7:Load Database\n8:Show Menu again\n9:Quit\n\n");
	while (1) {

		scanf_s("%s", input_char, _countof(input_char));
		input_int = input_char[0] - 48;

		//Clear database
		if (input_int == 1) {
			return_value=clear_database(&entries);
		}

		//Insert entry
		else if (input_int == 2) {
			return_value=insert_entries(&entries);
		}

		//Search entry
		else if (input_int == 3) {
			return_value = search_entries(&entries);
		}

		//Delete entry
		else if (input_int == 4) {
			return_value = delete_entries(&entries);
		}

		//Print database
		else if (input_int == 5) {
			return_value = print_database(&entries);
		}

		//Save database
		else if (input_int == 6) {
			return_value = save_database(&entries);
		}

		//Load database
		else if (input_int == 7) {
			loop = true;
			printf("Are you shure that you want to load a file? This will\ndelete all current entries in the database (y/n)\n");
			while (loop == true) {
				cin >> input_char;
				if (input_char[0] == 'y') {
					entries.clear();
					entries.push_back('\0');
					load_database(&entries);
					loop = false;
				}
				else if (input_char[0] == 'n') {
					printf("Loading canceled\n");
					loop = false;
				}
				else {
					printf("Please enter either a y or n\n");
				}
			}
		}

		//Print menu
		else if (input_int == 8) {
			std::printf("+--------+\n|  MENU  |\n+--------+\n\n");
			std::printf("1:Clear Database\n2:Insert Entry\n3:Search Entry\n4:Delete Entry\n5:Print Database\n6:Save Database\n7:Load Database\n8: Show Menu again\n9: Quit\n\n");
		}

		//Quit
		else if (input_int == 9) {
			std::printf("The program will now quit\n");
			system("pause");
			return 0;
		}
		

		//Incorrect entry
		else {
			std::printf("The character you have entered isn't an option, please enter an allowed number\n(remember that 6 shows the options)\n");
		}
	}
}
