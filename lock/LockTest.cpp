//
// Created by wujianchao5 on 2020/11/13.
//
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <chrono>
#include <thread>
#include <unordered_map>

struct Node
{
    int id;
    std::mutex mutex;
};

using Undo = std::function<void()>;


using SharedElement = std::shared_ptr<Node>;
using Container = std::unordered_map<std::string, SharedElement>;

Container container;


Undo generateUndo()
{
    SharedElement node = container.at("1");

    auto undo = [&node] {
        std::cout << "before lock" << std::endl;
        std::lock_guard lock(node->mutex);
        std::cout << "after lock" << std::endl;
    };
    return undo;
}

void invoke1(const Undo & fun)
{
    std::cout << "invoke" << std::endl;
    fun();
}

int main()
{
    SharedElement node = std::make_shared<Node>();
    node->id = 1;

    SharedElement node2 = std::make_shared<Node>();
    node2->id = 2;

    container.emplace("1", node);
    container.emplace("2", node2);

    Undo undo = generateUndo();
    invoke1(undo);

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(10s);
}