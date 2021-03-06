# Final Project Goals

### Leading Question
Our central goal for this project is to develop a program that can compute and store the Erdos number for any mathematical professor. We will do this by implementing a graph that stores all the people who have published mathematical papers, and then use this graph to search for specific people. This will involve a solid dataset of mathematical papers and a foundational understanding of the tree/graph data structure. We will rank mathematicians on their proximity to Erdos based on their Erdos number and the number of papers that they have written with Erdos.

### Dataset Acquisition and Processing
For this project, we plan to use the data set from Oakland University database of coauthors of Erdos. For example: https://oakland.edu/enp/thedata/erdos0/ is a list of authors who have written a paper with Erdos himself, along with the date of the first publication and the number of collaborations (if more than 1). We hope to use this data set to create a search tree on which we plan to implement  BFS and path finding algorithms to find erdos numbers of required mathematicians. This data set will help us find the Erdos number, the date of the publication and also the number of publications they have had with Erdos and/or other mathematicians. We will convert the data to VScode and hope to build various data structures such as graphs to help achieve the goal of the project. The constructor takes in two csv files as the input. One of the csv contains all the names for the graph. The other csv contains the number of publication for a subset of all mathematicians. The constructor has the run time of O(t), where t is the number of names inside the Erdos.csv.

### Graph Algorithms
We are planning to be covering the Breadth First Search Algorithm. The Breadth First Search Algorithm will take in a directed/undirected graph with unweighted edge weights (or edge weights of 1) and gives a path as an output through the graph. Because we are using the data set from https://oakland.edu/enp/thedata/, we predict that all of the edge weighted and decided based on the number of publications the person had with Erdos, the nodes of the graph will contain information of the name of the author as well as pointers to other nodes that have been co-authors of the same node. Two nodes are connected when they are co-authors to a paper. The BFS will have a run time of O(n + m). (n is the number of total vertices, whereas m is the number of total edges)

For one of our algorithms, we propose implementing Kruskal's Algorithm. This will be a class method and will return a vector of edges that connect a Minimum Spanning Tree. One can use this vector of Edges and the Vertices of the graph to construct a Kruskal Minimum Spanning Tree. This running time of the Kruskal Minimum Spanning Tree Algorithm should be O(n + mlog(n) + m) if it was implemented using a sorted array; n to build the disjoint set, mlog(n) build and sort the array; m to remove edges. (n is the number of total vertices, whereas m is the number of total edges)

For our final algorithm, we are planning on implementing a visualization algorithm presented by Kobourov: Barycentric method. source- http://cs.brown.edu/people/rtamassi/gdhandbook/chapters/force-directed.pdf The expected output would be a position vector for each vertex and we would then project it onto a PNG. We are hoping to use this visualization algorithm to project the Kruskal minimum spanning tree onto a PNG. The total running time of the visualization algorithm should be O(n^3). (n is the number of total vertices)


### Tentative Timeline
- (Week of 5th April)    Data acquisition
- (Week of 5th April)    Data procession
- (Week of 12th April)  Project framework set up (variables, constructor, destructor, etc.)
- (Week of 12th April)  BFS implementation and testing
- (Week of 19th April)  Mid-Project check in
- (Week of 19th April)  First graph algorithm implementation and testing
- (Week of 26th April)  Second graph algorithm implementation and testing
- (Week of 3rd May)    Final Testing
- (Week of 3rd May)    Production of Final write-up 
- (Week of 3rd May)    Final presentation preparation
- (May 12th due)          Final Project submission
