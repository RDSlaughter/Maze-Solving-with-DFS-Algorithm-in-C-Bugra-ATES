
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int Array[19][19];
char letters[19] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','X','Z'};
bool visited[19];
int countStep = 1;

void DFS(int root, bool visited[])
{
    int i;

    visited[root] = true;
    
    if(letters[root] == 'X')
    {
    	printf("\n\n %d. \tStep |  Index : %d \tLetter : %c  ==> ROOT ", countStep,root,letters[root]);
         countStep++ ;
	}
	else
	{
	    printf("\n\n %d. \tStep |  Index : %d \tLetter : %c ", countStep,root,letters[root]);
        countStep++ ;
	}


    for( i = 0; i < 19; i++)
    {
        if(Array[root][i] == 1 && visited[i] == false)
        {
            DFS(i, visited);
        }
    }
       if(letters[root] == 'Z')
        {
        	printf("\n\n\n Maze solved in %d steps (%c), reached to exit point.",countStep-1,letters[root]);
        	printf("\n\n DFS Algorithm is continuing to travel the remaining nodes...\n");
		}
}
 
void readMatrix()
{
    int i = 0;
    FILE *fp = fopen("matrix.txt", "r");
 
    while(fscanf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                 &Array[i][0],
                 &Array[i][1],
                 &Array[i][2],
                 &Array[i][3],
                 &Array[i][4],
                 &Array[i][5],
                 &Array[i][6],
                 &Array[i][7],
                 &Array[i][8],
                 &Array[i][9],
                 &Array[i][10],
                 &Array[i][11],
                 &Array[i][12],
                 &Array[i][13],
                 &Array[i][14],
                 &Array[i][15],
                 &Array[i][16],
                 &Array[i][17],
                 &Array[i][18]
                 
                 ) != EOF)
    {
        i = i + 1 ;
    }
}
 
int main()
{
	for(int i=0 ; i<19 ;i++)
	{
		visited[i] = false ;
	}
 
    readMatrix();
    DFS(17, visited);
    return 0;
}
