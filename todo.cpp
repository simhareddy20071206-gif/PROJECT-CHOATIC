#include <iostream>
#include <bits/stdc++.h>


using namespace std;

// ─── COLOR CODES ────────────────────────────────────────────
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define WHITE   "\033[1;37m"
#define COLOR  "\033[1;40m"

// ─── UI HELPERS ─────────────────────────────────────────────
void printLine( string c = "-", int len = 50) {
    cout << CYAN;
    for (int i = 0; i < len; i++) cout << c;
    cout << RESET << endl;
}

void printBanner() {
    cout << endl ;
    cout << endl;
    cout << endl;
    printLine("=" , 50);
    cout << RED << BOLD;
    cout << "  ██████╗██╗  ██╗ █████╗  ██████╗ ████████╗██╗ ██████╗" << endl;
    cout << " ██╔════╝██║  ██║██╔══██╗██╔═══██╗╚══██╔══╝██║██╔════╝" << endl;
    cout << " ██║     ███████║███████║██║   ██║   ██║   ██║██║     " << endl;
    cout << " ██║     ██╔══██║██╔══██║██║   ██║   ██║   ██║██║     " << endl;
    cout << " ╚██████╗██║  ██║██║  ██║╚██████╔╝   ██║   ██║╚██████╗" << endl;
    cout << "  ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚═╝ ╚═════╝" << endl;
    cout << RESET;
    cout << CYAN << "              ⚡  PROJECT CHAOTIC v1.0  ⚡" << RESET << endl;
    printLine("═", 57);
}

void printMenu() {
    printLine("-", 50);
    cout << CYAN << BOLD << "  📋  COMMANDS" << RESET << endl;
    printLine("-", 50);
    cout << GREEN  << "  ➕  add          " << RESET << "→ Add new tasks" << endl;
    cout << YELLOW << "  📋  show         " << RESET << "→ Show all tasks" << endl;
    cout << GREEN  << "  ✅  markdone     " << RESET << "→ Mark task as done" << endl;
    cout << YELLOW << "  ⌛  markpending  " << RESET << "→ Mark task as pending" << endl;
    cout << RED    << "  🗑️   remove       " << RESET << "→ Remove a task" << endl;
    cout << GREEN  << "  👍  showdone     " << RESET << "→ Show completed tasks" << endl;
    cout << YELLOW << "  ⌛  showpending  " << RESET << "→ Show pending tasks" << endl;
    cout << RED    << "  🛑  showunstarted" << RESET << "→ Show unstarted tasks" << endl;
    cout << MAGENTA<< "  🚪  quit         " << RESET << "→ Save & exit" << endl;
    cout << COLOR  << "  🤝 showinorder  " << RESET << "→ All tasks will show in order" << endl;  
    cout << "🤖" << " Ask AI" << "→ chat with ai" << endl;
    printLine("-", 50);
    cout << CYAN << "  > " << RESET;
}

void printSectionHeader(string title, string color) {
    cout << endl;
    printLine("-", 50);
    cout << color << BOLD << "  " << title << RESET << endl;
    printLine("-", 50);
}

// ─── TODO CLASS ─────────────────────────────────────────────
class todo {
public:
    unordered_multimap<string, int> map1;

    todo() {
        printBanner();
        cout << WHITE << BOLD << "  Welcome back, Narasimha. Let's get things done." << RESET << endl;
        printLine("==", 57);
    }

    void addtask(string s) {
        if (map1.find(s) == map1.end()) {
            map1.emplace(s, 1);
            cout << GREEN << "  ✅ Added: " << s << RESET << endl;
        } else {
            cout << YELLOW << "  ⚠️  Already exists: " << s << RESET << endl;
        }
    }

    void showdone() {
        printSectionHeader("🚀 COMPLETED TASKS", GREEN);
        bool found = false;
        for (auto w : map1) {
            if (w.second == 0) {
                cout << GREEN << "  👍  " << w.first << RESET << endl;
                found = true;
            }
        }
        if (!found) cout << YELLOW << "  No completed tasks yet. Get moving!" << RESET << endl;
        printLine("-", 50);
    }

    void showpending() {
        printSectionHeader("⌛ PENDING TASKS", YELLOW);
        bool found = false;
        for (auto w : map1) {
            if (w.second == 2) {
                cout << YELLOW << "  ⌛  " << w.first << RESET << endl;
                found = true;
            }
        }
        if (!found) cout << GREEN << "  No pending tasks!" << RESET << endl;
        printLine("-", 50);
    }
    void showinorder(){
        printSectionHeader("ALL TASKS BY ORDER" ,COLOR);
        for (auto w : map1) {
            if (w.second == 0) {
                cout << GREEN << "  👍  " << w.first << RESET << endl;
                
            }
        }
        printLine("-", 50);

         for (auto w : map1) {
            if (w.second == 2) {
                cout << YELLOW << "  ⌛  " << w.first << RESET << endl;
            }
        }
         printLine("-", 50);
        for (auto w : map1) {
            if (w.second == 1) {
                cout << RED << "  🛑  " << w.first << RESET << endl;
            }
        }
        cout << endl;
        cout << endl;

    }

    void showunstarted() {
        printSectionHeader("🛑 UNSTARTED TASKS", RED);
        bool found = false;
        for (auto w : map1) {
            if (w.second == 1) {
                cout << RED << "  🛑  " << w.first << RESET << endl;
                found = true;
            }
        }
        if (!found) cout << GREEN << "  No unstarted tasks. Beast mode!" << RESET << endl;
        printLine("-", 50);
    }

    void showtask() {
        printSectionHeader("📋 ALL TASKS", CYAN);
        if (map1.empty()) {
            cout << YELLOW << "  No tasks yet. Type 'add' to start." << RESET << endl;
        }
        for (auto w : map1) {
            if (w.second == 1)
                cout << RED    << "  🛑  " << w.first << RESET << endl;
            else if (w.second == 0)
                cout << GREEN  << "  👍  " << w.first << RESET << endl;
            else
                cout << YELLOW << "  ⌛  " << w.first << RESET << endl;
        }
        printLine("-", 50);
    }

    void markdoneTask(string s) {
        if (map1.find(s) != map1.end()) {
            auto it = map1.find(s);
            it->second = 0;
            cout << GREEN << "  🎉 Marked done: " << s << RESET << endl;
        } else {
            cout << RED << "  ❌ Task not found: " << s << RESET << endl;
        }
    }

    void removeTask(string s) {
        if (map1.find(s) != map1.end()) {
            map1.erase(map1.find(s));
            cout << RED << "  🗑️  Removed: " << s << RESET << endl;
        } else {
            cout << RED << "  ❌ Task not found: " << s << RESET << endl;
        }
    }

    void savetxt() {
        ofstream file("projectinfo.txt");
        for (auto w : map1)
            file << w.first << ":" << w.second << ",";
        file.close();
        cout << GREEN << "  💾 Progress saved." << RESET << endl;
    }

    void readtxt() {
        ifstream in("projectinfo.txt");
        string line;
        while (getline(in, line)) {
            stringstream ss(line);
            string token;
            while (getline(ss, token, ',')) {
                stringstream ss2(token);
                vector<string> words;
                string part;
                while (getline(ss2, part, ':'))
                    words.push_back(part);
                if (words.size() == 2)
                    map1.insert({words[0], stoi(words[1])});
            }
        }
    }

    void markpendingTask(string s) {
        if (map1.find(s) == map1.end()) {
            cout << RED << "  ❌ Task not found: " << s << RESET << endl;
        } else {
            auto it = map1.find(s);
            it->second = 2;
            cout << YELLOW << "  ⌛ Marked pending: " << s << RESET << endl;
        }
    }

    void askAi() {
    string context = "Tasks (0=done, 1=unstarted, 2=pending):\n";
    int n = 1;
    for (auto w : map1) {
        context += to_string(n++) + ". " + w.first + " [status: " + to_string(w.second) + "]\n";
    }

    string que;
    cout << CYAN << "  Ask AI: " << RESET;
    getline(cin, que);

    string fullPrompt = context + "\nUser question: " + que;
    string safePrompt = fullPrompt;
    replace(safePrompt.begin(), safePrompt.end(), '\n', ' ');

    string cmd = "curl -s http://localhost:11434/api/generate "
                 "-d '{\"model\":\"minimax-m2.5:cloud\","
                 "\"prompt\":\"" + safePrompt + "\","
                 "\"stream\":false}' 2>/dev/null | python3 -c \""
                 "import sys,json; d=json.load(sys.stdin); print(d['response'])\"";

    cout << MAGENTA << "  🤖 Thinking..." << RESET << endl;
    system(cmd.c_str());
   }

    void run() {
        string s;
        readtxt();
        printMenu();

        getline(cin, s);
        while (s != "quit") {
            if (s == "add") {
                cout << CYAN << "  Enter tasks (type 'done' to finish):" << RESET << endl;
                string add;
                getline(cin, add);
                while (add != "done") {
                    addtask(add);
                    getline(cin, add);
                }
            } else if (s == "show") {
                showtask();
            } else if (s == "markdone") {
                cout << CYAN << "  Enter tasks to mark done (type 'done' to finish):" << RESET << endl;
                string rem;
                getline(cin, rem);
                while (rem != "done") {
                    markdoneTask(rem);
                    getline(cin, rem);
                }
            } else if (s == "remove") {
                cout << CYAN << "  Enter task to remove:" << RESET << endl;
                string rem;
                getline(cin, rem);
                removeTask(rem);
            } else if (s == "markpending") {
                cout << CYAN << "  Enter task to mark pending:" << RESET << endl;
                string rem;
                getline(cin, rem);
                markpendingTask(rem);
            } else if (s == "showdone") {
                showdone();
            } else if (s == "showpending") {
                showpending();
            } else if (s == "showunstarted") {
                showunstarted();
            } else if(s == "showinorder"){
                showinorder();
            }else if(s == "Ask AI"){
                askAi();
            }
            else {
                cout << RED << "  ❌ Invalid command." << RESET << endl;
            }

            cout << CYAN << "  > " << RESET;
            getline(cin, s);
        }

        showtask();
        savetxt();
        printLine("==", 57);
        cout << MAGENTA << BOLD << "  ⚡ Chaotic OS signing off. See you tomorrow." << RESET << endl;
        printLine("==", 57);
    }
};

int main() {
    todo t1;
    t1.run();
    return 0;
}