#include "cs4050.h"
#include "Bellman-Ford.h"
#include "Util.h"

#include <float.h>
#include <stdio.h>

//Pseudocode from book
//FOREACH node v contained in V:
//    M[0,v] <- INFINITY
//M[0,t] <- 0
//FOR i = 1 to n-1
//    FOREACH node v contained in V
//        M[i,v] <- M[i-1,v]
//        FOREACH edge(v,w) contained in E
//            M[i,v] <- min { M[i,v], N[i-1, w] + LAMBDAvw



void ShortestPaths(
    Vertex * V, int countV,
    Edge * E, int countE,
    int t,
    float d[],
    int successor[])
{
    int previous[countV];
    int update[countV];

    for(int v = 0; v < countV; v++)
    {
        d[v] = FLT_MAX;
        successor[v] = -1;

        previous[v] = 0;
        update[v] = 0;

    }

    d[t] = 0;
    previous[t] = 1;


    for(int i = 1; i < countV; i++)
    {
        for(int w = 0; w < countV; w++)
        {
            if(previous[w] == 1)
            {
                for(int e = 0; e < countE; e++)
                {
                    if(E[e].to - 1 == w)
                    {
                        if(d[E[e].from - 1] > d[w] + E[e].weight)
                        {
                            d[E[e].from - 1] = d[w] + E[e].weight;
                            successor[E[e].from - 1] = w;
                            update[E[e].from - 1] = 1;
                        }

                    }
				}


            }

        }
        for(int i = 0; i < countV; i++)
        {
            previous[i] = update[i];
            update[i] = 0;
        }

    }

}
