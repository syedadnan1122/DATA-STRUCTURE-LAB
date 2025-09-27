#include <iostream>
#include <cstdlib> 
using namespace std;

int main() {
    int NParticipants;
 
    cout << " Please enter the number of participants: ";
    cin >> numParticipants;

    int *attendance = (int*)calloc(NParticipants, sizeof(int));

    if (attendance == NULL) { 
        cout << " Memory allocation failed. Exiting program..." << endl;
        return 1;
    }
    cout<<endl;
    cout << "Attendance list created Everyone is absent by defaulT." << endl << endl;
    
    cout << "========================" << endl;
   for(int i=0; i<NParticipants; i++)
   {
       cout << "Participant " << (i + 1) << ": ";
       cin >> attendance[i];
       
       if(attendance[i]!=1 && attendance[i]!=0)
       {
           cout << "Invalid! Entry" << endl;
            cout << "Participant " << (i + 1) << ": ";
            cin >> attendance[i];
       }
       
   }

    cout<<endl;
    cout << " Final Attendance List (1 = Present, 0 = Absent):" << endl << endl;
    
    cout << "   --------------------------" << endl;
   for (int i = 0; i < NParticipants; i++)
   {
    cout << "  | Participant " << (i + 1) << " : ";
    
    if (attendance[i] == 1)
    {
        cout <<" Present =" << endl;
    }
    else if(attendance[i] == 0)
    {
        cout << " Absent  =" << endl;
    }
  }
  cout << "   --------------------------" << endl;

    free(attendance);
    cout<<endl;
    cout << " register closed." << endl;
    return 0;
}
