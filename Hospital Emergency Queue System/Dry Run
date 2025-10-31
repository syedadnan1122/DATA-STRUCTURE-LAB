Initial State
text
Empty list: head = nullptr, tail = nullptr
Step 1: insertAtEnd(101)
text
head → [101] ← tail
        ↑      ↑
     prev=null next=null
Step 2: insertAtEnd(102)
text
head → [101] <-> [102] ← tail
        ↑         ↑
     prev=null  prev=101
                next=null
Step 3: insertAtBeginning(200) // critical patient
text
head → [200] <-> [101] <-> [102] ← tail
        ↑         ↑         ↑
     prev=null prev=200  prev=101
                next=101  next=null
Step 4: insertAtPosition(150, 2)
Position 2 means between [200] and [101]

text
head → [200] <-> [150] <-> [101] <-> [102] ← tail
        ↑         ↑         ↑         ↑
     prev=null prev=200  prev=150  prev=101
                next=150  next=101  next=null
Step 5: deleteFromBeginning()
Remove [200] from the beginning

text
head → [150] <-> [101] <-> [102] ← tail
        ↑         ↑         ↑
     prev=null prev=150  prev=101
                next=101  next=null
Step 6: insertAtEnd(300)
text
head → [150] <-> [101] <-> [102] <-> [300] ← tail
        ↑         ↑         ↑         ↑
     prev=null prev=150  prev=101  prev=102
                next=101  next=102  next=null
Final Answers:
(a) What is the patientID at the head?

text
150
(b) What is the patientID at the tail?

text
300
(c) Write the list from head → tail (forward traversal):

text
150 → 101 → 102 → 300
(d) Write the list from tail → head (backward traversal):

text
300 → 102 → 101 → 150
Final List Visualization:

text
head → [150] <-> [101] <-> [102] <-> [300] ← tail
        ↑         ↑         ↑         ↑
     prev=null prev=150  prev=101  prev=102
                next=101  next=102  next=null
