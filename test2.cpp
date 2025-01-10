#include <iostream>
#include<vector>
using namespace std;
int main(){
    int t,size;
    int sum1,sum2;
    vector<int>temp;
    cin>>t;
    while(t--){
        sum1=0;
        sum2=0;
        cin>>size;
        for(int i=0;i<size;i++){
            int num;
            cin>>num;
            temp.push_back(num);
        }
        for(int i=0;i<size;i+=2)
            sum1+=temp[i];
        for(int i=1;i<size;i+=2)
            sum2+=temp[i];
        temp.clear();
    }
    cout<<(sum1-sum2)<<endl;
    
}