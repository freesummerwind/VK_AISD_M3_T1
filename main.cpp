#include<vector>
#include<queue>
#include<cassert>

#include"IGraph.h"
#include"ListGraph.h"
#include"MatrixGraph.h"
#include"SetGraph.h"
#include"ArcGraph.h"

std::vector<int> BFS( const IGraph& graph, int vertex )
{
    std::vector<bool> visited( graph.VerticesCount(), false );
    std::vector<int> result;
    std::queue<int> bfsQ;
    bfsQ.push( vertex );
    visited[vertex] = true;
    while( bfsQ.size() > 0 ) {
        int current = bfsQ.front();
        bfsQ.pop();
        result.push_back( current );
        std::vector<int> adjList = graph.GetNextVertices( current );
        for( int i = 0; i < adjList.size(); ++i ) {
            if( !visited[adjList[i]] ) {
                bfsQ.push( adjList[i] );
                visited[adjList[i]] = true;
            }
        }
    }
    return result;
}

void testGraphs()
{
    IGraph* listGraph = new ListGraph(8 );
    listGraph->AddEdge(0, 1 );
    listGraph->AddEdge(0, 4 );
    listGraph->AddEdge(1, 2 );
    listGraph->AddEdge(1, 3 );
    listGraph->AddEdge(2, 5 );
    listGraph->AddEdge(3, 0 );
    listGraph->AddEdge(3, 4 );
    listGraph->AddEdge(3, 2 );
    listGraph->AddEdge(4, 6 );
    listGraph->AddEdge(5, 3 );
    listGraph->AddEdge(6, 3 );
    listGraph->AddEdge(6, 5 );
    listGraph->AddEdge(6, 7 );
    listGraph->AddEdge(7, 5 );
    {
        // listGraph
        {
            // test1.1 BFS
            std::vector<int> bfsResult = {7, 5, 3, 0, 4, 2, 1, 6};
            std::vector<int> listResult = BFS(*listGraph, 7);
            assert(bfsResult.size() == listResult.size());
            for (int i = 0; i < bfsResult.size(); ++i) {
                assert(bfsResult[i] == listResult[i]);
            }
        }
        {
            // test1.2 prevVertices
            std::vector<int> prev3 = {1, 5, 6};
            auto listResult = listGraph->GetPrevVertices( 3 );
            assert(prev3.size() == listResult.size());
            for (int i = 0; i < prev3.size(); ++i) {
                assert(prev3[i] == listResult[i]);
            }
        }
        {
            // test1.3 nextVertices
            std::vector<int> next6 = {3, 5, 7};
            auto listResult = listGraph->GetNextVertices( 6 );
            assert(next6.size() == listResult.size());
            for (int i = 0; i < next6.size(); ++i) {
                assert(next6[i] == listResult[i]);
            }
        }
    }
    {
        // matrixGraph
        MatrixGraph matrixGraph( *listGraph );
        {
            // test2.1 BFS
            std::vector<int> bfsResult = {7, 5, 3, 0, 2, 4, 1, 6};
            std::vector<int> matrixResult = BFS(matrixGraph, 7);
            assert(bfsResult.size() == matrixResult.size());
            for (int i = 0; i < bfsResult.size(); ++i) {
                assert(bfsResult[i] == matrixResult[i]);
            }
        }
        {
            // test2.2 prevVertices
            std::vector<int> prev3 = {1, 5, 6};
            auto matrixResult = matrixGraph.GetPrevVertices( 3 );
            assert(prev3.size() == matrixResult.size());
            for (int i = 0; i < prev3.size(); ++i) {
                assert(prev3[i] == matrixResult[i]);
            }
        }
        {
            // test2.3 nextVertices
            std::vector<int> next6 = {3, 5, 7};
            auto matrixResult = matrixGraph.GetNextVertices( 6 );
            assert(next6.size() == matrixResult.size());
            for (int i = 0; i < next6.size(); ++i) {
                assert(next6[i] == matrixResult[i]);
            }
        }
    }
    {
        // setGraph
        SetGraph setGraph( *listGraph );
        {
            // test3.1 BFS
            std::vector<int> bfsResult = {7, 5, 3, 0, 2, 4, 1, 6};
            std::vector<int> setResult = BFS(setGraph, 7);
            assert(bfsResult.size() == setResult.size());
            for (int i = 0; i < bfsResult.size(); ++i) {
                assert(bfsResult[i] == setResult[i]);
            }
        }
        {
            // test3.2 prevVertices
            std::vector<int> prev3 = {1, 5, 6};
            auto setResult = setGraph.GetPrevVertices( 3 );
            assert(prev3.size() == setResult.size());
            for (int i = 0; i < prev3.size(); ++i) {
                assert(prev3[i] == setResult[i]);
            }
        }
        {
            // test3.3 nextVertices
            std::vector<int> next6 = {3, 5, 7};
            auto setResult = setGraph.GetNextVertices( 6 );
            assert(next6.size() == setResult.size());
            for (int i = 0; i < next6.size(); ++i) {
                assert(next6[i] == setResult[i]);
            }
        }
    }
    {
        // arcGraph
        ArcGraph arcGraph( *listGraph );
        {
            // test4.1 BFS
            std::vector<int> bfsResult = {7, 5, 3, 0, 4, 2, 1, 6};
            std::vector<int> arcResult = BFS(arcGraph, 7);
            assert(bfsResult.size() == arcResult.size());
            for (int i = 0; i < bfsResult.size(); ++i) {
                assert(bfsResult[i] == arcResult[i]);
            }
        }
        {
            // test4.2 prevVertices
            std::vector<int> prev3 = {1, 5, 6};
            auto arcResult = arcGraph.GetPrevVertices( 3 );
            assert(prev3.size() == arcResult.size());
            for (int i = 0; i < prev3.size(); ++i) {
                assert(prev3[i] == arcResult[i]);
            }
        }
        {
            // test4.3 nextVertices
            std::vector<int> next6 = {3, 5, 7};
            auto arcResult = arcGraph.GetNextVertices( 6 );
            assert(next6.size() == arcResult.size());
            for (int i = 0; i < next6.size(); ++i) {
                assert(next6[i] == arcResult[i]);
            }
        }
    }
}

int main()
{
    testGraphs();
    return 0;
}
