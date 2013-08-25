#include <stdexcept>
#include <vector>

template<class T>
class CachedObj {
 public:
  void* operator new(std::size_t size);
  void operator delete(void* p, std::size_t size);
  virtual ~CachedObj();

 protected:
  T* next_;

 private:
  static void AddToFreelist(T* p);
  static std::allocator<T> alloc_mem;
  static T* freeStroe;
  static const std::size_t kChunk;
};

template<class T>
std::allocator<T> CachedObj<T>::alloc_mem;

template<class T>
T* CachedObj<T>::freeStroe = NULL;

template<class T>
const std::size_t CachedObj<T>::kChunk = 24;

// static
template<class T>
void* CachedObj<T>::operator new(std::size_t size) {
  if (size != sizeof(T))
    throw std::runtime_error("CachedObj: wrong size object in operator new");

  if (!freeStroe) {
    T* array = alloc_mem.allocate(kChunk);
    for (size_t i = 0; i < kChunk; i++)
      AddToFreelist(&array[i]);
  }

  T* p = freeStroe;
  freeStroe = freeStroe->CachedObj<T>::next_;
  return p;
}

// static
template<class T>
void CachedObj<T>::operator delete(void* p, std::size_t size) {
  if (p != NULL)
    AddToFreelist(static_cast<T*>(p));
}

template<class T>
CachedObj<T>::~CachedObj() {
}

// static
template<class T>
void CachedObj<T>::AddToFreelist(T* p) {
  p->CachedObj<T>::next_ = freeStroe;
  freeStroe = p;
}

class Screen : public CachedObj<Screen> {
 public:
  Screen() {}

 private:
  int arr[100000];
};

int main(int argc, char *argv[]) {
  Screen* screen = new Screen();
  delete screen;

  return 0;
}
