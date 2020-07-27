#include <thread>
#include <mutex>
#include <vector>

static std::mutex exclusive;

void segment_count(int array[],int l,int r,int counts[],int max_value){
    int* local_counts=new int[max_value+1];

    for(int i=l;i<r;i++) local_counts[array[i]]++;

    exclusive.lock();
    for(int i=0;i<=max_value;i++) counts[i]+=local_counts[i];
    exclusive.unlock();

    return;
}

void parallel_count(int array[], int array_size, int counts[], int max_value){
    int gap=array_size/4;
    int tmp_arr[5]={0,gap,gap*2,gap*3,array_size};

    std::vector<std::thread> list;
    for(int i=0;i<4;i++){
        list.push_back(std::thread(segment_count,array,tmp_arr[i],tmp_arr[i+1],counts,max_value));
        list[i].join();
    }
}