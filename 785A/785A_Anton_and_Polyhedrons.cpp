#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n,count = 0;
    string name;
    cin >> n;
    while(n--)
    {
       cin >> name;
       if(name == "Tetrahedron")
          count += 4;
       else if(name == "Cube")
          count += 6;
       else if(name == "Octahedron")
          count += 8;
       else if(name == "Dodecahedron")
          count += 12;
       else
           count += 20;
    }
    cout << count << endl;
    return 0;
}