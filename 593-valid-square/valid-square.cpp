class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2||p1==p3||p1==p4||p2==p3||p2==p4||p3==p4){
            return false;
        }
    int a = abs((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
    int b = abs((p3[0]-p2[0])*(p3[0]-p2[0])+(p3[1]-p2[1])*(p3[1]-p2[1]));
    int c = abs((p4[0]-p2[0])*(p4[0]-p2[0])+(p4[1]-p2[1])*(p4[1]-p2[1]));
    int d = abs((p1[0]-p3[0])*(p1[0]-p3[0])+(p1[1]-p3[1])*(p1[1]-p3[1]));
    int e = abs((p1[0]-p4[0])*(p1[0]-p4[0])+(p1[1]-p4[1])*(p1[1]-p4[1]));
    int f = abs((p3[0]-p4[0])*(p3[0]-p4[0])+(p3[1]-p4[1])*(p3[1]-p4[1]));
    set<int> p;
    p.insert(a);
    p.insert(b);
    p.insert(c);
    p.insert(d);
    p.insert(e);
    p.insert(f);
    if(p.size()==2){
        return true;
    }
    return false;
    }
};