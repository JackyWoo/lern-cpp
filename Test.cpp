//
// Created by wujianchao5 on 2021/1/4.
//
#include <iostream>
#include <list>
#include <queue>
#include <map>
#include <functional>

int main(){
    using namespace std;
    using String = std::string;

    using Job = std::function<void>();

    Job  job;

    if(job){
        cout<<"not null job"<<endl;
    }

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

}