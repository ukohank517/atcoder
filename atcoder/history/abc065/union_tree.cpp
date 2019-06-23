#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define MAX 100001

using namespace std;

int parent[MAX];
int size[MAX];

int N,Q;
vector<int> P;
vector<int> A;
vector<int> B;

void setup(int n){
  for (int i = 0;i <= n; i++){
    parent[i]=i;
    size[i]=0;
  }
}

//改良余地あり
int root(int n){
  if(n == parent[n]) return n;
  else{
    n = root(parent[n]);
    return n;
  }
}

bool same(int a, int b){
  if(root(a) == root(b)){
    cout << "Yes" << endl;
    return true;
  }
  else {
    cout << "No" << endl;
    return false;
  }
}

void unite(int a, int b){
  a = root(a);
  b = root(b);

  if(a==b) return;
  
  else{
    if(size[a] < size[b]){
      parent[a]=b;
    }
    else{
      parent[b]=a;
      if(size[a] == size[b]) size[a]++;
    }
  }
  
}


int main(){
  int inp,ina,inb;

  cin >> N >> Q;
  setup(N);
  for (int i = 0;i<Q;i++){
    cin >> inp >> ina >> inb;
    P.push_back(inp);
    A.push_back(ina);
    B.push_back(inb);
  }

  for(int i = 0;i<Q;i++){
    if(P[i]==0)unite(A[i],B[i]);
    else same(A[i],B[i]);
  }

  return 0;
}