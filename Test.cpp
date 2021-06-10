//
// Created by wujianchao5 on 2021/1/4.
//
#include <iostream>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <functional>
#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <thread>

using Task = std::function<void()>;

void execute(Task task) {
    task();
}

int main(){
    using namespace std;
    using String = std::string;

    using Job = std::function<void>();

    Job  job;
    cout<<"not null job"<<endl;

    list<int> l;

    cout<<l.size()<<endl;
    cout<<*l.begin()<<endl;

//    l.emplace_back("1");
//    l.emplace_back("2");
//    l.emplace_back("3");
    l.emplace_back(1);
    l.emplace_back(2);
    l.emplace_back(3);


    for(auto it = l.begin(); it!=l.end();it++){
        cout<<*it<<endl;
    }

    map<String, int> map = {{"1", 1}};

    auto tmp = map.find("2");
    if(tmp != map.end()) {
        cout << tmp->second << endl;
    }

    cout<< "priority_queue" <<endl;
    priority_queue<int> queue;
    // seg fault
//    int a = queue.top();

    std::vector<String> cluster_nodes = {"1"};
    std::vector<String> user_initialized_nodes = {"1"};
    std::vector<String> must_finished_nodes;
    std::set_intersection(cluster_nodes.cbegin(), cluster_nodes.cend(),
                          user_initialized_nodes.cbegin(),
                          user_initialized_nodes.cend(),
                          std::insert_iterator<std::vector<String>>(must_finished_nodes, must_finished_nodes.begin()));
    cout<<must_finished_nodes.size()<<endl;

    std::cout<< sizeof(unsigned long long) << std::endl;
    std::cout<< sizeof(unsigned long) << std::endl;

    // no building error
    auto f = [& map] {
        std::cout<<"a"<<std::endl;
    };


    std::cout<<sizeof(byte)<<std::endl;
    std::cout<<sizeof(char)<<std::endl;

//    char * a = "a";
//    byte * b = reinterpret_cast<byte *>('a');


    std::atomic<char> aa('a');
    std::cout<<sizeof(atomic<char>)<<std::endl;

    cout << "---not init int-----" <<endl;

    int i;
    int j = {};
    cout<<i<<endl;
    cout<<j<<endl;

    cout << "--------" <<endl;

    cout<< "shared_mutex size :"<< sizeof(std::shared_mutex)<<endl;
    cout<< "mutex size :"<< sizeof(std::mutex)<<endl;
    cout<< "long size :"<< sizeof(long)<<endl;
    cout<< "string size :"<< sizeof(std::string)<<endl;

    cout << "--------" <<endl;

    std::shared_ptr<std::map<String, String>> mm = make_shared<std::map<String, String>>();
    if(mm){
        cout<<"mm is initialized"<<endl;
    }
    string ss = "aa";
    mm->emplace(ss, move(ss));
    cout<<mm->cbegin()->first<<mm->cbegin()->second<<endl;
    cout<<ss<<endl;

    Task task = [&mm] {
        cout<<"in task\n";
        cout<<mm->cbegin()->first<<mm->cbegin()->second<<endl;
    };

    std::thread t(task);
    t.detach();

    this_thread::sleep_for(chrono::seconds(1));
//    execute(task);

    cout << "--------" <<endl;

    struct Pod
    {
        int32_t a;
        int32_t b;
    };
    std::unordered_map<int32_t, Pod> mm1 = {{1, {1,1}}, {1, {1,1}}, {1, {1,1}}};
    std::unordered_map<int32_t, Pod> mm2 = {{1, {1,1}}};
    std::cout<<sizeof(mm1)<<std::endl;
    std::cout<<sizeof(mm2)<<std::endl;

    std::vector<int> aaa = {1, 2, 3};
    for(auto it=aaa.rbegin(); it != aaa.rend(); it++)
    {
        cout<<*it<<endl;
    }

    cout << "--------" <<endl;

}