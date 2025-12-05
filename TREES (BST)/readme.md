⏳ The Time-Stream Stabilizer V1.0

A C++ simulation project that uses a Binary Search Tree (BST) to store, search, delete, and report historical events across time.
Each event is stored as a Time Capsule, and commands let users modify the timeline while keeping it “stable.”

🚀 Features
1. INJECT (Insert a new event)

Adds a new time capsule into the BST.

Maintains timeline order automatically.

Example:

INJECT 1990 Moon Landing Anniversary

2. PARADOX (Delete an event)

Removes an event from the tree.

Handles all deletion cases:

Leaf node

One-child node

Two-children node (uses inorder successor)

Example:

PARADOX 2001

3. SEARCH

Searches for a specific year in the timeline.

SEARCH 2020

4. REPORT

Prints all years/events in chronological order (inorder traversal).

5. TimeSpan

Displays time difference between earliest and latest events stored.

🧠 How It Works (Concept Summary)
Tree Structure

Each node is:

struct TimeCapsule {
    int year;
    string eventName;
    TimeCapsule* left;
    TimeCapsule* right;
};


The BST stores years in sorted order:

Left subtree → earlier years

Right subtree → later years

Core Algorithms
Task	Method Used
Insert	BST Insertion
Search	BST Lookup
Delete	BST Deletion (3-case handling)
Report	Inorder Traversal
Timespan	Min/Max traversal

This allows the program to efficiently model a “stable” timeline.

🛠️ How to Run
1. Compile
g++ -o timestream main.cpp

2. Run
./timestream

3. Input Commands

You can enter commands interactively:

INJECT 2020 Global Pandemic
INJECT 1995 Windows 95 Released
SEARCH 2020
PARADOX 1995
REPORT
EXIT

📌 Valid Commands
Command	Action
INJECT <year> <event>	Insert a new event
PARADOX <year>	Delete event from BST
SEARCH <year>	Find event
REPORT	Show all events sorted
EXIT	Quit program
📂 Project Structure
/Time-Stream-Stabilizer
│
├── main.cpp          # Full source code
├── README.md         # Documentation
└── LICENSE (optional)

🧪 Example Run
INJECT 2000 Millennium Celebration
> System: Injecting 2000... Timeline stable.

INJECT 1990 Early Tech Boom
> System: Injecting 1990... Timeline stable.

SEARCH 1990
> Result: Event Found! [1990: Early Tech Boom]

REPORT
1990 → Early Tech Boom
2000 → Millennium Celebration

❤️ Author

Syed Adnan (MAN GO)
AI Student – IMSciences Peshawar
C++ | Data Structures | Time Simulation Projects
