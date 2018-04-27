# Leetcode Problems Categorization
- [String](#string)
- [Stack](#stack)
- [Backtracking](#backtracking)
- [Dynamic Programming](#dynamic-programming)
- [Trie](#trie)
- [Graph](#graph)
- [Sweep Line](#sweep-line)
- [Sampling](#sampling)

## Solved problems not in Google list
 | Problems                    | Difficulty | Techniques                  |
 | :-------------------------  | :---:      | ----:                       |
 | Binary Tree Right Side View | :sweat:    | level traversal (dfs/queue) |
 | Nested List Weight Sum      | :sweat:    | recursion                   |
 | Nested List Weight Sum II   | :sweat:    | recursion with states       |
 | Mine Sweeper                | :v:        | normal dfs/bfs              |

## Google(90)
 | Problems                                               | Difficulty     | Techniques                                                   | Status            |
 | :-------------------------                             | :---:          | :----                                                        | :---:             |
 | Reverse Pair                                           | :sob:          | divide and conqure(slow)                                     | :v: :eyes:        |
 | Count of Range Sum                                     | :sob:          | 1. multiset/bounds 2. merge sort and count                   | :v: :eyes:        |
 | Count of Smaller Numbers After Self                    | :sob:          | binary search/lower bound                                    | :v: :eyes:        |
 | Queue Reconstruction by Height                         | :sweat:        | idea: sort by height and then by order                       | :eyes:            |
 | Sequence Reconstruction                                | :sweat:        | record ele->id, and track prev ele idex from given seqs      | :eyes:            |
 | Populating Next Right Pointers in Each Node II         | :eyes: :sob:   | level order easy, const space hard                           |                   |
 | Populating Next Right Pointers in Each Node            | :eyes: :sweat: | see above, every level, track start, prev node               |                   |
 | Letter Combinations of a Phone Number                  | :sweat:        |                                                              |                   |
 | Longest Absolute File Path                             | :sweat:        | stack/two pointer                                            | :v:               |
 | Bomb Enemy                                             | :sweat: :eyes: | matrix scan methods                                          |
 | 01 Matrix                                              | :sweat:        | dfs(TLE)/bfs/two pass idea(fastest)                          | :eyes: :v:        |
 | Lonely Pixel I                                         | :sweat:        | 2-D vector                                                   | :lock:            |
 | Lonely Pixel II                                        | :sweat:        |                                                              | :eyes: :lock:     |
 | Moving Average From Data Stream                        | Easy           | queue                                                        | :lock:            |
 | Pow(x, n)                                              | :sweat:        |                                                              |                   |
 | Spiral Matrix                                          | :sweat:        | rectange, track leftmost/down line, take care of center line |                   |
 | Spiral Matrix II                                       | :sweat:        | square, track leftmost/down line, center element             |                   |
 | License Key Formatting                                 | :sweat:        | string operation                                             | :v:               |
 | Plus One                                               | Easy           |                                                              |                   |
 | Read N Characters Given Read4 II – Call multiple times | :sob:          |                                                              |                   |
 | Repeated Substring Pattern                             | Easy           |                                                              | :eyes: :v:        |
 | Heaters                                                | Easy           | upper/lower bound                                            | :eyes: :v:        |
 | Fraction to Recurring Decimal                          | :sweat:        | hashmap/sstream/overflow                                     | :v:               |
 | Summary Ranges                                         | :sweat:        | stringstream/array/size_t                                    | :v:               |
 | Missing Ranges                                         | :sweat:        | same as above                                                | :v:               |
 | Median of Two Sorted Arrays                            | :eyes::sob:    | find kth smallest, eliminate k/2 each binary search          | :v:        :eyes: |
 | Find Median from Data Stream                           | :eyes::sob:    | 1) multiset 2) min/max heap for right/left array             | :v:               |
 | Sliding Window Median                                  | :eyes: :sob:   | use multiset and movd midIter accordingly                    | :v:               |
 | Sliding Window Maximum                                 | :sob:          |                                                              |                   |
 | Strobogrammatic Number                                 | Easy           | hashmap                                                      | :v: :lock:        |
 | Strobogrammatic Number II                              | :sweat:        | backtracking                                                 | :v: :lock:        |
 | Strobogrammatic Number III                             | :sob:          | combination/backtracking                                     | :v: :lock: :eyes: |
 | Group Shifted Strings                                  | Easy           |                                                              |                   |
 | 3Sum Smaller                                           | :sweat:        |                                                              |                   |
 | Alien Dictionary                                       | :sob:          |                                                              |                   |
 | Encode and Decode Strings                              | :sweat:        |                                                              |                   |
 | H-Index                                                | :sweat:        |                                                              |                   |
 | Logger Rater Limitter                                  | Easy           | map                                                          | :v:               |
 | Flatten 2D Vector                                      | :sweat:        | track row, col index                                         | :v:               |
 | Unique Word Abbreviation                               | Easy           | pass                                                         | :lock:            |
 | Valid Word Abbreviation                                | Easy           |                                                              | :lock:            |
 | Generalized Abbreviation                               | :sweat:        | dfs                                                          | :lock:            |
 | Game of Life                                           | :sweat:        | track state, note state changes cell value                   | :eyes: :v:        |
 | Flip Game                                              | Easy           |                                                              |                   |
 | Max Consecutive Ones                                   | Easy           |                                                              | :v:               |
 | Max Consecutive Ones  II                               | :sweat:        | idea similar to sliding windwo, track loc of zeros           | :eyes: :v:        |
 | Longest Increasing Path in a Matrix                    | :sob:          | dfs + memorization to prun                                   | :eyes: :v:        |
 | Smallest Rectangle Enclosing Black Pixels              | :sob:          | 1. brute force  2. four directions binary search idea        | :eyes: :lock:     |
 | Super Ugly Number                                      | :sweat:        |                                                              |                   |
 | Binary Tree Vertical Order Traversal                   | :sweat:        | tree traversal                                               | :lock:            |
 | Best Meeting Point                                     | :sweat:        | consider one dimensional case                                | :eyes: :v:        |
 | Maximum Product of Word Lengths                        | :sweat:        |                                                              |                   |
 | Friend Cycle                                           | :sweat:        | union find (var to track count, when union reduce one)       | :eyes: :v:        |
 | Patching Array                                         | :sob:          | greedily expand [0, sum) range                               | :eyes: :v:        |
 | Verify Preorder Serialization of a Binary Tree         | :sweat:        | stack to squash subtree/use in and out degree                |                   |
 | Reconstruct Itinerary                                  | :sweat:        |                                                              |                   |
 | Design Phone Directory                                 | :sweat:        | keep track of recycled and used                              | :v:               |

## Facebook(79)
 | Problems                                               | Difficulty     | Related Problems                                            | Status              |
 | :-------------------------                             | :---:          | :----                                                       | :---:               |
 | Move Zeroes                                            | Easy           | array/swap                                                  | :v:                 |
 | Split Array With Equal Sums                            | :sweat:        | cache sum + split strategy                                  | :eyes: :lock:       |
 | Split Array Largest Sum                                | :sob:          | find range, then binary search /dp                          | :eyes:  :v:         |
 | Rearrange String K Distance Apart                      | :sob:          | hash/heap/rearrange task w/o reorder                        | :lock: :eyes:       |
 | Task Scheduler                                         | :sweat:        | find formular + heap solution                               | :eyes: :v:          |
 | Divide Two Integers                                    | :sweat:        | hash map/prefix sum                                         | :v: :eyes:          |
 | Roman to Integer                                       | Easy           | add then minus two if voliate                               | :v: :eyes:          |
 | Integer to Roman                                       | :sweat:        | find separating points, then all adding                     | :v: :eyes:          |
 | Integer to English Words                               | :sob:          | list all special cases + convert hundreds                   | :v: :eyes:          |
 | Reverse String                                         | Easy           |                                                             | :v:                 |
 | Reverse StringII                                       | Easy           |                                                             | :v:                 |
 | Magical String                                         | :sweat:        | think about how to generate it                              | :eyes: :v:          |
 | Add Binary                                             | Easy           | bit by bit                                                  | :v:                 |
 | Letter Combinations of a Phone Number                  | :sweat:        | dfs                                                         | :v:                 |
 | Read N Characters Given Read4                          | Easy           | so concise                                                  | :lock: :eyes:       |
 | Read N Characters Given Read4 II – Call multiple times | :sob:          | buffer/read-write pos tracker                               | :lock: :eyes:       |
 | Remove Duplicates from Sorted Array                    | Easy           | two pointer                                                 | :v:                 |
 | Remove Duplicates from Sorted Array II                 | :sweat:        | two pointer + condition                                     | :v:                 |
 | Remove Duplicate Letters                               | :sob:          | map/stack                                                   | :v: :eyes:          |
 | Merge Sorted Array                                     | Easy           | two pointer                                                 | :v:                 |
 | Product of Array Except Self                           | :sweat:        | left->right, then right->left                               | :v:                 |
 | Reverse Nodes in k-Group                               | :sob:          |                                                             |                     |
 | Implement strStr()                                     | Easy           |                                                             |                     |
 | Count and Say                                          | Easy           | iterative/recursive/deduction                               | :v:                 |
 | Pow(x, n)                                              | :sweat:        |                                                             |                     |
 | Sqrt(x)                                                | :sweat:        |                                                             |                     |
 | Add Bold Tags in String                                | :sweat: :eyes: | greedy to extend matched index, can also use merge interval |                     |
 | Encode/Decode Tiny Url                                 | :sweat:        | rand()/unordered_map                                        | :v: :eyes:          |
 | Simplify Path                                          | :sweat:        | last char not being '/' case                                | :v:                 |
 | Text Justification                                     | :sob:          | just deal with string corner case                           | :v:                 |
 | Add and Search Word – Data structure design            | :sweat:        | followup with star sign                                     | :v:                 |
 | Increasing Subsequence                                 | :sweat:        | dfs/set to deduplicate                                      | :v:          :eyes: |
 | Word Ladder                                            | :sweat:        | (double) bfs                                                | :eyes: :v:          |
 | Word Ladder II                                         | :sob:          | (double) bfs                                                | :eyes: :v:          |
 | Sum of Left Leaves                                     | Easy           | recursion/iterative                                         | :v: :eyes:          |
 | One Edit Distance                                      | :sweat:        | 3 cases, and combine for concise code                       | :v:                 |
 | Excel Sheet Column Title                               | Easy           | mod/division                                                | :v:                 |
 | Reverse Linked List                                    | Easy           |                                                             | :v:                 |
 | Maximum Length of Pair Chains                          | :sweat:        | sort by ending time then greedy                             | :eyes: :v:          |
 | Minimu Height Trees                                    | :sweat:        | bf timeout, use graph degree                                | :eyes: :v:          |
 | Diameter of Binary Tree                                | :sweat:        | what is needed to compute the path                          | :v:                 |
 | H-Index                                                | :sweat:        |                                                             |                     |
 | H-Index II                                             | :sweat:        |                                                             |                     |
 | Find the Celebrity                                     | :sweat:        | a knows b, a is not candidate; otherwise a is candidate     | :eyes::lock:        |
 | First Bad Version                                      | Easy           |                                                             |                     |
 | Inorder Successor in BST                               | :sweat:        | BST property, track last larger node                        | :eyes: :lock:       |
 | Binary Tree Vertical Order Traversal                   | :sweat:        | map/inorder recursion/queue iteration                       | :eyes: :lock:       |
 | Increasing Triplet Subsequence                         | :sweat:        | think hard, tricky                                          | :v: :eyes:          |
 | Design Tic Tac Toe                                     | :sweat:        | extra space to keep track of current status                 | :eyes: :lock:       |
 | Restore IP Address                                     | :sweat:        | recursion                                                   | :eyes: :v:          |
 | Intersection of Two Arrays I/II                        | Easy           | check follow up questions                                   | :eyes: :v:          |

## Other Leetcode
 | Problems                                    | Difficulty | Techniques                                              | Status        |
 | :-------------------------                  | :---:      | :----                                                   | :---:         |
 | Print Binary Tree                           | :sweat:    | find matrix size, then populate                         | :eyes: :v:    |
 | Find Mode in BST                            | :sweat:    | BST inorder is sorted                                   | :eyes: :v:    |
 | Add One Row to Tree                         | :sweat:    | recursion/iterative                                     | :v:           |
 | Find Bottom Left Tree Value                 | :sweat:    | inorder travesal                                        | :v:           |
 | Most Frequent Subtree Sum                   | :sweat:    | postorder travesal to capture subtree sum               | :v:           |
 | Binary Tree Tilt                            | Easy       | postorder sum and track                                 | :v:           |
 | Merge Two Binary Trees                      | Easy       | recursion                                               | :v:           |
 | Subtree of Another Tree                     | Easy       |                                                         | :v:           |
 | Convert BST to Greater Tree                 | Easy       | right-inorder-left traversal                            | :v:           |
 | Average of Levels in Binary Tree            | Easy       | level order (bfs with queue/dfs)                        | :v:           |
 | Larget Value in Each Tree Row               | Easy       | level order (bfs with queue/dfs)                        | :v:           |
 | Construct String From Binary Tree           | Easy       |                                                         | :v:           |
 | Binary Tree Upside Down                     | :sweat:    | think about recursive/iterative solution                | :eyes: :v:    |
 | Non-overlapping Intervals                   | :sweat:    | idea (which one to remove!)                             | :eyes: :v:    |
 | Find Right Interval                         | :sweat:    | lower bound function                                    | :v:           |
 | Data Stream as Disjoint Intervals           | :sob:      | vector vs bst using set, how to merge/insert            | :eyes: :v:    |
 | Range Module                                | :sob:      | treemap based/vector based/so many corner case          | :eyes: :v:    |
 | K Inverse Pair Array                        | :sob:      | dp formula                                              | :eyes: :v:    |
 | Single Element in Sorted Array              | :sweat:    | O(lgn) binary search, but how                           | :eyes: :v:    |
 | Number of Boomerangs                        | Easy       | brute force                                             | :v:           |
 | Numbers Disappeared in Array                | Easy       | no extra space, use array itself, switch or mark        | :v:           |
 | First Missing Positive                      | :sob:      | use array itself and index to store value               | :v:           |
 | Next Closest Time                           | :sweat:    | ways to formulate next cloest time, min to hour         | :eyes:        |
 | Longest Word in Dictionary through Deleting | :sweat:    |                                                         | :v:           |
 | Relative Ranks                              | Easy       | customized sorting                                      | :v:           |
 | Detect Capitals                             | Easy       |                                                         | :v:           |
 | Flatten Binary Tree                         | :sweat:    | recursion, think about iterative                        | :eyes: :v:    |
 | Max Width of Binary Tree                    | :sweat:    | BFS with queue (which stores node and index)            | :eyes: :v:    |
 | Permuation in String                        | :sweat:    | ideas same as sliding window                            | :v:           |
 | Smallest Range                              | :sweat:    | same ideas as minimum window string                     | :eyes: :v:    |
 | Maximal Gap                                 | :sweat:    | bucket sort idea, find bucket size and number of bucket | :eyes: :v:    |
 | Exclusive Time of Functions                 | :sweat:    | stack                                                   | :eyes: :v:    |
 | Elimination Game                            | :sweat:    |                                                         | :eyes: :v:    |
 | Top K Frequent Words                        | :sweat:    | think about how to define comparator                    | :v:           |
 | Top K Frequent Element                      | :sweat:    | 1. map+heap 2. bucket sort                              | :eyes: :v:    |
 | Equal Tree Partition                        | :sweat:    | node sum + corner case                                  | :eyes: :v:    |
 | Partition List                              | :sweat:    | two pointers                                            | :v:           |
 | Balanced Binary Tree                        | Easy       | 1. top-down 2. buttom up                                | :eyes: :v:    |
 | Surrounded Region                           | :sweat:    | from edge to dfs mark reachable cell                    | :eyes: :v:    |
 | Minimum Path Sum                            | :sweat:    | 2d dp with 1d store, initial value!                     | :eyes: :v:    |


## Sorting Algorithms
 | Problems                   | Difficulty     | Techniques                                                    |
 | :------------------------- | :---:          | :----                                                         |
 | Merge Intervals            | :sweat:        | customized sorting + max(end1, end2) when merge               |
 | Insert Interval            | :sob: :eyes:   | find overlapped intervals first, remove and insert            |
 | Meeting Rooms              | :v:            | easy/customized sorting lambda                                |
 | Meeting Rooms II           | :sweat:        | 1. greedy ideas using pq; 2. sweep line with two arrays       |
 | Wiggle Sort                | :sweat:        | equal sign, 1) sort then switch; 2) compare + switch          |
 | Wiggle Sort II             | :sweat: :eyes: | no equal sign, 1) sort then pick; 2) O(N) virtual indexing??? |


## Linked Lists
 | Problems                   | Difficulty | Techniques                |
 | :------------------------- | :---:      | :----                     |
 | Reverse Linked List        | Easy       | 1. iterative 2. recursive |


## Tree Basics
- `k-ary` tree: each node has no more than `k` children
- one type of question:
    - recursive call is to compute part of the result, and return the partial result
    - assemble partial results from left and right subtree, and keep track of the final result by passing a reference

 | Problems                                       | Difficulty     | Techniques                                                                   |
 | :-------------------------                     | :---:          | :----                                                                        |
 | Validate Binary Search Tree                    | :sweat: :v:    | track min/max for eachsubtree, beter than inorder traversal                  |
 | Binary Tree Level Order Traversal I/II         | :v:            |                                                                              |
 | Binary Tree PreOrder Travesal/Iterator         | :sweat:        | iterative/recursive (stack, print current, push right, then left)            |
 | Binary Tree InOrder Travesal/Iterator          | :sweat:        | iterative/recursive (stack, push left, print, get right to push and all left |
 | Binary Tree PostOrder Travesal/Iterator        | :sob: :eyes:   | iterative/recursive (stack, push non-null left/right, use parent push next)  |
 | Lowest Common Ancestor of a Binary Tree        | :sweat: :v:    | recursion                                                                    |
 | Lowest Common Ancestor of a Binary Search Tree | :v:            | use bst property                                                             |
 | Binary Tree Serialization/Deserialization      | :sweat:        | preorder-recursion/level-order iteration                                     |
 | N-ary Tree Serialization/Deserialization       | :sweat:        | same as binary, need delim to identify number of children for each node      |
 | BST Serialization/Deserialization (compact)    | :sweat:        | preorder-recursion with min/max threshold                                    |
 | Find Duplicate Subtrees                        | :sweat:        | serialize to deduplicate, make sure serialize once                           |
 | Find Leaves of Binary Tree                     | :sweat:        | bottom up to count the height                                                |
 | Binary Tree Maximum Path Sum                   | :sob:          | global var to track max                                                      |
 | Longest Univalue Path                          | :sob: :eyes:   | recursive call for single side longest path, then combine and track globally |
 | Count Univalue Subtree                         | :sweat:        | postorder                                                                    |
 | Path Sum I/II/III                              | :sweat:        | III needs more attention                                                     |
 | Sum of Root to Leave Number                    | :sweat:        | each deeper level, x10                                                       |
 | Binary Tree Paths                              | Easy           | dfs                                                                          |
 | Maximum Binary Tree                            | :sweat:        | recursion/iterative (think this)                                             |
 | Convert Sorted Array/List to BST               | :sweat:        | concise coding                                                               |
 | Convert BST to Double Linked List              | :sweat:        | think about the recursion                                                    |
 | Closest Binary Search Tree Value               | :v:            | BST                                                                          |
 | Closest Binary Search Tree Value II            | :sob: :eyes:   | heap/BST, predecessor/successor                                              |
 | Binary Tree Longest Consecutive Sequence       | :sweat:        | top-down or bottom-up to count, and track max length                         |
 | Binary Tree Longest Consecutive Sequence II    | :sweat:        | bottom-up to count left/right max inc/dec length                             |
 | Delete a Node in BST                           | :sweat: :eyes: | find key, then del, how? track parent, delNode                               |
 | Delete Nodes from tree, return forests         | :sweat: :eyes: | post order                                                                   |

## Trie
 | Problems                     | Difficulty | Techniques                                      |
 | :-------------------------   | :---:      | :----                                           |
 | Valid Word Square            | :v:        | brute force                                     |
 | Word Squares                 | :sob:      | dfs/trie                                        |
 | Implement Trie (Prefix Tree) | :sweat:    |                                                 |
 | Word Search II               | :sob:      |                                                 |
 | Match words from char stream | :sweat:    | sliding window + suffix trie, how AC algorithm? |

## Graph
### Must-knows
- traversal: bfs/dfs
- topological sorting
- shortest path: Dijkstra/Prim's
- A`*` algorithm

classical problems
- cycle detection
- number of connected component
- topological sorting, recover path (for directed graph only)
### Undirected Graph
- add edges for both directions when bulding adjancent list
- remember to break `parent/child` cycle (not a real cycle), erase from data structure, or pass a `pre` variable
- needs to use `visited` set to avoid multiple traversal
- bfs: make use of `degree` vector, but start from degree 1

### problems
- cycle detection
    - all nodes traversal
    - dfs/bfs/uf
- number of connected components
    - all nodes traversal
    - dfs/uf
- union find (only for undirected graph)

### Directed Graph
- add edges for only one direction, but dfs/bfs add in the reverse way
- dfs: most of `directed` graph have multiple connected components, so `visited` would store in/out of path states
- bfs: make use of `degree` vector, and start from 0 degree

#### classical problems
- cycle dectection
    - dfs: top level for loop, in the loop do dfs, `vector<int>` to track visited no cycle, or in the path, if while in the path, got visited again, cycle detected
    - bfs
- topological sorting
    - dfs/bfs
- all path from `src` to `dst`
    - dfs (w/o caching/memorization) to track path
- strongly connected components (SCC)
    - bfs with two passes, one for origial direction order, one for reversed direction order, starting from the same node
    - should start from degree 1 node, if there exists degree 0 node, it cannot be SCC

 | Problems                                       | Difficulty     | Techniques                                                                |
 | :-------------------------                     | :---:          | :----                                                                     |
 | (`undirected`) Graph Valid Tree                | :eyes: :sweat: | 1. no cycle; 2. one component; dfs/bfs/union find                         |
 | (`undirected`) Number of Connected Components  | :sweat:        | union find/dfs                                                            |
 | (`undirected`) Clone Graph                     | :sweat:        | clean dfs/bfs (avoid cycle)                                               |
 | (`undirected`) Minimum Height Trees            | :sweat:        | use degrees, start from leaf node                                         |
 | Merge Accounts                                 | :sweat:        | bfs/union find                                                            |
 | Redundant Connection                           | :sweat:        | union find: first same parent edge                                        |
 | (`undirected`) Evaluate Division               | :sweat:        | union find/dfs                                                            |
 | (`directed`) Course Schedule I                 | :sweat:        | dfs(cycle detection, in/out path state)/bfs(tricker, use degree)          |
 | (`directed`) Course Schedule II                | :eyes: :sweat: | dfs(push path when all dependency is checked)/bfs(tricker), path tracking |
 | (`directed`) Course Schedule III               | :sweat:        | greedy/replace longest (not graph)                                        |
 | Alien Dictionary                               | :eyes: :sob:   | order is DAG edges (topological sort)                                     |
 | (`directed`) All Path from Src to Target       | :sweat:        | dfs w/o memorization                                                      |
 | (`directed`) task with priority and dependency | :sweat:        | bfs with priority queue to break tie                                      |
 | Graph Is Bipartite                             | :sweat:        | bfs starts with a random node                                             |

## Backtracking

### common points
- code skeletons for backtracking
```cpp
// recursively call dfs twice w/o current element, no loop
// but deduplication is a bit tricker
void dfs(nums, id, path, res){
    // do not include
    dfs(nums, id+1, path, res);
    // do include
    path.push_back(nums[id]);
    dfs(nums, id+1, path, res);
    path.pop_back();
}
// better loop skeleton to add deduplication
// current loop include the element
// next loop pop back to backtrack previous state where the element is not included for next loop
// Time complexity: T(n) = T(n-1) + T(n-2) + ... + T(0)
// thus is O(2^n) exponential, since each recursive, has one less call
void dfs(nums, id, path, res) {
    for(int i = id; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        dfs(nums, i+1, path, res);
        path.pop_back();
    }
}

// deduplicate
void dfs(nums, id, path, res) {
    for(int i = id; i < nums.size(); ++i) {
        // obvious, in the following case, the element is included in the previous stack frame
        if(i > id && nums[i] == nums[i-1]) continue;
        path.push_back(nums[i]);
        dfs(nums, i+1, path, res);
        path.pop_back();
    }
}
```


 | Problems                          | Difficulty     | Techniques                                                                      |
 | :-------------------------        | :---:          | :----                                                                           |
 | Subsets                           | :sweat:        | recursion -> think about iterative                                              |
 | Subsets II                        | :sweat:        | recursion/deduplication                                                         |
 | Permutation                       | :sweat: :eyes: | 1) dfs with visited indication (different from subset) 2) swap recursion        |
 | Permutation II (with duplication) | :sweat: :eyes: | 1) dfs (with de-deuplication) 2) swap with deduplication                        |
 | Find Permutation                  | :sweat:        | inc order, than reverse des sequences                                           |
 | Beautiful Arrangement             | :sweat:        | permutatione and validate 1) dfs backtracking and validate 2) swap and validate |
 | Beautiful ArrangementII           | :sweat:        | rather than dfs/swap, enumerate distinct diffs, and stop when k is reached      |
 | Combination Sum I/II/III          | :sweat:        | dfs+backtracing                                                                 |
 | Partition Equal Subset Sum        | :sweat:        | recursion timout, dp to the rescue                                              |
 | Partition to k Equal Sum Subset   | :sweat:        | dfs recursion                                                                   |
 | Palindrom Partition               | :sweat:        |                                                                                 |
 | Word Search                       | :sweat:        | dfs                                                                             |

## Traversal
- dfs
- bfs
    - suitable for distance

 | Problems                                   | Difficulty   | Techniques                                                     |
 | :-------------------------                 | :---:        | :----                                                          |
 | The Maze                                   | :sweat:      | dfs/bfs similar                                                |
 | The Maze II                                | :sweat:      | dfs/bfs similar, has to try all paths                          |
 | The Maze III                               | :sob:        | keep track of path                                             |
 | Walls and Gates                            | :sweat:      | start from gates see how far it goes                           |
 | Shortest Distance from All Buildings       | :sob: :eyes: | bfs from building to sum up dist, validate from all in the end |
 | Longest Line of Consecutive Ones in Matrix | :sweat: :v:     | 4-dim dp/dfs                                                   |

## Stack
- monotonic stack (idea, can be a vector)
    - keep increasing/decreasing order
    - when decrease/increase, calculate width/info needed, and pop accordingly
    - push extra element to make sure stack is emptied in the end

 | Problems                       | Difficulty    | Techniques                                             |
 | :-------------------------     | :---:         | :----                                                  |
 | Trapping Rain Water  (3D)      | :sob:  :eyes: | ????                                                   |
 | Largest Rectangle in Histogram | :sob: :eyes:  | stack idea important                                   |
 | Next Greater Element I         | :sweat: :eye: | one loop to find all next greater element with stack   |
 | Next Greater Element II        | :sweat: :eye: | cycular array with duplicates + stack only store index |

## Number Formulation

 | Problems                   | Difficulty     | Techniques                                                                       |
 | :------------------------- | :---:          | :----                                                                            |
 | Maximum Swap               | :sweat:        | locate the last max char after non-decreasing seq                                |
 | Remove K Digits            | :eyes: :sweat: | try to maintain increasing digits order                                          |
 | Create Maximum Number      | :eyes: :sob:   | choose i digits from one array, merge (when two digits equal), vector comparison |
 | Next Greater Element III   | :sweat:        | digits comp, think!!                                                             |
 | Next Permutation           | :sweat:        | same with finding next greater number                                            |

## Top K Problem
- use `heap` (check how to declare `priority_queue`)

 | Problems                   | Difficulty | Techniques               |
 | :------------------------- | :---:      | :----                    |
 | Merge k Sorted Lists       | :v:        | min heap with dummy node |


## Dynamic Programming
- dp for each to find state transfer formula
    - for each `n`, it has limited `k` states, can enumerate all possible states `dp[n][k]`, e.g., paint house
- dp for two strings (match) of size `m` and `n`
    - recursive: exponential
    - dp(m+1, n+1): initialize first row and col for dp vector, then find state transfer formula
- dp for backpack problems
- come up with recursive solution (with memorization), and then convert to dp
- following the state transfer, record the previous state for the current state, we can get the optimal solution path
- minmax idea

```cpp
// template
// winner: dp[i][j] = max(nums[i] - dp[i+1][r], nums[i] - dp[i][j-1])
// guess number: dp[i][j] = min(dp[i][j], cost(k) + max(dp[i][k-1], dp[k+1][j])) for k in [i,j]
// burst ballon: dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]) for k in [i, j]
for(int l = n; l >= 1; --l) {
    for(int r = l; r <= n; ++r) {
        for(int k = l; k <= r; ++k) {
            dp[l][r] = max(dp[l][r],
                            dp[l][k - 1] + dp[k + 1][r] +
                                v[l - 1] * v[r + 1] * v[k]);
        }
    }
}
```

 | Problems                                             | Difficulty     | Techniques                                                    |
 | :-------------------------                           | :---:          | :----                                                         |
 | Edit Distance                                        | :sob:          | 2-dim dp / recursion (timeout)                                |
 | Wildcard Matching                                    | :sob:          | iterative with greedy; recursive (timeout); dp                |
 | Regular Expression Matching                          | :sob:          | hard&slow recursion/fast dp!!!                                |
 | Distince Subsequence                                 | :sob:          | dp                                                            |
 | Palindrom Partition II                               | :sob: :eyes:   | 1. dp 2. two-sided extending                                  |
 | Encode String With Shortest Length                   | :sob: :eyes:   | idea                                                          |
 | Word Break                                           | :sweat:        | dp                                                            |
 | Word Break II                                        | :sob: :eyes:   | dp/back tracking/prunning                                     |
 | Maximal Square                                       | :sweat:        | dp/find len of sides                                          |
 | Maximal Rectangle                                    | :sob:          | find width(histogram)/height                                  |
 | Longest Increasing Subsequence                       | :sweat:        | 1. dp O(n^2) 2. greedy, only replace with becomes small       |
 | Russian Doll Envelopes                               | :sob: :eyes:   | sort by first dim, and then find LIS                          |
 | Russian Doll Envelopes 3D                            | :sob: :eyes:   | sort 1 dim, and then use dp for rest two dim                  |
 | Triangle                                             | :sweat:        | bottom up dp                                                  |
 | Decode Ways                                          | :sweat:        | recursion(slow)/dp(cornor cases)                              |
 | Decode Ways II                                       | :sweat:        | with * decoded as 1-9                                         |
 | Paint Fence                                          | :eyes:         | idea tricker                                                  |
 | Paint House (2 colors)                               | :sob: :eyes:   |                                                               |
 | Paint House II (k colors)                            | :sob: :eyes:   | dp->no dp storage needed                                      |
 | Burst Balloons                                       | :sob: :eyes:   | recursion timeout; dp tricky: consider k as the last to burst |
 | Best Time to Buy and Sell Stock I/II                 | Easy           | greedy                                                        |
 | Best Time to Buy and Sell Stock III/IV               | :sob:          | local/global dp, sooo hard                                    |
 | Best Time to Buy and Sell Stock with Cooldown        | :sweat:        |                                                               |
 | Best Time to Buy and Sell Stock with Transaction Fee | :sweat:        | current state depends on previous state sell/hold             |
 | Flip Game II                                         | :sweat:        | both player try to win, player1 flip, and player2 fails       |
 | Predict the Winner                                   | :sob: :eyes:   | recursion/memorization/mini-max dp                            |
 | Guess Number Higher or Less                          | :sob: :eyes:   | recursion/memorization/mini-max dp                            |
 | Guess Secret Word (google question)                  | :sweat: :eyes: | min-max to choose the starting word                           |
 | Maximum Vacation Days                                | :sob: :eyes:   | dp to find the state transfer formula                         |
 | Perfect Squares                                      | :sweat:        | dynamic programming from 1 to t                               |  |
 | Ones and Zeros                                       | :sob:          | dp                                                            |
 | Combination Sum IV                                   | :sweat:        | dp (different from I/II/III)                                  |
 | Coin Change                                          | :eyes: :sweat: | loop over all amount and then all coins                       |
 | Coin Change II                                       | :eyes: :sweat: | loop over all coins, then all amount                          |
 | Coin Path                                            | :eyes: :sob:   | dp, and reconstruct path                                      |
 | Gas Station                                          | :sweat: :eyes: |                                                               |

## String
 | Problems                                               | Difficulty   | Techniques                                        |
 | :-------------------------                             | :---:        | :----                                             |
 | Valid Anagrams                                         | Easy         | sort/map                                          |
 | Group Anagrams                                         | :sweat:      | hash map/sort string                              |
 | Find All Anagrams in String                            | Easy         | sliding window template + map to track count      |
 | Minimum Window Substring                               | :eyes: :sob: | sliding window template + map/count to track      |
 | Minimum Window Subsequence                             | :eyes: :sob: | diff from above, keep order, bruteforce, dp       |
 | Longest subsring without repeating chars               | :sweat:      | sliding window template + map to index            |
 | Longest Substring with At Most K Distinct Characters   | :sob:        | sliding window template + map to rightmost index  |
 | Valid Parentheses                                      | Easy         | stack/non-stack counter solution                  |
 | Generate Parentheses                                   | :sweat:      | dfs to print parenthsis                           |
 | Remove Invalid Parentheses                             | :sob:        | count num to remove, then dfs                     |
 | Remove Invalid Parentheses (return one valid solution) | :sob:        | 1.two loops 2. one loop                           |
 | Different Ways to add parentheses                      | :sweat:      | divide and conqure                                |
 | Expression Add Operators                               | :sob:        | get first val, then (op, val) pair dfs            |
 | Longest Uncommon Subsequence I                         | Easy         |                                                   |
 | Longest Uncommon Subsequence II                        | :sweat:      | utility function to check sub sequence            |
 | Delete Operation for Two Strings                       | :sweat:      | longest common subsequence problem, diff from LIS |

## Recursion
- easy to identify recursive subproblems
- as go into the next recursive call, the index grows, thus `O(n)` time complexity

 | Problems                         | Difficulty   | Techniques                                                             |
 | :-------------------------       | :---:        | :----                                                                  |
 | Evaluate Reverse Polish Notation | :v:          | stack or recursion                                                     |
 | Basic Calculator                 | :sob:        | parenthesis only, recursive with O(n) or iterative with stack          |
 | Basic Calculator II              | :sob:        | only +-\*/, agg only with higher ops                                   |
 | Basic Calculator III             | :sob:        | support parenthesis and all four ops                                   |
 | Decode String                    | :sweat:      | O(n) with changing index, check how to encode str with shortest length |
 | Optimal Account Balance          | :sob: :eyes: | idea to construct the debit array and recursion                        |

### Palindromic Problems
- check `if size(s) < 2`, return `true`

 | Problems                         | Difficulty | Techniques                                          |
 | :-------------------------       | :---:      | :----                                               |
 | Valid Palindrome                 | Easy       | transform()/tolower()/isalnum()                     |
 | Valid Palindrome II              | Easy       | at most remove 1 char                               |
 | Palindrome Linked List           | Easy       | stack to store 1st half/reverse 2nd half            |
 | Palindrome Permutation           | Easy       |                                                     |
 | Palindrome Permutation II        | :sweat:    | find half, then know how to do permutation          |
 | Palindromic Substrings           | :sweat:    | dp, str end to front, double-sided expansion faster |
 | Longest Palindromic Sub sequence | :sweat:    | dp, back to front, find how to transfer states      |
 | Longest Palindromic Sub string   | :sweat:    | dp, but double-sided expansion is faster            |
 | Shortest Palindrome              | :sob:      |                                                     |
 | Palindrome Pairs                 | :sob:      |                                                     |


## Array
 | Problems                                   | Difficulty     | Techniques                                                                              |
 | :-------------------------                 | :---:          | :----                                                                                   |
 | Sparse Vector Multiplication               | :sweat:        | pair store, 1. two pointer 2. binary search 3. divide & conqure                         |
 | Sparse Matrix Multiplication               | :sweat:        | avoid multiplication when possible                                                      |
 | Rotate Array                               | Easy           | think at lease 3 ways                                                                   |
 | Search in Rotated Sorted Array             | :sweat:        | decide which part is sorted, then choose direction                                      |
 | Search in Rotated Sorted Array II          | :sweat:        | only start/end equal affects it, how to break this                                      |
 | Find Min in Rotated Sorted Array           | :sweat:        | early stop if sorted                                                                    |
 | Find Min in Rotated Sorted Array II        | :sweat:        | how to break start/mid/end are equal                                                    |
 | Sort Colors                                | :sweat:        | two pointer/two side to middle                                                          |
 | Contiguous Array                           | :sweat:        | hash map/presum idea/store mod                                                          |
 | Two Sum                                    | Easy           | hashmap/two pointer                                                                     |
 | Two Sum II – Input array is sorted         | Easy           | two pointer to squeeze                                                                  |
 | Two Sum III – Data structure design        | Easy           | hashmap/multiset                                                                        |
 | Two Sum in BST                             | Easy           | inorder to form sorted array, two pointer                                               |
 | 3Sum                                       | :sweat:        | two pointer/de-duplicate                                                                |
 | 3Sum Closest                               | :sweat:        | two pointer/de-dupicate                                                                 |
 | 3Sum Smaller                               | :sweat:        | two pointer                                                                             |
 | Target Sum                                 | :sweat:        | 1. recursion 2. dp to cache                                                             |
 | Continuous Subarray Sum                    | :sweat:        | hash map/(a-c)%b==0/cornercase                                                          |
 | Maximum Subarray                           | :v:            | dp/think about divide & conqure                                                         |
 | Maximum Subrectangle Sum                   | :eyes: :sob:   | 2d maximum subarray, how to convert to 1d problems                                      |
 | Max Sum of Rectangle No Greater Than K     | :eyes: :sob:   | idea: max sum of sub rectangle + lower bound  of diff                                   |
 | Maximum Averate Subarray                   | Easy           | equals to find maximum sum of fixed size                                                |
 | Maximum Averate Subarray II                | :eyes: :sob:   | binary search in solution space + O(n) existence check                                  |
 | Maximum Sum of 3 Non-overlapping Subarrays | :eyes: :sob:   | presum, fix middle subarray, dp to cache left/right max                                 |
 | Minimum Size Subarray Sum                  | :sweat:        | two pointer find range, then reduce range, analyze why O(n)                             |
 | Maximum Size Subarray Sum Equals k         | :sweat:        | hash map/idea                                                                           |
 | Subarray Sum Equals k                      | :sweat:        | hash map/idea, initialization issue                                                     |
 | Subarray Prod Less Than k                  | :sweat:        | idea                                                                                    |
 | Shortest Unsorted Continuous Subarray      | :eyes:  Easy   | find the disordered index boundary                                                      |
 | Split Array into Consecutive Sequence      | :eyes: :sweat: | array sorted, greedy idea                                                               |
 | Longest Consecutive Sequence               | :sob:          | think differently  (linear solution)                                                    |
 | Longest Continuous Increasing Subsequence  | Easy           | basic array operation                                                                   |
 | Number of Longest Increasing Subsequence   | :eyes: :sweat: | dp to record maxlen up to i, another vec to record count                                |
 | Non-decreasing Array                       | :eyes: Easy    | find patterns to modify the number depends on three numbers                             |
 | Maximum Product of Three Numbers           | :v:            | sort and  not sort solution                                                             |
 | Majority Element                           | :v:            | cancel out                                                                              |
 | Majority Element II                        | :eyes: :sweat: | extend to n/k case                                                                      |
 | Find Duplicate Number (w/o modification)   | :sweat: :eyes: | 1) O(n^2) 2) set 3) binary search in value space O(Nlg(N)) 4) slow/fast cycle detection |

## Kth problem
- when locating `k`-th, binary first find the solution boundary, and then do binary search in the solution space might help
- in such cases `<k` definitely can move solution; `>=k' is not enough to return the result

 | Problems                                     | Difficulty | Techniques                                                 |
 | :-------------------------                   | :---:      | :----                                                      |
 | Kth Largest Element in an Array              | :sweat:    | quick select to narrow search space/heap, analyze k vs n/2 |
 | Kth Smallest Element in a BST                | :sweat:    | iterative/recursive                                        |
 | Kth Smallest Element in a sorted matrix      | :sweat:    | 1. heap 2. value (not index) binary search+ cnt            |
 | Kth Smallest Element in Multiplication Table | :sob:      | same as sorted matrix                                      |
 | Find K Closest Elements                      | :sweat:    |                                                            |
 | Find K Pairs with Smallest Sum               | :sweat:    | heap idea                                                  |
 | Find Kth Smallest Pair Distance              | :sob:      | find dist boundary, and then binary search                 |

## Iterator
  | Problems                     | Difficulty     | Techniques                                                |
  | :-------------------------   | :---:          | :----                                                     |
  | Peeking Iterator             | :sweat:        | store peeked value and isPeek flag                        |
  | Flatten Nested List Iterator | :eyes: :sweat: | use stack to track,  hasNext promote pointers             |
  | Zigzag Iterator              | :eyes: :sweat: | extend to k array, use queue to record begin/end iterator |
  | Binary Search Tree Iterator  | :sweat:        | inorder iterative impl                                    |

## Binary Search
 | Problems                   | Difficulty | Techniques                          |
 | :------------------------- | :---:      | :----                               |
 | Find Peak Element          | :sweat:    | how to move to the next iteration   |
 | Search a 2D Matrix         | :sweat:    | binary search, location conversion  |
 | Search a 2D Matrix II      | :sweat:    | find correct starting location      |
 | Diagonal Traversal         | :sweat:    | flip directions when meets boundary |
 | Valid Perfect Square       | :v:        | binary search in the domain space   |

## Two Pointers

 | Problems                   | Difficulty     | Techniques                                          |
 | :------------------------- | :---:          | :----                                               |
 | Sort Transformed Array     | :sweat: :eyes: | two pointer from side to middle                     |
 | Trapping Rain Water        | :sob:  :eyes:  | monotonic decreasing stack of indices / two pointer |


## Math
- `prime` number: a `natural number` greater than 1, and cannot be formed by multiplying two smaller natural number
    - heuristic to check up to `sqrt(n)` + `Sieve of Eratosthenes` to filter
- `composite` number: all `natural` numbers that are not 1 and not `prime` number
- 1 is not a `prime` number, nor is it a `composite` number

 | Problems                              | Difficulty | Techniques                                                          |
 | :-------------------------            | :---:      | :----                                                               |
 | get next prime/find all prime up to n | :sweat:    | 1. check multiplier to to sqrt(n); 2. exclude number multiple prime |
 | Multiply Strings                      | :sweat:    | reverse/quicker sol to add to the right bucket                      |

## Bits Manipulation
 | Problems                   | Difficulty | Techniques                                                                  |
 | :------------------------- | :---:      | :----                                                                       |
 | Hamming Distance           | Easy       | clear right most left 1                                                     |
 | Number of 1 in binary form | :eyes:     | keep clear right most 1 bit by n&(n-1), and ++cnt                           |
 | Total Hamming Distance     | :sweat:    | vertical 1s, combination                                                    |
 | Power of Two               | :v:        | only one non-zero bit, minus 1 check or rotate check                        |
 | Power of Three             | :eyes:     | logarithm `(log10(n)-log10(3))`, then check if it is integer                |
 | Power of Four              | :eyes:     | power of 2, and minus 1 dividable by 3, or the only bit on certain position |

## Data Structure Design
- `std::list` is implemented as a `double linked list`, so `prev/next` operation is `O(1)`
- `std::list` does not have member function of `prev` or `next`, and cannot perform pointer change

 | Problems                   | Difficulty | Techniques                   |
 | :------------------------- | :---:      | :----                        |
 | LRU Cache                  | :sob:      | double linked list/map  O(1) |
 | LFU Cache                  | :sob:      | double linked list/map  O(1) |
 | Min Stack                  | :v:        |                              |
 | Max Stack                  | :sob:      |                              |

## Island Problems
- `pair<int,int>` comparison is defined in stl as `p1.first < p2.first || (!(p1.first > p2.first) && p1.second < p2.second)`
- 'vecotr<int>` comparison is defined to compare each element, if all the same, the one with shorter length is smaller
- transform an image, is to transform all the points in the image (rotate 90/180/270 degrees, leftright/updown reflect)
- given point `(x,y)`, all transforms can results in 8 different representations, pick one as its intrinsic representation

 | Problems                      | Difficulty     | Techniques                                      |
 | :-------------------------    | :---:          | :----                                           |
 | Nnumber of Islands            | :v:            | dfs/marking                                     |
 | Number of Islands II          | :eyes: :sweat: | union find + pass compression                   |
 | Nnumber of Distinct Islands   | :eyes: :sweat: | use vector of pairs to store normalized island  |
 | Number of Distinct Islands II | :eyes: :sob:   | how to represent intrinct island                |
 | Island Perimeter              | :eyes: :v:     | just loop, no need to use dfs, side deduplicate |
 | Perfect Rectangle             | :sob: :eyes:   | criteria: area, and point reuse check           |


## Range Sum
 | Problems                     | Difficulty   | Techniques             |
 | :-------------------------   | :---:        | :----                  |
 | Range Sum Query 2D – Mutable | :eyes: :sob: | 2d binary indexed tree |
 | Range Sum Query 1D – Mutable | :eyes: :sob: | 1d binary indexed tree |

## Sampling

### modulo bias with `rand() % n`
- `rand()` generates uniformly distributed int in the range `[0, RAND_MAX]`
- `RAND_MAX` is library dependent, but usually equals to `32767`
- `rand() % n` is not uniformly distributed, if the modulo is non-zero, i.e., `(RAND_MAX+1) % n != 0`
- it introduces bias toward smaller numbers
- the bias is larger if the range `n` is larger
- to make it uniformly distributed

```cpp
int method1(int mi, int mx) {
    int n = mx - mi + 1;
    double x = RNAD_MAX + 1;
    return (rand() / x) * n + mi;
}

int method2(int mi, int mx) {
    int n = mx - mi + 1;
    int rlimit = RADN_MAX - RAND_MAX % n;

    // ignore random generated number that exceeds the limit
    int x = rand();
    while(true) {
        if(x < rlimit) break;
        x = rand();
    }
    return x % n + mi;
}
```

### sweep line
 | Problems                    | Difficulty     | Techniques                                                        |
 | :-------------------------  | :---:          | :----                                                             |
 | The Skyline Problem         | :sob:          | sweep line to track/update heights at start/end points (multiset) |
 | Number of Corner Rectangles | :sweat: :eyes: | brute force/loop and fix two rows optimization                    |


### reservoir sampling
given online stream of numbers, make sure probably for each number gets selected is the same.
idea: keep the first number, then with probability `1/i` to select the `i-th` number

```cpp
int random(vector<int>& nums) {
    int x = -1;
    for(int i = 0; i < nums.size(); ++i) {
        // 1/(i+1) possibility to replace
        if(rand() % (i+1) == 0) {
            x = nums[i];
        }
    }
    return x;
}
```

 | Problems                                    | Difficulty     | Techniques             |
 | :-------------------------                  | :---:          | :----                  |
 | Linked List Random Node                     | :sweat:        | reservoir sampling     |
 | Random Pick Index                           | :eyes: :sweat: | reservoir sampling     |
 | Insert Delete GetRandom O(1)                | :sweat:        | combine map and vector |
 | Insert Delete GetRandom O(1) with duplicate | :sweat:        | combine map and set    |
 | Weighted Random Number                      | :eyes: :sweat: |                        |
 | Get Random Point from rectangles            | :eyes: :sweat: |                        |
