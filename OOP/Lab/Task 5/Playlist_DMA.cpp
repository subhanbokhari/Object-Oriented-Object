#include<iostream>
#include<string>

using namespace std;

class FavoriteSongs {
	private:
		int size;
		string* songs;
	public:
=
		FavoriteSongs() {
			size = 0;
		};

		FavoriteSongs(int initial_size) {
			size = initial_size;
			songs = new string[size];
		}

		~FavoriteSongs() {
			delete[] songs;
		}

		void AddSong(string song) {
			string* temp = new string[size + 1];
			for (int i = 0; i < size; i++) {
				temp[i] = songs[i];
			}
			temp[size] = song;
			size += 1;
			songs = temp;
		}

		int GetSize() {
			return size;
		}

		void PrintSongs() {
			for (int i = 0; i < size; i++) {
				cout << songs[i] << endl;
			}
		}

		void DeleteSong(string song) {
			int index = -1;
			for (int i = 0; i < size; i++) {
				if (song == songs[i]) {
					index = i;
					break;
				}
			}
			if (index == -1) {
				cout << "Sorry, song not found" << endl;
				return;
			}
			string* temp = new string[size - 1];
			for (int i = 0; i < index; i++) {
				temp[i] = songs[i];
			}
			for (int i = index + 1; i < size; i++) {
				temp[i - 1] = songs[i];
			}
			size--;
			delete[] songs;
			songs = temp;
		}

		void UpdateSong(string song) {
			int index = -1;
			string new_song;
			for (int i = 0; i < size; i++) {
				if (song == songs[i]) {
					index = i;
					cout << "Enter the new song to replace it with:  ";
					cin >> new_song;
					songs[i] = new_song;
					cout << "Song updated successfully" << endl;
				}
			}
			if (index == -1) {
				cout << "Sorry, song not found" << endl;
				return;
			}
		}
};

int main() {
	FavoriteSongs obj1(5);


	int choice;
	string song;
	string new_song;
	string delete_song;


	do {
		cout << "1. Print all songs" << endl;
		cout << "2. Add a song" << endl;
		cout << "3. Delete a song" << endl;
		cout << "4. Update a song" << endl;
		cout << "5. Create a backup" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1) 
		{
				obj1.PrintSongs();
		}
		if (choice == 2)
		{
				cout << "Enter the new song you want to add:  ";
				cin>>new_song;
				obj1.AddSong(new_song);
		}
		if (choice == 3)
		{
				cout<<"enter new song you want to delete:  ";
				cin>>delete_song;
				obj1.DeleteSong(delete_song);
		}
		if (choice == 4)
		{
				cout<<"enter name of song that you want to replace: ";
				cin>>song;
				obj1.UpdateSong(song);
		}
		if (choice == 5)
		{
				FavoriteSongs backup(obj1);
				cout<<"backup created "<<endl;
				break;
		}
		}while(choice!=6);
	
}
