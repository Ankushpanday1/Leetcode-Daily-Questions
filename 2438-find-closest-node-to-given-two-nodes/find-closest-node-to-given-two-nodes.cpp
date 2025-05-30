class Solution {
public:
    using NodeDistances = std::map<int, int>;
    NodeDistances GetReachableNodesAndDistance(int startingNode, int stopNode, vector<int>& edges){
        NodeDistances result;
        std::map<int, int> visitHistory;
        int currentNode = startingNode;
        int distance = 0;
        ++visitHistory[currentNode];
        result[currentNode] = distance++; // append the node itself with 0 distance
        
        while(edges[currentNode] != -1){
            if(visitHistory[edges[currentNode]]){
                break;
            }
            result[edges[currentNode]] = distance++;
            if(currentNode == stopNode){
                break;
            }
            ++visitHistory[currentNode];
            currentNode = edges[currentNode];
        }
        return result;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        NodeDistances nodes1 = GetReachableNodesAndDistance(node1, node2, edges);
        NodeDistances nodes2 = GetReachableNodesAndDistance(node2, node1, edges);


        int size = nodes1.size() > nodes2.size() ? nodes2.size() : nodes1.size();
        NodeDistances* nodesA = nodes1.size() > nodes2.size() ? &nodes2 : &nodes1;
        NodeDistances* nodesB = nodes1.size() > nodes2.size() ? &nodes1 : &nodes2;

        std::vector<int> commonNodes;
        for(auto a : *nodesA){
            if(nodesB->find(a.first) != nodesB->end()){
                commonNodes.push_back(a.first);
            }
        }
        int min = INT_MAX;
        int minNode = -1;
        for(auto node : commonNodes){
            int currentMax = max(nodes1[node], nodes2[node]);
            if(min > currentMax){
                min = currentMax;
                minNode = node;
            } else if(min == currentMax){
                if(minNode > node){
                    minNode = node;
                }
            }
        }
        
        return minNode;
    }
};