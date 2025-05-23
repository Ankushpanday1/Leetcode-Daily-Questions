class Treap{
  static minstd_rand generator;

  struct Node{
    int priority;
    int value, size = 1, add;
    Node *l, *r;
    Node(int value): add(0), value(value), priority(generator()), l(nullptr), r(nullptr){}
  }*root = nullptr;

  static int getSize(Node *n){
    return n ? n->size : 0;
  }

  static void push(Node *n){
    if(n){
      if(n->add){            //if we need add
        n->value += n->add;

        if(n->l) n->l->add += n->add;
        if(n->r) n->r->add += n->add;

        n->add = 0;
      }
    }
  }

  static void update(Node *n){
    if(n){
      n->size = getSize(n->l) + 1 + getSize(n->r);
    }
  }

  static Node* merge(Node *a, Node *b){
    push(a);
    push(b);

    if(!a || !b) return a ? a : b;

    if(a->priority > b->priority){
      a->r = merge(a->r, b);
      update(a);
      return a;
    }
    else{
      b->l = merge(a, b->l);
      update(b);
      return b;
    }
  }

    static void split(Node *n, int k, Node *&a, Node*&b){
      push(n);

      if(!n){a = b = nullptr; return;}

      if(getSize(n->l) < k){
        split(n->r, k - getSize(n->l) - 1, n->r, b);
        a = n;
      }
      else{
        split(n->l, k, a, n->l);
        b = n;
      }
      update(a);
      update(b);
    }

public:
  int getValue(int index){
    Node *less, *equal, *greater;
    split(root, index, less, greater);
    split(greater, 1, equal, greater);
    int result = equal->value;
    root = merge(merge(less, equal), greater);
    return result;
  }

  void pushBack(int value){
    root = merge(root, new Node(value));
  }

  void addInRange(int indexL, int indexR, int val){
    Node *less, *equal, *greater;
    split(root, indexL, less, greater);
    split(greater,indexR - indexL + 1, equal, greater);

    equal->add += val;

    root = merge(merge(less, equal), greater);
  }
  
  void for_start(int n){      
  for (int i = 0; i != n; i++)
    root = merge(root, new Node(0));
  }
};

minstd_rand Treap::generator;

class Solution {
public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    vector<int> w(n);
    for(int i = 0; i != n; i++) w[nums1[i]] = i;
    
    vector<int> v(n);
    for(int i = 0; i != n; i++) v[i] = w[nums2[i]];
    
    Treap t;
    t.for_start(n);
    
    for(int i = 0; i != n; i++){
      if(v[i]) w[i] = t.getValue(v[i] - 1);
      else w[i] = 0;
      t.addInRange(v[i], n-1, 1);
    }
    
    Treap k;
    k.for_start(n);
    long ans = 0;
    k.addInRange(0, v.back(), 1);
    
    for(int i = n-2; i; i--){
      if(v[i] != n-1) ans += long(w[i]) * k.getValue(v[i] + 1); 
      k.addInRange(0, v[i], 1);
    }
 
    return ans;
  }
};