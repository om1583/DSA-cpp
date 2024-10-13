#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

        heap()
        {
            arr[0]=-1;
            size=0;
        }

        //insert at end
        void insert(int x)
        {
        
            size++;
            int idx=size;
            arr[idx]=x;

            while(idx>1)
            {
                int parent=idx/2;
                if(arr[parent]<arr[idx])
                {
                    swap(arr[idx],arr[parent]);
                    idx= parent;
                }
                else
                {
                    return;
                }
            }
        }

        // delete from top
        void deletefromHeap()
        {
            if(size==0)
            {
                cout<<"heap is empty!"<<endl;
                return;
            }
            arr[1]=arr[size];
            size--;
            int i=1;
            while(i<size)
            {
                int left= 2*i;
                int right= 2*i+1;
                if(left<=size && arr[left]>arr[i])
                {
                    swap(arr[left],arr[i]);
                    i=left;
                }
                else if(right<=size && arr[right]>arr[i])
                {
                    swap(arr[right],arr[i]);
                    i=right;
                }
                else
                {
                    return;
                }
            }
        }

        void print()
        {
            for(int i=1;i<=size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main()
{
    heap h;
    h.insert(10);
    h.insert(7);
    h.insert(9);
    h.insert(6);
    h.insert(8);
     h.print();
    h.deletefromHeap();
    
    h.print();
    return 0;
}