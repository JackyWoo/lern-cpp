//
// Created by wujianchao5 on 2020/12/21.
//

template<typename T = int>
void func(T a);

int main(){
    func(1);
    func<int>(1);
}

template<typename T>
void func(T a){
    
}

