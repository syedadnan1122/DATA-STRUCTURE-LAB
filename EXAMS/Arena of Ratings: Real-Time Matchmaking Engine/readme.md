<div align="center">
  <img src="./banner.svg" alt="Arena of Ratings Banner" width="100%">
</div>

<div align="center">

# Arena of Ratings – BST Implementation

**🎮 Elite Matchmaking & Leaderboard System Powered by Binary Search Tree**

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://github.com/syedadnan1122/Arena-of-Ratings)
[![BST](https://img.shields.io/badge/Data_Structure-BST-00f3ff?style=for-the-badge)](https://github.com/syedadnan1122/Arena-of-Ratings)
[![No STL](https://img.shields.io/badge/No_STL-Pure_Pointers-ff00e5?style=for-the-badge)](https://github.com/syedadnan1122/Arena-of-Ratings)

*Developed for Data Structures Lab (C++) Final Exam*

[View Demo](#-example-session) · [Report Bug](https://github.com/syedadnan1122/Arena-of-Ratings/issues) · [Request Feature](https://github.com/syedadnan1122/Arena-of-Ratings/issues)

</div>

---

## 📌 Overview

This project implements a **Binary Search Tree (BST)**–based matchmaking and leaderboard system for a game called **Arena of Ratings**.

Each player is stored in the tree using their **rating as the unique key**.  
All searching, ordering, and ranking operations are performed using BST properties.

### ✨ Key Highlights

- 🌳 **Pure BST Implementation** - No STL containers
- ⚡ **O(log n) Average Complexity** - Efficient operations
- 🎯 **15+ Commands** - Complete player management
- 💻 **Pointer-Based** - Dynamic memory management
- ⚔️ **Combat System** - Health, damage, healing

---

## 🧠 Data Structure Used

**Binary Search Tree (BST)**
- Pointer-based dynamic structure
- Rating as unique key
- No STL ordered containers used

**Player Node Structure:**
```cpp
struct Player {
    int rating;        // Unique key
    string name;       // Player name
    long long hp;      // Health points
    Player* left;      // Left child
    Player* right;     // Right child
};
```

---

## ⚙️ Supported Commands

### 🔹 Insertion & Deletion
- `JOIN rating name hp` – insert a new player
- `LEAVE rating` – delete an existing player

### 🔹 Search & Update
- `STATUS rating` – display player information
- `DAMAGE rating amount` – decrease health points
- `HEAL rating amount` – increase health points

### 🔹 Tree Queries
- `NEXT X` – next higher rated player
- `PREV X` – previous lower rated player
- `MATCH X` – closest rating to X
- `RANGE L R` – list players in rating range
- `RANK X` – count of players with rating less than X
- `KTH k` – k-th smallest rated player

### 🔹 Structural Queries
- `DUEL A B` – distance between two players in BST
- `STATS` – display tree statistics

---

## 📊 Time Complexity

| Operation | Average | Worst Case |
|-----------|---------|------------|
| INSERT    | O(log n) | O(n) |
| DELETE    | O(log n) | O(n) |
| SEARCH    | O(log n) | O(n) |
| SUCCESSOR | O(log n) | O(n) |
| PREDECESSOR | O(log n) | O(n) |
| RANK      | O(log n) | O(n) |
| KTH       | O(log n) | O(n) |

---

## 🚀 How to Run

### Prerequisites
- C++ compiler (g++ recommended)
- C++11 or later

### Compile
```bash
g++ arena.cpp -o arena
```

### Run
```bash
./arena
```

### Input Format
The program reads from standard input:
```
<number_of_commands>
<command_1>
<command_2>
...
```

---

## 💻 Example Session

```bash
> JOIN 100 Alice 1000
JOINED

> JOIN 50 Bob 800
JOINED

> JOIN 150 Carol 950
JOINED

> STATUS 100
100 Alice 1000

> DAMAGE 100 300
DAMAGED 700

> HEAL 100 150
HEALED 850

> NEXT 50
100 Alice 850

> PREV 150
100 Alice 850

> MATCH 75
50 Bob 800

> RANK 100
1

> KTH 2
100 Alice 850

> RANGE 50 150
50 Bob 800
100 Alice 850
150 Carol 950

> DUEL 50 150
DIST 2

> STATS
PLAYERS 3
MIN 50
MAX 150
HEIGHT 1
LEAVES 2

> LEAVE 100
LEFT

> STATS
PLAYERS 2
MIN 50
MAX 150
HEIGHT 1
LEAVES 2
```

---

## 📐 Tree Properties

### Height Definition
- Empty tree → `-1`
- Single node → `0`
- General case → `1 + max(height(left), height(right))`

### Special Nodes
- **Leaf** → node with no children
- **Root** → topmost node (no parent)

### Distance Measurement
- **Duel Distance** → number of edges on the path between two nodes in BST
- Uses Lowest Common Ancestor (LCA) algorithm

---

## 🚫 Restrictions Followed

✅ **No use of:**
- `std::map`
- `std::set`
- `multiset` / `multimap`
- Any STL ordered containers

✅ **Implementation requirements:**
- Fully pointer-based BST implementation
- Ordering strictly based on **rating**
- Manual memory management
- Recursive and iterative approaches

---

## 📁 Project Structure

```
Arena-of-Ratings/
├── arena.cpp           # Main implementation file
├── banner.svg          # Animated project banner
├── README.md           # This file
└── examples/
    └── sample_input.txt
```

---

## 🧪 Testing

### Sample Test Cases

**Test 1: Basic Operations**
```
5
JOIN 100 Alice 1000
STATUS 100
DAMAGE 100 200
HEAL 100 100
STATS
```

**Test 2: Tree Traversal**
```
7
JOIN 50 Bob 800
JOIN 100 Alice 1000
JOIN 150 Carol 950
NEXT 50
PREV 150
MATCH 75
RANGE 40 160
```

**Test 3: Ranking Queries**
```
6
JOIN 25 Dan 700
JOIN 50 Bob 800
JOIN 100 Alice 1000
RANK 50
KTH 2
DUEL 25 100
```

---

## 🎯 Key Features Explained

### 1. **Efficient Search**
Uses BST properties for O(log n) average search time

### 2. **Dynamic Updates**
Players can join/leave, health can be modified in real-time

### 3. **Flexible Queries**
- Find next/previous rated players
- Get closest match to any rating
- Rank players by position
- Calculate distances in tree structure

### 4. **Tree Analytics**
- Monitor total players
- Track min/max ratings
- Analyze tree height and structure
- Count leaf nodes

---

## 🐛 Known Limitations

- **Unbalanced Tree**: Without self-balancing (like AVL/Red-Black), worst case can be O(n)
- **No Duplicate Ratings**: Each rating must be unique
- **Integer Ratings Only**: Ratings are stored as integers
- **No Persistence**: Data is lost when program exits

---

## 🔮 Future Enhancements

- [ ] Implement AVL or Red-Black tree for guaranteed O(log n)
- [ ] Add support for duplicate ratings
- [ ] Save/load game state to file
- [ ] GUI interface
- [ ] Network multiplayer support
- [ ] Player statistics tracking

---

## 📚 Learning Outcomes

This project demonstrates understanding of:
- Binary Search Tree implementation
- Tree traversal algorithms (inorder, preorder, postorder)
- Recursive and iterative solutions
- Pointer manipulation and memory management
- Algorithm complexity analysis
- C++ data structures without STL

---

## 👨‍💻 Author

**Syed Adnan Saeed**  
Fast NUCES Peshawar  
Data Structures Lab - Final Exam Paper 3rd symester

📧 Email: [your.email@example.com](syed1adnan1.com)  
🔗 GitHub: [@syedadnan1122](https://github.com/syedadnan1122)

---

## 📄 License

This project is part of academic coursework and is available for educational purposes.

---

## 🙏 Acknowledgments

- Course Instructor: [SYED SHAYAN ALI]
- Data Structures Lab - Fast NUCES Peshawar
- C++ Reference Documentation
- Binary Search Tree algorithms and concepts

---

<div align="center">

### ⭐ If you found this helpful, please star the repository! ⭐

**Made with ❤️ using pure C++ and BST algorithms**

[Back to Top](#arena-of-ratings--bst-implementation)

</div>
