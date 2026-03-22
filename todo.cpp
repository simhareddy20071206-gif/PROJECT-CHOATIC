#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>

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
    // markdone a task 
    void  markdoneTask(string s){
       if(map1.find(s) != map1.end()){
          auto it = map1.find(s);
          it->second = 0;
          cout << "Congrats On completion" << endl;
       }else{
        cout << "Task not found yet " << endl;
       }
       
    }
 
 // remove a task
    void removeTask(string s){
      if(map1.find(s) != map1.end()){
         auto it = map1.find(s);
         map1.erase(it);
         cout << "Task removed sucessfully" << endl;
      }else{
         cout << "Task Not Found" << endl;
      }
    }
    

    // to save the eveything as a txt file

    void savetxt(){
       ofstream file ("projectinfo.txt");
       for(auto w : map1){
         file << w.first << ":" << w.second <<",";
       }
       file.close();

    }

    void readtxt(){
      ifstream in ("projectinfo.txt");
      string line;

      while(getline(in , line)){
         stringstream ss(line);
         string token;
         
         while(getline(ss , token , ',')){
            string word = token;
            stringstream ss(word);
            vector<string>words;
            while(getline(ss ,token , ':' )){
               words.push_back(token);
            }

            int key = stoi(words[1]);
            string val = words[0];

            map1.insert({val,key});
         }
      }
    }
    void run(){
    string s;
    readtxt();

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
       else if(s == "markdone"){  // to  markdoneTask tasks code 
         cout << "Enter the task you wanna  markdoneTask :" << endl;
         string rem;
        
         getline(cin,rem);


         while(rem != "done"){
            markdoneTask(rem);
           getline(cin , rem);
         }


       }else if (s == "remove"){
           cout << "Enter the Task you want to remove" << endl;

           string rem;

           getline(cin ,rem);
           
           removeTask(rem);
       }
       else{
        cout << "INVALID COMMAND " << endl;
        cout << "Type 'quit' to exit " << endl;
       }
       
      getline(cin , s);
      
    }


    showtask();
    savetxt();

    return;
    }

   

};



int main(){
  
    todo t1;
    t1.run();
       
    return 0;
}