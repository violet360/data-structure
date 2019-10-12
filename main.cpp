#include<bits/stdc++.h>
using namespace std;

bool sortbyratio(const pair<int,int> &a, const pair<int,int> &b){
    return ((a.first/a.second)>(b.first/b.second));
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  vector< pair <double,double> > vect;
  int s = weights.size();
  for(int i=0;i<s;i++){
    vect.push_back(make_pair(values[i],weights[i]));
  }
  sort(vect.begin(),vect.end(),sortbyratio);
  int k=0;
  double value = 0.0;
for(int i = 0; i<s;i++){
    if(k+vect[i].second<=capacity){
        k+=vect[i].second;
        value+=vect[i].first;
    }
    else{
        int remain=capacity-k;
        value+=vect[i].first*((double)remain/vect[i].second);
    }
}

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value =  get_optimal_value(capacity, weights, values);

 std::cout.precision(7);
  std::cout << optimal_value << std::endl;
  return 0;
}
