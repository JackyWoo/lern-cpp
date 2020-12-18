//
// Created by wujianchao5 on 2020/12/24.
//

#define free(p) {                                                       \
        printf("@@%s:%d:%s():free(0x%lx)\n", __FILE__, __LINE__,            \
            __func__, (unsigned long)p);                                \
        free(p);                                                        \
}

#define malloc(size) ({                                                 \
        void* ptr=malloc(size);\
        printf("@@%s:%d:%s():malloc(0x%lx)\n", __FILE__, __LINE__,            \
            __FUNCTION__, (unsigned long)ptr);                                \
        ptr;                                                        \
})

#define new new(__FILE__, __LINE__,__FUNCTION__)


void* operator new(size_t size, const char *file, int line,const char *function) throw (std::bad_alloc){
void * ptr=malloc(size);
printf("&&%s:%d:%s:new(size=%u)=%p\n",file,line,function,size,ptr);
if(ptr==NULL)
throw std::bad_alloc();
printf("override operator new");
return ptr;
}