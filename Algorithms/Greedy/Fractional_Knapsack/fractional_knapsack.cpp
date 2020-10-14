#include <iostream>
#include <vector>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) {
  double value = 0.0;
  vector<float> temp(n);
  int maxi=0,j;

  while(capacity>0){
  for(int i=0;i<n;i++)
  {
      cout<<weights[i]<<values[i];
      temp[i]=(float)weights[i]/values[i];
      if(temp[i] > maxi)
      {

        maxi=temp[i];
        j=i;
      }
  }
      if(weights[j]<capacity)
      {
          value+=values[j];
          capacity-=weights[j];
      }
      else
      {
          value+=capacity*(values[j]/weights[j]*1.0);
          capacity=0;
      }
      weights[j]=-1;
      values[j]=-1;
      cout<<capacity;
      break;

  }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values,n);

  cout.precision(10);
  cout << optimal_value << std::endl;
  return 0;
}
