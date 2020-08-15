// 本文件中提供了一些方法，用以检测指针是否被释放。
// 你不需要在意这个文件中的代码。
#include <cstdlib>

class AllocManager {
public:
	struct pointer_record {
		uintptr_t ptr;
		bool array, released;
	};

private:
	static const size_t INIT_RECORDS = 5;
	
	static pointer_record *_records;
	static size_t _size, _capacity;
	static bool record_allocation;

	static void _ensure_size(size_t sz) {
		if (_records == nullptr || _capacity < sz) {
			record_allocation = false;
			size_t new_size = _records == nullptr ? INIT_RECORDS : _capacity * 2;
			auto *ptr = new pointer_record[new_size];
			if (_records != nullptr) {
				memcpy(ptr, _records, sizeof(pointer_record) * _capacity);
				delete[] _records;
			}
			_records = ptr;
			_capacity = new_size;
			record_allocation = true;
			// cerr << "_ensure_size(" << sz << "): resized to " << new_size << endl;
		}
	}
	
	static void add_record(void *ptr, bool array) {
		auto addr = reinterpret_cast<uintptr_t>(ptr);
		int idx = -1;
		for (int i = 0; i < _size; ++i)
			if (_records[i].ptr == addr) {
				idx = i;
				break;
			}
		if (idx == -1) {
			idx = _size++;
			_ensure_size(_size);
		}
		_records[idx] = {addr, array, false};
	}

	static pointer_record &find_record(void *ptr) {
		_ensure_size(0);
		auto addr = reinterpret_cast<uintptr_t>(ptr);
		for (int i = 0; i < _size; ++i)
			if (_records[i].ptr == addr) return _records[i];
		throw runtime_error("Trying to free a pointer that wasn't allocated");
	}

public:	
	template<typename T>
	static bool check_released(T *ptr) {
		return find_record(reinterpret_cast<void *>(ptr)).released;
	}

	friend void *operator new(size_t);
	friend void *operator new[](size_t);
	friend void operator delete(void *) noexcept;
	friend void operator delete[](void *) noexcept;
};

AllocManager::pointer_record *AllocManager::_records = nullptr;
size_t AllocManager::_size = 0;
size_t AllocManager::_capacity = 0;
bool AllocManager::record_allocation = true;


void *operator new(size_t sz) {
	void *ptr = malloc(sz);
	if (AllocManager::record_allocation) {
		// cerr << "new " << sz << " " << hex << ptr << dec << endl;
		AllocManager::add_record(ptr, false);
	}
	return ptr;
}

void *operator new[](size_t sz) {
	void *ptr = malloc(sz);
	if (AllocManager::record_allocation) {
		// cerr << "new[] " << sz << " " << hex << ptr << dec << endl;
		AllocManager::add_record(ptr, true);
	}
	return ptr;
}

void operator delete(void *ptr) noexcept {
	if (ptr == nullptr) return;
	if (AllocManager::record_allocation) {
		// cerr << "delete " << hex << ptr << dec << endl;
		auto &record = AllocManager::find_record(ptr);
		if (record.array)
			throw runtime_error("Trying to free an array pointer with `delete`");
		if (record.released)
			throw runtime_error("Trying to free a pointer that was already deallocated");
		record.released = true;
	}
	free(ptr);
}

void operator delete[](void *ptr) noexcept {
	if (ptr == nullptr) return;
	if (AllocManager::record_allocation) {
		// cerr << "delete[] " << hex << ptr << dec << endl;
		auto &record = AllocManager::find_record(ptr);
		if (!record.array)
			throw runtime_error("Trying to free a non-array pointer with `delete[]`");
		if (record.released)
			throw runtime_error("Trying to free a pointer that was already deallocated");
		record.released = true;
	}
	free(ptr);
}
