This part of the assignment aims at providing you with a programming exercise involving linked list, stack, queue, and the STL.

You are to study and complete this supplied partial program that does the following:

    TODO - Use the STL stack template class to develop a custom queue class (named cnPtrQueue).

        - Further information on implementing a queue using 2 stacks is available here.

            - The cnPtrQueue has member variable numItems (that keeps track of the number of items in the queue), which should be helpful for implementing the member function size() (for inspecting the number of items in the queue).
                - Use the cnPtrQueue to perform a breadth-first (level) traversal of a linked list of linked lists data structure and process (print) the data items stored in the structure.

        - Further information on linked list of linked lists and level traversal using queue is available here.

Test your completed program with at least the supplied the test input file (a5p2_test.in) : make test (or, if you prefer to do it "manually", ./a5p2 auto < a5p2_test.in > a5p2_test.out). The correct output should look as follows:

--------------------------------------------------------------------------

Dynamic memory for 0 CNodes freed
Dynamic memory for 1 PNodes freed
11
11
Dynamic memory for 1 CNodes freed
Dynamic memory for 1 PNodes freed
11  12  13  14
11  12  13  14
Dynamic memory for 4 CNodes freed
Dynamic memory for 1 PNodes freed
21  22  23  24
21  22  23  24
Dynamic memory for 0 CNodes freed
Dynamic memory for 4 CNodes freed
Dynamic memory for 2 PNodes freed
11  12  13  14
11  12  13  14
Dynamic memory for 4 CNodes freed
Dynamic memory for 0 CNodes freed
Dynamic memory for 2 PNodes freed
11  12  13  14  21  41  42
11  21  41  12  42  13  14
Dynamic memory for 4 CNodes freed
Dynamic memory for 1 CNodes freed
Dynamic memory for 0 CNodes freed
Dynamic memory for 2 CNodes freed
Dynamic memory for 4 PNodes freed
21  22  23  24  31  51  52
21  31  51  22  52  23  24
Dynamic memory for 0 CNodes freed
Dynamic memory for 4 CNodes freed
Dynamic memory for 1 CNodes freed
Dynamic memory for 0 CNodes freed
Dynamic memory for 2 CNodes freed
Dynamic memory for 5 PNodes freed

--------------------------------------------------------------------------




Your Tasks

Study the supplied files - how they all relate to each other.
Fill in the "holes" intentionally left:

    - Implementation of cnPtrQueue in cnPtrQueue.cpp.
    - Function body of ShowAll_BF in nodes_LLoLL.cpp.
        - You are to put the cnPtrQueue (NOT the STL queue) to use here. (You will earn little or no credit if you use the STL queue).

Test the "holes-filled-in" program. Be sure to also read this Q&A page.

Deliverables
    - Source files: nodes_LLoLL.cpp, cnPtrQueue.cpp. (softcopy and hardcopy)
    - Test output (corresponding to the supplied test input a5p2_test.in): a5p2_test.out. (hardcopy only)