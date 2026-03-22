#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class todo{
public:
   unordered_multimap<string,int>map1;


   todo(){
    cout << "hello! welcome to the app" << endl;
   }
    
   //add a task
   void addtask(string s){
     if(map1.find(s) == map1.end()){
        map1.emplace(s,1);
     }else{
        cout << " already have the task" << endl;
     }
     
    
   }

   void showtask(){
    cout << "TASK LIST : " << endl;


    for (auto w : map1){
        // printing tasks
        if(w.second == 1){
            cout << "\033[31m" << w.first << "\033[0m" << endl;
        }else{
            cout << "\033[32m" << w.first << "\033[0m" << endl;
        }
    }
   }
    // remove a task 
    void  removeTask(string s){
       if(map1.find(s) != map1.end()){
          auto it = map1.find(s);
          it->second = 0;
          cout << "Congrats On completion" << endl;
       }else{
        cout << "Task not found yet " << endl;
       }
       
    }
    void run(){
    string s;

    getline(cin ,s);
    while(s != "quit"){

       if(s == "add"){   //. to add tasks code
        cout << "Enter the task you want to add" << endl;
        string add;
      
        getline(cin , add);
        while(add != "done"){
           addtask(add);
           getline(cin , add);
        }
       }
       else if(s == "show"){    /// to show tasks
        showtask();
        
       }
       else if(s == "remove"){  // to  removeTask tasks code 
         cout << "Enter the task you wanna  removeTask :" << endl;
         string rem;
        
         getline(cin,rem);


         while(rem != "done"){
            removeTask(rem);
           getline(cin , rem);
         }


       }
       else{
        cout << "INVALID COMMAND " << endl;
        cout << "Type 'quit' to exit " << endl;
       }
       
      getline(cin , s);
      
    }


    showtask();
    return;
    }

   

};



int main(){
  
    todo t1;
    t1.run();
       
    return 0;
}