#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

class MaxHeap{
    int arr[1000];
    int heapsize;
    int parent(int i){
        return i/2;
    }
    int left(int i){
        return 2*i;
    }
    int right(int i){
        return 2*i+1;
    }
    public:
        MaxHeap(int a[], int n){
            heapsize=n;
            for(int i=1;i<=n;++i){
                arr[i]=a[i-1];
            }
            construct();
        }
        void max_heapify(int i){
            int largest=i;
            int l=left(i);
            int r=right(i);
            if(l<=heapsize && arr[largest]<arr[l])
                largest=l;
            if(r<=heapsize && arr[largest]<arr[r])
                largest=r;
            if(largest!=i){
                swap(arr[i], arr[largest]);
                max_heapify(largest);
            }
        }

        void construct(){
            for(int i=heapsize/2;i>=1;--i){
                max_heapify(i);
            }
        }

        int get_max(){
            if(heapsize<1)
                return -1;
            return arr[1];
        }

        int extract_max(){
            if(heapsize<1)
                return -1;
            int temp=arr[1];
            arr[1]=arr[heapsize];
            heapsize--;
            max_heapify(1);
        }

        void increase_key(int i, int key){
            if(key<=arr[i])
                cout<<"The key can only be increased..."<<endl;
            else{
                arr[i]=key;
                while(i>1){
                    if(arr[i]>arr[parent(i)]){
                        swap(arr[i], arr[parent(i)]);
                        i=parent(i);
                    }
                    else
                        break;
                }
            }
        }

        void insert_key(int key){
            heapsize++;
            arr[heapsize]=-INT_MAX;
            increase_key(heapsize, key);
        }
};


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    MaxHeap h(arr, n);
    cout<<h.get_max()<<endl;
    h.insert_key(999);
    cout<<h.get_max()<<endl;
}
