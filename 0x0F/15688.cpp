// #include<bits/stdc++.h>
// using namespace std;

// int arr[1000005];
// int ism[1000005];//~ -1    절댓값이 1,000,000보다 작거나 같은 정수
// int isp[1000005]; //0~1000000
// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     for(int i=0;i<n;i++){
//         cin >>arr[i];
//     }
//     //-일때 처리!
//     for(int i=0;i<n;i++){
//         if(arr[i]>=0)isp[arr[i]]++;
//         else{
//             ism[-arr[i]]++;
//         }
//     }

//     for(int i=1000000;i>0;i--){
//         if(ism[i]>0){
//             for(int k=0;k<ism[i];k++){
//                 cout<< -i<<'\n';
//             }
//         }
//     }
//     for(int i=0;i<=1000000;i++){
//         if(isp[i]>0){
//             for(int k=0;k<isp[i];k++){
//                 cout<< i<<'\n';
//             }
//         }
//     }
    


//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int freq[2000001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        int a;
        cin >>a;
        freq[a+1000000]++;
    }
    
    for(int i=0;i<=2000000;i++){
        while (freq[i]--)
        {
            cout<<i-1000000<<'\n';
        }
        
    }
    
}