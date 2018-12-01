class Solution {

private:
    
    int DRAW = 0, MOUSE = 1, CAT = 2; // winning states;
    int color[50][50][3]; // Winner of that state
    int degree[50][50][3]; // degree[node/state]: the number of neutral children of this node
    
    struct Node {
        int _mousePosition;
        int _catPosition;
        int _turn;
        int _winner; // winner at this state
    };
    
    vector<Node> adjacentNodes(vector<vector<int>>& graph, int m, int c, int turn) {
        vector<Node> _adjacentNodes;
        if (turn == 2) {
            for(int i=0;i<graph[m].size();i++)
                _adjacentNodes.push_back(Node{graph[m][i], c, 3-turn});
        } else {
            for (int i=0;i<graph[c].size();i++) 
                if (graph[c][i] > 0)
                    _adjacentNodes.push_back(Node{m, graph[c][i], 3-turn});
        }
        return _adjacentNodes;
    }
    
public:
    int catMouseGame(vector<vector<int>>& graph) {
        
        int N = graph.size();
        
        for(int m=0;m<N;m++) {
            for(int c=0;c<N;c++) {
                degree[m][c][1] = graph[m].size();
                degree[m][c][2] = graph[c].size();
                for(int i=0;i<graph[c].size();i++) { 
                    if (graph[c][i]== 0) {
                        degree[m][c][2]--;
                        break;
                    }
                }
            }
        }
            
        // enqueued : all nodes that are colored
        queue<Node> Q;
        
        for (int i=0;i<N;i++)
            for (int t=1;t<=2;t++) {
                color[0][i][t] = MOUSE;
                Q.push(Node{0, i, t, MOUSE});
                if (i > 0) {
                    color[i][i][t] = CAT;
                    Q.push(Node{i, i, t, CAT});
                }
            }

        // percolate
        while (!Q.empty()) {
            // for nodes that are colored :
            Node node = Q.front();
            Q.pop();
            
            int mousePosition = node._mousePosition;
            int catPosition = node._catPosition;
            int turn = node._turn;
            int winner = node._winner;
            
            vector<Node> _adjacentNodes = adjacentNodes(graph, mousePosition, catPosition, turn);
            
            for (int i=0;i<_adjacentNodes.size();i++) {
                int i2 = _adjacentNodes[i]._mousePosition;
                int j2 = _adjacentNodes[i]._catPosition; 
                int t2 = _adjacentNodes[i]._turn;
                
                if (color[i2][j2][t2] == DRAW) {
                    if (t2 == winner) { // Jiska turn hai, wohin winner hai.
                        color[i2][j2][t2] = winner;
                        Q.push(Node{i2, j2, t2, winner});
                    } else {
                        degree[i2][j2][t2]--;
                        if (degree[i2][j2][t2] == 0) { // no way to reach a winning state. So, winner for this state is opponent.
                            color[i2][j2][t2] = 3 - t2;
                            Q.push(Node{i2, j2, t2, 3 - t2});
                        }
                    }
                }
            }
        }

        return color[1][2][1];
    }
};