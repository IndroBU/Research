#include <bits/stdc++.h>
using namespace std;
#define mx 10485760
string str;
string tree[mx * 3];

void built(int node, int b, int e)
{
    if (b == e) {
       tree[node] = str[b-1];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    built(Left, b, mid);
    built(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
string substr(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return "";
    if (b >= i && e <= j)
        return tree[node];

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    string p1 = substr(Left, b, mid, i, j);
    string p2 = substr(Right, mid + 1, e, i, j);
    return p1 + p2;
}


int main () {

  ifstream fin;
  fin.open("input.txt");

  int q;
  int l,u;
 if(fin.is_open())
  {
    while(fin>>str)
    {
          int n= str.size();
      built(1,1,n);
      fin>>q;
      while(q--){
      fin>>l>>u;
      cout<<substr(1,1,n,l,u)<<endl;
      //cout<<str.substr (l,u)<<endl;

    }

  }
   fin.close();
  }
  else cout << "Unable to open file";



  return 0;
}

