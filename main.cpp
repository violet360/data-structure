#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
   int numRefills=0, currentRefill=0;
   int n = stops.size();
   while(currentRefill<=n){
    int lastRefill=currentRefill;
    while(currentRefill<=n&&(stops[currentRefill+1]-stops[lastRefill])<=tank){
        currentRefill=currentRefill+1;
    }
    if(currentRefill==lastRefill)
        return -1;
    if(currentRefill<=n)
        numRefills=numRefills+1;
   }
   return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}



