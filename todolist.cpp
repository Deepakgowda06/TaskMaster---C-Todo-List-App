#include <iostream>
#include <string>
#include<fstream>

using namespace std;
 struct todolist
 {
 	int id;
 	string task;
 };
   
 int ID;
 
 
void banner();
void addtask();
void showtask();
int searchtask();
void deletetask();
void updatetask();
void exitProgram();


int main(){
system("cls");
while(true){
	banner();
	cout<<"\n\t 1. Add Task";			
	cout<<"\n\t 2. Show Task";
	cout<<"\n\t 3. Search Task";
	cout<<"\n\t 4. Delete Task";
	cout<<"\n\t 5. Update Task";
	cout<<"\n\t 6. Exit ";		
	
	int choice;
	cout<<"\nEnter  the choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			addtask();
			break;
			
		case 2:
			showtask();
			break;
		case 3:
			searchtask();
			break;
		case 4:
			deletetask();
			break;
		case 5:
			updatetask();
			break;
		case 6:
			 exitProgram();
			 break;
			
				}
				
}
	return 0;
}

void banner(){
	cout<<"---------------------------------------"<<endl;
	cout<<"|      Welecome to  To_Do List        |"<<endl;
	cout<<"---------------------------------------"<<endl;
}

void addtask(){
	system("cls"); 
	banner();
	todolist todo;
	cout<<"Enter new Task : "<<endl;
	cin.get();
	getline(cin,todo.task);
	char save;
	cout<<"Save ? (Y/N) :";
	cin>>save;
	if(save=='y'){
		ID++;
		ofstream fout;
		fout.open("todo.txt",ios::app);
		// ofstream fout("todo1.txt",ios::trunc);
		fout<<ID;
		fout<<"\n"<<todo.task<<endl;
		fout.close();
		
		char more;
		cout<<"Add more task ? (Y/N) ";
		cin>>more;
		if(more=='y'){
			addtask();
		}		
		else{
			system("cls");
			cout<< " Added successfully "<<endl;
			return;
		}
	}
	system("cls");	
}

void showtask()
{
	banner();
	todolist todo;
	ifstream fin;
	fin.open("todo.txt");
	cout<<"Task : "<<endl;
	
	while (fin >> todo.id)
	{
		
		fin.ignore();
		getline(fin, todo.task);
		if(!todo.task.empty()){
			cout<<"\t"<<todo.id<<" : "<<todo.task<<endl;
		}	
		else{
	
    		cout<<"\t empty! "<<endl;
		}
	}
	fin.close();
	char exit;
	cout<<" exit ! : (Y/N)";
	cin>>exit;
	if(exit != 'y'){
		showtask();
	}
	system("cls");
	
} 

int searchtask(){
	system("cls");
	banner();
	int id;
	cout<<"Enter task id : ";
	cin>>id;
	todolist todo;
	ifstream fin("todo.txt");
	while (!fin.eof())
	{
		fin>>todo.id;
		fin.ignore();
		getline(fin,todo.task);
		if(todo.id==id){
			system("cls");
			cout<<"\t"<<todo.id<<" : "<<todo.task<<endl;
			return id;

			}
	}
	system("cls");
	cout<<"Not found"<<endl;
	return 0;

}
void deletetask()
{
    system("cls");
    int id = searchtask();
    if(id != 0) {
        char del;
        cout << "\n\t Delete ? (Y/N) :";
        cin >> del;
        if(del == 'y') {
            todolist todo;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream fin("todo.txt"); 
            
          

            int index = 1;
            while(fin >> todo.id) {
                fin.ignore(); 
                getline(fin, todo.task); 

                if(todo.id != id) {
                    tempfile << index << "\n" << todo.task << "\n";
                    index++;
                }
            }
            
            fin.close();
            tempfile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            system("cls");
            cout << "\n\t Deleted successfully!" << endl;
        } else {
            system("cls");
            cout << "\n\t Not Deleted!" << endl;
        }
    }
}
void updatetask()
{
    system("cls");
    int id = searchtask();

    if (id != 0) {
        char update;
        cout << "\n\t Update task? (Y/N) :";
        cin >> update;

        if (update == 'y') {
            todolist todo;
            ofstream tempfile("temp.txt");  
            ifstream fin("todo.txt");       
            
           
            string newTask;
            cout << "Enter updated task: ";
            cin.ignore(); 
            getline(cin, newTask); 

            
            while (fin >> todo.id) {
                fin.ignore();
                getline(fin, todo.task);

                
                if (todo.id == id) {
                    todo.task = newTask;
                }

            
                tempfile << todo.id << "\n" << todo.task << "\n";
            }

            fin.close();
            tempfile.close();

            
            remove("todo.txt");
            rename("temp.txt", "todo.txt");

            system("cls");
            cout << "\n\t Task updated successfully!" << endl;
        } else {
            system("cls");
            cout << "\n\t Task not updated!" << endl;
        }
    }
}
void exitProgram() {
    system("cls");
    cout << "\n\t Exiting the program... Thank you for using the To-Do List!" << endl;
    exit(0);  
}