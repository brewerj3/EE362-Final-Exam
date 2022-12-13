#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define NUMNODES 6

struct node {
    int id;
    struct node *next;
};

struct node **createAdjList(int n) /* Create adjacency list of n nodes */
{
    struct node **adjList = (struct node **) malloc(sizeof(struct node *) * n);
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
    return adjList;
}

void destroyAdjList(struct node **adjList, int n) {
    struct node *p;
    struct node *temp;
    for (int i = 0; i < n; i++) {
        for (p = adjList[i]; p != NULL;) {
            temp = p;
            p = p->next;
            free(temp);
        }
    }
    free(adjList);
}

struct node *createNode(int n) {
    struct node *i = (struct node *) malloc(sizeof(struct node));
    i->id = n;
    i->next = NULL;
    return i;
}

struct node **insertLink(int i, int j, struct node **adjList) {
    struct node *temp = adjList[i];
    adjList[i] = createNode(j);
    adjList[i]->next = temp;
    return adjList;
}

struct node **createGraph1() {
    struct node **graph1 = createAdjList(NUMNODES);
    graph1 = insertLink(1, 2, graph1);
    graph1 = insertLink(1, 3, graph1);
    graph1 = insertLink(3, 2, graph1);
    graph1 = insertLink(3, 0, graph1);
    graph1 = insertLink(2, 5, graph1);
    graph1 = insertLink(2, 0, graph1);
    graph1 = insertLink(0, 5, graph1);
    graph1 = insertLink(0, 4, graph1);
    graph1 = insertLink(5, 4, graph1);
    return graph1;
}

void displayList(struct node *list) {
    for (struct node *p = list; p != NULL; p = p->next) {
        printf("->%2d ", p->id);
    }
    printf("\n");
}

int findIndegree(struct node **adjList, int nodeID, int arraySize) {
    int indegree = 0;
    for (int i = 0; i < arraySize; i++) {
        struct node *temp = adjList[i];
        while (temp != NULL) {
            if (temp->id == nodeID) {
                indegree++;
            }
            temp = temp->next;
        }
    }
    return indegree;
}

int summArray(const int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + array[i];
    }
    return sum;
}

struct node *topsort(struct node **adjList, int n) {
    struct node *head = createNode(-1);                          // Return this when done.
    int indegreeArray[n];                                           // Create Array of indegrees.
    for (int i = 0; i < n; i++) {
        indegreeArray[i] = findIndegree(adjList, i, n);
    }
    int firstHead = 0;
    while (summArray(indegreeArray, n) > n*-1) {
        // Find the zero indegree
        int zeroIndegree = 0;
        for (int i = 0; i < n; i++) {
            if (indegreeArray[i] == 0) {
                zeroIndegree = i;
                break;
            }
        }

        printf("\n\n");
        for (int i = 0; i < n; i++) {
            printf("indegreeArray[%i] = %i\n", i, indegreeArray[i]);    // Print indegree array for debugging
        }

        // Insert zero indegree struct into sorted list
        struct node *temp = adjList[zeroIndegree];
        while (temp != NULL) {
            indegreeArray[temp->id]--;    // Decrement the indegrees pointed too by adjList[zeroIndegree]->next
            temp = temp->next;
        }

        indegreeArray[zeroIndegree] = -1;   // remove the zeroindegree from the array

        // Add the zeroIndegree to the sortedList
        if (firstHead == 0) {
            head->id = zeroIndegree;
            firstHead = 1;
        } else {
            struct node *pNode = head;
            while (pNode->next != NULL) {
                pNode = pNode->next;
            }
            pNode->next = createNode(zeroIndegree);
        }
    }

    return head;
}


void displayAdjList(struct node **adjList, int n) {
    struct node *p;
    for (int i = 0; i < n; i++) {
        printf("%2d:", i);
        for (p = adjList[i]; p != NULL; p = p->next) {
            printf("->%2d", p->id);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    struct node **graph1 = createGraph1();
    printf("Adjacency list of graph 1\n");
    displayAdjList(graph1, NUMNODES);

    printf("Topologically sorted list ");

    struct node *list = topsort(graph1, NUMNODES);
    displayList(list);

    destroyAdjList(graph1, NUMNODES);
}

