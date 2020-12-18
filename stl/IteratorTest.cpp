//
// Created by wujianchao5 on 2020/12/15.
//

/**
 * 1. 不能在for循环中向vector对象添加元素
 * 2. push_back，会使该迭代器失效
 *
 *
    1. 输入迭代器(Input Iterator):只能向前单步迭代元素，不允许修改由该迭代器所引用的元素；
    2. 输出迭代器(Output Iterator):只能向前单步迭代元素，对由该迭代器所引用的元素只有写权限；
    3. 向前迭代器(Forward Iterator):该迭代器可以在一个区间中进行读写操作，它拥有输入迭代器的所有特性和输出迭代器的部分特性，以及向前单步迭代元素的能力；
    4. 双向迭代器(Bidirectional Iterator):在向前迭代器的基础上增加了向后单步迭代元素的能力；
    5. 随机访问迭代器(Random Access Iterator):不仅综合以后4种迭代器的所有功能，还可以像指针那样进行算术计算；

    6. vector、deque提供的是随机访问迭代器，list提供的是双向迭代器，set和map提供的是向前迭代器。
 */

