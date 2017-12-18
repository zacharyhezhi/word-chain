//
//  main.c
//  ass2
//
//  Created by 贺植 on 2017/10/9.
//  Copyright © 2017年 贺植. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "queue.h"
#include "Graph.h"
#include "stack.h"

#define MAX_ARRAY_SIZE 1005
//#define INF 99999999

/**
 * task1, time complex is O(n^2), because it's double loop to find the connection
 * task2, time complex is O(n^3), because it's a floyd algorithm.
 * Floyed algorithm loop 3, so the time complex is O(n^3)
 */

int n;
char word[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE]={0};

#define MAX_NODES 1000

int visited[MAX_NODES];  // array to store visiting order
// indexed by vertex 0..nV-1

bool dfsPathCheck(Graph g, int nV, Vertex v, Vertex dest) {
    Vertex w;
    for (w = 0; w < nV; w++)
        if (adjacent(g, v, w) && visited[w] == -1) {
            visited[w] = v;
            if (w == dest)
                return true;
            else if (dfsPathCheck(g, nV, w, dest))
                return true;
        }
    return false;
}

bool findPathDFS(Graph g, int nV, Vertex src, Vertex dest) {
    Vertex v;
    for (v = 0; v < nV; v++)
        visited[v] = -1;
    visited[src] = src;
    return dfsPathCheck(g, nV, src, dest);
}




/*int floyd[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE]={0};

int max(int i,int j)
{
    return i>j ? i:j;
}

int edit_a_char(char a[],char b[])
{
    int sum=0;
    if(strlen(a)==strlen(b))
    {
        int i;
        for(i=0;i< max((int)strlen(a), (int)strlen(b));i++)
        {
            if(a[i]!=b[i])
            {
                sum++;
                if(sum>1)
                    return 0;
            }
        }
        return sum==1;
    }
    return 0;
}
*/

 int CompareTwoWords(char word1[], char word2[]){
    int len1 = (int)strlen(word1);
    int len2 = (int)strlen(word2);
    if (abs((int)(len1-len2)) > 1){ //if more than two,prove false
        return 0;
    }
    
    //if equal
    if (len1 == len2){
        int pos = 0;
        int i;
        for (i = 0; i < len1; i++){
            if (word1[i] != word2[i]){
                pos = i;
                int j;
                for (j = pos + 1; j < len1; j++){
                    if (word1[j] != word2[j]){
                        return 0;
                    }
                }
                break;
            }
        }
    }
    
    //if left for one char distance,for code length,deal with something
    else{
        char str_large[20], str_small[20];
        if (len1 > len2){
            strcpy(str_large, word1);
            strcpy(str_small, word2);
        }
        else if (len1 < len2){
            strcpy(str_large, word2);
            strcpy(str_small, word1);
        }
        int i;
        for (i = 0; i < strlen(str_small); i++){
            if (str_small[i] != str_large[i]){
                int pos = i;
                int j;
                for (j = pos; j < strlen(str_small); j++){
                    if (str_small[j] != str_large[j + 1]){
                        return 0;
                    }
                }
                break;
            }
        }
    }
    return 1;
}


/*
int add_a_char(char a[], char b[])
{
    if(strlen(a)+1==strlen(b))
    {
        int i;
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]!=b[i])
                break;
        }
        for(;i<strlen(a);i++)
        {
            if(a[i]!=b[i+1])
                return 0;
        }
        return 1;
    }
    return 0;
}

int remove_a_char(char a[],char b[])
{
    if(strlen(a)==strlen(b)+1)
    {
        int i;
        for(i=0;i<strlen(b);i++)
        {
            if(a[i]!=b[i])
                break;
        }
        for(;i<strlen(b);i++)
        {
            if(a[i+1]!=b[i])
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int res[MAX_ARRAY_SIZE];
int maxlen=INF;

void print()
{
    printf("%s",word[res[0]]);
    for(int i=1;i<-1*maxlen;i++)
    {
        printf(" -> %s",word[res[i]]);
    }
    printf("\n");
}

void search(int start,int end)
{
    res[floyd[start][end]*(-1)]=end;
    if(start==end)
    {
        print();
        return;
    }
    for(int k=0;k<n;k++)
    {
        if(floyd[start][end]==floyd[start][k]-1 && floyd[k][end]==-1)
        {
            search(start,k);
        }
    }
}
*/

int main(void) {

    printf("Enter a number: ");
    scanf("%d",&n);
    Graph SearchGraph = newGraph(n);
    Edge SearchEdge;
    stack Searchstack = NULL;
    for(int i=0;i<n;i++)
    {
        printf("Enter word: ");
        scanf("%s",word[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%s: ",word[i]);
        for(int j=i+1;j<n;j++)
        {
            if(CompareTwoWords(word[i], word[j]))
                printf(" %s",word[j]);
                SearchEdge.v = i;
                SearchEdge.w = j;
                insertEdge(SearchGraph, SearchEdge);
        }
        printf("\n");
    }
    
    for(int src=0; src<n; src++)
        for(int dest=src+1;dest<n;dest++)
        {
            if (findPathDFS(SearchGraph, n, src, dest)) {
                Vertex v = dest;
                while (v != src) {
                    printf("%d - ", v);
                    Stackpush(Searchstack, v);
                    v = visited[v];
                }
                printf("%d\n", src);
                StackPush(Searchstack, src);
            }
        }
    
    while(!StackIsEmpty(Searchstack))
    {
        Vertex m  = StackPop(Searchstack);
        printf("%d - ", m);
    }
    }
    /*
        for(int j=0;j<n;j++)
        {
            floyd[i][j]=INF;
        }
    }
    printf("\n");
    
    for(int i=0;i<n;i++)
    {
        floyd[i][i]=0;
        printf("%s:",word[i]);
        for(int j=i+1;j<n;j++)
        {
            if(CompareTwoWords(word[i],word[j]))
            {
                floyd[i][j]=-1;
                printf(" %s",word[j]);
            }
        }
        printf("\n");
    }
    
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(floyd[i][j]>floyd[i][k]+floyd[k][j])
                {
                    floyd[i][j]=floyd[i][k]+floyd[k][j];
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(maxlen>floyd[i][j]-1)
            {
                maxlen=floyd[i][j]-1;
            }
        }
    }
    printf("\n");
    printf("Maximum chain length: %d\n",-1*maxlen);
    printf("Maximal chains:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(maxlen==floyd[i][j]-1)
            {
                search(i,j);
            }
        }
    }
    return EXIT_SUCCESS;
}
*/
